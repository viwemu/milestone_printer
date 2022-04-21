//
//  Header.h
//  RtPrinterLib
//
//  Created by testosx on 18/07/2017.
//  Copyright © 2017 bluedrum. All rights reserved.
//
#import "EnumTypeDef.h"

#ifndef Header_h
#define Header_h
//#define isShowLog
#ifdef   isShowLog
#define SLog(...) NSLog(__VA_ARGS__)
#else
#define SLog(...) {}
#endif



#endif /* Header_h */

#define override_Exception_Format @"You must override:% @ methods in %@'s subclasses"
#define UIColorFromHex(s) [UIColor colorWithRed:(((s & 0xFF0000) >> 16))/255.0 green:(((s &0xFF00) >>8))/255.0 blue:((s &0xFF))/255.0 alpha:1.0]

extern const NSString * PrinterConnectedNotification;
extern const NSString * PrinterDisconnectedNotification ;


extern const NSString * BleDeviceConnectedNotify;
extern const NSString * BleDeviceDataChanged;
extern const NSString * BleServiceFindDevice;
extern const NSString * BleDeviceRssiChanged;
extern const NSString * BleServiceStatusChanged ;
extern const NSString * BleSystemBluetoothReady;

/*!
 坐标位置，可用于条码，文本的打印
 Coordinate position, can be used for bar code, text printing 
 @param x x
 @param y y
 @param width width
 @param height height
 @return Coordinate
 */
Coordinate CoordMake(NSInteger x, NSInteger y, NSInteger width, NSInteger height);


