//
// Created by david.couples@couples.local on 10/12/21.
//

#include "CPU.h"
#include "BUS.h"

CPU::CPU(){
    using a = CPU;
    instructionSet = {
        { "BRK", &a::BRK, &a::IMM, 7, 0},{ "ORA", &a::ORA, &a::IZX, 6, 0},{ "???", &a::NOP, &a::IMP, 2, 0},{ "???", &a::NOP, &a::IMP, 1, 0},{ "TSB", &a::TSB, &a::ZP0, 3, 0},{ "ORA", &a::ORA, &a::ZP0, 3, 0},{ "ASL", &a::ASL, &a::ZP0, 5, 0},{ "RMB0", &a::RMB, &a::ZP0, 5, 0},{ "PHP", &a::PHP, &a::IMP, 3, 0},{ "ORA", &a::ORA, &a::IMM, 2, 0},{ "ASL", &a::ASL, &a::ACC, 2, 0},{ "TSB", &a::TSB, &a::ABS, 1, 0},{ "???", &a::NOP, &a::IMP, 4, 0},{ "ORA", &a::ORA, &a::ABS, 4, 0},{ "ASL", &a::ASL, &a::ABS, 6, 0},{ "???", &a::NOP, &a::IMP, 6, 0},
        { "BPL", &a::BPL, &a::REL, 2, 0},{ "ORA", &a::ORA, &a::IZY, 5, 0},{ "ORA", &a::ORA, &a::IZP, 4, 0},{ "???", &a::NOP, &a::IMP, 1, 0},{ "TRB", &a::TRB, &a::ZP0, 4, 0},{ "ORA", &a::ORA, &a::ZPX, 4, 0},{ "ASL", &a::ASL, &a::ZPX, 6, 0},{ "RMB1", &a::RMB, &a::ZP0, 6, 1},{ "CLC", &a::CLC, &a::IMP, 2, 0},{ "ORA", &a::ORA, &a::ABY, 4, 0},{ "INC", &a::INC, &a::ACC, 2, 0},{ "TRB", &a::TRB, &a::ABS, 1, 0},{ "???", &a::NOP, &a::IMP, 4, 0},{ "ORA", &a::ORA, &a::ABX, 4, 0},{ "ASL", &a::ASL, &a::ABX, 7, 0},{ "???", &a::NOP, &a::IMP, 7, 0},
        { "JSR", &a::JSR, &a::ABS, 6, 0},{ "AND", &a::AND, &a::IZX, 6, 0},{ "???", &a::NOP, &a::IMP, 2, 0},{ "???", &a::NOP, &a::IMP, 1, 0},{ "BIT", &a::BIT, &a::ZP0, 3, 0},{ "AND", &a::AND, &a::ZP0, 3, 0},{ "ROL", &a::ROL, &a::ZP0, 5, 0},{ "RMB2", &a::RMB, &a::ZP0, 5, 2},{ "PLP", &a::PLP, &a::IMP, 4, 0},{ "AND", &a::AND, &a::IMM, 2, 0},{ "ROL", &a::ROL, &a::ACC, 2, 0},{ "BIT", &a::BIT, &a::ABS, 1, 0},{ "BIT", &a::BIT, &a::ABS, 4, 0},{ "AND", &a::AND, &a::ABS, 4, 0},{ "ROL", &a::ROL, &a::ABS, 6, 0},{ "???", &a::NOP, &a::IMP, 6, 0},
        { "BMI", &a::BMI, &a::REL, 2, 0},{ "AND", &a::AND, &a::IZY, 5, 0},{ "AND", &a::AND, &a::IZP, 2, 0},{ "???", &a::NOP, &a::IMP, 1, 0},{ "BIT", &a::BIT, &a::ZPX, 4, 0},{ "AND", &a::AND, &a::ZPX, 4, 0},{ "ROL", &a::ROL, &a::ZPX, 6, 0},{ "RMB3", &a::RMB, &a::ZP0, 6, 3},{ "SEC", &a::SEC, &a::IMP, 2, 0},{ "AND", &a::AND, &a::ABY, 4, 0},{ "DEC", &a::DEC, &a::ACC, 2, 0},{ "BIT", &a::BIT, &a::ABX, 1, 0},{ "???", &a::NOP, &a::IMP, 4, 0},{ "AND", &a::AND, &a::ABX, 4, 0},{ "ROL", &a::ROL, &a::ABX, 7, 0},{ "???", &a::NOP, &a::IMP, 7, 0},
        { "RTI", &a::RTI, &a::IMP, 6, 0},{ "EOR", &a::EOR, &a::IZX, 6, 0},{ "???", &a::NOP, &a::IMP, 2, 0},{ "???", &a::NOP, &a::IMP, 1, 0},{ "???", &a::NOP, &a::IMP, 3, 0},{ "EOR", &a::EOR, &a::ZP0, 3, 0},{ "LSR", &a::LSR, &a::ZP0, 5, 0},{ "RMB4", &a::RMB, &a::ZP0, 5, 4},{ "PHA", &a::PHA, &a::IMP, 3, 0},{ "EOR", &a::EOR, &a::IMM, 2, 0},{ "LSR", &a::LSR, &a::ACC, 2, 0},{ "JMP", &a::JMP, &a::ABS, 1, 0},{ "JMP", &a::JMP, &a::ABS, 3, 0},{ "EOR", &a::EOR, &a::ABS, 4, 0},{ "LSR", &a::LSR, &a::ABS, 6, 0},{ "???", &a::NOP, &a::IMP, 6, 0},
        { "BVC", &a::BVC, &a::REL, 2, 0},{ "EOR", &a::EOR, &a::IZY, 5, 0},{ "EOR", &a::EOR, &a::IZP, 2, 0},{ "???", &a::NOP, &a::IMP, 1, 0},{ "???", &a::NOP, &a::IMP, 4, 0},{ "EOR", &a::EOR, &a::ZPX, 4, 0},{ "LSR", &a::LSR, &a::ZPX, 6, 0},{ "RMB5", &a::RMB, &a::ZP0, 6, 5},{ "CLI", &a::CLI, &a::IMP, 2, 0},{ "EOR", &a::EOR, &a::ABY, 4, 0},{ "PHY", &a::PHY, &a::STK, 2, 0},{ "???", &a::NOP, &a::IMP, 1, 0},{ "???", &a::NOP, &a::IMP, 8, 0},{ "EOR", &a::EOR, &a::ABX, 4, 0},{ "LSR", &a::LSR, &a::ABX, 7, 0},{ "???", &a::NOP, &a::IMP, 7, 0},
        { "RTS", &a::RTS, &a::IMP, 6, 0},{ "ADC", &a::ADC, &a::IZX, 6, 0},{ "???", &a::NOP, &a::IMP, 2, 0},{ "???", &a::NOP, &a::IMP, 1, 0},{ "STZ", &a::STZ, &a::ZP0, 3, 0},{ "ADC", &a::ADC, &a::ZP0, 3, 0},{ "ROR", &a::ROR, &a::ZP0, 5, 0},{ "RMB6", &a::RMB, &a::ZP0, 5, 6},{ "PLA", &a::PLA, &a::IMP, 4, 0},{ "ADC", &a::ADC, &a::IMM, 2, 0},{ "ROR", &a::ROR, &a::ACC, 2, 0},{ "JMP", &a::JMP, &a::IND, 1, 0},{ "JMP", &a::JMP, &a::IND, 5, 0},{ "ADC", &a::ADC, &a::ABS, 4, 0},{ "ROR", &a::ROR, &a::ABS, 6, 0},{ "???", &a::NOP, &a::IMP, 6, 0},
        { "BVS", &a::BVS, &a::REL, 2, 0},{ "ADC", &a::ADC, &a::IZY, 5, 0},{ "ADC", &a::ADC, &a::IZP, 2, 0},{ "???", &a::NOP, &a::IMP, 1, 0},{ "STZ", &a::STZ, &a::ZPX, 4, 0},{ "ADC", &a::ADC, &a::ZPX, 4, 0},{ "ROR", &a::ROR, &a::ZPX, 6, 0},{ "RMB7", &a::RMB, &a::ZP0, 6, 7},{ "SEI", &a::SEI, &a::IMP, 2, 0},{ "ADC", &a::ADC, &a::ABY, 4, 0},{ "PLY", &a::PLY, &a::STK, 2, 0},{ "JMP", &a::JMP, &a::AIX, 1, 0},{ "???", &a::NOP, &a::IMP, 4, 0},{ "ADC", &a::ADC, &a::ABX, 4, 0},{ "ROR", &a::ROR, &a::ABX, 7, 0},{ "???", &a::NOP, &a::IMP, 7, 0},
        { "???", &a::NOP, &a::IMP, 2, 0},{ "STA", &a::STA, &a::IZX, 6, 0},{ "???", &a::NOP, &a::IMP, 2, 0},{ "???", &a::NOP, &a::IMP, 1, 0},{ "STY", &a::STY, &a::ZP0, 3, 0},{ "STA", &a::STA, &a::ZP0, 3, 0},{ "STX", &a::STX, &a::ZP0, 3, 0},{ "SMB0", &a::SMB, &a::ZP0, 3, 0},{ "DEY", &a::DEY, &a::IMP, 2, 0},{ "???", &a::NOP, &a::IMP, 2, 0},{ "TXA", &a::TXA, &a::IMP, 2, 0},{ "STY", &a::STY, &a::ABS, 1, 0},{ "STY", &a::STY, &a::ABS, 4, 0},{ "STA", &a::STA, &a::ABS, 4, 0},{ "STX", &a::STX, &a::ABS, 4, 0},{ "???", &a::NOP, &a::IMP, 4, 0},
        { "BCC", &a::BCC, &a::REL, 2, 0},{ "STA", &a::STA, &a::IZY, 6, 0},{ "STX", &a::STX, &a::IZP, 2, 0},{ "???", &a::NOP, &a::IMP, 1, 0},{ "STY", &a::STY, &a::ZPX, 4, 0},{ "STA", &a::STA, &a::ZPX, 4, 0},{ "STX", &a::STX, &a::ZPY, 4, 0},{ "SMB1", &a::NOP, &a::ZP0, 4, 1},{ "TYA", &a::TYA, &a::IMP, 2, 0},{ "STA", &a::STA, &a::ABY, 5, 0},{ "TXS", &a::TXS, &a::IMP, 2, 0},{ "STZ", &a::STZ, &a::ABS, 1, 0},{ "???", &a::NOP, &a::IMP, 5, 0},{ "STA", &a::STA, &a::ABX, 5, 0},{ "???", &a::NOP, &a::IMP, 5, 0},{ "???", &a::NOP, &a::IMP, 5, 0},
        { "LDY", &a::LDY, &a::IMM, 2, 0},{ "LDA", &a::LDA, &a::IZX, 6, 0},{ "LDX", &a::LDX, &a::IMM, 2, 0},{ "???", &a::NOP, &a::IMP, 1, 0},{ "LDY", &a::LDY, &a::ZP0, 3, 0},{ "LDA", &a::LDA, &a::ZP0, 3, 0},{ "LDX", &a::LDX, &a::ZP0, 3, 0},{ "SMB2", &a::NOP, &a::ZP0, 3, 2},{ "TAY", &a::TAY, &a::IMP, 2, 0},{ "LDA", &a::LDA, &a::IMM, 2, 0},{ "TAX", &a::TAX, &a::IMP, 2, 0},{ "LDY", &a::LDY, &a::ACC, 1, 0},{ "LDY", &a::LDY, &a::ABS, 4, 0},{ "LDA", &a::LDA, &a::ABS, 4, 0},{ "LDX", &a::LDX, &a::ABS, 4, 0},{ "???", &a::NOP, &a::IMP, 4, 0},
        { "BCS", &a::BCS, &a::REL, 2, 0},{ "LDA", &a::LDA, &a::IZY, 5, 0},{ "LDA", &a::LDA, &a::IZP, 2, 0},{ "???", &a::NOP, &a::IMP, 1, 0},{ "LDY", &a::LDY, &a::ZPX, 4, 0},{ "LDA", &a::LDA, &a::ZPX, 4, 0},{ "LDX", &a::LDX, &a::ZPY, 4, 0},{ "SMB3", &a::NOP, &a::ZP0, 4, 3},{ "CLV", &a::CLV, &a::IMP, 2, 0},{ "LDA", &a::LDA, &a::ABY, 4, 0},{ "TSX", &a::TSX, &a::IMP, 2, 0},{ "LDY", &a::LDY, &a::ABX, 4, 0},{ "LDY", &a::LDY, &a::ABX, 4, 0},{ "LDA", &a::LDA, &a::ABX, 4, 0},{ "LDX", &a::LDX, &a::ABY, 4, 0},{ "???", &a::NOP, &a::IMP, 4, 0},
        { "CPY", &a::CPY, &a::IMM, 2, 0},{ "CMP", &a::CMP, &a::IZX, 6, 0},{ "???", &a::NOP, &a::IMP, 2, 0},{ "???", &a::NOP, &a::IMP, 1, 0},{ "CPY", &a::CPY, &a::ZP0, 3, 0},{ "CMP", &a::CMP, &a::ZP0, 3, 0},{ "DEC", &a::DEC, &a::ZP0, 5, 0},{ "SMB4", &a::NOP, &a::ZP0, 5, 4},{ "INY", &a::INY, &a::IMP, 2, 0},{ "CMP", &a::CMP, &a::IMM, 2, 0},{ "DEX", &a::DEX, &a::IMP, 2, 0},{ "CPY", &a::CPY, &a::ABS, 2, 0},{ "CPY", &a::CPY, &a::ABS, 4, 0},{ "CMP", &a::CMP, &a::ABS, 4, 0},{ "DEC", &a::DEC, &a::ABS, 6, 0},{ "???", &a::NOP, &a::IMP, 6, 0},
        { "BNE", &a::BNE, &a::REL, 2, 0},{ "CMP", &a::CMP, &a::IZY, 5, 0},{ "CMP", &a::CMP, &a::IZP, 2, 0},{ "???", &a::NOP, &a::IMP, 1, 0},{ "???", &a::NOP, &a::IMP, 4, 0},{ "CMP", &a::CMP, &a::ZPX, 4, 0},{ "DEC", &a::DEC, &a::ZPX, 6, 0},{ "SMB5", &a::NOP, &a::ZP0, 6, 5},{ "CLD", &a::CLD, &a::IMP, 2, 0},{ "CMP", &a::CMP, &a::ABY, 4, 0},{ "PHX", &a::PHX, &a::STK, 2, 0},{ "???", &a::NOP, &a::IMP, 7, 0},{ "???", &a::NOP, &a::IMP, 4, 0},{ "CMP", &a::CMP, &a::ABX, 4, 0},{ "DEC", &a::DEC, &a::ABX, 7, 0},{ "???", &a::NOP, &a::IMP, 7, 0},
        { "CPX", &a::CPX, &a::IMM, 2, 0},{ "SBC", &a::SBC, &a::IZX, 6, 0},{ "???", &a::NOP, &a::IMP, 2, 0},{ "???", &a::NOP, &a::IMP, 1, 0},{ "CPX", &a::CPX, &a::ZP0, 3, 0},{ "SBC", &a::SBC, &a::ZP0, 3, 0},{ "INC", &a::INC, &a::ZP0, 5, 0},{ "SMB6", &a::NOP, &a::ZP0, 5, 6},{ "INX", &a::INX, &a::IMP, 2, 0},{ "SBC", &a::SBC, &a::IMM, 2, 0},{ "NOP", &a::NOP, &a::IMP, 2, 0},{ "CPX", &a::CPX, &a::ABS, 1, 0},{ "CPX", &a::CPX, &a::ABS, 4, 0},{ "SBC", &a::SBC, &a::ABS, 4, 0},{ "INC", &a::INC, &a::ABS, 6, 0},{ "???", &a::NOP, &a::IMP, 6, 0},
        { "BEQ", &a::BEQ, &a::REL, 2, 0},{ "SBC", &a::SBC, &a::IZY, 5, 0},{ "SBC", &a::SBC, &a::IZP, 2, 0},{ "???", &a::NOP, &a::IMP, 1, 0},{ "???", &a::NOP, &a::IMP, 4, 0},{ "SBC", &a::SBC, &a::ZPX, 4, 0},{ "INC", &a::INC, &a::ZPX, 6, 0},{ "SMB7", &a::NOP, &a::ZP0, 6, 7},{ "SED", &a::SED, &a::IMP, 2, 0},{ "SBC", &a::SBC, &a::ABY, 4, 0},{ "PLX", &a::PLX, &a::STK, 2, 0},{ "???", &a::NOP, &a::IMP, 1, 0},{ "???", &a::NOP, &a::IMP, 4, 0},{ "SBC", &a::SBC, &a::ABX, 4, 0},{ "INC", &a::INC, &a::ABX, 7, 0},{ "???", &a::NOP, &a::IMP, 7, 0},
    };
}

