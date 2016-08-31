//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#include "Expr_Node_Visitor.h"
#include "Subtract_Node.h"

//
// Subtract_Node
//
// Using Binary Node's default constructor.
Subtract_Node::Subtract_Node (void)
	:Binary_Node(),
	subtract_precedence_(1)
{}

//
// Subtract_Node ( Expr_Node *, Expr_Node *)
//
// Using Binary Node's initializing constructor for Composite Pattern.
Subtract_Node::Subtract_Node (Expr_Node * node1, Expr_Node * node2)
	:Binary_Node(node1,node2),
	subtract_precedence_(1)
{}

//
// ~Subtract_Node
//
// if the nodes left and right are not null delete them.
Subtract_Node::~Subtract_Node (void)
{
	// Arvind, you should let the binary node handle this since it is responsible
	// for managing the left/right nodes. Right now, you are duplicate a LOT of the
	// code for deleting the left/right nodes in each concrete class.

	// Dr.Hill, I have put the deletion of the left and right nodes in the Binary
	// Node class. Hence, I removed the duplication of code from the Subtract Node.
}

//
// binary_eval (int, int)
//
// returns subtraction of n1 and n2.
int Subtract_Node::binary_eval (int n1, int n2)
{
	return n1-n2;
}

//
// accept (Expr_Node_Visitor &)
//
// accept method for visitor pattern to visit subtraction node.
void Subtract_Node::accept (Expr_Node_Visitor & v)
{
	v.Visit_Subtraction_Node(*this);
}

//
// get_binary_precedence
//
int Subtract_Node::get_binary_precedence (void)
{
	return subtract_precedence_;
}

//
// change_binary_precedence (int )
//
// adds the value of precedence to be incremented.
void Subtract_Node::change_binary_precedence (int increment_precedence)
{
	subtract_precedence_=subtract_precedence_+increment_precedence;
}