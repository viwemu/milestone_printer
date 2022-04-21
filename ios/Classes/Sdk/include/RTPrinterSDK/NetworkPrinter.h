//
//  NetworkPrinter.h
//  PrinterExample
//
//  Created by king on 2019/10/21.
//  Copyright © 2019年 Printer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NetPrinterInfo;

/*!
 获取网络打印机的回调 Get a network printer
 @param netPrinterinfo 搜索到的打印机信息 Searched printer information
 */
typedef void(^NetPrinterBlock)(NetPrinterInfo *netPrinterinfo);


  @interface NetworkPrinter : NSObject
+(NetworkPrinter *)sharedInstance;
-(NSArray *)GetNetPrintList;
-(void)ClearNetPrintList;
-(void)GetNetWorkPrinter:(NetPrinterBlock)netprinterBlock;


  //@property (nonatomic, strong) SafeMutableArray * NetprintList;//打印机列表

  @property (nonatomic,strong) NetPrinterBlock callbackNetPrinter;

@end

/*网络打印机结构体*/
@interface NetPrinterInfo : NSObject
@property(nonatomic,copy) NSString* mac;
@property(nonatomic,copy) NSString* ip;
@property(nonatomic,copy) NSString* subMask;
@property(nonatomic,copy) NSString* gateWay;
@end








NS_ASSUME_NONNULL_END