CPU::~CPU() = default;

uint8_t CPU::read(uint16_t address) {
    return bus->cpuRead(address, false);
}

void CPU::write(uint16_t address, uint8_t data){
    bus->cpuWrite(address, data);
}

void CPU::reset() {

    address_abs = 0xFFFC;
    uint16_t lo = read(address_ab   s + 0);
    uint16_t hi = read(address_abs + 1);

    pc = ( hi << 8 ) | lo;

    a = 0;
    x = 0;
    y = 0;

    stack = 0xEF;
    status = 0x00 | U;

    address_abs = 0x0000;
    address_rel = 0x0000;

    fetched = 0x00;
    cycles = 8;
    ready = true;
    phi2 = true;
}

void CPU::irq(){
    if (GetFlag(I) == 0){
        write(0x0100 + stack, (pc >> 8) & 0x00FF);
        stack--;
        write(0x0100 + stack, pc & 0x00FF);
        stack--;

        SetFlag(B, false);
        SetFlag(U, true);
        SetFlag(I, true);
        write(0x0100 + stack, status);
        stack--;

        address_abs = 0xFFFE;

        uint16_t lo = read(address_abs + 0);
        uint16_t hi = read(address_abs + 1);

        pc = (hi << 8) | lo;

        cycles = 7;
    }
}

