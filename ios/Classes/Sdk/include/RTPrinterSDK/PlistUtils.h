//
//  PlistUtils.h
//  SportStone
//
//  Created by  Andrew Huang on 15/1/9.
//  Copyright (c) 2015年  Andrew Huang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PlistUtils : NSObject


//读取plist文件,如果checkDocDir = YES表示优先从共享目录读取,
//否则从应用内部资源读取
+(NSMutableArray *)readPlistArray:(NSString *)plistName checkDocDir:(BOOL)checkDocDir;


+(BOOL)isBundleFileExist:(NSString * )fileName;
+(BOOL) isSandboxFileExists:(NSString*)fileName;
+(BOOL) deleteSandboxFile:(NSString*)fileName;
+ (NSString*)getSandboxFilePath:(NSString*)fileName;

+ (NSString *) writeToSandboxFile: (NSString*)fileName withData:(NSMutableArray *)data;
+ (NSMutableArray *) readFromSandboxFile: (NSString *)fileName;

+ (NSString *) writeToFile: (NSString*)fileName withData:(NSData *)data;
+(NSData *)readFromFile:(NSString *)fileName;


+ (NSMutableArray *) readPlistFile: (NSString *)fileName;

+(void)saveStringConfig:(NSString *)name value:(NSString*)value;
+(NSString* )loadStringConfig:(NSString *)name;
+(NSString* )loadStringConfig:(NSString *)name defaultValue:(NSString *)defaultValue;

+(void)saveBoolConfig:(NSString *)name value:(BOOL)value;
+(BOOL )loadBoolConfig:(NSString *)name;

+(void)saveIntConfig:(NSString *)name value:(NSInteger)value;
+(void)saveObjectConfig:(NSString *)name value:(NSObject *)value;
+(NSInteger )loadIntConfig:(NSString *)name;
+(NSInteger )loadIntConfig:(NSString *)name defaultValue:(NSInteger)defaultValue;
+(NSObject * )loadObjectConfig:(NSString *)name defaultValue:(NSObject *)defaultValue;


+(void)saveUserObjectConfig:(NSString *)name value:(NSObject *)value;
+(void)saveUserObjectArray:(NSString *)name array:(NSArray *)array;
+(NSObject * )loadUserObjectConfig:(NSString *)name;
+(NSMutableArray *)loadUserObjectArray:(NSString *)name ;

+(void)removeObjectConfig:(NSString *)name;
@end
