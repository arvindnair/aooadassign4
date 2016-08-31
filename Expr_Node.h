//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EXPR_NODE_H_
#define _EXPR_NODE_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>

/// Forward Declaration of Expr_Node_Visitor class.
class Expr_Node_Visitor;

/**
* @class Expr_Node
*
* Basic implementation of Expr_Node.
*/
class Expr_Node
{
public:

	/// Default constructor.
	Expr_Node (void);

	/// Destructor.
	virtual ~Expr_Node (void);

	/**
	* Eval method using Composite Pattern for particular nodes.
	* It is a pure virtual function.
	* 
	* @return         Result of Evaluation for particular nodes.
	*/
	virtual int eval (void) = 0;

	/**
	* Returns the precedence for the Expression Node.
	*
	* @return         Expression Node's Precedence.
	*/
	virtual int get_precedence()=0;

	/**
	* Increases the precedence of the Expression Node based on operations.
	* It is a pure virtual function.
	*
	* @param[in]        increment_precedence           Value to increase precedence.
	*/
	virtual void change_precedence(int increment_precedence)=0;

	/**
	* It is used to indicate the type of node.
	*
	* @return          String to indicate the type of node.
	*/
	virtual std::string node_type()=0;

	/**
	* Accept method for all Nodes. It is pure virtual function.
	*
	* @param[in]        v           Expr_Node_Visitor reference.
	*/
	virtual void accept (Expr_Node_Visitor & v) = 0;

private:

	/// Copy Constructor.
	Expr_Node (const Expr_Node &);

	/// Assignment Operator.
	const Expr_Node & operator = (const Expr_Node &);

};

#endif // !_EXPR_NODE_H_




