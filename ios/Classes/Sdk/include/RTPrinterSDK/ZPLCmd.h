//
//  ZPLCmd.h
//  RTPrinterSDK
//
//  Created by King on 22/02/2018.
//  Copyright © 2018 Rongta. All rights reserved.
//

#import "Cmd.h"

@interface ZPLCmd : Cmd

/*!
 是否启用usb接口
 Enable / disable usb function
 @param isEnable yes:启用（Enable）  no:禁用（disable）
*/
-(NSData *)GetSetUsbEnableCmd:(BOOL) isEnable;
/*
 * Draw Box
 * 画矩形
 *
 * @param x     box's x axis x轴
 * @param y     box's axis width y轴
 * @param width     box's width 矩形宽度
 * @param height    box's height 矩形高度
 * @param lineWidth line's width 线粗
 */
-(NSData *)GetDrawBoxCmd:(int)x y:(int)y width:(int)width height:(int)height lineWidth:(int)lineWidth;
-(NSData *)GetCancelPrintCmd;

@end
