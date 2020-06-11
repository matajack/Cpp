#include "Multiply_Expr_Node.h"
#include "Expr_Node_Visitor.h"


Multiply_Expr_Node::Multiply_Expr_Node() : Binary_Expr_Node()
{

}

Multiply_Expr_Node::~Multiply_Expr_Node()
{

}

int Multiply_Expr_Node::eval() const
{
	return (left_->eval() * right_->eval());
}

void Multiply_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Multiply_Node(*this);
}