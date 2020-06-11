#include "Expr_Tree_Builder.h"
#include "Stack.h"
#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Number_Expr_Node.h"
#include "Multiply_Expr_Node.h"
#include "Divide_Expr_Node.h"
#include "Mod_Expr_Node.h"
#include "Open_Par_Node.h"
#include "Closed_Par_Node.h"


Expr_Tree_Builder::Expr_Tree_Builder() 
	:tree_(nullptr),
	temp(nullptr),
	binary_temp(nullptr)
{

}

Expr_Tree_Builder::~Expr_Tree_Builder()
{

}


// Pushing a number node onto the stack to then be set as a leaf on the tree
void Expr_Tree_Builder::build_number(int n)
{
	temp = new Number_Expr_Node(n);
	if (this->tree_->the_tree_.size() == 0) {
		this->tree_->the_tree_.push(temp);
	}
	else {
		binary_temp = (Binary_Expr_Node*)this->tree_->the_tree_.top();
		binary_temp->set_right(temp);
		this->tree_->the_tree_.pop();
		this->tree_->the_tree_.push(binary_temp);
	}
}

// All Binary_Expr_Node objects will pop 2 elements of the stack and 
// then point to them with the right_ and left_ Expr_Node pointers
void Expr_Tree_Builder::build_add_operator() 
{
	binary_temp = new Add_Expr_Node();
	binary_temp->set_left(this->tree_->the_tree_.top());
	this->tree_->the_tree_.pop();
	this->tree_->the_tree_.push(binary_temp);
}

void Expr_Tree_Builder::build_subtract_operator()
{
	binary_temp = new Subtract_Expr_Node();
	binary_temp->set_left(this->tree_->the_tree_.top());
	this->tree_->the_tree_.pop();
	this->tree_->the_tree_.push(binary_temp);
}

void Expr_Tree_Builder::build_multiply_operator()
{
	binary_temp = new Multiply_Expr_Node();
	binary_temp->set_left(this->tree_->the_tree_.top());
	this->tree_->the_tree_.pop();
	this->tree_->the_tree_.push(binary_temp);
}

void Expr_Tree_Builder::build_divide_operator()
{
	binary_temp = new Divide_Expr_Node();
	binary_temp->set_left(this->tree_->the_tree_.top());
	this->tree_->the_tree_.pop();
	this->tree_->the_tree_.push(binary_temp);
}

void Expr_Tree_Builder::build_mod_operator()
{
	binary_temp = new Mod_Expr_Node();
	binary_temp->set_left(this->tree_->the_tree_.top());
	this->tree_->the_tree_.pop();
	this->tree_->the_tree_.push(binary_temp);
}

void Expr_Tree_Builder::build_open_parenthesis()
{

}

void Expr_Tree_Builder::build_close_parenthesis(int n)
{
	temp = new Number_Expr_Node(n);
	if (dynamic_cast<Open_Par_Node*>(this->tree_->the_tree_.top())) {
		this->tree_->the_tree_.push(temp);
	}
	else {
		binary_temp = (Binary_Expr_Node*)this->tree_->the_tree_.top();
		binary_temp->set_right(temp);
		this->tree_->the_tree_.pop();
		this->tree_->the_tree_.push(binary_temp);
	}
}

Expr_Tree * Expr_Tree_Builder::get_expression()
{
	return tree_;
}