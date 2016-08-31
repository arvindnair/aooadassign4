//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _NUMBER_NODE_H_
#define _NUMBER_NODE_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include "Expr_Node.h"

/**
* @class Number_Node
*
* Basic implementation of Number_Node.
*/
class Number_Node : public Expr_Node
{
public:

	/// Default constructor.
	Number_Node (void);

	/**
	* Initializing constructor.
	*
	* @param[in]      n            Number passed.
	*/
	Number_Node (int n);

	/// Destructor.
	virtual ~Number_Node (void);

	/**
	* Eval method using Composite Pattern for Number Node.
	*
	* 
	* @return         The number stored in the node.
	*/
	virtual int eval (void);

	/**
	* Gets the value stored in Number Node.
	*
	* 
	* @return         The number stored in the node.
	*/
	int get_value (void) const;

	/**
	* Accept method for Number Node.
	*
	* @param[in]        v           Expr_Node_Visitor reference.
	*/
	virtual void accept (Expr_Node_Visitor & v);

	/**
	* Returns the precedence for Number Node.
	*
	* @return         Number Node Precedence.
	*/
	virtual int get_precedence();

	/**
	* Increases the precedence of the Unary Node based on operations.
	*
	* @param[in]       increment_precedence    Value to increase precedence.
	*/
	virtual void change_precedence(int increment_precedence);

	/**
	* It is used to indicate the type of node which in this case is Number.
	*
	* @retval          NUMBER                  String to indicate node.
	*/
	virtual std::string node_type();

private:

	/// Copy Constructor.
	Number_Node (const Number_Node &);

	/// Assignment Operator.
	const Number_Node & operator = (const Number_Node &);

	// A variable to store the number.
	int n_;

	// Variable to store the Number Node's precedence.
	int number_precedence_;

};

#endif // !_NUMBER_NODE_H_
