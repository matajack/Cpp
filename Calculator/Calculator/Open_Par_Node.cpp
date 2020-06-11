#include "Open_Par_Node.h"
#include "Expr_Node_Visitor.h"


Open_Par_Node::Open_Par_Node() : Unary_Expr_Node()
{

}

Open_Par_Node::~Open_Par_Node()
{

}

void Open_Par_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Open_Node(*this);
}

int Open_Par_Node::eval() const
{
	if (this->child_)
		return this->child_->eval();
}

