//
// Created by david.couples@couples.local on 10/12/21.
//

#include "BUS.h"

BUS::BUS() {
    for (auto &item : ram) item = 0x00;

    cpu.ConnectBus(this);
    pvia.ConnectBus(this);
    svia.ConnectBus(this);
};

BUS::~BUS() = default;


uint8_t BUS::cpuRead(uint16_t address, bool bReadOnly) {

    if ( address >= 0x0000 && address <= 0x7EFF)
        return ram[address];
    else if (address >= 0x7FC0 && address <= 0x7FDF)
        return pvia.readData(address);
        // send to pVia;
//    else if ( address >= 0x7FE0 && address <= 0x7FFF)
//        return svia.readData(address);
    else
        return rom->cpuRead(address);


}

void BUS::cpuWrite(uint16_t address, uint8_t data) {
    if ( address >= 0x0000 && address <= 0x7EFF)
        ram[address] = data;
    else if (address >= 0x7FC0 && address <= 0x7FDF)
        pvia.writeData(address, data);

}

void BUS::reset() {
    cpu.reset();
}

void BUS::clock() {
    cpu.clock();
}