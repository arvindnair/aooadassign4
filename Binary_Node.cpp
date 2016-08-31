//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#include <iostream>
#include "Binary_Node.h"

//
// Binary_Node
//
// Default Constructor so left and right nodes are null.
Binary_Node::Binary_Node (void)
	:left_(0),
	right_(0),
	left_null_(true),
	right_null_(true)
{}

//
// Binary_Node(Expr_Node *, Expr_Node *)
//
// Initializing the left and right nodes with passed nodes for Composite Pattern.
Binary_Node::Binary_Node (Expr_Node * node1, Expr_Node * node2)
	:left_(node1),
	right_(node2),
	left_null_(false),
	right_null_(false)
{}

//
// ~Binary_Node
//
Binary_Node::~Binary_Node (void)
{
	// if left node is not null delete left node.
	if (!this->is_left_null())
	{
		delete this->left_;
	}
	// if right node is not null delete right node.
	if (!this->is_right_null())
	{
		delete this->right_;
	}
}

//
// eval
//
// Evaluate the left and right nodes and return the result 
// after binary operation.
int Binary_Node::eval (void)
{
	int n1=0;
	int n2=0;
	if (this->left_)
	{
		n1=this->left_->eval();
	}
	// throw exception if left is null.
	else
	{
		throw std::runtime_error("Invalid Expression");
	}
	if (this->right_)
	{
		n2=this->right_->eval();
	}
	// throw exception if right is null.
	else
	{
		throw std::runtime_error("Invalid Expression");
	}
	// evaluate as per particular operation.
	int result=this->binary_eval(n1,n2);
	return result;
}

//
// is_left_null
//
// checks if left is null.
bool Binary_Node::is_left_null (void) const
{
	return this->left_null_;
}

//
// is_right_null
//
// checks if right is null.
bool Binary_Node::is_right_null (void) const
{
	return this->right_null_;
}

//
// get_left_child
//
// gets reference to left child.
Expr_Node * Binary_Node::get_left_child (void) const
{
	return this->left_;
}

//
// get_right_child
//
// gets reference to right child.
Expr_Node * Binary_Node::get_right_child (void) const
{
	return this->right_;
}

//
// change_left_node (Expr_Node *)
//
// set left child to the node passed and make the left null variable false.
void Binary_Node::change_left_node (Expr_Node * change_left)
{
	left_=change_left;
	this->change_left_null(false);
}

//
// change_right_node (Expr_Node *)
//
// set right child to the node passed and make the right null variable false.
void Binary_Node::change_right_node (Expr_Node * change_right)
{
	right_=change_right;
	this->change_right_null(false);
}

//
// get_precedence
//
// call the particular binary operator's precedence and return the result.
int Binary_Node::get_precedence (void)
{
	int i=this->get_binary_precedence();
	return i;
}

//
// change_precedence (int)
//
// calls the particular binary node's precedence
void Binary_Node::change_precedence (int increment_precedence)
{
	this->change_binary_precedence(increment_precedence);
}

//
// node_type
//
std::string Binary_Node::node_type (void)
{
	return "BINARY";
}

//
// change_left_null (bool)
//
void Binary_Node::change_left_null (bool value)
{
	left_null_=value;
}

//
// change_right_null (bool)
//
void Binary_Node::change_right_null (bool value)
{
	right_null_=value;
}