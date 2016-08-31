//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _DIVIDE_NODE_H_
#define _DIVIDE_NODE_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include "Binary_Node.h"

/**
* @class Divide_Node
*
* Basic implementation of Divide_Node.
*/
class Divide_Node : public Binary_Node
{
public:

	/// Default constructor.
	Divide_Node (void);

	/**
	* Initializing constructor.
	*
	* @param[in]      node1        First Node
	* @param[in]      node2        Second Node
	*/
	Divide_Node (Expr_Node * node1, Expr_Node * node2);

	/// Destructor.
	virtual ~Divide_Node (void);

	/**
	* Evaluation for Division Operation.
	*
	* @param[in]      n1           First Node
	* @param[in]      n2           Second Node
	* @return         Result of Evaluation for  Division.
	* @exception      std::runtime_error   Division By Zero : Undefined
	*/
	virtual int binary_eval (int n1,int n2);

	/**
	* Accept method for Division Node.
	*
	* @param[in]        v           Expr_Node_Visitor reference.
	*/
	virtual void accept (Expr_Node_Visitor & v);

	/**
	* Returns the precedence for Division Node.
	*
	* @return         Divide Node Precedence.
	*/
	virtual int get_binary_precedence (void);

	/**
	* Increases the precedence of the Divide Node based on operations.
	*
	* @param[in]        increment_precedence           Value to increase precedence.
	*/
	virtual void change_binary_precedence (int increment_precedence);

private:

	/// Copy Constructor.
	Divide_Node (const Divide_Node &);

	/// Assignment Operator.
	const Divide_Node & operator = (const Divide_Node &);

	// Variable to store the Divide Node's precedence.
	int divide_precedence_;

};



#endif // !_DIVIDE_NODE_H_