void CPU::nmi(){
    write(0x0100 + stack, (pc >> 8) & 0x00FF);
    stack--;
    write(0x0100 + stack, pc & 0x00FF);
    stack--;

    SetFlag(B, false);
    SetFlag(U, true);
    SetFlag(I, true);
    write(0x0100 + stack, status);
    stack--;

    address_abs = 0xFFFE;

    uint16_t lo = read(address_abs + 0);
    uint16_t hi = read(address_abs + 1);

    pc = (hi << 8) | lo;

    cycles = 8;
};

void CPU::clock(){

    // ready
    if ( ready && phi2 ) {
        if (cycles == 0) {
            opcode = read(pc);

            SetFlag(U, true);
            pc++;
            cycles = instructionSet[opcode].cycles;

            uint8_t address_cycles = (this->*instructionSet[opcode].addressMode)();
            uint8_t instruction_cycles = (this->*instructionSet[opcode].operate)();

            cycles += (address_cycles & instruction_cycles);
            SetFlag(U, true);
        }
        cycles--;
    }
}

uint8_t CPU::GetFlag(CPUFLAGS f) const {

    return ((status & f) > 0) ? 1 : 0;
}

void CPU::SetFlag(CPUFLAGS f, bool v) {
    if (v)
        status |= f;
    else
        status &= ~f;
}

