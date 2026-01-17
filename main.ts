//% color=#00AEEF weight=90 icon="\uf294"
namespace qwer {

    // Shim
   
    let currentValue = 0
    let started = false
 
    /**
     * Start continuous advertising of a byte.
     * Calling this again changes the advertised byte.
     */
    //% block="advertise byte %value"
    export function advertiseByte(value: number): void {
        currentValue = value

        if (!started) {
            started = true
            control.inBackground(function () {
                while (true) {
                    //advShim(currentValue)
                    qwer.advShim()
                    basic.pause(1000) // fixed 1s period
                }
            })
        }
    }

      //% shim=qwer::advShimq
    
    export function advShim():void {
        return;
    }
}
