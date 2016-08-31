// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include <iostream>
#include "Expr_Evaluator.h"

//
// Expr_Evaluator
//
Expr_Evaluator::Expr_Evaluator (void)
{}

//
// ~Expr_Evaluator
//
Expr_Evaluator::~Expr_Evaluator (void)
{}

//
// calculator (const std::string &)
//
int Expr_Evaluator::calculator (const std::string & infix)
{
	try
	{
		// use expression tree builder class to build the tree.
		Expr_Tree_Builder b;
		int result=0;
		// call to parse expression which will create the tree.
		parse_expr(infix,b);
		// call to evaluate expression to evaluate the tree.
		evaluate_expr(b,result);
		return result;
	}
	catch(std::exception& e)
	{
		// rethrow exception for try catch in driver.
		const std::string es=e.what();
		throw std::runtime_error(es);
	}
}

//
// parse_expr (const std::string &, Expr_Builder &)
//
bool Expr_Evaluator::parse_expr (const std::string & infix, Expr_Builder & builder)
{
	// check if expression has proper spaces and parenthesis.
	if (!(is_expression(infix)))
	{
		throw std::runtime_error("Invalid Expression");
	}
	// creating a stream of strings.
	std::istringstream input(infix);
	// declaring token strings to store current and previous tokens.
	std::string token;
	std::string token_previous;
	// declaring variable count to count the nodes leaving out the parenthesis nodes.
	size_t count=0;
	builder.build_expression();
	while(!input.eof())
	{
		// Arvind, you have not implemented the builder pattern correctly. The
		// client should not have any logic related to the build process, such as
		// keeping track of the stack of operands. Instead, the concrete builder
		// should be responsible maintaining that information. Please fix your
		// design such that the client just class the correct build method on the
		// builder for each token that it extracts from the input. The client
		// (i.e., this method) should not have a stack or any state pertaining to
		// how the build process should work.

		// Dr.Hill, I have moved the stack of operands to the builder. Now, the client 
		// calls the correct build method for the particular token extracted from the 
		// input. The Expression Evaluator does not have any stack or state pertaining 
		// to how the build process should work.

		count++;
		input >> token;

		// if the token is an operator then create the particular nodes.
		// pushes the particular operator string onto string stack.
		if (is_operator(token))
		{
			// if token is a unary operator, build unary operand.
			if (is_unary(token,token_previous,count))
			{
				builder.build_unary_operand();
			}
			// check for the tokens and previous token should not be an operator and build the operands accordingly.
			else
			{
				if (token=="+" && (!(is_operator(token_previous))))
				{
					builder.build_add_operand();
				}
				else if (token=="-" && (!(is_operator(token_previous))))
				{
					builder.build_subtract_operand();
				}
				else if (token=="*" && (!(is_operator(token_previous))))
				{
					builder.build_multiply_operand();
				}
				else if (token=="/" && (!(is_operator(token_previous))))
				{
					builder.build_divide_operand();
				}
				else if (token=="%"  && (!(is_operator(token_previous))))
				{
					builder.build_modulus_operand();
				}
				// if current token is operator (+, *, / and %) and previous token is also
				// an operator then expression is invalid.
				else
				{
					throw std::runtime_error("Invalid Expression");
				}
			}
		}
		// if token is equal to left parenthesis build left parenthesis
		// for both parenthesis decrement count. 
		else if (token=="(")
		{
			builder.build_left_parenthesis();
			count--;
		}
		// if token is equal to right parenthesis build right parenthesis
		else if (token==")")
		{
			builder.build_right_parenthesis();
			count--;
		}
		// check if the token is a number.
		else
		{
			// create value variable to store the integer.
			int value=0;
			// if the token is a number then build number node otherwise it is 
			// an invalid expression.
			if(is_number(token,count,token_previous,value))
			{
				builder.build_number(value);
			}
			else
			{
				throw std::runtime_error("Invalid Expression");
			}
		}
		token_previous=token;
	}
	// if only one token is passed then it is an invalid expression. 
	if (count<=1)
	{
		throw std::runtime_error("Invalid Expression");
	}
	return true;
}