uint8_t CPU::fetch() {
    if (instructionSet[opcode].addressMode != &CPU::IMP)
        fetched = read(address_abs);
}

bool CPU::complete(){
    return cycles == 0;
}

std::map<uint16_t, std::string> CPU::disassemble(uint16_t nStart, uint16_t nStop)
{
    uint32_t addr = nStart;
    uint8_t value = 0x00, lo = 0x00, hi = 0x00;
    std::map<uint16_t, std::string> mapLines;
    uint16_t line_addr = 0;

    // A convenient utility to convert variables into
    // hex strings because "modern C++"'s method with
    // streams is atrocious
    auto hex = [](uint32_t n, uint8_t d)
    {
        std::string s(d, '0');
        for (int i = d - 1; i >= 0; i--, n >>= 4)
            s[i] = "0123456789ABCDEF"[n & 0xF];
        return s;
    };

    // Starting at the specified address we read an instruction
    // byte, which in turn yields information from the instructionSet table
    // as to how many additional bytes we need to read and what the
    // addressing mode is. I need this info to assemble human readable
    // syntax, which is different depending upon the addressing mode

    // As the instruction is decoded, a std::string is assembled
    // with the readable output
    while (addr <= (uint32_t)nStop)
    {
        line_addr = addr;

        // Prefix line with instruction address
        std::string sInst = "$" + hex(addr, 4) + ": ";

        // Read instruction, and get its readable name
        uint8_t uOpcode = bus->cpuRead(addr, true);
        addr++;
        sInst += instructionSet[opcode].name + " ";

        // Get oprands from desired locations, and form the
        // instruction based upon its addressing mode. These
        // routines mimmick the actual fetch routine of the
        // 6502 in order to get accurate data as part of the
        // instruction
        if (instructionSet[opcode].addressMode == &CPU::IMP)
        {
            sInst += " {IMP}";
        }
        else if (instructionSet[opcode].addressMode == &CPU::IMM)
        {
            value = bus->cpuRead(addr, true);
            addr++;
            sInst += "#$" + hex(value, 2) + " {IMM}";
        }
        else if (instructionSet[opcode].addressMode == &CPU::ZP0)
        {
            lo = bus->cpuRead(addr, true); addr++;
            hi = 0x00;
            sInst += "$" + hex(lo, 2) + " {ZP0}";
        }
        else if (instructionSet[opcode].addressMode == &CPU::ZPX)
        {
            lo = bus->cpuRead(addr, true); addr++;
            hi = 0x00;
            sInst += "$" + hex(lo, 2) + ", X {ZPX}";
        }
        else if (instructionSet[opcode].addressMode == &CPU::ZPY)
        {
            lo = bus->cpuRead(addr, true); addr++;
            hi = 0x00;
            sInst += "$" + hex(lo, 2) + ", Y {ZPY}";
        }
        else if (instructionSet[opcode].addressMode == &CPU::IZX)
        {
            lo = bus->cpuRead(addr, true); addr++;
            hi = 0x00;
            sInst += "($" + hex(lo, 2) + ", X) {IZX}";
        }
        else if (instructionSet[opcode].addressMode == &CPU::IZY)
        {
            lo = bus->cpuRead(addr, true); addr++;
            hi = 0x00;
            sInst += "($" + hex(lo, 2) + "), Y {IZY}";
        }
        else if (instructionSet[opcode].addressMode == &CPU::ABS)
        {
            lo = bus->cpuRead(addr, true); addr++;
            hi = bus->cpuRead(addr, true); addr++;
            sInst += "$" + hex((uint16_t)(hi << 8) | lo, 4) + " {ABS}";
        }
        else if (instructionSet[opcode].addressMode == &CPU::ABX)
        {
            lo = bus->cpuRead(addr, true); addr++;
            hi = bus->cpuRead(addr, true); addr++;
            sInst += "$" + hex((uint16_t)(hi << 8) | lo, 4) + ", X {ABX}";
        }
        else if (instructionSet[opcode].addressMode == &CPU::ABY)
        {
            lo = bus->cpuRead(addr, true); addr++;
            hi = bus->cpuRead(addr, true); addr++;
            sInst += "$" + hex((uint16_t)(hi << 8) | lo, 4) + ", Y {ABY}";
        }
        else if (instructionSet[opcode].addressMode == &CPU::IND)
        {
            lo = bus->cpuRead(addr, true); addr++;
            hi = bus->cpuRead(addr, true); addr++;
            sInst += "($" + hex((uint16_t)(hi << 8) | lo, 4) + ") {IND}";
        }
        else if (instructionSet[opcode].addressMode == &CPU::REL)
        {
            value = bus->cpuRead(addr, true); addr++;
            sInst += "$" + hex(value, 2) + " [$" + hex(addr + (int8_t)value, 4) + "] {REL}";
        }

        // Add the formed string to a std::map, using the instruction's
        // address as the key. This makes it convenient to look for later
        // as the instructions are variable in length, so a straight up
        // incremental index is not sufficient.
        mapLines[line_addr] = sInst;
    }

    return mapLines;
}

