//
//  CardiacCMDType.h
//  VivalnkSDK
//
//  Created by vivalnk on 2017/12/26.
//  Copyright © 2017年 vivalnk. All rights reserved.
//

#ifndef CardiacCMDType_h
#define CardiacCMDType_h

#define VivalnkDeprecated(instead) NS_DEPRECATED_IOS(1_0, 1_2_2, instead)


//v330命令类型
typedef NS_ENUM(NSInteger, Cardiac_CommandType) {
    cardiac_startSampling,                          ///0
    cardiac_stopSampling,                           ///1
    cardiac_shutDownDevice,                         ///2
    
    cardiac_patchSelfTest,                          ///3
    cardiac_patchSetClock,                          ///4
    
    cardiac_eraseFlash,                             ///5
    cardiac_QureyFlash,                             ///6
    
    cardiac_setUserInfo,                            ///7
    cardiac_readUserInfo,                           ///8
    cardiac_eraseUserInfo,                          ///9
    
    cardiac_readSn,                                 ///10
    
    cardiac_readPatchVersion,                       ///11
    cardiac_sendRF,                                 ///12
    cardiac_enableOTA,                              ///13
    cardiac_checkPatchStatus,                       ///14
    cardiac_activeStatus,
    cardiac_setCollectBPfrequency,
    cardiac_readCollectBPfrequency
};







#endif /* CardiacCMDType_h */
