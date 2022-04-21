//
//  ThermalPrinterFactory.h
//  RTPrinterSDK
//
//  Created by King on 12/12/2017.
//  Copyright © 2017 Rongta. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PrinterFactory.h"
#import "ThermalPrinter.h"

@interface ThermalPrinterFactory : PrinterFactory
+(ThermalPrinter *) Create;
@end
