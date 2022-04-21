//
//  CPCLCmd.h
//  RTPrinterSDK
//
//  Created by King on 18/12/2017.
//  Copyright © 2017 Rongta. All rights reserved.
//

#import "Cmd.h"

@interface CPCLCmd : Cmd
/*!
 * GetDrawLineCmd 画线
 * @param x0 左上角的 X 坐标。
 * @param y0 左上角的 Y 坐标。
 * @param x1 以下项的 X 坐标：
 *           - 水平轴的右上角。
 *           - 垂直轴的左下角
 * @param y1 以下项的 Y 坐标：
 - 水平轴的右上角。
 - 垂直轴的左下角。
 * @param lineWidth 线条的单位宽度。
 */
-(NSData *)GetDrawLineCmd:(int)lineWidth x0:(int)x0 y0:(int)y0 x1:(int)x1 y1:(int)y1 isFullLine:(BOOL)isFullLine;

/*!生成矩形框
 * 用户可以使用 BOX 命令生成具有指定线条宽度的矩形
 * @param x0 左上角的 X 坐标。
 * @param y0 左上角的 Y 坐标。
 * @param x1 右下角的 X 坐标。
 * @param y1 右下角的 Y 坐标。
 * @param width 形成矩形框的线条的单位宽度。
 */
- (NSData *) GetDrawBoxCmd:(int)x0 y0:(int)y0 x1:(int)x1 y1:(int)y1 width:(int)width;
/*!
 * 画线
 * @param x0 左上角的 X 坐标。
 * @param y0 左上角的 Y 坐标。
 * @param x1 以下项的 X 坐标：
 *           - 水平轴的右上角。
 *           - 垂直轴的左下角
 * @param y1 以下项的 Y 坐标：
 - 水平轴的右上角。
 - 垂直轴的左下角。
 * @param width 线条的单位宽度。
 */
-(NSData *) GetLineCmd:(int)x0 y0:(int)y0 x1:(int)x1 y1:(int)y1 width:(int)width;

@end