// Addressing Modes
uint8_t CPU::ABS() {
    uint16_t lo = 0x00, hi = 0x00;

    lo = read(pc);
    pc++;
    hi = read(pc);
    address_abs = ( hi << 8 ) | lo;
    return 0;
}

uint8_t CPU::AIX(){
    uint16_t lo = 0x00, hi = 0x00;

    lo = read(pc);
    pc++;
    hi = read(pc);
    pc++;

    pc = ( hi << 8 ) | lo + x;
    return 0;
}

uint8_t CPU::ABX(){
    uint16_t lo = 0x00, hi = 0x00;
    lo = read(pc);
    pc++;
    hi = read(pc);
    pc++;

    address_abs = ( hi << 8 ) | lo + x;

    if (( address_abs & 0xFF00) != (hi << 8))
        return 1;
    else
        return 0;
}

uint8_t CPU::ABY(){
    uint16_t lo = 0x00, hi = 0x00;
    lo = read(pc);
    pc++;
    hi = read(pc);
    pc++;

    address_abs = ( hi << 8 ) | lo + y;
    if (( address_abs & 0xFF00) != (hi << 8))
        return 1;
    else
        return 0;
}

uint8_t CPU::IND() {

    uint16_t lo_ptr = 0x00, hi_ptr = 0x00;

    lo_ptr = read(pc);
    pc++;
    hi_ptr = read(pc);
    pc++;

    uint16_t ptr = (hi_ptr << 8) | lo_ptr;
    address_abs = (read(ptr + 1) << 8) | read(ptr + 8);
    return 0;
}

uint8_t CPU::ACC() {
    return 0;
}

uint8_t CPU::IMM() {
    address_abs = pc++;
    return 0;
}

uint8_t CPU::IMP(){
    fetched = a;
    return 0;
}

uint8_t CPU::REL(){
    address_rel = read(pc);
    pc++;
    if ( address_rel & 0x80 )
        address_rel |= 0xFF00;

    return 0;
}

uint8_t CPU::STK(){
    address_abs = 0x0100 + stack;
    return 0;
}

