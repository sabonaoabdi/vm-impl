#include "../includes/vm.hpp"
#include <iostream>

VM::VM(std::vector<int> program) : program_(std::move(program)) {}

void VM::run() {
    while (running_) {
        eval(fetch());
        ip_++;
    }
}

void VM::register_dump() const {
    static const std::array<char, 5> names {'A', 'B', 'C', 'D', 'E'};
    for (unsigned int i = 0; i < registers_.size(); ++i) {
        std::cout << "Register " 
        << names.at(i) 
        << ": " << registers_.at(i) << std::endl;
    } 
}

int VM::fetch() {
    return program_.at(ip_);
}

void VM::eval(int instr) {
    switch (instr) {
        case InstructionSet::HLT: {
            running_ = false;
            break;
        }
        case InstructionSet::PSH: {
            stack_.push(program_.at(ip_ + 1));
            ip_++;
            break;
        }
        case InstructionSet::ADD: {
            int a = stack_.top();
            stack_.pop();
            int b = stack_.top();
            stack_.pop();
            stack_.push(a+b);
            break;
        }
        case InstructionSet::POP: {
            stack_.pop();
            break;
        }
        case InstructionSet::LOAD: {
            registers_[static_cast<Registers>(program_.at(++ip_))] = stack_.top();
            stack_.pop();
            break;
        }
        default: {
            std::cerr << "Error: Illegal OpCode Passed" << std::endl;
            running_ = false;
            break;
        }
    }
}