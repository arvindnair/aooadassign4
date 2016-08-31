//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EXPR_NODE_VISITOR_
#define _EXPR_NODE_VISITOR_

#include "Expr_Node.h"
#include "Number_Node.h"
#include "Unary_Node.h"
#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Modulus_Node.h"

/**
* @class Expr_Node_Visitor
*
* Basic implementation of Expr_Node_Visitor.
*/
class Expr_Node_Visitor
{
public:

	/// Default constructor.
	Expr_Node_Visitor (void);

	/// Destructor.
	virtual ~Expr_Node_Visitor (void);

	/**
	* Used to visit a number node. It is a pure virtual function.
	* 
	* @param[in]      node           Number node reference passed.
	*/
	virtual void Visit_Number_Node (const Number_Node & node) = 0;

	/**
	* Used to visit a unary node. It is a pure virtual function.
	* 
	* @param[in]      node           Unary node reference passed.
	*/
	virtual void Visit_Unary_Node (const Unary_Node & node) = 0;

	/**
	* Used to visit a Addition node. It is a pure virtual function.
	* 
	* @param[in]      node           Addition node reference passed.
	*/
	virtual void Visit_Addition_Node (const Add_Node & node) = 0;

	/**
	* Used to visit a Subtraction node. It is a pure virtual function.
	* 
	* @param[in]      node           Subtraction node reference passed.
	*/
	virtual void Visit_Subtraction_Node (const Subtract_Node & node) = 0;

	/**
	* Used to visit a Multiplication node. It is a pure virtual function.
	* 
	* @param[in]      node           Multiplication node reference passed.
	*/
	virtual void Visit_Multiplication_Node (const Multiply_Node & node) = 0;

	/**
	* Used to visit a Division node. It is a pure virtual function.
	* 
	* @param[in]      node           Division node reference passed.
	*/
	virtual void Visit_Division_Node (const Divide_Node & node) = 0;

	/**
	* Used to visit a Modulus node. It is a pure virtual function.
	* 
	* @param[in]      node           Modulus node reference passed.
	*/
	virtual void Visit_Modulus_Node (const Modulus_Node & node) = 0;


private:

	/// Copy Constructor.
	Expr_Node_Visitor (const Expr_Node_Visitor &);

	/// Assignment Operator.
	const Expr_Node_Visitor & operator = (const Expr_Node_Visitor &);

};

#endif // !_EXPR_NODE_VISITOR_
