//
//  VVSpO2CMDOperate.h
//  VivalnkSDK
//
//  Created by 徐伟 on 2020/5/28.
//  Copyright © 2020 cyan. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VVSpO2Measure : NSObject

/**
 * @brief get read device infomation
 * @param deviceId devise serial number
 */
+ (void)readDeviceInfo:(NSString *)deviceId;

/**
 * @brief Get real-time SpO2(Oxygen Saturation) data
 * @param deviceId devise serial number
 */
+ (void)readRealTimeSpO2:(NSString *)deviceId;

/**
 *
 * Get real-time waveform
 * @param deviceId devise serial number
*/
+ (void)readRealTimeWaveformSpO2:(NSString *)deviceId;


/**
 * Get the SpO2(Oxygen Saturation) data of the file
 * @return All SpO2 HistoryData
 */
+ (NSArray *)readHistorySpO2;

/**
 * @brief Set the frequency of auto obtaining real-time SpO2 data
 * @param timer frequency value,must be greater than 0,default 4S, unit: S
 * @discussion It needs to be set before connecting the blood oxygen equipment, and the setting will be the default value after connecting.
 */
+ (void)setGetRealtimeSpO2Timer:(NSInteger)timer;

/**
 * Start SpO2 firmware update (OTA)
 * @param deviceId  devise serial number
 * @param progressPlx progress Returns the progress of the update
 * @param statePlx titleMsg Return updated header information，stateMsg Returns updated status information
 * @discussion If the OTA process is interrupted (the APP is killed or artificially interrupted), after scanning the O2 Updater, call this method to restart the OTA (no connection is required). In other cases, the OTA needs to be connected.
 */
+ (void)startUpdateSpO2Firmware:(NSString *)deviceId withProgressState:(void(^)(float progress))progressPlx withOTAState:(void(^)(NSString *titleMsg,NSString *stateMsg))statePlx;

@end

NS_ASSUME_NONNULL_END
