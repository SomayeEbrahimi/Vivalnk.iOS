//
//  VVConfigManager.h
//  VivalnkSDK
//
//  Created by 徐伟 on 2019/12/17.
//  Copyright © 2019 cyan. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VVConfigManager : NSObject

/**
 * Perform baseline drift processing on the returned ECG so that the waveform is on a horizontal line
 * @param ecgArray ecg array data
 * @param deviceId Device number to be processed
 * @return Return processed data
 * @discussion Since the generated ecg data is a continuous data, there will be a drift phenomenon at the beginning due to the influence of the human electrode. This method is to pull the waveform down on the same horizontal line when drawing, so that the waveform will look better
 */
+ (NSArray *)getBaseLineDataToDraw:(NSArray *)ecgArray withDeviceId:(NSString *)deviceId;


/**
 * Set the data to send to the cloud switch
 * @param enable YES is to send data to the server, NO is not sent, the default is not to send
 */
+ (void)setDataToCloudEnable:(BOOL)enable;


/**
 * Set whether to enable background positioning
 * @param enable Yes means open, NO means close, default YES
 */
+ (void)setBackgroundLocation:(BOOL)enable;


/**
 * Set the frequency of scanning body temperature data, unit: S
 * @param timer Scanning time value, range 0.1~1, default value is 0.5 unit: S
 * @discussion The smaller the set value, the higher the acceptance rate in the background, otherwise, the lower the acceptance rate in the background. If you are not allowed to be in the background, you do not need to call this interface.
 */
+ (void)setScanTemperatureTimer:(float)timer;


/**
 * Set whether to agree with location information acquisition
 * @param enable YES means agree,NO means disagree,default YES
 * @discussion If positioning is not set or allowed, then this interface is invalid. Only when the positioning is agreed, then this interface is meaningful.
 */
+ (void)setIsAgreeGetLocationInfo:(BOOL)enable;




@end

NS_ASSUME_NONNULL_END
