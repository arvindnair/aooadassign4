//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _TREE_EXPR_Node_FACTORY_H_
#define _TREE_EXPR_Node_FACTORY_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include "Expr_Node_Factory.h"

/**
* @class Tree_Expr_Node_Factory
*
* Implementation of Tree_Expr_Node_Factory.
*/
class Tree_Expr_Node_Factory : public Expr_Node_Factory
{
public:

	/// Default constructor.
	Tree_Expr_Node_Factory (void);

	/// Destructor.
	virtual ~Tree_Expr_Node_Factory (void);

	/**
	* Creates and returns a new Number Node object.  
	*
	* @return         New Number Node object.
	*/
	virtual Number_Node *  create_number_node (int num);

	/**
	* Creates and returns a new Unary Node object.  
	*
	* @return         New Unary Node object.
	*/
	virtual Unary_Node * create_unary_node (void);

	/**
	* Creates and returns a new Addition Node object.  
	*
	* @return         New Addition Node object.
	*/
	virtual Add_Node * create_add_node (void);

	/**
	* Creates and returns a new Subtract Node object.  
	*
	* @return         New Subtraction Node object.
	*/
	virtual Subtract_Node * create_subtract_node (void);

	/**
	* Creates and returns a new Multiply Node object.  
	*
	* @return         New Multiply Node object.
	*/
	virtual Multiply_Node * create_multiply_node (void);

	/**
	* Creates and returns a new Divide Node object.  
	*
	* @return         New Divide Node object.
	*/
	virtual Divide_Node * create_divide_node (void);

	/**
	* Creates and returns a new Modulus Node object.  
	*
	* @return         New Modulus Node object.
	*/
	virtual Modulus_Node * create_modulus_node (void);

private:

	/// Copy Constructor.
	Tree_Expr_Node_Factory (const Tree_Expr_Node_Factory &);

	/// Assignment Operator.
	const Tree_Expr_Node_Factory & operator = (const Tree_Expr_Node_Factory &);

};

#endif // !_TREE_EXPR_Node_FACTORY_H_
