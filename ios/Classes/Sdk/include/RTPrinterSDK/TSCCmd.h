//
//  TSCCmd.h
//  RTPrinterSDK
//
//  Created by King on 18/12/2017.
//  Copyright © 2017 Rongta. All rights reserved.
//

#import "Cmd.h"

@interface TSCCmd : Cmd
/*!
 画线或长条物
 Draw a line or strip
 @param coord 线条坐标 unit:(dot)
             Line coordinates
 */
-(NSData *)GetBARcmd:(Coordinate)coord;
/*!
 for 806 MINI
 将指定的区域反相打印
 Reverse printing the specified area
 */
-(NSData *)GetReverseCmd:(Coordinate)coord;


@end
