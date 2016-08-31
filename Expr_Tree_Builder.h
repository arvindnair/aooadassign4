//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EXPR_TREE_BUILDER_H_
#define _EXPR_TREE_BUILDER_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include "Stack.h"
#include "Expr_Builder.h"
#include "Tree_Expr_Node_Factory.h"

/**
* @class Expr_Tree_Builder
*
* Basic implementation of Expr_Tree_Builder.
*/
class Expr_Tree_Builder : public Expr_Builder
{
public:

	/// Default constructor.
	Expr_Tree_Builder (void);

	/// Destructor.
	virtual ~Expr_Tree_Builder (void);

	/**
	* Used to initialize the build process.
	* 
	*/
	virtual void build_expression (void);

	/**
	* Used to build a number node. Push the number node after 
	* creation from passed value onto stack.
	* 
	* @param[in]      n            Number passed.
	*/
	virtual void build_number (int n);

	/**
	* Used to build a unary node. It first creates a Unary node and changes 
	* its precedence and then pushes the unary node onto the operator  
	* stack.
	*
	*/
	virtual void build_unary_operand (void);

	/**
	* Used to build an addition node. It first creates an Add Node and  
	* then calls the push binary operand function for further operations.
	*
	*/
	virtual void build_add_operand (void);

	/**
	* Used to build an subtraction node. It first creates a Subtract Node and  
	* then calls the push binary operand function for further operations.
	*
	*/
	virtual void build_subtract_operand (void);

	/**
	* Used to build an multiplication node. It first creates a Multiply Node and  
	* then calls the push binary operand function for further operations.
	*
	*/
	virtual void build_multiply_operand (void);

	/**
	* Used to build an division node. It first creates a Divide Node and  
	* then calls the push binary operand function for further operations.
	*
	*/
	virtual void build_divide_operand (void);

	/**
	* Used to build an modulus node. It first creates a Modulus Node and  
	* then calls the push binary operand function for further operations.
	*
	*/
	virtual void build_modulus_operand (void);

	/**
	* Increases the precedence of the nodes created after open/left parenthesis is encountered.
	*
	*/
	virtual void build_left_parenthesis (void);

	/**
	* Decreases the precedence of the nodes created after closed/right parenthesis is encountered.
	*
	*/
	virtual void build_right_parenthesis (void);

	/**
	* Used to get reference to the tree. It first pops the nodes from the operator
	* stack, calling the change node function. Finally the node stack will have only
	* one node which will contain the whole expression tree. the tree variable is 
	* assigned reference to this node and this node is popped from the node stack.
	*
	* @return         Reference of tree built.
	*/
	virtual Expr_Node * get_expression (void);

private:

	/// Copy Constructor.
	Expr_Tree_Builder (const Expr_Tree_Builder &);

	/// Assignment Operator.
	const Expr_Tree_Builder & operator = (const Expr_Tree_Builder &);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// DEFINE ANY HELPER METHODS HERE

	/**
	* Pops the first node from the stack and returns it.
	*
	* @return         The first node popped from stack.
	* @exception      std::runtime_error       Invalid Expression
	*/
	Expr_Node * stack_first_node (void);

	/**
	* Pops the second node from the stack and returns it.
	*
	* @param[in]      node1                    First node from stack
	* @return         The second node popped from stack.
	* @exception      std::runtime_error       Invalid Expression
	*/
	Expr_Node * stack_second_node (Expr_Node * node1);

	/**
	* It checks whether the node passed can be pushed onto the operator stack. If the 
	* node passed has lower precedence than those in the operator stack, then the node
	* from operator stack is popped and its children are changed and added to the node
	* stack for the tree generation. This continues till the operator stack is empty or 
	* a lower precedence node is encountered upon which it returns true.
	*
	* @param[in]      node1                    First node from stack
	* @retval         true                     Passed node can be pushed on operator stack.
	* @exception      std::runtime_error       Invalid Expression
	*/
	bool check_stack_status (Expr_Node * node1);

	/**
	* It changes the left and right node if the passed node is binary node and if it 
	* is unary node then changes its child using dynamic cast and node type function of
	* the nodes. It pops (one if unary and two if binary) elements from the node stack
	* to attach to the current node passed and finally push the current node to the node
	* stack.
	*
	* @param[in]      node1                    Node whose children are to be set.
	*/
	void change_operator_node (Expr_Node * node1);

	/**
	* It is the common funcion for all binary nodes to avoid code duplication. It first increases
	* the precedence as per the precedence factor for open and closed parenthesis. Then it will
	* check if the node can be pushed onto the operator stack and once the check is done, the 
	* particular binary node is pushed onto the operator stack.
	*
	* @param[in]      node1                    Node which is to be pushed to operator stack.
	*/
	void push_binary_operator (Expr_Node * node1);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// The Expression Node tree.
	Expr_Node * tree_;

	// A stack of Expression Nodes to store the nodes for tree generation.  
	Stack <Expr_Node*> node_stack_;

	// A stack of Expression nodes to store the operator nodes.
	Stack <Expr_Node*> op_stack_;

	// A variable to check if delete is necessary.
	bool delete_flag;

	// A tree expression node factory object.
	Tree_Expr_Node_Factory factory;

	// Used to increment the precedence for each and every node as per parenthesis.
	int precedence_factor_;

};


#endif // !_EXPR_TREE_BUILDER_H_
