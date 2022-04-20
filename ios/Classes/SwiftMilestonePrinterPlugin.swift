import Flutter
import UIKit

public class SwiftMilestonePrinterPlugin: NSObject, FlutterPlugin {
  static let channelName = "milestone_printer"
  
  public static func register(with registrar: FlutterPluginRegistrar) {
    let channel = FlutterMethodChannel(name: channelName, binaryMessenger: registrar.messenger())
    let handler =  PrinterHandler(channel: channel)
    registrar.addMethodCallDelegate(handler, channel: channel)
  }
  
  public func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
    result("iOS " + UIDevice.current.systemVersion)
  }
}

class PrinterHandler: NSObject, FlutterPlugin {
  
  var channel: FlutterMethodChannel
  
  var printers: [String: Printer] = [:]
  let currentPrinterCmdType = PrinterCmdType(0) // esc
  
  init(channel: FlutterMethodChannel) {
    self.channel = channel
    super.init()
    registerNotification(self, selector: #selector(handleConnectState))
  }
  
  static func register(with registrar: FlutterPluginRegistrar) {
    
  }
  
  
  public func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
    let args = call.arguments as? Dictionary<String, Any>
    switch call.method {
    case "connect":
      let ips: [String] = (args?["ips"] as? [String]) ?? []
      for ip in ips {
        connect(ip: ip)
      }
    case "disconnect":
      let ips: [String] = (args?["ips"] as? [String]) ?? []
      for ip in ips {
        disconnect(ip: ip)
      }
      break
    case "cut":
      let ips: [String] = (args?["ips"] as? [String]) ?? []
      for ip in ips {
        cut(ip: ip)
      }
      break
    case "getConnectedPrinters":
      result(printers.values)
      break
    case "printer":
      let ips: [String] = (args?["ips"] as? [String]) ?? []
      let data: [Int] = (args?["bytes"] as? [Int]) ?? []
      for ip in ips {
        print(ip: ip,bytes: data);
      }
      break;
    case "dispose":
      dispose()
      break
    default:
      result(FlutterMethodNotImplemented)
    }
  }
  
  func dispose() {
    printers.values.forEach { printer in
      printer.close()
    }
    NotificationCenter.default.removeObserver(self)
  }
  
  func connect(ip: String) {
    let printerInter: PrinterInterface = WIFIFactory.create()
    printerInter.address = ip
    printerInter.port = 9100
    printerInter.printerCmdtype = currentPrinterCmdType
//    printerInter.isNeedCallBack = true
//    printerInter.callbackPrinterStatus = { (status, message) -> () in
//    }
//    printerInter.callbackPrintFinsh = { [weak self] (success, message) -> () in
//      if (success) {
//        self?.onPrintSuccess(ip: ip)
//      } else {
//        self?.onPrintFailed(ip: ip, message: message)
//      }
//      Swift.print(success)
//    }
    let printer = Printer()
    printer.printerPi = printerInter
    printer.open()
    self.printers[ip] = printer
  }
  
  func printCallBack(success: Bool, message: String) {
    
  }
  
  func disconnect(ip: String) {
    self.printers[ip]?.close()
    printers.removeValue(forKey: ip)
  }
  
  func cut(ip: String) {
    if (printers[ip] == nil) {
      return;
    }
    let cmd: Cmd = ESCFactory.create()
    cmd.append(cmd.getCutPaperCmd(CutterMode_Full))
    cmd.append(cmd.getCutPaperCmd(CutterMode_Full))
    printers[ip]?.writeAsync(cmd.getCmd())
  }
  
  func print(ip: String, bytes: [Int]) {
    if (printers[ip] == nil) {
      return
    }
    printers[ip]?.writeAsync(Data(bytes: bytes, count: bytes.count))
  }
  
  func onPrintSuccess(ip: String) {
    channel.invokeMethod("onPrintSuccess", arguments: ip)
  }
  
  func onPrintFailed(ip: String, message: String?) {
    var arguments: Dictionary<String, String> = [:]
    arguments["ip"] = ip
    arguments["message"] = message ?? ""
    channel.invokeMethod("onPrintFailed", arguments: arguments)
  }
  
  func registerNotification(_ observer: Any?, selector aSelector: Selector) {
    if let observer = observer {
      NotificationCenter.default.addObserver(observer, selector: aSelector, name: NSNotification.Name(NSNotification.Name.PrinterConnected.rawValue), object: nil)
      NotificationCenter.default.addObserver(observer, selector: aSelector, name: NSNotification.Name(NSNotification.Name.PrinterDisconnected.rawValue), object: nil)
      NotificationCenter.default.addObserver(observer, selector: aSelector, name: NSNotification.Name(BleDeviceDataChanged), object: nil)
    }
  }
  
  @objc
  func handleConnectState(notification: NSNotification) {
    DispatchQueue.main.async {
      switch (notification.name) {
      case NSNotification.Name.PrinterConnected:
        let obj: ObserverObj = notification.object as! ObserverObj
        let wifiInter = obj.msgobj as! WifiInterface
        self.channel.invokeMethod("onConnectSuccess", arguments: wifiInter.address)
        break;
      case NSNotification.Name.PrinterDisconnected:
        let obj: ObserverObj = notification.object as! ObserverObj
        let wifiInter = obj.msgobj as! WifiInterface
        self.channel.invokeMethod("onConnectInterrupted", arguments: wifiInter.address)
        break;
      default:
        break;
      }
    }
  }
}
