//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EXPR_EVALUATOR_H_
#define _EXPR_EVALUATOR_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include <sstream>
#include "Expr_Builder.h"
#include "Expr_Tree_Builder.h"
#include "Expr_Node.h"
#include "Stack.h"

/**
* @class Expr_Evaluator
*
* Basic implementation of Expr_Evaluator.
*/
class Expr_Evaluator
{
public:

	/// Default constructor.
	Expr_Evaluator (void);

	/// Destructor.
	~Expr_Evaluator (void);

	/**
	* It take the given infix expression as string and then calculates the result
	* and returns the result to the driver.
	* 
	* @param[in]       infix                 Infix string.
	* @return          Result of the operation.
	*/
	int calculator (const std::string & infix);



private:
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// DEFINE ANY HELPER METHODS HERE

	/**
	* Parses the given infix expression and calls on the build nodes as per
	* the particular tokens encountered. If expression is not valid then 
	* std::runtime_error is thrown.
	* 
	* @param[in]       infix                 Infix string.
	* @param[in]       builder               Expression Builder.
	* @retval          true                  Operation Succeeded.
	* @exception       std::runtime_error    Invalid Expression.
	*/
	bool parse_expr (const std::string & infix, Expr_Builder & builder);

	/**
	* It evaluates the expression and stores the result. It uses the builder's 
	* get_result method to obtain result.
	* 
	* @param[in]       infix                 Infix string.
	* @param[in]       builder               Expression Builder.
	*/
	void evaluate_expr (Expr_Builder & builder, int & result);

	/**
	* Checks if the token is a token is an operator and returns true if it is an
	* operator and returns false if it is not an operator.
	* 
	* @param[in]       token                 Particular token to be checked.
	* @retval          true                  Token is an operator.
	* @retval          false                 Token is not an operator.
	*/
	bool is_operator (const std::string & token) const;

	/**
	* Checks if the token is a token is an number and returns true if it is an
	* number and returns false if it is not an number.If expression is not valid then 
	* std::runtime_error is thrown.
	* 
	* @param[in]       token                 Particular token to be checked.
	* @param[in]       count                 Counts the number of tokens.
	* @param[in]       token_previous        The previous token.
	* @param[in]       value                 The integer value of the number.
	* @retval          true                  Passed token is a number.
	* @retval          false                 Passed token is not a number.
	* @exception       std::runtime_error    Invalid Expression.
	*/
	bool is_number (const std::string & token, size_t & count, std::string & token_previous, int & value) const;

	/**
	* Checks if the token is a token is an expression and returns true if it is an
	* expression and returns false if it is not an expression.If expression is not 
	* valid then std::runtime_error is thrown.
	* 
	* @param[in]       infix                 Infix expression to be checked.
	* @retval          true                  Passed string is an expression.
	* @retval          false                 Passed string is not an expression.
	* @exception       std::runtime_error    Invalid Expression.
	*/
	bool is_expression (const std::string & infix) const;

	/**
	* Checks if the token is a token is an unary operator and returns true if it is an
	* unary and returns false if it is not an unary operator.If expression is not valid then 
	* std::runtime_error is thrown.
	* 
	* @param[in]       token                 Particular token to be checked.
	* @param[in]       count                 Counts the number of tokens.
	* @param[in]       token_previous        The previous token.
	* @retval          true                  Passed token is a unary operator.
	* @retval          false                 Passed token is not a unary operator.
	* @exception       std::runtime_error    Invalid Expression.
	*/
	bool is_unary (std::string & token,std::string & token_previous, size_t & count);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/// Copy Constructor.
	Expr_Evaluator (const Expr_Evaluator &);

	/// Assignment Operator.
	const Expr_Evaluator & operator = (const Expr_Evaluator &);

	// Stack to store operators in string format.
	Stack<std::string> op_stack_;
};

#include "Expr_Evaluator.inl"

#endif // !_EXPR_EVALUATOR_H_
