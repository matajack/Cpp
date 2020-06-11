#include "Binary_Expr_Node.h"


Binary_Expr_Node::Binary_Expr_Node()
	:right_(nullptr),
	left_(nullptr)
{

}

Binary_Expr_Node::~Binary_Expr_Node()
{

}

void Binary_Expr_Node::set_left(Expr_Node * left)
{
	left_ = left;
}

void Binary_Expr_Node::set_right(Expr_Node * right)
{
	right_ = right;
}