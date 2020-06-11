#pragma once
class Add_Expr_Node;
class Subtract_Expr_Node;
class Number_Expr_Node;
class Multiply_Expr_Node;
class Divide_Expr_Node;
class Mod_Expr_Node;
class Open_Par_Node;
class Closed_Par_Node;

class Expr_Node_Visitor {
public:  
	virtual ~Expr_Node_Visitor(void) {}
	virtual void Visit_Addition_Node (const Add_Expr_Node & node);
	virtual void Visit_Subtraction_Node (const Subtract_Expr_Node & node); 
	virtual void Visit_Number_Node (const Number_Expr_Node & node);  
	virtual void Visit_Multiply_Node(const Multiply_Expr_Node & node);
	virtual void Visit_Divide_Node(const Divide_Expr_Node & node);
	virtual void Visit_Mod_Node(const Mod_Expr_Node & node);
	virtual void Visit_Open_Node(const Open_Par_Node & node);
	virtual void Visit_Closed_Node(const Closed_Par_Node & node);
	// ... 
}; 


