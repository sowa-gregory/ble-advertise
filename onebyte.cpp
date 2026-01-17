#include "MicroBit.h"

extern MicroBit uBit;

namespace bleraw
{
    /**
     * Advertise one custom byte using Eddystone UID beacon format (non-connectable).
     * - namespace[0] = your custom byte
     * - rest of namespace + instance = fixed/padded
     * Very small packet (~20-25 bytes on air), low power, widely supported by scanners.
     */
    void advertiseShim(uint8_t value)
    {
        // Stop any current advertising (very important!)
        uBit.bleManager.stopAdvertising();

        // Eddystone UID format: 10 byte namespace + 6 byte instance
        uint8_t namespace_id[10] = {value, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
        uint8_t instance_id[6]   = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC};  // arbitrary fixed pattern

        // -50 dBm tx power, non-connectable = true beacon mode
        uBit.bleManager.advertiseEddystoneUid(
            (const char*)namespace_id,
            (const char*)instance_id,
            -50,                // tx power calibration value
            true                // non-connectable (beacon style)
        );

        // Optional: make advertising faster / lower power (default is usually ok)
        // uBit.bleManager.setAdvertisingInterval(100);  // 100 ms
    }

   
}