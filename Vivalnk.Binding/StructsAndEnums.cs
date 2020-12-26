using ObjCRuntime;

namespace Vivalnk.Binding
{
    [Native]
    public enum Cardiac_CommandType : long
    {
        startSampling,
        stopSampling,
        shutDownDevice,
        patchSelfTest,
        patchSetClock,
        eraseFlash,
        QureyFlash,
        setUserInfo,
        readUserInfo,
        eraseUserInfo,
        readSn,
        readPatchVersion,
        sendRF,
        enableOTA,
        checkPatchStatus,
        activeStatus,
        setCollectBPfrequency,
        readCollectBPfrequency
    }

    [Native]
    public enum Vital_CommandType : long
    {
        startSampling,
        stopSampling,
        shutDownDevice,
        patchSelfTest,
        patchSetClock,
        enableModeZero,
        enableModeOne,
        enableModeTwo,
        enableModeThree,
        uploadFlash,
        cancelUploadFlash,
        eraseFlash,
        QureyFlash,
        setUserInfo,
        readUserInfo,
        eraseUserInfo,
        readSn,
        readPatchVersion,
        sendRF,
        enableOTA,
        checkPatchStatus,
        flashReceivedFinish,
        sendACKofSdkRecieveRawData,
        heartBeatCommand,
        ackOfSdkRecieveRawData
    }

    [Native]
    public enum ScanDeviceType : long
    {
        FeverDevice = 200,
        VitalDevice = 310,
        CardiacDevice = 330,
        SpO2Device = 400
    }
}
