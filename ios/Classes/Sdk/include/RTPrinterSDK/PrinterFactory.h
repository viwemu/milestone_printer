//
//  PrinterFactory.h
//  RTPrinterSDK
//
//  Created by King on 28/11/2017.
//  Copyright © 2017 Rongta. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Printer.h"

/*!
 创建打印机工厂的基类
 Create a printer factory base class
 */
@interface PrinterFactory : NSObject
/*!
 创建打印机Printer类
 Create Printer Printer class
 */
+(Printer*) Create;
@end
