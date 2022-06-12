//
// Created by david.couples@couples.local on 10/12/21.
//

#include "ROM.h"


ROM::ROM(const std::string &sFileName, const uint8_t romSize) {

    romSpace.resize(romSize);
    for (auto &i : romSpace) i = 0x00;
    std::ifstream ifs;
    ifs.open(sFileName, std::ios::binary);

    if (ifs.is_open()) {
        while (!ifs.eof())
            ifs.read((char *) romSpace.data(), 1);
    }
}

ROM::~ROM() = default;

void ROM::cpuWrite(uint16_t address, uint8_t data) {
    romSpace.at(address) = data;
}

uint8_t ROM::cpuRead(uint16_t address) {
    return romSpace.at(address)
}



