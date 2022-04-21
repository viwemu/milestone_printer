//
//  CmdFactory.h
//  RTPrinterSDK
//
//  Created by King 22/11/2017.
//  Copyright © 2017 Rongta. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Cmd.h"

/*!
 所有指令的工厂基类
 Factory base class for all instructions
 */
@interface CmdFactory : NSObject
  +(Cmd*) Create;
@end
