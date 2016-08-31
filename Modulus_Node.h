//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _MODULUS_NODE_H_
#define _MODULUS_NODE_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include "Binary_Node.h"

/**
* @class Modulus_Node
*
* Basic implementation of Modulus_Node.
*/
class Modulus_Node : public Binary_Node
{
public:

	/// Default constructor.
	Modulus_Node (void);

	/**
	* Initializing constructor.
	*
	* @param[in]      node1        First Node
	* @param[in]      node2        Second Node
	*/
	Modulus_Node (Expr_Node * node1, Expr_Node * node2);

	/// Destructor.
	virtual ~Modulus_Node (void);

	/**
	* Evaluation for Modulus Operation.
	*
	* @param[in]      n1           First Node
	* @param[in]      n2           Second Node
	* @return         Result of Evaluation for  Modulus.
	* @exception      std::runtime_error   Modulus By Zero : Undefined
	*/
	virtual int binary_eval (int n1,int n2);

	/**
	* Accept method for  Modulus Node.
	*
	* @param[in]        v           Expr_Node_Visitor reference.
	*/
	virtual void accept (Expr_Node_Visitor & v);

	/**
	* Returns the precedence for Modulus Node.
	*
	* @return         Modulus Node Precedence.
	*/
	virtual int get_binary_precedence (void);

	/**
	* Increases the precedence of the Modulus Node based on operations.
	*
	* @param[in]        increment_precedence           Value to increase precedence.
	*/
	virtual void change_binary_precedence (int increment_precedence);

private:

	/// Copy Constructor.
	Modulus_Node (const Modulus_Node &);

	/// Assignment Operator.
	const Modulus_Node & operator = (const Modulus_Node &);

	// Variable to store the Modulus Node's precedence.
	int modulus_precedence_;

};



#endif // !_MODULUS_NODE_H_
