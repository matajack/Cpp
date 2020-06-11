#pragma once
#include "Expr_Node.h"

class Unary_Expr_Node : public Expr_Node { 
public:   
	Unary_Expr_Node(void);
	virtual ~Unary_Expr_Node(void);
	virtual int eval(void) const = 0;
protected: 
	Expr_Node * child_;
};