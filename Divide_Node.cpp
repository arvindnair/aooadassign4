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
#include "Divide_Node.h"

//
// Divide_Node
//
// Using Binary Node's default constructor.
Divide_Node::Divide_Node (void)
	:Binary_Node(),
	divide_precedence_(2)
{}

//
// Divide_Node ( Expr_Node *, Expr_Node *)
//
// Using Binary Node's initializing constructor for Composite Pattern.
Divide_Node::Divide_Node (Expr_Node * node1, Expr_Node * node2)
	:Binary_Node (node1,node2),
	divide_precedence_(2)
{}

//
// ~Divide_Node
//
// if the nodes left and right are not null delete them.
Divide_Node::~Divide_Node (void)
{
	// Arvind, you should let the binary node handle this since it is responsible
	// for managing the left/right nodes. Right now, you are duplicate a LOT of the
	// code for deleting the left/right nodes in each concrete class.

	// Dr.Hill, I have put the deletion of the left and right nodes in the Binary
	// Node class. Hence, I removed the duplication of code from the Divide Node.
}

//
// binary_eval (int, int)
//
// returns division of n1 and n2.
int Divide_Node::binary_eval (int n1, int n2)
{
	// If divide by zero occurs then throw exception.
	if (n2==0)
	{
		throw std::runtime_error("Division By Zero : Undefined");
	}
	return n1/n2;
}

//
// accept (Expr_Node_Visitor &)
//
// accept method for visitor pattern to visit division node.
void Divide_Node::accept (Expr_Node_Visitor & v)
{
	v.Visit_Division_Node(*this);
}

//
// get_binary_precedence
//
int Divide_Node::get_binary_precedence (void)
{
	return divide_precedence_;
}

//
// change_binary_precedence (int)
//
// adds the value of precedence to be incremented.
void Divide_Node::change_binary_precedence (int increment_precedence)
{
	divide_precedence_=divide_precedence_+increment_precedence;
}