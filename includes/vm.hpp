#ifndef VM_HPP
#define VM_HPP

#include <array>
#include <stack>
#include <vector>

class VM {
    public:
    explicit VM(std::vector<int> program);
    void run();
    void register_dump() const;
    enum InstructionSet { PSH, ADD, POP, LOAD, HLT };
    enum Registers { A, B, C, D, E };

    private:
    int fetch();
    void eval(int instr);
    std::vector<int> program_;
    std::stack<int> stack_;
    std::array<int, 5> registers_ {};
    int ip_ = 0;
    bool running_ = true;
};

#endif