#pragma once

#include <variant>
#include <vector>
#include <memory>

// Binary operators.
enum class BinOp
{
    add,
    sub,
    mul,
    div
};

////////////////////////////////
// Expr

// Declaring types so we can declare the variant.
// They use the variant, so it must be declared before defining their bodies.
struct BinOpExpr;
struct NumExpr;

using Expr = std::variant<
    BinOpExpr,
    NumExpr
>;

struct BinOpExpr {
    std::unique_ptr<Expr> left;
    BinOp op;
    std::unique_ptr<Expr> right;
};

struct NumExpr {
    int value;
};

////////////////////////////////
// Program

struct Program {
    std::vector<Expr> exprs;
};

