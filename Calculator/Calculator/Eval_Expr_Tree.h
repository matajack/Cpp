#pragma once
#include "Expr_Node_Visitor.h"

class Eval_Expr_Tree : public Expr_Node_Visitor {
public:   
	Eval_Expr_Tree(void); 
	virtual ~Eval_Expr_Tree(void);  
	
	// Methods for visiting concrete nodes   
	virtual void Visit_Addition_Node(const Add_Expr_Node & node);
	virtual void Visit_Subtraction_Node (const Subtract_Expr_Node & node);  
	virtual void Visit_Number_Node (const Number_Expr_Node & node); 
	virtual void Visit_Multiply_Node(const Multiply_Expr_Node & node);
	virtual void Visit_Divide_Node(const Divide_Expr_Node & node);
	virtual void Visit_Mod_Node(const Mod_Expr_Node & node);
	virtual void Visit_Open_Node(const Open_Par_Node & node);
	virtual void Visit_Closed_Node(const Closed_Par_Node & node);
	// ...  
	int result (void) const
	{
		return this->result_;
	} 
private:  
	int result_;   
	// other state for calculating result 
}; 