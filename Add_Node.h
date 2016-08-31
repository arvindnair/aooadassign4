//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _ADD_NODE_H_
#define _ADD_NODE_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include "Binary_Node.h"

/**
* @class Add_Node
*
* Basic implementation of Add_Node.
*/
class Add_Node : public Binary_Node
{
public:

	/// Default constructor.
	Add_Node (void);

	/**
	* Initializing constructor.
	*
	* @param[in]      node1        First Node
	* @param[in]      node2        Second Node
	*/
	Add_Node (Expr_Node * node1, Expr_Node * node2);

	/// Destructor.
	virtual ~Add_Node (void);

	/**
	* Evaluation for Addition Operation.
	*
	* @param[in]      n1           First Node
	* @param[in]      n2           Second Node
	* @return         Result of Evaluation for Addition.
	*/
	virtual int binary_eval (int n1,int n2);

	/**
	* Accept method for Addition Node.
	*
	* @param[in]        v           Expr_Node_Visitor reference.
	*/
	virtual void accept (Expr_Node_Visitor & v);

	/**
	* Returns the precedence for Addition Node.
	*
	* @return         Add Node Precedence.
	*/
	virtual int get_binary_precedence (void);

	/**
	* Increases the precedence of the Add Node based on operations.
	*
	* @param[in]        increment_precedence           Value to increase precedence.
	*/
	virtual void change_binary_precedence (int increment_precedence);

private:

	/// Copy Constructor.
	Add_Node (const Add_Node &);

	/// Assignment Operator.
	const Add_Node & operator = (const Add_Node &);

	// Variable to store the Add Node's precedence.
	int add_precedence_;
};

#endif // !_ADD_NODE_H_