uint8_t CPU::ZP0(){
    address_abs = read(pc);
    pc++;
    address_abs &= 0x00FF;
    return 0;
}

uint8_t CPU::IZX() {
    uint16_t t = read(pc);
    pc++;

    uint16_t lo = read((t + (uint16_t)x) & 0x00FF);
    uint16_t hi = read( (t + (uint16_t)x + 1) & 0x00FF);

    address_abs = ( hi << 8 ) | lo;
    return 0;
}

uint8_t CPU::ZPX(){
    uint16_t zp = read(pc);
    pc++;

    address_abs = (zp + x) & 0x00FF;
    return 0;
}

uint8_t CPU::ZPY(){
    uint16_t zp = read(pc);
    pc++;

    address_abs = (zp + y) & 0x00FF;
    return 0;
}

uint8_t CPU::IZP(){
    uint16_t zp = read(pc);
    pc++;

    address_abs = read(zp & 0x00FF);
    return 0;
}

uint8_t CPU::IZY(){
    uint16_t t = read(pc);
    pc++;

    uint16_t lo = read(t & 0x00FF);
    uint16_t hi = read((t + 1) & 0x00FF);

    address_abs = (hi << 8) | lo;
    address_abs += y;

    if ((address_abs & 0xFF00) != (hi << 8))
        return 1;
    else
        return 0;
}

// MNEMONICS
uint8_t CPU::ADC(){

    fetch();

    temp = (uint16_t)a + (uint16_t)fetched + (uint16_t)GetFlag(C);

    SetFlag(C, temp > 255);
    SetFlag(Z, (temp & 0x00FF) == 0);
    SetFlag(V, (~((uint16_t)a ^ (uint16_t)fetched) & ((uint16_t)a ^ (uint16_t)temp)) & 0x0080);
    SetFlag(N, temp & 0x80);

    a = temp & 0x00FF;
    return 1;
}

uint8_t CPU::AND(){
    fetch();
    a &= fetched;
    SetFlag(Z, a==0);
    SetFlag(N, a & 0x80);
    return 1;
}

uint8_t CPU::ASL(){
    fetch();
    temp = (uint16_t)fetched << 1;
    SetFlag(C, (temp & 0xFF00) > 0);
    SetFlag(Z, (temp & 0x00FF) == 0x00);
    SetFlag(N, temp & 0x80);

    if ( instructionSet[opcode].addressMode == &CPU::IMP)
        a = temp & 0x00FF;
    else
        write(address_abs, temp & 0x00FF);
    return 0;
}

uint8_t CPU::BBR(){
    fetch();
    temp = ( 1 << (instructionSet[opcode].offset - 1));

    cycles++;

    if ( (fetched & temp) == 0) {
        address_abs = pc + address_rel;
        if ((address_abs & 0xFF00) != (pc & 0xFF00))
            cycles++;
    }

    return 0;
}

uint8_t CPU::BBS(){
    fetch();
    temp = ( 1 << (instructionSet[opcode].offset - 1));

    cycles++;

    if ( (fetched & temp) > 0) {
        address_abs = pc + address_rel;
        if ((address_abs & 0xFF00) != (pc & 0xFF00))
            cycles++;
    }

    return 0;
}

uint8_t CPU::BCC(){

    if (GetFlag(C) == 0 ){
        cycles++;
        address_abs = pc + address_rel;
        if (( address_abs & 0xFF00) != ( pc & 0xFF00))
            cycles++;

        pc = address_abs;
    }
    return 0;
}

uint8_t CPU::BCS(){

    if (GetFlag(C) == 1 ){
        cycles++;
        address_abs = pc + address_rel;
        if (( address_abs & 0xFF00) != ( pc & 0xFF00))
            cycles++;

        pc = address_abs;
    }
    return 0;
}

uint8_t CPU::BEQ(){

    if (GetFlag(Z) == 1 ){
        cycles++;

        address_abs = pc + address_rel;

        if ((address_abs & 0xFF00) != (pc & 0xFF00))
            cycles++;
        pc = address_abs;
    }
    return 0;
}

uint8_t CPU::BIT(){
    fetch();
    temp = a & fetched;
    SetFlag(Z, (temp & 0x00FF) == 0x00);
    SetFlag(N, fetched & (1 << 7));
    SetFlag(V, fetched & (1 << 6));
    return 0;
}

uint8_t CPU::BMI(){

    if (GetFlag(N) == 1 ){
        cycles++;

        address_abs = pc + address_rel;

        if ((address_abs & 0xFF00) != (pc & 0xFF00))
            cycles++;
        pc = address_abs;
    }
    return 0;

}

uint8_t CPU::BNE(){
    if (GetFlag(Z) == 0 ){
        cycles++;

        address_abs = pc + address_rel;

        if ((address_abs & 0xFF00) != (pc & 0xFF00))
            cycles++;
        pc = address_abs;
    }
    return 0;

}

uint8_t CPU::BPL(){
    if (GetFlag(N) == 0){
        cycles++;

        address_abs = pc + address_rel;

        if ((address_abs & 0xFF00) != (pc & 0xFF00))
            cycles++;
        pc = address_abs;
    }
    return 0;

}

uint8_t CPU::BRA(){
    address_abs = pc + address_rel;

    if ((address_abs & 0xFF00) != (pc & 0xFF00))
        cycles++;

}

