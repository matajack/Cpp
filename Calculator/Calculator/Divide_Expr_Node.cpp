#include "Divide_Expr_Node.h"
#include "Expr_Node_Visitor.h"


Divide_Expr_Node::Divide_Expr_Node() : Binary_Expr_Node()
{

}

Divide_Expr_Node::~Divide_Expr_Node()
{

}

int Divide_Expr_Node::eval() const
{
	return (left_->eval() / right_->eval());
}

void Divide_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Divide_Node(*this);
}