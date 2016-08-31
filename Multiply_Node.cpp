//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#include <iostream>
#include "Expr_Node_Visitor.h"
#include "Multiply_Node.h"

//
// Multiply_Node
//
// Using Binary Node's default constructor.
Multiply_Node::Multiply_Node (void)
	:Binary_Node(),
	multiply_precedence_(2)
{}

//
// Multiply_Node ( Expr_Node *, Expr_Node *)
//
// Using Binary Node's initializing constructor for Composite Pattern.
Multiply_Node::Multiply_Node (Expr_Node * node1, Expr_Node * node2)
	:Binary_Node(node1,node2),
	multiply_precedence_(2)
{}

//
// ~Multiply_Node
//
// if the nodes left and right are not null delete them.
Multiply_Node::~Multiply_Node (void)
{
	// Arvind, you should let the binary node handle this since it is responsible
	// for managing the left/right nodes. Right now, you are duplicate a LOT of the
	// code for deleting the left/right nodes in each concrete class.

	// Dr.Hill, I have put the deletion of the left and right nodes in the Binary
	// Node class. Hence, I removed the duplication of code from the Multiply Node.
}

//
// binary_eval (int, int)
//
// returns multiplication of n1 and n2.
int Multiply_Node::binary_eval (int n1, int n2)
{
	return n1*n2;
}

//
// accept (Expr_Node_Visitor &)
//
// accept method for visitor pattern to visit multiplication node.
void Multiply_Node::accept (Expr_Node_Visitor & v)
{
	v.Visit_Multiplication_Node(*this);
}

//
// get_binary_precedence
//
int Multiply_Node::get_binary_precedence (void)
{
	return multiply_precedence_;
}

//
// change_binary_precedence (int )
//
// adds the value of precedence to be incremented.
void Multiply_Node::change_binary_precedence (int increment_precedence)
{
	multiply_precedence_=multiply_precedence_+increment_precedence;
}