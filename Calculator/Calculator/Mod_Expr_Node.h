#pragma once
#include "Binary_Expr_Node.h"

class Mod_Expr_Node : public Binary_Expr_Node {
public:
	Mod_Expr_Node(void);
	virtual ~Mod_Expr_Node(void);
	virtual int eval() const;
	virtual void accept(Expr_Node_Visitor & v);
	friend class Eval_Expr_Tree;
};