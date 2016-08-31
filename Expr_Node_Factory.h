//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EXPR_NODE_FACTORY_H_
#define _EXPR_NODE_FACTORY_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include "Expr_Node.h"
#include "Number_Node.h"
#include "Unary_Node.h"
#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Modulus_Node.h"
#include "Binary_Node.h"

/**
* @class Expr_Node_Factory
*
* Basic implementation of Expr_Node_Factory.
*/
class Expr_Node_Factory
{
public:

	/// Default constructor.
	Expr_Node_Factory (void);

	/// Destructor.
	virtual ~Expr_Node_Factory (void) = 0;

	/**
	* Creates and returns a new Number Node object.  
	*
	* @return         New Number Node object.
	*/
	virtual Number_Node * create_number_node (int num) = 0;

	/**
	* Creates and returns a new Unary Node object.  
	*
	* @return         New Unary Node object.
	*/
	virtual Unary_Node * create_unary_node (void) = 0;

	/**
	* Creates and returns a new Addition Node object.  
	*
	* @return         New Addition Node object.
	*/
	virtual Add_Node * create_add_node (void) = 0;

	/**
	* Creates and returns a new Subtract Node object.  
	*
	* @return         New Subtraction Node object.
	*/
	virtual Subtract_Node * create_subtract_node (void) = 0;

	/**
	* Creates and returns a new Multiply Node object.  
	*
	* @return         New Multiply Node object.
	*/
	virtual Multiply_Node * create_multiply_node (void) = 0;

	/**
	* Creates and returns a new Divide Node object.  
	*
	* @return         New Divide Node object.
	*/
	virtual Divide_Node * create_divide_node (void) = 0;

	/**
	* Creates and returns a new Modulus Node object.  
	* 
	* @return         New Modulus Node object.
	*/
	virtual Modulus_Node * create_modulus_node (void) = 0;

private:

	/// Copy Constructor.
	Expr_Node_Factory (const Expr_Node_Factory &);

	/// Assignment Operator.
	const Expr_Node_Factory & operator = (const Expr_Node_Factory &);
};

#endif // !_EXPR_Node_FACTORY_H_
