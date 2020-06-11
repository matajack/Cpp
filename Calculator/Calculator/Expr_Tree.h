#pragma once
#include "Expr_Node.h"
#include "Stack.h"

class Expr_Tree
{
public:
	Stack<Expr_Node*> the_tree_;
};