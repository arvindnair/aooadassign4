//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _SUBTRACT_NODE_H_
#define _SUBTRACT_NODE_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include "Binary_Node.h"

/**
* @class Subtract_Node
*
* Basic implementation of Subtract_Node.
*/
class Subtract_Node : public Binary_Node
{
public:

	/// Default constructor.
	Subtract_Node (void);

	/**
	* Initializing constructor.
	*
	* @param[in]      node1        First Node
	* @param[in]      node2        Second Node
	*/
	Subtract_Node (Expr_Node * node1, Expr_Node * node2);

	/// Destructor.
	virtual ~Subtract_Node (void);

	/**
	* Evaluation for Subtraction Operation.
	*
	* @param[in]      n1           First Node
	* @param[in]      n2           Second Node
	* @return         Result of Evaluation for Subtraction.
	*/
	virtual int binary_eval(int n1,int n2);

	/**
	* Accept method for Subtraction Node.
	*
	* @param[in]        v           Expr_Node_Visitor reference.
	*/
	virtual void accept (Expr_Node_Visitor & v);

	/**
	* Returns the precedence for Subtraction Node.
	*
	* @return         Subtract Node Precedence.
	*/
	virtual int get_binary_precedence();

	/**
	* Increases the precedence of the Subtract Node based on operations.
	*
	* @param[in]        increment_precedence           Value to increase precedence.
	*/
	virtual void change_binary_precedence(int increment_precedence);

private:

	/// Copy Constructor.
	Subtract_Node (const Subtract_Node &);

	/// Assignment Operator.
	const Subtract_Node & operator = (const Subtract_Node &);

	// Variable to store the Subtract Node's precedence.
	int subtract_precedence_;

};

#endif // !_SUBTRACT_NODE_H_
