//
//  LabelPrinterFactory.h
//  RTPrinterSDK
//
//  Created by King on 12/12/2017.
//  Copyright © 2017 Rongta. All rights reserved.
//

#import "PrinterFactory.h"
#import "LabelPrinter.h"

@interface LabelPrinterFactory : PrinterFactory
+(LabelPrinter *) Create;

@end
