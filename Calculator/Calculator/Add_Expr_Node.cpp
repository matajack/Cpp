#include "Add_Expr_Node.h"
#include "Expr_Node_Visitor.h"


Add_Expr_Node::Add_Expr_Node() : Binary_Expr_Node()
{

}

Add_Expr_Node::~Add_Expr_Node()
{

}

int Add_Expr_Node::eval() const
{
	return (left_->eval() + right_->eval());
}

void Add_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Addition_Node(*this);
}