#pragma once
#include <iostream>
#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Number_Expr_Node.h"

class Print_Inorder_Expr : public Expr_Node_Visitor {
public:  
	Print_Inorder_Expr(std::ostream & out) 
		: out_(out)
	{
	
	}  
	virtual ~Print_Inorder_Expr(void) {}

	// Methods for visiting concrete nodes   
	virtual void Visit_Addition_Node(const Add_Expr_Node & node) {}
	virtual void Visit_Subtraction_Node(const Subtract_Expr_Node & node) {}
	virtual void Visit_Number_Node(const Number_Expr_Node & node) {}
	// ... 
private: 
	// output stream  
	std::ostream out_;
}; 