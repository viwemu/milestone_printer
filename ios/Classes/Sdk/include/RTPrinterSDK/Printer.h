//
//  Printer.h
//  RTPrinterSDK
//
//  Created by King 22/11/2017.
//  Copyright © 2017 Rongta. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PrinterInterface.h"
#import "TextSetting.h"
#import "CommonSetting.h"
#import "BitmapSetting.h"
#import "NetworkPrinter.h"


/*!
 打印机基类
 Printer base class
 */
@interface Printer:NSObject

/*!
 打印机连接的接口(如蓝牙，wifi)
 Printer connection interface (such as Bluetooth, wifi)

 */
@property(nonatomic,retain) PrinterInterface * PrinterPi;

/*!
  打印文本设置
  Print text settings
 */
@property(nonatomic,strong,readonly) TextSetting * TextSets;

/*!
  通用设置
 Universal settings
 */
@property(nonatomic,strong) CommonSetting * CommonSetts;

/*!
 图像设置
 Image settings
 */
@property(nonatomic,strong,readonly) BitmapSetting * BitmapSetts;

/*!
 是否已经连接到打印机
 Whether it has been connected to the printer
 */
@property(nonatomic,readonly) BOOL IsOpen;

/*!蓝牙写入方式
 Bluetooth write mode
 */
@property (nonatomic) BleWriteType blewritetype;

/*!
  write后，是否需要回调！
  After writing, do you need a callback!
 */
@property (nonatomic) BOOL IsNeedCallBack;

/*!
 发送数据到打印机
 Sending data to the printer
 @param data 要发送的命令数据
 */
-(void) Write:(NSData *) data;

/*!
 发送数据到打印机 异步执行
 Sending data to the printer(Asynchronous execution)
 @param data 要发送的命令数据  Command data to send
 */
-(void) WriteAsync:(NSData *)data;

/*!
 读取数据（暂无用）
 Read data (temporarily useless)
 */
-(void) Read;

/*!
  开启连接打印机
 Open connection printer
 */
-(void) Open;

/*!
 关闭连接
 Close connection
 */
-(void) Close;
-(void) GetNetworkPrinter:(NetPrinterBlock) netPrinterBlock;


@end
