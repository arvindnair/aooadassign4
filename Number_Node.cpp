//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#include <iostream>
#include "Number_Node.h"
#include "Expr_Node_Visitor.h"

//
// Number_Node
//
// Default Constructor.
Number_Node::Number_Node (void)
	:number_precedence_(4)
{}

//
// Number_Node (int)
//
// Store the number passed in a variable n_.
Number_Node::Number_Node (int n)
	:n_(n),
	number_precedence_(4)
{}

//
// ~Number_Node
//
// Destructor.
Number_Node::~Number_Node (void)
{}

//
// eval
//
// Returns the stored number.
int Number_Node::eval (void)
{
	return n_;
}

//
// get_value
//
// Returns the stored number.
int Number_Node::get_value (void) const
{
	return n_;
}

//
// accept (Expr_Node_Visitor &)
//
// accept method for visitor pattern to visit number node.
void Number_Node::accept (Expr_Node_Visitor & v)
{
	v.Visit_Number_Node(*this);
}

//
// get_precedence
//
int Number_Node::get_precedence (void)
{
	return number_precedence_;
}

//
// change_precedence (int )
//
// adds the value of precedence to be incremented.
void Number_Node::change_precedence (int increment_precedence)
{
	number_precedence_=number_precedence_+increment_precedence;
}

//
// node_type
//
std::string Number_Node::node_type (void)
{
	return "NUMBER";
}