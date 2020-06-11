#include "Closed_Par_Node.h"
#include "Expr_Node_Visitor.h"


Closed_Par_Node::Closed_Par_Node() : Unary_Expr_Node()
{

}

Closed_Par_Node::~Closed_Par_Node()
{

}

void Closed_Par_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Closed_Node(*this);
}

int Closed_Par_Node::eval() const
{
	if (this->child_)
		return this->child_->eval();
}