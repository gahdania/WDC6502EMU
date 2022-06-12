//
// Created by david.couples@couples.local on 10/12/21.
//

#ifndef WDC65C02_ROM_H
#define WDC65C02_ROM_H
#include <cstdint>
#include <string>
#include <vector>
#include <fstream>


class ROM {

public:
    ROM(const std::string& sFileName, uint8_t romSize);
    ~ROM();

    uint8_t cpuRead(uint16_t address);
    void cpuWrite(uint16_t address, uint8_t data);

private:
    std::vector<uint8_t> romSpace;

};


#endif //WDC65C02_ROM_H
