#include "token.h"
#include "parse.h"
#include "print.h"
#include <vector>
#include <iostream>

std::vector<Token> tokens()
{
    return {
        TLPar{},
        TNum{1},
        TAdd{},
        TNum{2},
        TRPar{},
        TMul{},
        TLPar{},
        TNum{3},
        TSub{},
        TNum{4},
        TRPar{}
    };
}

int main() {
    Input input(tokens());
    Parsed<Program> program = parse_program(input);

    if (program) {
        std::cout << print_program(program.value());
    }
    else {
        std::cout << "parse error (" << input.pos() << "): " << program.error().what << "\n";
    }
}
