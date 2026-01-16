#include "pxt.h"
using namespace pxt;

namespace bleraw {

    // Advertise one byte as manufacturer data, non-connectable
    void advertiseOneByteShim(uint8_t value) {

        // BLE advertisement:
        // 02 01 06       → Flags
        // 03 FF 01 XX    → Manufacturer data (XX = value)
        uint8_t adv[] = {
            0x02, 0x01, 0x06,
            0x03, 0xFF, 0x01, value
        };

        uBit.bleManager.advertise(adv, sizeof(adv), false);
    }
}
