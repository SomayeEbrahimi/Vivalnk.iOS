//
//  VitalType.h
//  VivalnkSDK
//
//  Created by 徐伟 on 2018/11/21.
//  Copyright © 2018 cyan. All rights reserved.
//

#ifndef VitalType_h
#define VitalType_h

typedef NS_ENUM(NSInteger, Vital_CommandType) {
    vital_startSampling,                          ///0
    vital_stopSampling,                           ///1
    vital_shutDownDevice,                         ///2
    
    vital_patchSelfTest,                          ///3
    vital_patchSetClock,                          ///4
    
    vital_enableModeZero,                         ///5
    vital_enableModeOne,                          ///6
    vital_enableModeTwo,                          ///7
    vital_enableModeThree,                        ///8
    
    vital_uploadFlash,                            ///9
    vital_cancelUploadFlash,                      ///10
    vital_eraseFlash,                             ///11
    vital_QureyFlash,                             ///12
    
    vital_setUserInfo,                            ///13
    vital_readUserInfo,                           ///14
    vital_eraseUserInfo,                          ///15
    
    vital_readSn,                                 ///16
    
    vital_readPatchVersion,                       ///17
    vital_sendRF,                                 ///18
    vital_enableOTA,                              ///19
    vital_checkPatchStatus,                       ///20
    
    vital_flashReceivedFinish,                     ///21
    vital_sendACKofSdkRecieveRawData,              ///22
    vital_heartBeatCommand,                        ///23
    vital_ackOfSdkRecieveRawData                   ///24
};
#endif /* VitalType_h */
