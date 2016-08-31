//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _UNARY_NODE_H_
#define _UNARY_NODE_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include "Expr_Node.h"

/**
* @class Unary_Node
*
* Implementation of Unary_Node.
*/
class Unary_Node : public Expr_Node
{
public:

	/// Default constructor.
	Unary_Node (void);

	/**
	* Initializing constructor.
	*
	* @param[in]      node1        First Node.
	*/
	Unary_Node (Expr_Node * node1);

	/// Destructor.
	virtual ~Unary_Node (void);

	/**
	* Eval method using Composite Pattern for Unary Operations.
	*
	* @return         Result of Evaluation for Unary Operations.
	* @exception       std::runtime_error    Invalid Expression.
	*/
	virtual int eval (void);

	/**
	* Checks if child is null.
	*
	* @retval         true          The child is null.
	* @retval         false         The child is not null.
	*/
	virtual bool is_child_null (void) const;

	/**
	* Returns reference of child.
	*
	* @return         Reference of child.
	*/
	virtual Expr_Node * get_child (void) const;

	/**
	* Used to set/change the unary child of the unary node.
	*
	* @param[in]        change_child           Node to put as child.
	*/
	virtual void change_child_node (Expr_Node * change_child);

	/**
	* Accept method for Unary Node.
	*
	* @param[in]        v           Expr_Node_Visitor reference.
	*/
	virtual void accept (Expr_Node_Visitor & v);

	/**
	* Returns the precedence for Unary Node.
	*
	* @return         Unary Node Precedence.
	*/
	virtual int get_precedence (void);

	/**
	* Increases the precedence of the Unary Node based on operations.
	*
	* @param[in]       increment_precedence   Value to increase precedence.
	*/
	virtual void change_precedence (int increment_precedence);

	/**
	* It is used to indicate the type of node which in this case is Unary.
	*
	* @retval          UNARY                  String to indicate node.
	*/
	virtual std::string node_type (void);

private:

	/// Copy Constructor.
	Unary_Node (const Unary_Node &);

	/// Assignment Operator.
	const Unary_Node & operator = (const Unary_Node &);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// DEFINE ANY HELPER METHODS HERE

	/**
	* Used to set/change the child null variable of the unary node to indicate that
	* its child exists. Set internally by the change child node function.
	*
	* @param[in]        value           True or False if the child exists or not.
	*/
	virtual void change_child_null (bool value);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Child of Unary.
	Expr_Node * child_;

	// Variable to check if child is null.
	bool child_null_;

	// Variable to store the Unary Node's precedence.
	int unary_precedence_;

};


#endif // !_UNARY_NODE_H_