uint8_t CPU::BRK(){
    pc++;

    SetFlag(I, 1);
    write(0x0100 + stack, (pc >> 8) & 0x00FF);
    stack--;
    write(0x0100 + stack, pc & 0x00FF);
    stack--;

    SetFlag(B, 1);
    write(0x0100 + stack, status);
    stack--;
    SetFlag(B, 0);

    pc = (uint16_t)read(0xFFFE) | ((uint16_t)read(0xFFFF) << 8);
    return 0;
}

uint8_t CPU::BVC(){

    if (GetFlag(V) == 0){
        cycles++;
        address_abs = pc + address_rel;

        if ((address_abs & 0xFF00) != (pc & 0xFF00))
            cycles++;

        pc = address_abs;
    }
    return 0;
}

uint8_t CPU::BVS(){

    if (GetFlag(V) == 1){
        cycles++;
        address_abs = pc + address_rel;

        if ((address_abs & 0xFF00) != (pc & 0xFF00))
            cycles++;

        pc = address_abs;
    }
    return 0;
}

uint8_t CPU::CLC(){
    SetFlag(C, false);
    return 0;
}

uint8_t CPU::SEC(){
    SetFlag(C, true);
    return 0;
}

uint8_t CPU::CLD(){
    SetFlag(D, false);
    return 0;
}

uint8_t CPU::SED(){
    SetFlag(D, true);
    return 0;
}

uint8_t CPU::CLI(){
    SetFlag(I, false);
    return 0;
}

uint8_t CPU::SEI(){
    SetFlag(I, true);
    return 0;
}

uint8_t CPU::CLV(){
    SetFlag(V, false);
    return 0;
}

uint8_t CPU::CMP(){
    fetch();
    temp = (uint16_t)a - (uint16_t) fetched;
    SetFlag(C, a >= fetched);
    SetFlag(Z, (temp & 0x00FF) == 0x0000);
    SetFlag(N, temp & 0x0080);
    return 0;
}

uint8_t CPU::CPX(){
    fetch();
    temp = (uint16_t)x - (uint16_t) fetched;
    SetFlag(C, x >= fetched);
    SetFlag(Z, (temp & 0x00FF) == 0x0000);
    SetFlag(N, temp & 0x0080);
    return 0;
}

uint8_t CPU::CPY(){
    fetch();
    temp = (uint16_t)y - (uint16_t) fetched;
    SetFlag(C, y >= fetched);
    SetFlag(Z, (temp & 0x00FF) == 0x0000);
    SetFlag(N, temp & 0x0080);
    return 0;
}

uint8_t CPU::DEC(){
    fetch();

    temp = fetched - 1;
    write(address_abs, temp & 0x00FF);
    SetFlag(Z, (temp & 0x00FF) == 0x0000);
    SetFlag(N, temp & 0x0080);
    return 0;
}

uint8_t CPU::DEX(){
    x--;
    SetFlag(Z, x == 0x00);
    SetFlag(N, x & 0x80);
    return 0;
}

uint8_t CPU::DEY(){
    y--;
    SetFlag(Z, y == 0x00);
    SetFlag(N, y & 0x80);
    return 0;
}

uint8_t CPU::EOR(){
    fetch();

    a ^= fetched;
    SetFlag(Z, y == 0x00);
    SetFlag(N, y & 0x80);
    return 1;
}

uint8_t CPU::INC(){
    fetch();

    temp = fetched + 1;
    write(address_abs, temp & 0x00FF);
    SetFlag(Z, (temp & 0x00FF) == 0x0000);
    SetFlag(N, temp & 0x0080);
    return 0;
}

uint8_t CPU::INX(){
    x++;
    SetFlag(Z, x == 0x00);
    SetFlag(N, x & 0x80);
    return 0;
}

uint8_t CPU::INY(){
    y++;
    SetFlag(Z, y == 0x00);
    SetFlag(N, y & 0x80);
    return 0;
}

uint8_t CPU::JMP(){
    pc = address_abs;
    return 0;
};

uint8_t CPU::JSR(){
    pc--;

    write(0x0100 + stack, (pc >> 8 ) & 0x00FF);
    stack--;
    write(0x0100 + stack, pc & 0x00FF);
    stack--;

    pc = address_abs;
}

uint8_t CPU::LDA(){
    fetch();
    a = fetched;
    SetFlag(Z, a==0);
    SetFlag(N, a & 0x80);
    return 1;
}

uint8_t CPU::LDX(){
    fetch();
    x = fetched;
    SetFlag(Z, x==0);
    SetFlag(N, x & 0x80);
    return 1;
}

uint8_t CPU::LDY(){
    fetch();
    y = fetched;
    SetFlag(Z, y==0);
    SetFlag(N, y & 0x80);
    return 1;
}

uint8_t CPU::LSR(){
    fetch();

    SetFlag(C, fetched & 0x0001);
    temp = fetched >> 1;
    SetFlag(Z, (temp & 0x00FF) == 0x0000);
    SetFlag(N, temp & 0x0080);
    if ( instructionSet[opcode].addressMode == &CPU::IMP)
        a = temp & 0x00FF;
    else
        write(address_abs, temp & 0x00FF);
    return 0;
}

uint8_t CPU::NOP(){
    return 0;
}

uint8_t CPU::ORA() {

    fetch();

    a |= fetched;
    SetFlag(Z, a == 0x00);
    SetFlag(N, a & 0x80);
    return 1;
}

