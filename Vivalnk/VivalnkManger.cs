using Foundation;
using Vivalnk.Binding;

namespace Vivalnk
{
    public class VivalnkManger
    {
        public static VVBleManager vvbleManager = new VVBleManager();

        public static void Init()
        {
            vvbleManager.BleReconnectEnabled = true;
            vvbleManager.PrintLog(true);

            vvbleManager.Init();
        }

        public static string StartScan(ScanDeviceType deviceType)
        {
            int statusCode = vvbleManager.CheckBle;

            vvbleManager.StartScan(new VVToolUseClass()
            {
                ScanTimeout = 1000 * 60
            }, deviceType);

            return string.Empty;
        }

        public static void StopScan()
        {
            vvbleManager.StopScan();
        }

        public static void Disconnect(ScanDeviceType deviceType, string deviceId)
        {
            vvbleManager.Disconnect(deviceType, deviceId);
        }

        public static void SendCardiacCommand(string deviceId, Cardiac_CommandType commandType)
        {
            vvbleManager.SendCardiacCommand(new CardiacCommand() { DeviceId = deviceId, TimeOut = 5000, CardiacType = commandType });
        }

        public static void SendVitalCommand(string deviceId, Vital_CommandType commandType)
        {
            vvbleManager.SendVitalCommand(new VitalCommand() { DeviceId = deviceId, TimeOut = 5000, VitalType = commandType });
        }

        public class BluetoothScanListener : BluetoothScanListenerDelegate
        {
            public override void OnDeviceFound(VVToolUseClass device)
            {
                StopScan();
            }
        }

        public class BluetoothConnectListener : BluetoothConnectListenerDelegate
        {
            public override void ConnectOnError(int code, string msg)
            {
                throw new System.Exception(msg);
            }

            public override void OnConnected(VVToolUseClass device)
            {
                throw new System.Exception("device connected");
            }

            public override void OnDisconnected(VVToolUseClass device, bool isForce)
            {
                throw new System.Exception("device disconnected");
            }

            public override bool OnResume(string deviceId)
            {
                return false;
            }
        }

        public class BluetoothStateListener : BluetoothStateListenerDelegate
        {
            public override void OnBluetoothClose()
            {
            }

            public override void OnBluetoothOpen()
            {
            }

            public override void OnBluetoothSwitchToOnStatus()
            {
            }
        }

        public class ReceiveDataListener : vlBLEDelegates
        {
            public override void OnReceiveData(NSObject Data)
            {
                if (Data != null)
                {
                    // get data
                }
                return;
            }
        }
    }
}