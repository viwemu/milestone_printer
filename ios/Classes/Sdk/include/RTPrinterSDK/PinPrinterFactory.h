//
//  PinPrinterFactory.h
//  RTPrinterSDK
//
//  Created by King on 28/11/2017.
//  Copyright © 2017 Rongta. All rights reserved.
//

#import "PrinterFactory.h"
#import "PinPrinter.h"
/*!
  针打的打印机工厂类
  Pin printer factory category
 */
@interface PinPrinterFactory : PrinterFactory
+(PinPrinter *) Create;

@end
