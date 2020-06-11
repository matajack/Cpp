#pragma once
#include "Expr_Node.h"

class Number_Expr_Node : public Expr_Node {
public:
	Number_Expr_Node(int num);
	virtual ~Number_Expr_Node(void);
	virtual int eval() const;
	virtual void accept(Expr_Node_Visitor & v);
	friend class Eval_Expr_Tree;
private:
	int stored_num_;
};