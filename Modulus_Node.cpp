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
#include "Modulus_Node.h"

//
// Modulus_Node
//
// Using Binary Node's default constructor.
Modulus_Node::Modulus_Node (void)
	:Binary_Node(),
	modulus_precedence_(2)
{}

//
// Modulus_Node ( Expr_Node *, Expr_Node *)
//
// Using Binary Node's initializing constructor for Composite Pattern.
Modulus_Node::Modulus_Node (Expr_Node * node1, Expr_Node * node2)
	:Binary_Node(node1,node2),
	modulus_precedence_(2)
{}

//
// ~Modulus_Node
//
// if the nodes left and right are not null delete them.
Modulus_Node::~Modulus_Node (void)
{
	// Arvind, you should let the binary node handle this since it is responsible
	// for managing the left/right nodes. Right now, you are duplicate a LOT of the
	// code for deleting the left/right nodes in each concrete class.

	// Dr.Hill, I have put the deletion of the left and right nodes in the Binary
	// Node class. Hence, I removed the duplication of code from the Modulus Node.
}

//
// binary_eval (int, int)
//
// returns modulus of n1 and n2.
int Modulus_Node::binary_eval (int n1, int n2)
{
	// if the second element is zero then throw exception as modulus
	// by zero is undefined.
	if (n2==0)
	{
		throw std::runtime_error("Modulus By Zero : Undefined");
	}
	return n1%n2;
}

//
// accept (Expr_Node_Visitor &)
//
// accept method for visitor pattern to visit modulus node.
void Modulus_Node::accept (Expr_Node_Visitor & v)
{
	v.Visit_Modulus_Node(*this);
}

//
// get_binary_precedence
//
int Modulus_Node::get_binary_precedence (void)
{
	return modulus_precedence_;
}

//
// change_binary_precedence (int )
//
// adds the value of precedence to be incremented.
void Modulus_Node::change_binary_precedence (int increment_precedence)
{
	modulus_precedence_=modulus_precedence_+increment_precedence;
}