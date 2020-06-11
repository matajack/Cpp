#pragma once
#include "Unary_Expr_Node.h"


class Open_Par_Node : public Unary_Expr_Node
{
public:
	Open_Par_Node();
	~Open_Par_Node();
	virtual void accept(Expr_Node_Visitor & v);
	virtual int eval(void)const;
	friend class Eval_Expr_Tree;
};