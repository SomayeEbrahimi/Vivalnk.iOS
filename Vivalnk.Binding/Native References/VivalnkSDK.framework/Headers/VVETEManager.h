//
//  ETEManager.h
//  VivalnkSDK
//
//  Created by vivalnk on 2018/1/18.
//  Copyright © 2018年 vivalnk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VVETEParameter.h"


typedef enum Type : NSUInteger {
    kETEFlash = 0,
    kETERealTime = 1,
    kETEMain = 2,
    kETERecalc = 3
} ETEType;

@protocol eteAnalysisDelegates <NSObject>

@optional

- (void)onETEResultUpdated:(id)result;

@end

@interface VVETEManager : NSObject

@property (nonatomic) NSDate *startTime;
@property(nonatomic,assign)id<eteAnalysisDelegates>delegate;
//初始化hr算法实例
- (void)initHRInstance;

- (VVETEManager *)initWithType:(ETEType) type;

- (NSString *)getETEVersion;

/*return:
 * -1: Invalid input
 * 0: Can't estimate maxHr or maxMET
 * 1: Success
 */
- (int)setETEParameters:(VVETEParameter *) parameter;

/**
 *
 * @param modeOneData data
 */
- (void)analyzerData:(id)modeOneData;

- (void) saveInstance;

@end
