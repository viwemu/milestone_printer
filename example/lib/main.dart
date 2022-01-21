import 'package:flutter/material.dart';
import 'package:milestone_printer/milestone_printer.dart';
import 'package:milestone_printer/milestone_state.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  @override
  void initState() {
    super.initState();
    MilestonePrinter.init();
    MilestonePrinter.controller.stream.listen((event) {
      if (event is MilestoneConnectSuccessState) {
        print('MilestoneConnectSuccessState ${event.ip}');
      } else if (event is MilestoneConnectInterruptedState) {
        print('MilestoneConnectInterruptedState ${event.ip}');
      } else if (event is MilestonePrintSuccessState) {
        print('MilestoneConnectSuccessState ${event.ip}');
      } else if (event is MilestonePrintFailedState) {
        print('MilestonePrintFailedState ${event.ip}');
      }
    });
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Plugin example app'),
        ),
        body: Column(
          children: [
            ElevatedButton(
              onPressed: () => connect(),
              child: const Text('Connect'),
            ),
            ElevatedButton(
              onPressed: () => cut(),
              child: const Text('Cut'),
            ),
            ElevatedButton(
              onPressed: () => startPrint(),
              child: const Text('printer'),
            )
          ],
        ),
      ),
    );
  }

  void connect() async {
    MilestonePrinter.connect(['192.168.1.187', '192.168.1.188']);
  }

  void cut() async {
    MilestonePrinter.cut(['192.168.1.187', '192.168.1.188']);
  }

  void startPrint() async {
    List<int> bytes = [
      27,
      36,
      0,
      0,
      27,
      97,
      49,
      29,
      33,
      17,
      28,
      46,
      76,
      97,
      109,
      32,
      66,
      117,
      115,
      105,
      110,
      101,
      115,
      115,
      10,
      10,
      27,
      36,
      0,
      0,
      29,
      33,
      0,
      28,
      46,
      56,
      56,
      52,
      32,
      80,
      46,
      32,
      72,
      101,
      114,
      114,
      101,
      114,
      97,
      44,
      32,
      83,
      116,
      44,
      32,
      80,
      97,
      116,
      101,
      114,
      111,
      115,
      44,
      32,
      77,
      101,
      116,
      114,
      111,
      32,
      77,
      97,
      110,
      105,
      108,
      97,
      44,
      32,
      80,
      104,
      105,
      108,
      105,
      112,
      112,
      105,
      110,
      101,
      115,
      44,
      32,
      80,
      104,
      105,
      108,
      105,
      112,
      112,
      105,
      110,
      101,
      115,
      10,
      27,
      36,
      0,
      0,
      28,
      46,
      48,
      51,
      52,
      50,
      51,
      53,
      51,
      56,
      48,
      53,
      10,
      10,
      27,
      36,
      0,
      0,
      27,
      97,
      48,
      28,
      46,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      10,
      27,
      36,
      0,
      0,
      28,
      46,
      84,
      105,
      109,
      101,
      27,
      36,
      180,
      0,
      27,
      97,
      50,
      28,
      46,
      48,
      49,
      47,
      49,
      55,
      47,
      50,
      48,
      50,
      50,
      32,
      50,
      51,
      58,
      50,
      49,
      10,
      27,
      36,
      0,
      0,
      27,
      97,
      48,
      28,
      46,
      79,
      114,
      100,
      101,
      114,
      32,
      78,
      117,
      109,
      98,
      101,
      114,
      27,
      36,
      64,
      1,
      27,
      97,
      50,
      28,
      46,
      35,
      49,
      52,
      50,
      10,
      27,
      36,
      0,
      0,
      27,
      97,
      48,
      28,
      46,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      10,
      27,
      36,
      0,
      0,
      28,
      46,
      73,
      116,
      101,
      109,
      115,
      27,
      36,
      227,
      0,
      27,
      97,
      49,
      28,
      46,
      81,
      116,
      121,
      27,
      36,
      40,
      1,
      27,
      97,
      50,
      28,
      46,
      65,
      109,
      111,
      117,
      110,
      116,
      10,
      27,
      36,
      0,
      0,
      27,
      97,
      48,
      28,
      46,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      10,
      27,
      36,
      0,
      0,
      28,
      46,
      83,
      107,
      121,
      112,
      101,
      32,
      51,
      54,
      32,
      80,
      114,
      111,
      32,
      80,
      108,
      117,
      115,
      27,
      36,
      239,
      0,
      27,
      97,
      49,
      28,
      46,
      49,
      27,
      36,
      29,
      1,
      27,
      97,
      50,
      28,
      46,
      80,
      72,
      80,
      54,
      57,
      46,
      48,
      10,
      27,
      36,
      0,
      0,
      27,
      97,
      48,
      28,
      46,
      27,
      36,
      245,
      0,
      27,
      97,
      49,
      28,
      46,
      27,
      36,
      98,
      1,
      27,
      97,
      50,
      28,
      46,
      48,
      10,
      27,
      36,
      0,
      0,
      27,
      97,
      48,
      28,
      46,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      10,
      27,
      36,
      0,
      0,
      28,
      46,
      83,
      117,
      98,
      116,
      111,
      116,
      97,
      108,
      27,
      36,
      17,
      1,
      27,
      97,
      50,
      28,
      46,
      80,
      72,
      80,
      54,
      57,
      46,
      48,
      48,
      10,
      27,
      36,
      0,
      0,
      27,
      97,
      48,
      28,
      46,
      68,
      105,
      115,
      99,
      111,
      117,
      110,
      116,
      27,
      36,
      17,
      1,
      27,
      97,
      50,
      28,
      46,
      45,
      80,
      72,
      80,
      48,
      46,
      48,
      48,
      10,
      27,
      36,
      0,
      0,
      27,
      97,
      48,
      28,
      46,
      69,
      120,
      99,
      108,
      46,
      32,
      32,
      40,
      48,
      37,
      41,
      27,
      36,
      29,
      1,
      27,
      97,
      50,
      28,
      46,
      80,
      72,
      80,
      48,
      46,
      48,
      48,
      10,
      27,
      36,
      0,
      0,
      27,
      97,
      48,
      28,
      46,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      45,
      10,
      27,
      36,
      0,
      0,
      27,
      69,
      1,
      28,
      46,
      84,
      111,
      116,
      97,
      108,
      27,
      36,
      17,
      1,
      27,
      97,
      50,
      28,
      46,
      80,
      72,
      80,
      54,
      57,
      46,
      48,
      48,
      10,
      10,
      10,
      10,
      10,
      10,
      10,
      29,
      86,
      48
    ];
    MilestonePrinter.print(['192.168.1.187', '192.168.1.188'], bytes);
  }
}