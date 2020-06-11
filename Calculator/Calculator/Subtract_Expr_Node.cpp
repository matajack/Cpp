#include "Subtract_Expr_Node.h"
#include "Expr_Node_Visitor.h"

Subtract_Expr_Node::Subtract_Expr_Node() : Binary_Expr_Node()
{

}

Subtract_Expr_Node::~Subtract_Expr_Node()
{

}

int Subtract_Expr_Node::eval() const
{
	return (left_->eval() - right_->eval());
}

void Subtract_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Subtraction_Node(*this);
}