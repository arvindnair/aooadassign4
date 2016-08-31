//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EXPR_BUILDER_H_
#define _EXPR_BUILDER_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include "Expr_Node.h"
#include "Eval_Expr_Tree.h"

/**
* @class Expr_Builder
*
* Basic implementation of Expr_Builder.
*/
class Expr_Builder
{
public:

	/// Default constructor.
	Expr_Builder (void);

	/// Destructor.
	virtual ~Expr_Builder (void);

	/**
	* Used to initialize the build process. It is a pure virtual 
	* function.
	* 
	*/
	virtual void build_expression (void) = 0;

	/**
	* Used to build a number node. It is a pure virtual function.
	* 
	* @param[in]      n            Number passed.
	*/
	virtual void build_number (int n) = 0;

	/**
	* Used to build a unary node. It is a pure virtual function.
	*
	*/
	virtual void build_unary_operand (void) = 0;

	/**
	* Used to build an addition node. It is a pure virtual function.
	*
	*/
	virtual void build_add_operand (void) = 0;

	/**
	* Used to build a subtract node. It is a pure virtual function.
	*
	*/
	virtual void build_subtract_operand (void) = 0;

	/**
	* Used to build a multiply node. It is a pure virtual function.
	*
	*/
	virtual void build_multiply_operand (void) = 0;

	/**
	* Used to build a divide node. It is a pure virtual function.
	*
	*/
	virtual void build_divide_operand (void) = 0;

	/**
	* Used to build a modulus node. It is a pure virtual function.
	*
	*/
	virtual void build_modulus_operand (void) = 0;

	/**
	* Increases the precedence of the nodes created after open/left parenthesis is encountered. 
	* It is a pure virtual function.
	*
	*/
	virtual void build_left_parenthesis (void) = 0;

	/**
	* Decreases the precedence of the nodes created after closed/right parenthesis is encountered. 
	* It is a pure virtual function.
	*
	*/
	virtual void build_right_parenthesis (void) = 0;

	/**
	* Used to get reference to the structure built. It is a pure 
	* virtual function.
	*
	* @return         Reference of structure built.
	*/
	virtual Expr_Node * get_expression (void) = 0;

private:

	/// Copy Constructor.
	Expr_Builder (const Expr_Builder &);

	/// Assignment Operator.
	const Expr_Builder & operator = (const Expr_Builder &);

};

#endif // !_EXPR_BUILDER_H_
