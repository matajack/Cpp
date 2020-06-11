#include <string>
#include "Stack.h"
#include <iostream>
#include "Expr_Tree_Builder.h"
#include "Eval_Expr_Tree.h"
#include "Calculator.h"


int main (int argc, char * argv [])
{
	std::string quit = "NO";
	std::string expression = "";
	Expr_Tree_Builder the_Builder;
	Eval_Expr_Tree the_Visitor;

	Calculator * temp = new Calculator(the_Builder, the_Visitor);
	
	while (quit != "QUIT")
	{
		std::cout << "Input: ";

		std::getline(std::cin,expression);

		temp->parse_expr(expression);

		std::cout << "Answer = " << temp->evaluate(expression);

		std::cout << "\nIf you would like to exit type 'QUIT' : ";
		std::getline(std::cin, quit);
	}
	delete temp;
	return 0;
}
