#include "Mod_Expr_Node.h"
#include "Expr_Node_Visitor.h"

Mod_Expr_Node::Mod_Expr_Node() : Binary_Expr_Node()
{

}

Mod_Expr_Node::~Mod_Expr_Node()
{

}

int Mod_Expr_Node::eval() const
{
	return (left_->eval() % right_->eval());
}

void Mod_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Mod_Node(*this);
}