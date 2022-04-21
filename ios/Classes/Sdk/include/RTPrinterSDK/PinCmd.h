//
//  PinCmd.h
//  RTPrinterSDK
//
//  Created by King 22/11/2017.
//  Copyright © 2017 Rongta. All rights reserved.
//


#import "Cmd.h"
#import "EnumTypeDef.h"


/*!
 针打的命令类
 pincmd command class
 */
@interface PinCmd : Cmd

/*!
  绝对定点位置定位
  以当前左边限为基准，右移打印头n／60 英寸。若该距离超越右边限，此
  设定无效。最大设置距离为 10.6 英寸。
 
 Absolute fixed position positioning
 With the current left margin as a reference, move the printhead n / 60 inches to the right. 
 If the distance is beyond the right limit,
 this Setting is invalid. The maximum setting distance is 10.6 inches.
 
 @param n ≤636
 @return NSData
 */
-(NSData *)GetAbsolutePrintPositionCmd:(NSInteger)n;
/*!
 设定页长度为 n 行／英寸。打印机根据当前的行距设定，将行数演算为英寸储存。随后的新行距
 设定亦不会改变此页长值。当前的行位置
 以后将作为页首位置，而底栏空则被撤消
 
 Set the page length to n lines / inch. Printer based on the current line spacing settings, 
  the number of lines calculated as inches. Followed by the new line spacing
   Settings will not change the page long value. The current line location
   The future will be the top position, while the bottom bar is empty
 
 @param ipageunit 页长单位 Page long unit，PageUnit_Row:单位为行(Row) PageUnit_inch：单位为英寸(inch)
 @param ipageLen Row1≤ipageLen≤127
 @return 页长指令
 */
-(NSData *)GetPageLengthCmd:(PageUnit)ipageunit ipageLen:(NSInteger)ipageLen;

-(NSData *)GetPageLengthCmd:(PageLengthType)pageLengthtype;



/*!
  双重打印 Double printing
  首先正常地完成一行的打印，接着稍下移再打印，以产生加重的效果
 First of all, the normal completion of a line of printing,
 then slightly lower and then print, in order to produce aggravate effect
 
 @param isDoublePrint 是否双重打印 Whether double printing
 */
-(NSData *)GetIsDualPrintCmd:(SettingMode)isDoublePrint;//是否双重打印

/*!
 实现单次 n/180 跳行
 Single n / 180 skip
 
 @param jumpMode 跳行模式  Jump mode
 @param n   跳行单位 n/180
 @return NSData
 */
-(NSData *)GetJumpingRow180thCmd:(JumpMode)jumpMode n:(NSInteger)n;
/*!
 获取行距的命令 
 Get line spacing command
 @param spacingmode 行距模式 Row spacing mode
 @param n 0≤n≤255
 @return NSData
 */
-(NSData *)GetRowSpaceingCmd:(RowSpacingMode)spacingmode n:(NSInteger)n;

/*!
 设定打印方向 若设定 EDS 开关图象方向 项为双向，此命令设定无效。
 Set the printing direction
 @param printdirectionmode 打印方向
 @return NSData
 */
-(NSData *)GetPrintDirectionCmd:(PrintDirectionMode)printdirectionmode;

/*!
 设置字体风格
 Set font style
 @param FontStyle836 字体风格 font style
 @return <#return value description#>
 */
-(NSData *)GetFontStyle836sCmd:(FontStyle836)FontStyle836;// 设定修饰字体

/*!
 打印结束，退纸
 End of printing, rewinding
 @return NSData
 */
-(NSData *)GetPrintEndCmd;
@end
