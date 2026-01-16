//% color=#00AEEF weight=90 icon="\uf294"
namespace bleraw {

    // Shim declaration
    //% shim=bleraw::advertiseOneByteShim
    declare function advertiseOneByteShim(value: number): void;

    /**
     * Periodically advertise one byte as manufacturer data.
     * The byte is broadcast in a non-connectable BLE advertisement.
     */
    //% block="periodically advertise byte %value every %interval ms"
    export function periodicByte(value: number, interval: number): void {
        control.inBackground(function () {
            while (true) {
                advertiseOneByteShim(value);
                basic.pause(interval);
            }
        });
    }
}
