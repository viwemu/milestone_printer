//
//  ObserverObj.h
//  RTPrinterSDK
//
//  Created by King on 18/12/2017.
//  Copyright © 2017 Rongta. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
  通知消息的对象
 The object of the notification message
 */
@interface ObserverObj : NSObject
@property (nonatomic,retain) id  Msgobj;
@property (nonatomic,retain) id  Msgvalue;
+ (ObserverObj *)Create:(id)MsgObj value:(id)Msgvalue;


@end