uint8_t CPU::PHA(){

    write(0x0100 + stack, a);
    stack--;
    return 0;
}

uint8_t CPU::PHP(){
    write( 0x0100 + stack, status | B | U);
    SetFlag(B, false);
    SetFlag(U, false);
    stack--;
    return 0;
}

uint8_t CPU::PHX(){

    write(0x0100 + stack, x);
    stack--;
    return 0;
}

uint8_t CPU::PHY(){

    write(0x0100 + stack, y);
    stack--;
    return 0;
}

uint8_t CPU::PLA(){
    stack++;
    a = read(0x0100 + stack);
    SetFlag(Z, a == 0x00);
    SetFlag(N, a & 0x80);
    return 0;
}

uint8_t CPU::PLP(){
    stack++;
    status = ( 0x0100 + stack);
    SetFlag(U, true);
    return 0;
}

uint8_t CPU::PLX(){
    stack++;
    x = read(0x0100 + stack);
    SetFlag(Z, a == 0x00);
    SetFlag(N, a & 0x80);
    return 0;
}

uint8_t CPU::PLY(){
    stack++;
    y = read(0x0100 + stack);
    SetFlag(Z, a == 0x00);
    SetFlag(N, a & 0x80);
    return 0;
}

uint8_t CPU::RMB(){
    fetch();
    fetched &= ~(1 << instructionSet[opcode].offset);
    write(address_abs, fetched);
    return 0;
}

uint8_t CPU::ROL(){
    fetch();
    temp = (uint16_t)(fetched << 1) | GetFlag(C);
    SetFlag(C, temp & 0xFF00);
    SetFlag(Z, (temp & 0x00FF) == 0x0000);
    SetFlag(N, temp & 0x0080);
    if (instructionSet[opcode].addressMode == &CPU::IMP)
        a = temp & 0x00FF;
    else
        write(address_abs, temp & 0x00FF);
    return 0;

}

uint8_t CPU::ROR(){
    fetch();
    temp = (uint16_t)(GetFlag(C) << 7) | (fetched >> 1);
    SetFlag(C, fetched & 0x01);
    SetFlag(Z, (temp & 0x00FF) == 0x00);
    SetFlag(N, temp & 0x0080);
    if (instructionSet[opcode].addressMode == &CPU::IMP)
        a = temp & 0x00FF;
    else
        write(address_abs, temp & 0x00FF);
    return 0;

}

uint8_t CPU::RTI(){
    stack++;
    status = read(0x0100 + stack);
    status &= ~B;
    status &= ~U;

    stack++;
    pc = (uint16_t)read(0x0100 + stack);
    stack++;
    pc |= (uint16_t)read(0x0100 + stack) << 8;
    return 0;
};

uint8_t CPU::RTS(){
    stack++;
    pc = (uint16_t)read(0x0100 + stack);
    stack++;
    pc |= (uint16_t)read(0x0100 + stack) << 8;

    pc++;
    return 0;
}

uint8_t CPU::SBC() {

    fetch();

    uint16_t value = (uint16_t)fetched ^ 0x00FF;
    temp = (uint16_t)a + value + (uint16_t) GetFlag(C);
    SetFlag(C, temp & 0xFF00);
    SetFlag(Z, ((temp & 0x00FF) == 0));
    SetFlag(V, (temp ^ (uint16_t)a) & (temp ^ value) & 0x0080);
    SetFlag(N, temp & 0x0080);
    a = temp & 0x00FF;
    return 1;
}

uint8_t CPU::SMB() {
    fetch();
    fetched |= (1 << instructionSet[opcode].offset);
    write(address_abs, fetched);
    return 0;
}

uint8_t CPU::STA(){
    write(address_abs, a);
    return 0;
};

uint8_t CPU::STP() {
    phi2 = true;
    return 0;
}

uint8_t CPU::STX(){
    write(address_abs, x);
    return 0;
}

uint8_t CPU::STY(){
    write(address_abs, y);
    return 0;
}

uint8_t CPU::STZ(){
    write(address_abs, 0x00);
    return 0;
}

uint8_t CPU::TAX(){
    x = a;
    SetFlag(Z, x == 0x00);
    SetFlag(N, x & 0x80);
    return 0;
}

uint8_t CPU::TAY(){
    y = a;
    SetFlag(Z, y == 0x00);
    SetFlag(N, y & 0x80);
    return 0;
}

uint8_t CPU::TRB(){
    fetch();

    temp = ~(uint16_t)a & (uint16_t)fetched;
    SetFlag(Z, (temp & 0x00FF) == 0);
    write(address_abs, temp & 0x00FF);
    return 0;
}

uint8_t CPU::TSB(){
    fetch();

    temp = a | fetched;
    SetFlag(Z, (temp & 0x00FF) == 0);
    write(address_abs, temp & 0x00FF);
    return 0;
}

uint8_t CPU::TSX(){
    x = stack;
    SetFlag(Z, x == 0x00);
    SetFlag(N, x & 0x80);
    return 0;
}

uint8_t CPU::TXA(){
    a = x;
    SetFlag(Z, a == 0x00);
    SetFlag(N, a & 0x80);
    return 0;
}

uint8_t CPU::TXS() {
    stack = x;
    return 0;
}

uint8_t CPU::TYA(){
    a = y;
    SetFlag(Z, a == 0x00);
    SetFlag(N, a & 0x80);
    return 0;
}

uint8_t CPU::WAI() {
    ready = false;
    return 0;
}