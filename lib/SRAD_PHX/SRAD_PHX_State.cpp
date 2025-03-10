#include "SRAD_PHX.h"


void FLIGHT::calculateState() {
    switch(STATE) {
        case(STATES::PRE_NO_CAL):
            if(calibrate()) {
                STATE = STATES::PRE_CAL;
            }
            break;

        case(STATES::PRE_CAL):
            if(isAscent()) {
                STATE = STATES::FLIGHT_ASCENT;
            }
            break;

        case STATES::FLIGHT_ASCENT:
            if(isDescent()) {
                STATE = STATES::FLIGHT_DESCENT;
            }
            break;

        case STATES::FLIGHT_DESCENT:
            if(isLanded()) {
                STATE = STATES::POST_LANDED;
            }
            break;
    }
}

bool FLIGHT::isCal() {
    return calibrated;
}
bool FLIGHT::isAscent() {

}
bool FLIGHT::isDescent() {

}
bool FLIGHT::isLanded() {

}

bool FLIGHT::calibrate() {
    
}