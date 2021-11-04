#include "PWMSample.h"

using namespace codal;

void PWMSample_main(codal::STM32DISCO_L475VG_IOT& discoL475VgIot)
{
    while (true) {
        for (int i = 0; i < 1024; i++) {
            discoL475VgIot.io.D2.setAnalogValue(i);
            discoL475VgIot.sleep(1);
        }

        for (int i = 0; i < 1024; i++) {
            discoL475VgIot.io.D2.setAnalogValue(1024 - i);
            discoL475VgIot.sleep(1);
        }
    }
}