//
// evaluate_expr (Expr_Builder &, int &)
//
void Expr_Evaluator::evaluate_expr (Expr_Builder & builder, int & result)
{
	// declare evaluate expression tree class to pass in accept for Visitor Pattern
	// by calling accept after getting expression.
	Eval_Expr_Tree evaluate;
	Expr_Node * expr=builder.get_expression();
	expr->accept(evaluate);
	result=evaluate.result();
}

//
// is_number (const std::string &, size_t &, std::string &, int &)
//
bool Expr_Evaluator::is_number (const std::string & token, size_t & count, std::string & token_previous, int & value) const
{
	// make num_temp_1 contain token in istringstream format.
	std::istringstream num_temp_1(token);
	// declare a int variable 
	int num=0;
	// if num_temp_1 i.e., the token is a number then check conditions below.
	if(!(num_temp_1 >> num).fail())
	{
		// using stringstream to convert the obtained number into a string.
		std::stringstream ss;
		ss << num;
		std::string str = ss.str();
		// now check if the token and the string are equal e.g. if 5a is token then
		// str will be 5 and it is not a valid expression.
		if(str==token)
		{
			value = atoi(token.c_str());
			// if the count is greater than 1 then check if previous token is an integer.
			if(count>1)
			{
				std::istringstream num_temp_2(token_previous);
				int num_1=0;
				// num_temp_2 is is an integer then two integers simultaneously is an invalid expression.
				if(!(num_temp_2 >> num_1).fail())
				{
					return false;
				}
			}
			return true;
		}
		// if the token is not a number but alphanumeric character.
		else
		{
			return false;
		}
	}
	// else the token is not an integer.
	else
	{
		return false;
	}
}

//
// is_expression (const std::string &)
//
bool Expr_Evaluator::is_expression (const std::string & infix) const
{
	// if input is blank expression is invalid.
	if (infix[0]=='\0')
	{
		return false;
	}
	// if the expression starts or ends with a space or if there are two
	// spaces between valid terms it is not a valid expression. Using NOR
	// i.e., expression should have no spaces at beginning or ending or both.
	if (!((infix[0]==' ') || (infix[infix.size()-1]==' ')))
	{
		// check for two spaces together.
		for (size_t i = 0; i < (infix.size()-1); i++)
		{
			// if two consecutive terms are spaces then it is not a valid expression.
			if (infix[i]==' ' && infix[i+1]==' ')
			{
				return false;
			}
		}
	}
	// expression has spaces at beginning or ending or both.
	else
	{
		return false;
	}
	// counter to count left parenthesis.
	size_t left_count=0;
	// counter to count right parenthesis.
	size_t right_count=0;
	for (size_t i = 0; i < infix.size(); i++)
	{
		// if infix string contains left parenthesis then increment left_count.
		if (infix[i]=='(')
		{
			left_count++;
		}
		// if infix string contains right parenthesis then increment right_count.
		if (infix[i]==')')
		{
			right_count++;
		}
	}
	// if the left and right parenthesis count are not equal then return false,
	// expression is invalid.
	if (left_count!=right_count)
	{
		return false;
	}
	return true;
}

//
// is_unary (std::string &,std::string &, size_t &)
//
bool Expr_Evaluator::is_unary (std::string & token,std::string & token_previous, size_t & count)
{
	// if an operator is passed first and it is -, then it is a unary operator.
	if (count==1 && token=="-")
	{
		return true;
	}
	// if the previous token is an operator or an left parenthesis and current is - then
	// it is a unary operator.
	else if ((is_operator(token_previous)|| token_previous=="(") && token=="-")
	{
		return true;
	}
	// if the first token passed is an operator but not -, then the exression is invalid. 
	else if (count==1 && (token=="+" || token=="*" || token=="/" || token=="%"))
	{
		throw std::runtime_error("Invalid Expression");
	}
	return false;
}
