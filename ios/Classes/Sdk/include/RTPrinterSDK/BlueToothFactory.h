//
//  BlueToothFactory.h
//  RTPrinterSDK
//
//  Created by King on 28/11/2017.
//  Copyright © 2017 Rongta. All rights reserved.
//

#import "PrinterInterface.h"
#import "PIFactory.h"
#import "EnumTypeDef.h"
#import "RTBlueToothPI.h"

/*!
 创建蓝牙接口工厂类
 Factory class to create a RTBlueToothPI interface
 */
@interface BlueToothFactory : PIFactory

/*!
 根据蓝牙类型bluekind，创建对应的蓝牙接口RTBlueToothPI
 Through the parameter bluekind, create Bluetooth interface RTBlueToothPI
 interface
 @param bluekind 蓝牙类型 Bluetooth type
 @return RTBlueToothPI
 */
+(RTBlueToothPI *) Create:(BlueToothKind) bluekind;
@end
