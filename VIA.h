//
// Created by david.couples@couples.local on 10/12/21.
//

#ifndef WDC65C02_VIA_H
#define WDC65C02_VIA_H
#include <cstdint>
#include <string>
#include <memory>

class BUS;

class VIA {
public:
    VIA();
    ~VIA();

    void writeToBus(uint16_t address, uint8_t data);
    uint8_t readFromBus(uint16_t address);

    void ConnectBus(BUS *n) { bus = n; }

    enum REG6522 {
        ORB_W   = 0x00,     // output register Port B
        IRB_R   = 0x00,     // input register PORT B
        ORA_W   = 0x01,     // output register Port A
        IRA_R   = 0x01,     // input register Port A
        DDRB    = 0x02,     // Data dir register for Port B
        DDRA    = 0x03,     // Data dir register for port A
        T1CL_W  = 0x04,     // T1 Low Order Latches (when writing)
        T1CL_R  = 0x04,     // T1 Low order counter (when reading)
        T1CH    = 0x05,     // T1 High order counter
        T1LL    = 0x06,     // T1 low order latches
        T1LH    = 0x07,     // t1 high order latches
        T2CL_W  = 0x08,     // T2 low order latches (when writing)
        T2CL_R  = 0x08,     // T2 low order counter (when reading);
        T2CH    = 0x09,     // T2 high order counter
        ShiftR  = 0x0A,     // shift register
        ACR     = 0x0B,     // aux control register
        PCR     = 0x0C,     // peripheral control register
        IFR     = 0x0D,     // interrupt flag register
        IER     = 0x0E,     // interrupt enable register
        ORAN_W  = 0x0F,
        IRAN_R  = 0x0F,
    };

    enum INT6522 {
        CA2   = ( 1 << 0 ),
        CA1   = ( 1 << 1 ),
        SR    = ( 1 << 2 ),
        CB2   = ( 1 << 3 ),
        CB1   = ( 1 << 4 ),
        T1    = ( 1 << 5 ),
        T2    = ( 1 << 6 ),
        SET   = ( 1 << 7 ),
        IRQ   = ( 1 << 7)
    };

private:

    void SetEnableFlag(INT6522 i, bool v);
    uint8_t GetEnableFlag(INT6522 i);
    uint8_t GetInterrupt(INT6522 i);
    void SetInterrupt(INT6522 i);
    void SetAuxControl(uint8_t);
    uint8_t GetAuxControl(uint8_t);

    struct PORT {
        std::string name;
        uint8_t ddr = 0x00;
        uint8_t data = 0x00;
    } portA, portB;

    BUS *bus = nullptr;



    uint8_t t1clLatches  = 0x00;
    uint8_t t1clCounter  = 0x00;
    uint8_t t1chCounter  = 0x00;
    uint8_t t1llLatches  = 0x00;
    uint8_t t1lhLatches  = 0x00;
    uint8_t t2clLatches  = 0x00;
    uint8_t t2clCounter  = 0x00;
    uint8_t t2chCounter  = 0x00;
    uint8_t shiftReg     = 0x00;
    uint8_t auxControl   = 0x00;
    uint8_t periControl  = 0x00;
    uint8_t intFlagReg   = 0x00;
    uint8_t intEnReg     = 0x00;

};


#endif //WDC65C02_VIA_H
