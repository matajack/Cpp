#pragma once
#include "Expr_Builder.h"
#include "Stack.h"
#include "Binary_Expr_Node.h"

class Expr_Tree_Builder : public Expr_Builder {
public:
	Expr_Tree_Builder(void);
	virtual ~Expr_Tree_Builder(void);
	virtual void start_expression(void) {    
		// ...    
		this->tree_ = new Expr_Tree;  
	}  
	virtual void build_number (int n);
	virtual void build_add_operator (void);  
	virtual void build_subtract_operator (void); 
	virtual void build_multiply_operator(void);
	virtual void build_divide_operator(void);
	virtual void build_mod_operator(void);
	// ...  
	virtual void build_open_parenthesis(void);
	virtual void build_close_parenthesis(int n);

	Expr_Tree * get_expression(void);

private:  
	// current state of expression tree 
	Expr_Tree * tree_;

	// other variables to coordinate build process 
	
	// pointer to Expr_Node derived class that will be pushed onto the stack
	Expr_Node * temp;

	// pointer for the Binary_Expr_Node objects
	Binary_Expr_Node * binary_temp;

}; 