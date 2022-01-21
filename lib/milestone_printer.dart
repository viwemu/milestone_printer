import 'dart:async';

import 'package:flutter/services.dart';
import 'package:rxdart/rxdart.dart';

import 'milestone_state.dart';

class MilestonePrinter {
  static const MethodChannel _channel = MethodChannel('milestone_printer');
  static StreamController<MilestoneState> controller = BehaviorSubject<MilestoneState>();

  static void init() {
    _channel.setMethodCallHandler(methodHandler);
  }

  static void connect(List<String> ips) async {
    await _channel.invokeMethod('connect', {'ips': ips});
  }

  static void disconnect(List<String> ips) async {
    await _channel.invokeMethod('disconnect', {'ips': ips});
  }

  static void cut(List<String> ips) async {
    await _channel.invokeMethod('cut', {'ips': ips});
  }

  static void print(List<String> ips, List<int> bytes) async {
    await _channel.invokeMethod('printer', {'ips': ips, 'bytes': bytes});
  }

  static void dispose() async {
    await _channel.invokeMethod('dispose');
  }

  static Future<List<String>?> getConnectedPrinters() async {
    return _channel.invokeMethod<List<String>>('printer');
  }

  static Future<bool?> isConnected(String ip) async {
    return _channel.invokeMethod<bool?>('isConnected', {'ip': ip});
  }

  static Future<void> methodHandler(MethodCall call) async {
    switch (call.method) {
      case "onConnectSuccess":
        controller.sink.add(MilestoneConnectSuccessState(call.arguments));
        break;
      case "onConnectInterrupted":
        controller.sink.add(MilestoneConnectInterruptedState(call.arguments));
        break;
      case "onPrintSuccess":
        controller.sink.add(MilestonePrintSuccessState(call.arguments));
        break;
      case "onPrintFailed":
        controller.sink.add(MilestonePrintFailedState(call.arguments['ip'], call.arguments['message']));
        break;
      default:
    }
  }
}
