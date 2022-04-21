//
//  BlutToothPrinterInterface.h
//  RTPrinterSDK
//
//  Created by King 22/11/2017.
//  Copyright © 2017 Rongta. All rights reserve
//

#import "PrinterInterface.h"
#import "EnumTypeDef.h"
#import "RTDeviceinfo.h"
@class RTDeviceinfo;

/*!
 蓝牙连接的接口
 Bluetooth connection interface
 */
@interface RTBlueToothPI : PrinterInterface
/*!
 蓝牙传输最大尺寸
 Bluetooth transmission maximum size
 */
@property (nonatomic) NSInteger MTULength;
/*!
 分包发间隔秒数（单位:毫秒）
 Send data interval seconds (unit: milliseconds)
 */
@property (nonatomic)  NSInteger SendDelayMS;

/*!蓝牙连接类型  
   Bluetooth connection type
 */
@property (nonatomic) BlueToothKind BleKind;

/*!
 开始扫描蓝牙设备
 Start scanning Bluetooth devices
 @param scanSeconds 要扫描几秒(暂时无用,改为自行调用stopScan来停止扫描)
    To scan a few seconds (temporarily useless, call stopScan instead to stop scanning)
 @param isclear 是否清除原有的蓝牙列表 YES:清除 NO:不清除
    Whether to clear the original Bluetooth list YES: Clear NO: Do not clear
 @return 是否成功启用扫描 Whether to enable scanning successfully
 */
-(BOOL)startScan:(NSInteger)scanSeconds isclear:(BOOL)isclear;

/*!
 停止扫描 Stop scanning
 */
-(void) stopScan;

/*!
 获取蓝牙列表 Get Bluetooth list
 @return 蓝牙列表的数组 An array of Bluetooth lists
 */
-(NSArray *) getBleDevicelist;



/*!
 不用扫描，通过uuid直接连接蓝牙 
 Do not scan, connect directly to the Bluetooth through uuid


 @param uuid 蓝牙的地址 Bluetooth address
 @return 是否启动连接。  Whether to start the connection
        连接成功是通过发送消息:PrinterConnectedNotification来得知
        Connection is successful by sending the message: PrinterConnectedNotification
 */
-(BOOL)connectNoSCanByUUID:(NSString  *) uuid;//




@end
