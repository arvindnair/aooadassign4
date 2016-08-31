//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _MULTIPLY_NODE_H_
#define _MULTIPLY_NODE_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include "Binary_Node.h"

/**
* @class Multiply_Node
*
* Basic implementation of Multiply_Node.
*/
class Multiply_Node : public Binary_Node
{
public:

	/// Default constructor.
	Multiply_Node (void);

	/**
	* Initializing constructor.
	*
	* @param[in]      node1        First Node
	* @param[in]      node2        Second Node
	*/
	Multiply_Node (Expr_Node * node1, Expr_Node * node2);

	/// Destructor.
	virtual ~Multiply_Node (void);

	/**
	* Evaluation for Multiplication Operation.
	*
	* @param[in]      n1           First Node
	* @param[in]      n2           Second Node
	* @return         Result of Evaluation for Multiplication.
	*/
	virtual int binary_eval (int n1,int n2);

	/**
	* Accept method for Multiplication Node.
	*
	* @param[in]        v           Expr_Node_Visitor reference.
	*/
	virtual void accept (Expr_Node_Visitor & v);

	/**
	* Returns the precedence for Multiplication Node.
	*
	* @return         Multiply Node Precedence.
	*/
	virtual int get_binary_precedence();

	/**
	* Increases the precedence of the Multiply Node based on operations.
	*
	* @param[in]        increment_precedence           Value to increase precedence.
	*/
	virtual void change_binary_precedence(int increment_precedence);

private:

	/// Copy Constructor.
	Multiply_Node (const Multiply_Node &);

	/// Assignment Operator.
	const Multiply_Node & operator = (const Multiply_Node &);

	// Variable to store the Multiply Node's precedence.
	int multiply_precedence_;

};

#endif // !_MULTIPLY_NODE_H_
