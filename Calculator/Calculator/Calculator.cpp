#include "Calculator.h"
#include "Expr_Builder.h"
#include <string>
#include <iostream>
#include <memory>
#include <sstream>

Calculator::Calculator(Expr_Builder & builder, Eval_Expr_Tree & eval)
	: builder_(&builder),
	eval_(&eval)
{

} 
int Calculator::evaluate(const std::string & infix)
{
	if (!this->parse_expr(infix))
		return false;  
	std::unique_ptr <Expr_Tree> expr(this->builder_->get_expression());
	if (nullptr == expr.get())
		return false;  
	// evaluate the expression  
	expr->the_tree_.top()->accept(*eval_);
	return eval_->result();
}

bool Calculator::parse_expr(const std::string & infix) {
	std::istringstream input(infix);
	// create a input stream parser  

	std::string par_input = "";

	// variables to convert string number to an int number
	int number = 0;
	std::stringstream number_as_str;
	Calculator * par_calc = new Calculator(*builder_, *eval_);


	std::string token;                // current token in string/stream  
	builder_->start_expression();            // start a new expression  
	while (!input.eof ()) {    
		input >> token;   
		par_input = par_input + " " + token + " ";
		if (token == "+")
			this->builder_->build_add_operator();
		else if (token == "-")
			this->builder_->build_subtract_operator();
		else if (token == "*")
			this->builder_->build_multiply_operator();
		else if (token == "/")
			this->builder_->build_divide_operator();
		else if (token == "%")
			this->builder_->build_mod_operator();
		else if (token == "(" || token == "[") {
			par_input = "";
			this->builder_->build_open_parenthesis();
		}
		else if (token == ")" || token == "]") {
			par_input = par_input.substr(0, par_input.size() - 3);
			this->builder_->build_close_parenthesis(par_calc->evaluate(par_input));
		}
		else
		{
			number_as_str << token;
			number_as_str >> number;
			number_as_str.str("");
			number_as_str.clear();

			this->builder_->build_number(number);
		}
		// ...  
	}  
	return true; 
}; 