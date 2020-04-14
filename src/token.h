#pragma once

#include <variant>

struct TLPar {};
struct TRPar {};
struct TNum { int value; };
struct TAdd {};
struct TSub {};
struct TMul {};
struct TDiv {};

using Token = std::variant<
    TLPar,
    TRPar,
    TNum,
    TAdd,
    TSub,
    TMul,
    TDiv
>;
