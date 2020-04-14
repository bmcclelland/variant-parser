#pragma once

#include "ast.h"
#include "parse_input.h"
#include "parse_result.h"
#include "result.h"

Parsed<Program> parse_program(Input&);

template <typename T>
using Parser = Parsed<T>(*)(Input&);

template <typename T, typename... Ts>
auto any(Input& input, char const* expecting, Parser<T> first, Ts... rest) -> Parsed<T> {
    auto rollback = input.mark_rollback();
    Parser<T> fns[] = { first, rest... };

    for (auto f : fns) {
        Parsed<T> p = f(input);

        if (p) {
            rollback.cancel();
            return p;
        }
    }

    return ParseError { std::string("expected ") + expecting };
}

