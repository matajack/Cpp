#pragma once
#include "Expr_Node.h"

class Binary_Expr_Node : public Expr_Node {
public:  
	Binary_Expr_Node(void);  
	virtual ~Binary_Expr_Node(void);  
	virtual int eval(void) const = 0;
	void set_left(Expr_Node * left);
	void set_right(Expr_Node * right);

protected:  
	Expr_Node * right_; 
	Expr_Node * left_;
}; 
