//
//  WIFIFactory.h
//  RTPrinterSDK
//
//  Created by King on 28/11/2017.
//  Copyright © 2017 Rongta. All rights reserved.
//

#import "PIFactory.h"
#import "WifiInterface.h"

/*!
  创建WifiInterface接口的工厂类
 Factory class to create the WifiInterface interface
 */
@interface WIFIFactory : PIFactory
/*!创建WifiInterface接口
 Create WifiInterface interface
 */
+(WifiInterface *) Create;
@end
