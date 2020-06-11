#pragma once
#include "Expr_Builder.h"
#include "Eval_Expr_Tree.h"
#include <string>
#include <iostream>


class Calculator
{
public:
	Calculator(Expr_Builder & builder, Eval_Expr_Tree & eval);
	int evaluate(const std::string & infix);
	bool parse_expr(const std::string & infix);
private:
	// builder pointer to build the tree
	Expr_Builder * builder_;

	// visitor to visit each node and perform each operation
	Eval_Expr_Tree * eval_;
};