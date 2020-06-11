#pragma once
class Expr_Node_Visitor;

class Expr_Node {
public:   
	Expr_Node(void);
	virtual ~Expr_Node(void);
	
	// Used to traverse the tree  
	virtual int eval (void) const = 0;

	// This is using the Expr_Node_Visitor and it is giving me
	// errors since the Expr_Node_Visitor cannot be defined if 
	// Expr_Node is not defined
	virtual void accept(Expr_Node_Visitor & v) = 0;
}; 
