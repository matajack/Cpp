#pragma once
#include "Binary_Expr_Node.h"
#include "Expr_Node_Visitor.h"

class Add_Expr_Node : public Binary_Expr_Node {
public:
	Add_Expr_Node(void);
	virtual ~Add_Expr_Node(void);
	virtual int eval() const;
	virtual void accept(Expr_Node_Visitor & v);
	friend class Eval_Expr_Tree;
};