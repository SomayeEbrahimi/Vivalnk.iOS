//
//  VVToolUseClass.h
//  VitalSDK
//
//  Created by kevin on 2018/5/29.
//  Copyright © 2018年 com.vivalnk.iOS.cyan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CardiacCMDType.h"
#import "VitalType.h"

@interface VVToolUseClass : NSObject
//设备
@property (nonatomic,assign) int rssi;
@property (nonatomic,copy) NSString *name;
@property (nonatomic,copy) NSString *fwVersion;
@property (nonatomic,copy,readwrite) NSString *password;
@property (nonatomic,assign,readwrite)BOOL isEnc;
//扫描超时时间
@property (nonatomic,assign)NSInteger scanTimeout;

//连接
@property (nonatomic,assign)NSInteger connectRetry;
@property (nonatomic,assign)NSInteger connectTimeout;

@end

@interface CardiacCommand : NSObject
//Cardiac Scout patch use
@property(nonatomic,copy)NSString *deviceId;
@property(nonatomic,assign)NSInteger timeOut;
@property(nonatomic,assign)Cardiac_CommandType cardiacType;
@property(nonatomic,copy)NSString *info;
@end

@interface VitalCommand : NSObject
//Vital Scout patch use
@property(nonatomic,copy)NSString *deviceId;
@property(nonatomic,assign)NSInteger timeOut;
@property(nonatomic,assign)Vital_CommandType vitalType;
@property(nonatomic,copy)NSString *info;
@end


