#include <stack>

#include "src/instruction_set.cc"
#include "src/registers.cc"


static const std::array<int, 9> program {
    PSH, 5,
    PSH, 612,
    ADD,
    LOAD, A,
    HLT,
};

bool running = true;
int ip = 0;
std::stack<int> stack;

int fetch() {
    return program.at(ip);
}

void eval(int instr) {
    switch (instr) {
        case HLT: {
            running = false;
            break;
        }
        case PSH: {
            stack.push(program.at(++ip));
            break;
        }
        case ADD: {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(a+b);
            break;
        }
        case POP: {
            stack.pop();
            break;
        }
        case LOAD: {
            registers[static_cast<Registers>(program.at(++ip))] = stack.top();
            stack.pop();
            break;
        }
        default: {
            std::cerr << "Error: Illegal OpCode Passed" << std::endl;
            running = false;
            break;
        }
    }
}


int main() {
    while (running) {
        eval(fetch());
        ip++;
    }
    dump();
    return 0;
}