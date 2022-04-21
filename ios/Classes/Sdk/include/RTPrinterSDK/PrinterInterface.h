//
//  PrinterInterface.h
//  RTPrinterSDK
//
//  Created by yjm 22/11/2017.
//  Copyright © 2017 Rongta. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "EnumTypeDef.h"
#import "PrinterStatusObj.h"


/*!
 打印机接口的基类
 The base class of the printer interface
 */
@interface PrinterInterface:NSObject

/*!
 设备逻辑名称 用于蓝牙名称
 The device logical name is used for Bluetooth name
 */
@property (nonatomic, copy) NSString  * Name;

/*!
 是否已经连接上打印机
 Whether the printer has been connected to the printer
 */
@property (nonatomic,readonly) BOOL IsOpen;
/*!
 连接地址
 Connection address
 */
@property (nonatomic,copy) NSString * Address;
/*!
 连接端口(仅限wifiInterface使用)
 Connection port (only for wifiInterface use)
 */
@property (nonatomic) NSInteger Port;
/*!
 连接超时的时间，单位:秒(仅限wifiInterface使用)
 Connection timeout, unit: second (wifiInterface only)
*/
@property (nonatomic) NSTimeInterval Timeout;
/*!指令类型, sdk内部没用到，为了给外部多连接时使用
 Instruction type, sdk internal useless, in order to use the external multi-connection
 */
@property (nonatomic) PrinterCmdType printerCmdtype;

/*!蓝牙写入方式
 Bluetooth write mode
 */
@property (nonatomic) BleWriteType blewritetype;
@property (nonatomic) BOOL IsNeedCallBack;//write后，是否需要回调！

@property (nonatomic,strong) GetPrinterStatus callbackPrinterStatus;
@property (nonatomic,strong) PrintFinsh callbackPrintFinsh;
@property (nonatomic,strong) PackNumberBlock callbackwhenSendProgressUpdate; //发送进度的回调
@property (nonatomic,strong) PackNumberBlock callbackwhenSendSuccess;  //发送成功的回调
@property (nonatomic,strong) PackNumberBlock callbackwhenSendFailure; //发送失败的回调
@property (nonatomic,strong) ConnectObjBlock callbackDisConnect; //连接断开的回调
@property (nonatomic,strong) ConnectObjBlock callbackConnected; //连接成功的回调



/*!
 发送数据到打印机
 Send data to the printer
 */
-(void) Write:(NSData *)data;


/*!
 发送数据到打印机，异步执行
 Send data to printer, execute asynchronously
 @param data 要发送的数据
 */
-(void) WriteAsync:(NSData *)data;
/*!
 从打印机读取数据(暂无用)
 Read data from the printer (useless)
 */
-(void) Read;

/*!
 连接打印机
 Connect the printer
 */
-(void) Open;
/*!
 断开连接
 Disconnect
 */
-(void) Close;
/*!
  用于获取从蓝牙广播得到的地址，wifi得到的是ip地址
  To get the address from the bluetooth broadcast, the wifi gets the IP address.
*/
-(NSString *) getShortAddress;

@end
