#include "Number_Expr_Node.h"
#include "Expr_Node_Visitor.h"

Number_Expr_Node::Number_Expr_Node(int num)
	:stored_num_(num)
{

}

Number_Expr_Node::~Number_Expr_Node()
{

}

int Number_Expr_Node::eval() const
{
	return stored_num_;
}

void Number_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Number_Node(*this);
}