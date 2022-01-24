package com.lamle.milestoneprinter.milestone_printer;


import android.app.Activity;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;

import androidx.annotation.NonNull;

import com.rt.printerlibrary.bean.PrinterStatusBean;
import com.rt.printerlibrary.bean.WiFiConfigBean;
import com.rt.printerlibrary.cmd.Cmd;
import com.rt.printerlibrary.cmd.EscFactory;
import com.rt.printerlibrary.connect.PrinterInterface;
import com.rt.printerlibrary.enumerate.CommonEnum;
import com.rt.printerlibrary.factory.cmd.CmdFactory;
import com.rt.printerlibrary.factory.connect.WiFiFactory;
import com.rt.printerlibrary.factory.printer.UniversalPrinterFactory;
import com.rt.printerlibrary.observer.PrinterObserver;
import com.rt.printerlibrary.observer.PrinterObserverManager;
import com.rt.printerlibrary.printer.RTPrinter;
import com.rt.printerlibrary.utils.PrintStatusCmd;
import com.rt.printerlibrary.utils.PrinterStatusPareseUtils;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import io.flutter.embedding.engine.plugins.FlutterPlugin;
import io.flutter.embedding.engine.plugins.activity.ActivityAware;
import io.flutter.embedding.engine.plugins.activity.ActivityPluginBinding;
import io.flutter.plugin.common.MethodCall;
import io.flutter.plugin.common.MethodChannel;
import io.flutter.plugin.common.MethodChannel.MethodCallHandler;
import io.flutter.plugin.common.MethodChannel.Result;

/** MilestonePrinterPlugin */
public class MilestonePrinterPlugin implements MethodCallHandler, PrinterObserver, ActivityAware, FlutterPlugin {
  private MethodChannel channel;

//  private BinaryMessenger binaryMessenger;

  private Activity activity;

  private Map<String, RTPrinter> printers = new HashMap<>();
  private Map<String, Boolean> connectedPrinters = new HashMap<>();

  private Handler uiThreadHandler = new Handler(Looper.getMainLooper());


  @Override
  public void onAttachedToActivity(@NonNull ActivityPluginBinding binding) {
    activity = binding.getActivity();
    Log.e("MilestonePrinterPlugin", activity == null ? "activity == null" : "activity != null");
  }

  @Override
  public void onDetachedFromActivityForConfigChanges() {

  }

  @Override
  public void onReattachedToActivityForConfigChanges(@NonNull ActivityPluginBinding binding) {

  }

  @Override
  public void onDetachedFromActivity() {

  }

  @Override
  public void onAttachedToEngine(@NonNull FlutterPluginBinding flutterPluginBinding) {
    channel = new MethodChannel(flutterPluginBinding.getBinaryMessenger(), "milestone_printer");
    channel.setMethodCallHandler(this);

    PrinterObserverManager.getInstance().add(this);
  }

  @Override
  public void onMethodCall(@NonNull MethodCall call, @NonNull Result result) {
    final Map<String, Object> args = call.arguments();
    List<String> ips;
    switch (call.method) {
      case "connect":
        ips = (List<String>) args.get("ips");
        for (String ip : ips) {
          connect(ip);
        }
        break;
      case "disconnect":
        ips = (List<String>) args.get("ips");
        for (String ip : ips) {
          disconnect(ip);
        }
        break;
      case "cut":
        ips = (List<String>) args.get("ips");
        for (String ip : ips) {
          cut(ip);
        }
        break;
      case "printer":
        ips = (List<String>) args.get("ips");
        List<Integer> data = (List<Integer>) args.get("bytes");
        byte bytes[] = new byte[data.size()];
        for (int i = 0; i < data.size(); i++) {
          bytes[i] = (byte) ((int) data.get(i));
        }
        for (String ip : ips) {
          print(ip, bytes);
        }
        break;
      case "dispose":
        dispose();
        break;
      case "isConnected":
        String ip = (String) args.get("ip");
        result.success(connectedPrinters.get(ip));
        break;
      case "getConnectedPrinters":
        result.success(getConnectedPrinters());
        break;
    }
  }

