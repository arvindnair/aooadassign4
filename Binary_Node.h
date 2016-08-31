//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _BINARY_NODE_H_
#define _BINARY_NODE_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include "Expr_Node.h"

/**
* @class Binary_Node
*
* Basic implementation of Binary_Node.
*/
class Binary_Node : public Expr_Node
{
public:

	/// Default constructor.
	Binary_Node (void);

	/**
	* Initializing constructor.
	*
	* @param[in]      node1        First Node
	* @param[in]      node2        Second Node
	*/
	Binary_Node(Expr_Node * node1, Expr_Node * node2);

	/// Destructor.
	virtual ~Binary_Node (void);

	/**
	* Eval method using Composite Pattern for Binary Operations.
	*
	* 
	* @return         Result of Evaluation for Binary Operations.
	*/
	virtual int eval (void);

	/**
	* Binary Eval method for particular Binary Operations.
	* It is a pure virtual function.
	* 
	* @return         Result of Evaluation for Binary Operations.
	* @exception      std::runtime_error    Invalid Expression.
	*/
	virtual int binary_eval (int n1, int n2) = 0;

	/**
	* Checks if left child is null.
	*
	* @retval         true          The left child is null.
	* @retval         false         The left child is not null.
	*/
	virtual bool is_left_null (void) const;

	/**
	* Checks if right child is null. 
	*
	* @retval         true          The right child is null.
	* @retval         false         The right child is not null.
	*/
	virtual bool is_right_null (void) const;

	/**
	* Returns reference of left child.
	*
	* @return         Reference of left child.
	*/
	virtual Expr_Node * get_left_child (void) const;

	/**
	* Returns reference of right child.
	*
	* @return         Reference of right child.
	*/
	virtual Expr_Node * get_right_child (void) const;

	/**
	* Used to set/change the left child of the binary node.
	*
	* @param[in]        change_left           Node to put as left.
	*/
	virtual void change_left_node (Expr_Node * change_left);

	/**
	* Used to set/change the right child of the binary node.
	*
	* @param[in]        change_right           Node to put as right.
	*/
	virtual void change_right_node (Expr_Node * change_right);

	/**
	* Returns the precedence for the Binary Node.
	*
	* @return         Binary Node's Precedence.
	*/
	virtual int get_precedence (void);

	/**
	* Increases the precedence of the Binary Node based on operations.
	*
	* @param[in]        increment_precedence           Value to increase precedence.
	*/
	virtual void change_precedence (int increment_precedence);

	/**
	* Returns the precedence for the particular Binary Node.
	* It is pure virtual function.
	*
	* @return         Binary Node's Precedence.
	*/
	virtual int get_binary_precedence (void) = 0;

	/**
	* Increases the precedence of the particular Binary Node based on operations.
	* It is pure virtual function.
	*
	* @param[in]        increment_precedence           Value to increase precedence.
	*/
	virtual void change_binary_precedence (int add_precedence) = 0;

	/**
	* It is used to indicate the type of node which in this case is Binary.
	*
	* @retval          BINARY                  String to indicate node.
	*/
	virtual std::string node_type (void);

	/**
	* Accept method for Binary Operation.
	*
	* @param[in]        v           Expr_Node_Visitor reference.
	*/
	virtual void accept (Expr_Node_Visitor & v) = 0;

protected:

	/// Copy Constructor.
	Binary_Node (const Binary_Node &);

	/// Assignment Operator.
	const Binary_Node & operator = (const Binary_Node &);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// DEFINE ANY HELPER METHODS HERE

	/**
	* Used to set/change the left null variable of the binary node to indicate that
	* its left child exists. Set internally by the change left node function.
	*
	* @param[in]        value           True or False if the left child exists or not.
	*/
	virtual void change_left_null (bool value);

	/**
	* Used to set/change the right null variable of the binary node to indicate that
	* its right child exists. Set internally by the change right node function.
	*
	* @param[in]        value           True or False if the right child exists or not.
	*/
	virtual void change_right_null (bool value);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Left Child
	Expr_Node * right_;

	// Right Child
	Expr_Node * left_;

	// Variable to check if left child is null.
	bool left_null_;

	// Variable to check if right child is null.
	bool right_null_;

};

#endif // !_BINARY_NODE_H_
