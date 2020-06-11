#pragma once
#include "Binary_Expr_Node.h"


class Multiply_Expr_Node : public Binary_Expr_Node {
public:
	Multiply_Expr_Node(void);
	virtual ~Multiply_Expr_Node(void);
	virtual int eval() const;
	virtual void accept(Expr_Node_Visitor & v);
	friend class Eval_Expr_Tree;
};