  @Override
  public void onDetachedFromEngine(@NonNull FlutterPluginBinding binding) {
    channel.setMethodCallHandler(null);
  }

  void connect(String ip) {
    WiFiConfigBean wiFiConfigBean = new WiFiConfigBean(ip, 9100);
    printers.put(ip, new UniversalPrinterFactory().create());

    PrinterInterface printerInterface = new WiFiFactory().create();
    printerInterface.setConfigObject(wiFiConfigBean);
    printerInterface.setmName(wiFiConfigBean.ip);

    printers.get(ip).setPrinterInterface(printerInterface);
    printers.get(ip).setPrintListener(printerStatusBean -> {
      if (printerStatusBean.printStatusCmd == PrintStatusCmd.cmd_PrintFinish) {
        if (printerStatusBean.blPrintSucc) {
          onPrintSuccess(ip);
        } else {
          onPrintFailed(ip, PrinterStatusPareseUtils.getPrinterStatusStr(printerStatusBean));
        }
      }
    });
    try {
      printers.get(ip).connect(wiFiConfigBean);
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  List<String> getConnectedPrinters() {
    return new ArrayList<>(printers.keySet());
  }

  void disconnect(String ip) {
    printers.get(ip).disConnect();
    printers.remove(ip);
    connectedPrinters.remove(ip);
  }

  void dispose() {
    for (Map.Entry<String, RTPrinter> entry : printers.entrySet()) {
      entry.getValue().disConnect();
    }
  }

  void cut(String ip) {
    if (printers.get(ip) == null) {
      return;
    }
    CmdFactory cmdFactory = new EscFactory();
    Cmd cmd = cmdFactory.create();
    cmd.append(cmd.getAllCutCmd());
    printers.get(ip).writeMsgAsync(cmd.getAppendCmds());
  }

  void print(String ip, byte[] bytes) {
    if (printers.get(ip) == null) {
      return;
    }
    printers.get(ip).writeMsgAsync(bytes);
  }

  @Override
  public void printerObserverCallback(PrinterInterface printerInterface, int state) {
    Log.e("MilestonePrinterPlugin", "printerObserverCallback");
    uiThreadHandler.post(() -> {
      switch (state) {
        case CommonEnum.CONNECT_STATE_SUCCESS:
          if (printerInterface != null && printerInterface.getConfigObject() != null) {
            connectedPrinters.put(printerInterface.getmName(), true);
            onConnectSuccess(printerInterface.getmName());
          }
          break;
        case CommonEnum.CONNECT_STATE_INTERRUPTED:
          if (printerInterface != null) {
            connectedPrinters.put(printerInterface.getmName(), false);
            onConnectInterrupted(printerInterface.getmName());
          }
          break;
        default:
          break;
      }
    });
  }

  @Override
  public void printerReadMsgCallback(PrinterInterface printerInterface, byte[] bytes) {
    PrinterStatusBean StatusBean = PrinterStatusPareseUtils.parsePrinterStatusResult(bytes);
    if (StatusBean.printStatusCmd == PrintStatusCmd.cmd_PrintFinish) {
      if (StatusBean.blPrintSucc) {
        onPrintSuccess(printerInterface.getmName());
      }
    }
  }


  private void onConnectSuccess(String ip) {
        channel.invokeMethod("onConnectSuccess", ip);
  }

  private void onConnectInterrupted(String ip) {
        channel.invokeMethod("onConnectInterrupted", ip);
  }

  private void onPrintSuccess(String ip) {
        channel.invokeMethod("onPrintSuccess", ip);
  }

  private void onPrintFailed(String ip, String message) {
        Map<String, String> arguments = new HashMap<>();
        arguments.put("ip", ip);
        arguments.put("message", message);
        channel.invokeMethod("onPrintFailed", arguments);
  }
}
