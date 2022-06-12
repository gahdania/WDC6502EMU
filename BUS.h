//
// Created by david.couples@couples.local on 10/12/21.
//

#ifndef WDC65C02_BUS_H
#define WDC65C02_BUS_H
#include <memory>
#include <cstdint>
#include <string>
#include <fstream>
#include <vector>
#include "CPU.h"
#include "ROM.h"
#include "VIA.h"
#include "ACIA.h"


class BUS {
public:
    BUS();
    ~BUS();

    CPU cpu;
    VIA pvia, svia;
    // ACIA acia;

    uint8_t ram[32 * 1024]{};

    void        cpuWrite(uint16_t address, uint8_t data);
    uint8_t     cpuRead(uint16_t, bool bReadOnly);

    void reset();
    void clock();

private:
    std::shared_ptr<ROM> rom;
};


#endif //WDC65C02_BUS_H
