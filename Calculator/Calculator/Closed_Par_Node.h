#pragma once
#include "Unary_Expr_Node.h"


class Closed_Par_Node : public Unary_Expr_Node
{
public:
	Closed_Par_Node();
	~Closed_Par_Node();
	virtual void accept(Expr_Node_Visitor & v);
	virtual int eval(void) const;
	friend class Eval_Expr_Tree;
};