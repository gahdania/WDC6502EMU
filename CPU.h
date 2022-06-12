//
// Created by david.couples@couples.local on 10/12/21.
//

#ifndef WDC65C02_CPU_H
#define WDC65C02_CPU_H
#pragma once
#include <vector>
#include <string>
#include <map>

class BUS;

class CPU {

public:
    CPU();
    ~CPU();

    uint8_t a       = 0x00;     // A register
    uint8_t x       = 0x00;     // X register
    uint8_t y       = 0x00;     // Y register
    uint8_t stack   = 0xEF;     // stack pointer
    uint16_t pc     = 0x0000;   // program counter
    uint8_t status  = 0x00;     // program counter
    bool ready      = true;           // emulates the ready pin on the processor
    bool phi2       = false;           // emulates the cpu is receiving a clock signal

    void reset();
    void irq();
    void nmi();
    void clock();

    void ConnectBus(BUS *n) { bus = n; }

    std::map<uint16_t, std::string> disassemble(uint16_t nStart, uint16_t nStop);

    enum CPUFLAGS {
        C = ( 1 << 0 ),     // Carry Flag
        Z = ( 1 << 1 ),     // Zero flag
        I = ( 1 << 2 ),     // Disable IRQs
        D = ( 1 << 3 ),     // BCD mode
        B = ( 1 << 4 ),     // Break flag
        U = ( 1 << 5 ),     // Unused
        V = ( 1 << 6 ),     // overflow flag
        N = ( 1 << 7 ),     // negative flag
    };

private:
    uint8_t GetFlag(CPUFLAGS f) const;
    void    SetFlag(CPUFLAGS f, bool v);

    uint8_t     fetched = 0x00;         // working input for ALU
    uint16_t    temp = 0x0000;          // convenience variable
    uint16_t    address_abs = 0x0000;   // final result for memory addresses
    uint16_t    address_rel = 0x0000;   // temp storage for the jump related instructions
    uint8_t     opcode = 0x00;          // instruction byte
    uint8_t     cycles = 0x00;          // remaining cycles for the instruction



    BUS         *bus = nullptr;
    void        write(uint16_t address, uint8_t data);
    uint8_t     read(uint16_t address);

    uint8_t     fetch();
    bool        complete();

    struct INSTRUCTION {
        std::string     name;
        uint8_t         (CPU::*operate    )() = nullptr;
        uint8_t         (CPU::*addressMode)() = nullptr;
        uint8_t         cycles = 0;
        uint8_t         offset = 0;
    };

    std::vector<INSTRUCTION> instructionSet;

    // Addressing Modes data sheet designations in the comments
    //  mode               indicator            mode               indicator
    uint8_t ABS();      /*    a     */      uint8_t AIX();      /*   (a, x) */
    uint8_t ABX();      /*   a, x   */      uint8_t ABY();      /*    a, y  */
    uint8_t IND();      /*   (a)    */      uint8_t ACC();      /*     A    */
    uint8_t IMM();      /*    #     */      uint8_t IMP();      /*     !    */
    uint8_t REL();      /*    r     */      uint8_t STK();      /*     s    */
    uint8_t ZP0();      /*    zp    */      uint8_t IZX();      /*  (zp, x) */
    uint8_t ZPX();      /*  zp, x   */      uint8_t ZPY();      /*   zp, y  */
    uint8_t IZP();      /*   (zp)   */      uint8_t IZY();      /*  (zp), y */

    // Mnemonics for opcodes
    uint8_t ADC();      uint8_t AND();      uint8_t ASL();      uint8_t BBR();
    uint8_t BBS();      uint8_t BCC();      uint8_t BCS();      uint8_t BEQ();
    uint8_t BIT();      uint8_t BMI();      uint8_t BNE();      uint8_t BPL();
    uint8_t BRA();      uint8_t BRK();      uint8_t BVC();      uint8_t BVS();
    uint8_t CLC();      uint8_t CLD();      uint8_t CLI();      uint8_t CLV();
    uint8_t CMP();      uint8_t CPX();      uint8_t CPY();      uint8_t DEC();
    uint8_t DEX();      uint8_t DEY();      uint8_t EOR();      uint8_t INC();
    uint8_t INX();      uint8_t INY();      uint8_t JMP();      uint8_t JSR();
    uint8_t LDA();      uint8_t LDX();      uint8_t LDY();      uint8_t LSR();
    uint8_t NOP();      uint8_t ORA();      uint8_t PHA();      uint8_t PHP();
    uint8_t PHX();      uint8_t PHY();      uint8_t PLA();      uint8_t PLP();
    uint8_t PLX();      uint8_t PLY();      uint8_t RMB();      uint8_t ROL();
    uint8_t ROR();      uint8_t RTI();      uint8_t RTS();      uint8_t SBC();
    uint8_t SEC();      uint8_t SED();      uint8_t SEI();      uint8_t SMB();
    uint8_t STA();      uint8_t STP();      uint8_t STX();      uint8_t STY();
    uint8_t STZ();      uint8_t TAX();      uint8_t TAY();      uint8_t TRB();
    uint8_t TSB();      uint8_t TSX();      uint8_t TXA();      uint8_t TXS();
    uint8_t TYA();      uint8_t WAI();
};


#endif //WDC65C02_CPU_H
