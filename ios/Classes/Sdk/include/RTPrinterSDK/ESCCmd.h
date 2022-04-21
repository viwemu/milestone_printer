//
//  ESCCmd.h
//  RTPrinterSDK
//
//  Created by King 22/11/2017.
//  Copyright © 2017 Rongta. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Cmd.h"
#import "EnumTypeDef.h"

@interface ESCCmd :Cmd
//设置打印区域宽度n:点数  1mm=8点 Set the print area width n: points 1mm = 8 points
- (NSData *) GetSetAreaWidthCmd:(NSUInteger)n;
//设定左侧留白量 n:点数 1mm = 8点 Set the amount of white space on the left side n: number of points, 1mm = 8 points
- (NSData *) GetSetLeftStartSpacingCmd:(NSUInteger)n;

@end
