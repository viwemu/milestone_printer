class MilestoneState {}

class MilestoneConnectSuccessState extends MilestoneState {
  MilestoneConnectSuccessState(this.ip);

  String? ip;
}

class MilestoneConnectInterruptedState extends MilestoneState {
  MilestoneConnectInterruptedState(this.ip);

  String? ip;
}

class MilestonePrintSuccessState extends MilestoneState {
  MilestonePrintSuccessState(this.ip);

  String? ip;
}

class MilestonePrintFailedState extends MilestoneState {
  MilestonePrintFailedState(this.ip, this.message);

  String? ip;
  String? message;
}
