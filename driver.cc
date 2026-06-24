#include "includes/vm.hpp"

static const std::vector<int> program {
    VM::InstructionSet::PSH, 5,
    VM::InstructionSet::PSH, 5,
    VM::InstructionSet::ADD,
    VM::InstructionSet::LOAD, VM::Registers::A,
    VM::InstructionSet::HLT,
};


int main() {
    VM my_vm(program);
    my_vm.run();
    my_vm.register_dump();
    return 0;
}