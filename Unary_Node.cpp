//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#include "Unary_Node.h"
#include "Expr_Node_Visitor.h"

//
// Unary_Node
//
// Default constructor and child is null.
Unary_Node::Unary_Node (void)
	:child_(0),
	child_null_(true),
	unary_precedence_(3)
{}

//
// Unary_Node (Expr_Node * )
//
// Initialize child with passed node for Composite Pattern.
Unary_Node::Unary_Node (Expr_Node * node1)
	:child_(node1),
	child_null_(false),
	unary_precedence_(3)
{}

//
// ~Unary_Node
//
// If child node is not null, delete child.
Unary_Node::~Unary_Node (void)
{
	if (!is_child_null())
	{
		delete child_;
	}
}

//
// eval
//
// Evaluate the child and then return the result after unary operation.
int Unary_Node::eval (void)
{
	int n1=0;
	if (this->child_)
	{
		n1=this->child_->eval();
	}
	// if child is null throw exception.
	else
	{
		throw std::runtime_error("Invalid Expression");
	}
	// performing unary by subtraction (minus).
	int result=0-n1;
	return result;
}

//
// is_child_null
//
// check if child is null.
bool Unary_Node::is_child_null (void) const
{
	return child_null_;
}

//
// get_child
//
// get the child reference.
Expr_Node * Unary_Node::get_child (void) const
{
	return child_;
}

//
// change_child_node (Expr_Node * )
//
// set child to the node passed and make the child null variable false.
void Unary_Node::change_child_node (Expr_Node * change_child)
{
	child_=change_child;
	this->change_child_null(false);
}

//
// accept
//
// accept method for visitor pattern to visit unary node.
void Unary_Node::accept (Expr_Node_Visitor & v)
{
	v.Visit_Unary_Node(*this);
}

//
// get_precedence
//
int Unary_Node::get_precedence (void)
{
	return unary_precedence_;
}

//
// change_precedence (int )
//
// adds the value of precedence to be incremented.
void Unary_Node::change_precedence (int increment_precedence)
{
	unary_precedence_=unary_precedence_+increment_precedence;
}

//
// node_type
//
std::string Unary_Node::node_type (void)
{
	return "UNARY";
}

//
// change_child_null (bool )
//
void Unary_Node::change_child_null (bool value)
{
	child_null_=value;
}