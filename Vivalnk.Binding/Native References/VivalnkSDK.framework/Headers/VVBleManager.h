//
//  VVBleManager.h
//  VivalnkSDK
//
//  Created by vivalnk on 2016/11/9.
//  Copyright © 2016年 vivalnk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "VVToolUseClass.h"

typedef NS_ENUM(NSInteger, ScanDeviceType){
    FeverDevice = 200,
    VitalDevice = 310,
    CardiacDevice = 330,
    SpO2Device = 400
};


@protocol vlBLEDelegates <NSObject>

@required
/*! @brief returns data content
 *
 * @param Data 返回的数据内容(key/value)
 *
 * @discussion This method returns the content of the data, including important data such as ecg, HR, RR, etc.
 */
- (void)onReceiveData:(id)Data;

@optional
/**
 * @brief Device power update callback interface
 * @param result battery data update
 * @discussion If it is connected to a body temperature device, the power information of the charging box is recalled; if it is connected to a healthy or electrocardiographic device, the power information of the device is recalled.
 */
- (void)onReceivedBatteryStatus:(id)result;

/**
 * @brief When calling the method sendCardiacCommand: or sendVitalCommand: when sending a command, the following three proxy methods will be called
 */
/**
 * start command
 * @param type Type of command sent
 * @discussion When the command is just sent, the current command content will be called back
 */
- (void)onStart:(id)type NS_DEPRECATED_IOS(1.0,1.2.2,"discard");

/**
 * @brief Command completion callback
 * @param result Command information
 * @discussion This method will be called back when the instruction is completed, including the information content corresponding to the instruction.
 */
- (void)onComplete:(id)result;

/**
 * @brief command error
 * @param error Command error message
 *
 * @discussion This method will be called back when an error occurs during the instruction sending process, including error information.
 */
- (void)onError:(id)error;


@end

@protocol BluetoothConnectListenerDelegate <NSObject>

@required
/**
 * @param device disconnect device information
 * @param isForce whether it is actively disconnected
 * @discussion This method will be called back when the device is disconnected.
 *  When isForce is Yes, it is the callback of actively disconnecting the device, and when NO, it is passively disconnecting (caused by being too far away, etc.)
 */
- (void)onDisconnected:(VVToolUseClass *)device isForce:(BOOL)isForce;
/**
 * @brief device connect success
 * @param device Information about successfully connected devices
 * @discussion When the device is successfully connected, it will callback through this proxy
 */
- (void)onConnected:(VVToolUseClass *)device;
/**
 设备连接失败回调
 connect falied
 @param code error code(错误码)
 @param msg  error message(详细错误内容)
 @discussion  This method will be called back if the connection fails
 */
- (void)connectOnError:(int)code msg:(NSString *)msg;

/**
 @brief Callback when the device automatically reconnects
 @param deviceId  device number
 @discussion If a device is automatically reconnecting, this method will call back the device number that is being automatically reconnected
 */
- (BOOL)onResume:(NSString *)deviceId;
@optional
/**
 开始连接BLE回调
 start connect
 */
- (void)connectOnStart VivalnkDeprecated("discard");

/**
 get Characteristics Service
 */
- (void)onServiceReady NS_DEPRECATED_IOS(1.0,1.2.2,"discard");

@end
//监听扫描回调
@protocol BluetoothScanListenerDelegate <NSObject>

@required
/**
 * Returns information scanned to the device
 * @param device Equipment Information Object
 */
- (void)onDeviceFound:(VVToolUseClass *)device;
@optional

/**
 * Callback when scanning out
 * @param code  error code  错误码
 * @param msg   error message 错误内容
 */
- (void)onScanError:(int)code :(NSString *)msg;

@end
@protocol BluetoothStateListenerDelegate <NSObject>

@optional
/**
 Bluetooth is on
 */
- (void)onBluetoothOpen;
/**
 Bluetooth is off
 */
- (void)onBluetoothClose;
/**
 Bluetooth status switching
 */
- (void)onBluetoothSwitchToOnStatus;

@end

@interface VVBleManager : NSObject <CBCentralManagerDelegate,CBPeripheralDelegate>

/**
 自动重连是否激活，YES为是，NO为否，默认为NO
 enable BLE reconnect , YES = enable, NO = disable
 */
@property(nonatomic,assign)BOOL bleReconnectEnabled;

/**
 * get BLE device connect status
 * Only suitable for connecting one device
 */
@property(nonatomic,assign,readonly)BOOL isConnected;


@property(nonatomic,assign)id<vlBLEDelegates>delegate;
@property(nonatomic,assign)id<BluetoothConnectListenerDelegate>connectDelegate;
@property(nonatomic,assign)id<BluetoothScanListenerDelegate>scanDelegate;
@property(nonatomic,assign)id<BluetoothStateListenerDelegate>bleStateDelegate;

/**
 * get Vivalnk(sdk) instance object
 */
+ (instancetype)shareInstance;

/**
 * 开始扫描BLE设备
 * start scan BLE device
*/
- (void)startScan:(VVToolUseClass *)options withDeviceType:(ScanDeviceType)deviceType;
/**
 * 停止扫描BLE设备
 * stop scan BLE device
*/
- (void)stopScan;

/**
 * 开始连接BLE设备
 * start connect with BLE device
 * @param options peripheral name
 */
- (void)connect:(VVToolUseClass *)options;

/**
 * 断开与BLE设备的连接，并且停止扫描
 * dissconnect with BLE device,stop scan if scanning
*/
- (void)disconnect:(ScanDeviceType)deviceType withDeviceID:(NSString *)deviceId;


/**
 * @brief send VV330-ECG command
 * if you used patch is VV330-ECG,use this function
 */
- (void)sendCardiacCommand:(CardiacCommand *)request;

/**
 * @brief send VV310-Wellness Monitor command
 * if you used patch is VV310-Wellness Monitor,use this function
 */
- (void)sendVitalCommand:(VitalCommand *)request;

/**
 * @brief APP重启后可以调用这个方法进行自动重连(不包含体温设备)
 * @param connectTime 设置连接时长,超过时长没有连接成功,则退出自动重连逻辑,单位:S
 */
- (void)startAutomaticReconnectAfterAppLaunch:(NSInteger)connectTime withComplex:(void(^)(BOOL success,NSString *msg))complex;

/**
 * @discussion Get all connected device IDs
 */
- (NSArray *)getAllConnectedDeviceID;
/**
 * get bluetooth status
 */
- (int)checkBle;

/**
 * @brief 获取SDK版本
 * get SDK Version
 */
- (NSString *)getVersion;

/**
 * show sdk running log
 * @param show   BOOL value, YES to print log; NO not to print log. Default is NO.
 */
- (void)printLog:(BOOL)show;

/**
 * 连接vital的设备可以调用这个方法一次性完成数据采集及上传命令
 * The device connected to VV310-wellness monitor  can call this method to complete data acquisition and upload commands at one time.
 */
- (void)enableAutoDataSampling;

/**
 when no data return,You can call this method
 */
- (BOOL)callbackACKCommand:(NSString *)deviceName;


@end
