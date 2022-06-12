//
// Created by david.couples@couples.local on 10/12/21.
//

#include "VIA.h"
VIA::VIA(){
    portB.name = "Port B";
    portA.name = "Port A";

}
VIA::~VIA() = default;

void VIA::writeToBus(uint16_t address, uint8_t data) {
    switch (address & 0x00FF){
        case (ORA_W):
            portA.data = data;
            break;
        case (ORB_W):
            portB.data = data;
            break;
        case (DDRA):
            portA.ddr = data;
            break;
        case(DDRB):
            portB.ddr = data;
            break;
            case ()

    }
}


void VIA::SetEnableFlag(INT6522 i, bool v) {

    if (v)
        intEnReg |= i;
    else
        intEnReg &= ~i;
}

uint8_t VIA::GetEnableFlag(INT6522 i) {
    return (( intEnReg & i) > 0) ? 1 : 0;
}

void VIA::