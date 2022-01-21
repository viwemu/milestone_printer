#import "MilestonePrinterPlugin.h"
#if __has_include(<milestone_printer/milestone_printer-Swift.h>)
#import <milestone_printer/milestone_printer-Swift.h>
#else
// Support project import fallback if the generated compatibility header
// is not copied when this plugin is created as a library.
// https://forums.swift.org/t/swift-static-libraries-dont-copy-generated-objective-c-header/19816
#import "milestone_printer-Swift.h"
#endif

@implementation MilestonePrinterPlugin
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
  [SwiftMilestonePrinterPlugin registerWithRegistrar:registrar];
}
@end
