#include "Eval_Expr_Tree.h"
#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Number_Expr_Node.h"
#include "Multiply_Expr_Node.h"
#include "Divide_Expr_Node.h"
#include "Mod_Expr_Node.h"
#include "Open_Par_Node.h"
#include "Closed_Par_Node.h"


Eval_Expr_Tree::Eval_Expr_Tree()
	: result_(0)
{

}

Eval_Expr_Tree::~Eval_Expr_Tree()
{

}


// Running the eval() method for any node type to traverse the tree and receive the result

void Eval_Expr_Tree::Visit_Number_Node(const Number_Expr_Node & node)
{
  // COMMENT: You are not using the visitor pattern correctly.
  // Instead, you have mixed the visitor with the composite version
  // of evaluate. You are to visit the left and right node via the
  // accept method to correctly implement the visitor pattern.
  // (e.g., left->accept (*this))

  // ANSWER: I have changed the visitor to evaluate based upon the left and right nodes for the given node it visits

	result_ = node.stored_num_;
}

void Eval_Expr_Tree::Visit_Addition_Node(const Add_Expr_Node & node)
{
  // COMMENT: You are not using the visitor pattern correctly.
  // Instead, you have mixed the visitor with the composite version
  // of evaluate. You are to visit the left and right node via the
  // accept method to correctly implement the visitor pattern.
  // (e.g., left->accept (*this))

  // ANSWER: I have changed the visitor to evaluate based upon the left and right nodes for the given node it visits

	result_ = node.left_->eval() + node.right_->eval();
}

void Eval_Expr_Tree::Visit_Subtraction_Node(const Subtract_Expr_Node & node)
{
  // COMMENT: You are not using the visitor pattern correctly.
  // Instead, you have mixed the visitor with the composite version
  // of evaluate. You are to visit the left and right node via the
  // accept method to correctly implement the visitor pattern.
  // (e.g., left->accept (*this))

  // ANSWER: I have changed the visitor to evaluate based upon the left and right nodes for the given node it visits

	result_ = node.left_->eval() - node.right_->eval();
}

void Eval_Expr_Tree::Visit_Multiply_Node(const Multiply_Expr_Node & node)
{
  // COMMENT: You are not using the visitor pattern correctly.
  // Instead, you have mixed the visitor with the composite version
  // of evaluate. You are to visit the left and right node via the
  // accept method to correctly implement the visitor pattern.
  // (e.g., left->accept (*this))

  // ANSWER: I have changed the visitor to evaluate based upon the left and right nodes for the given node it visits

	result_ = node.left_->eval() * node.right_->eval();
}

void Eval_Expr_Tree::Visit_Divide_Node(const Divide_Expr_Node & node)
{
  // COMMENT: You are not using the visitor pattern correctly.
  // Instead, you have mixed the visitor with the composite version
  // of evaluate. You are to visit the left and right node via the
  // accept method to correctly implement the visitor pattern.
  // (e.g., left->accept (*this))

  // ANSWER: I have changed the visitor to evaluate based upon the left and right nodes for the given node it visits

	result_ = node.left_->eval() / node.right_->eval();
}

void Eval_Expr_Tree::Visit_Mod_Node(const Mod_Expr_Node & node)
{
  // COMMENT: You are not using the visitor pattern correctly.
  // Instead, you have mixed the visitor with the composite version
  // of evaluate. You are to visit the left and right node via the
  // accept method to correctly implement the visitor pattern.
  // (e.g., left->accept (*this))

  // ANSWER: I have changed the visitor to evaluate based upon the left and right nodes for the given node it visits

	result_ = node.left_->eval() % node.right_->eval();
}

void Eval_Expr_Tree::Visit_Open_Node(const Open_Par_Node & node)
{
	result_ = node.child_->eval();
}

void Eval_Expr_Tree::Visit_Closed_Node(const Closed_Par_Node & node)
{
	
}