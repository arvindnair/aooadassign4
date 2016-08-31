// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include "Expr_Node_Factory.h"
#include "Tree_Expr_Node_Factory.h"

//
// Tree_Expr_Node_Factory
//
// Default Constructor.
Tree_Expr_Node_Factory::Tree_Expr_Node_Factory (void)
{}

//
// ~Tree_Expr_Node_Factory
//
// Destructor.
Tree_Expr_Node_Factory::~Tree_Expr_Node_Factory (void)
{}

//
// create num Node
//
// returns a Num Node object.
Number_Node *  Tree_Expr_Node_Factory::create_number_node (int num)
{
	return new Number_Node(num);
}

//
// create num Node
//
// returns a Unary Node object using default constructor.
Unary_Node * Tree_Expr_Node_Factory::create_unary_node (void)
{
	return new Unary_Node();
}

//
// create add Node
//
// returns a Add Node object using default constructor.
Add_Node * Tree_Expr_Node_Factory::create_add_node (void)
{
	return new Add_Node();
}

//
// create subtract Node
//
// returns a Subtract Node object using default constructor.
Subtract_Node * Tree_Expr_Node_Factory::create_subtract_node (void)
{
	return new Subtract_Node();
}

//
// create multiply Node
//
// returns a Multiply Node object using default constructor.
Multiply_Node * Tree_Expr_Node_Factory::create_multiply_node (void)
{
	return new Multiply_Node();
}

//
// create divide Node
//
// returns a Divide Node object using default constructor.
Divide_Node * Tree_Expr_Node_Factory::create_divide_node (void)
{
	return new Divide_Node();
}

//
// create modulus Node
//
// returns a Modulus Node object using default constructor.
Modulus_Node * Tree_Expr_Node_Factory::create_modulus_node (void)
{
	return new Modulus_Node();
}

