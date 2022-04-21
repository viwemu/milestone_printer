//
//  PIFactory.h
//  RTPrinterSDK
//
//  Created by King on 28/11/2017.
//  Copyright © 2017 Rongta. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PrinterInterface.h"

/*!
 创建指令的工厂基类
 The factory base class that created the PrinterInterface
 */
@interface PIFactory : NSObject
+(PrinterInterface *) Create;
@end
