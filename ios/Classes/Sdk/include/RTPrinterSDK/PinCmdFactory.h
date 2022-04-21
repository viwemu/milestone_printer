//
//  PinCmdFactory.h
//  RTPrinterSDK
//
//  Created by King 28/11/2017.
//  Copyright © 2017 Rongta. All rights reserved.
//

#import "CmdFactory.h"
#import "PinCmd.h"

/*!
 创建针打PinCmd类的工厂
 @return PinCmd
 */
@interface PinCmdFactory : CmdFactory

+(PinCmd*)Create;
@end
