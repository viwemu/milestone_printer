//
//  BitmapSetting.h
//  RTPrinterSDK
//
//  Created by King on 04/12/2017.
//  Copyright © 2017 Rongta. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EnumTypeDef.h"

/*!
 图片设置
 Bitmap settings
 */
@interface BitmapSetting : NSObject<NSCopying>

/*!
 限制图片的最大宽度
 Limit the maximum width of the image
 */
@property (nonatomic) NSInteger limitWidth;
/*!
 图片的对齐方式（热敏才有效）
 */
@property (nonatomic) Alignment  Alignmode;//行对齐方式

/*!
  图片打左上角x坐标 for TSC, Cpcl
  When printing a picture, the x coordinate of the upper left corner (for TSC, Cpcl)
 */
@property (nonatomic) NSInteger pos_X;
/*!
 图片打印左上角y坐标 for TSC, Cpcl
 When printing a picture, the y coordinate of the upper left corner (for TSC, Cpcl)
*/

@property (nonatomic) NSInteger pos_Y;


/*!
   BitmapSetting object copy
 */
-(void)AssignValue:(BitmapSetting *) setting;

@end
