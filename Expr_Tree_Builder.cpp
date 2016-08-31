//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#include <iostream>
#include "Expr_Tree_Builder.h"

#define INCREASE_PRECEDENCE 10                // To increase the precedence_factor by 10 for incoming nodes after left parenthesis.
#define DECREASE_PRECEDENCE -10               // To decrease the precedence_factor by 10 for incoming nodes after right parenthesis.

//
// Expr_Tree_Builder
//
// set the variables of tree and precedence to zero hence delete flag is false.
Expr_Tree_Builder::Expr_Tree_Builder (void)
	:tree_(0),
	delete_flag(false),
	precedence_factor_(0)
{}

//
// ~Expr_Tree_Builder
//
// If the delete flag is true then if the node stack is not empty
// delete its objects and if tree is not zero delete tree.
Expr_Tree_Builder::~Expr_Tree_Builder (void)
{
	// If the delete flag is true then delete objects.
	if (delete_flag)
	{
		// if the node stack is not empty, delete its objects.
		while (!node_stack_.is_empty())
		{
			Expr_Node * exprtemp=node_stack_.top();
			node_stack_.pop();
			delete exprtemp;
		}
		// if the operator stack is not empty, delete its objects.
		while (!op_stack_.is_empty())
		{
			Expr_Node * exprtemp=op_stack_.top();
			op_stack_.pop();
			delete exprtemp;
		}
		// if tree is not zero, delete tree.
		if (this->tree_!=0)
		{
			delete this->tree_;
		}
	}
}

//
// build_expression
//
// initialize the tree to a temporary number node and set delete
// flag to true.
void Expr_Tree_Builder::build_expression (void)
{
	this->tree_=factory.create_number_node(0);
	delete_flag=true;
}

//
// build_number (int)
//
// Push the number node after creation from passed value onto node stack. 
void Expr_Tree_Builder::build_number (int n)
{
	Expr_Node * n1=factory.create_number_node(n);
	n1->change_precedence(precedence_factor_);
	node_stack_.push(n1);
}

//
// build_unary_operand
//
// Creates a unary node, changes its precedence as per precedence factor and 
// pushes onto the operator stack.
void Expr_Tree_Builder::build_unary_operand (void)
{
	Expr_Node * op_node=factory.create_unary_node();
	op_node->change_precedence(precedence_factor_);
	op_stack_.push(op_node);
}

//
// build_add_operand
//
// Creates an Add Node and calls push binary operator function.
void Expr_Tree_Builder::build_add_operand (void)
{
	Expr_Node * op_node=factory.create_add_node();
	push_binary_operator(op_node);
}

//
// build_subtract_operand
//
// Creates a Subtract Node and calls push binary operator function.
void Expr_Tree_Builder::build_subtract_operand (void)
{
	Expr_Node * op_node=factory.create_subtract_node();
	push_binary_operator(op_node);
}

//
// build_multiply_operand
//
// Creates a Multiply Node and calls push binary operator function.
void Expr_Tree_Builder::build_multiply_operand (void)
{
	Expr_Node * op_node=factory.create_multiply_node();
	push_binary_operator(op_node);
}

//
// build_divide_operand
//
// Creates a Divide Node and calls push binary operator function.
void Expr_Tree_Builder::build_divide_operand (void)
{
	Expr_Node * op_node=factory.create_divide_node();
	push_binary_operator(op_node);
}

//
// build_modulus_operand
//
// Creates a Modulus Node and calls push binary operator function.
void Expr_Tree_Builder::build_modulus_operand (void)
{
	Expr_Node * op_node=factory.create_modulus_node();
	push_binary_operator(op_node);
}

//
// build_left_parenthesis
//
// increase the precedence factor.
void Expr_Tree_Builder::build_left_parenthesis (void)
{
	precedence_factor_=precedence_factor_+INCREASE_PRECEDENCE;
}

//
// build_right_parenthesis
//
// decrease the precedence factor.
void Expr_Tree_Builder::build_right_parenthesis (void)
{
	precedence_factor_=precedence_factor_+DECREASE_PRECEDENCE;
}

//
// get_expression
//
// Return reference to the tree to calculate result.
Expr_Node * Expr_Tree_Builder::get_expression (void)
{
	// pop operator stack calling change operator node function as infix expression is over.
	while (!(op_stack_.is_empty()))
	{
		Expr_Node * n1=op_stack_.top();
		change_operator_node(n1);
		op_stack_.pop();
	}
	// Expression is invalid if stack is empty or stack size is not 1.
	if (node_stack_.is_empty() || node_stack_.size()!=1)
	{
		throw std::runtime_error("Invalid Expression");
	}
	Expr_Node * exprtemp=this->tree_;
	this->tree_=node_stack_.top();
	node_stack_.pop();
	// delete the temporary assigned node of tree.
	delete exprtemp;
	return this->tree_;
}



//
// stack_first_node
//
// Return the first element popped from node stack.
Expr_Node * Expr_Tree_Builder::stack_first_node (void)
{
	if (node_stack_.is_empty())
	{
		throw std::runtime_error("Invalid Expression");
	}
	Expr_Node * n2=node_stack_.top();
	node_stack_.pop();
	return n2;
}

//
// stack_second_node (Expr_Node *)
//
// Return the second element popped from node stack.
Expr_Node * Expr_Tree_Builder::stack_second_node (Expr_Node * node1)
{
	// Delete the node (first element popped) when exception is thrown.
	if (node_stack_.is_empty())
	{
		delete node1;
		throw std::runtime_error("Invalid Expression");
	}
	Expr_Node * n1=node_stack_.top();
	node_stack_.pop();
	return n1;
}

//
// check_stack_status (Expr_Node *)
//
bool Expr_Tree_Builder::check_stack_status (Expr_Node * node1)
{
	// if operator stack is not empty and the passed node's reference is not greater than the current node
	// on top of operator stack, pop the operator stack and call change operator node for the popped node.
	while (!(op_stack_.is_empty()) && (node1->get_precedence()<=op_stack_.top()->get_precedence()))
	{
		Expr_Node * n1=op_stack_.top();
		change_operator_node(n1);
		op_stack_.pop();
	}
	return true;
}

//
// change_operator_node (Expr_Node *)
//
void Expr_Tree_Builder::change_operator_node (Expr_Node * node1)
{
	// if the node passed is binary then set its left and right as first and 
	// second node popped from the node stack and push passed node to node stack.
	if (node1->node_type()=="BINARY")
	{
		Expr_Node * n2=stack_first_node();
		Expr_Node * n1=stack_second_node(n2);
		// Using dynamic cast to Binary Node as node is of expression node type.
		Binary_Node * btemp=dynamic_cast<Binary_Node*>(node1);
		btemp->change_left_node(n1);
		btemp->change_right_node(n2);
		node_stack_.push(btemp);
	}
	// Here, the node passed is unary so set its child as first node
	// popped from the node stack and push passed node to node stack.
	else
	{
		Expr_Node * n1=stack_first_node();
		// Using dynamic cast to Unary Node as node is of expression node type.
		Unary_Node * utemp=dynamic_cast<Unary_Node*>(node1);
		utemp->change_child_node(n1);
		node_stack_.push(utemp);
	}
}

//
// push_binary_operator (Expr_Node *)
//
void Expr_Tree_Builder::push_binary_operator (Expr_Node * node1)
{
	// change the precedence as per precedence factor and when operator stack status
	// is checked push the passed node onto the operator stack.
	node1->change_precedence(precedence_factor_);
	if (check_stack_status(node1))
	{
		op_stack_.push(node1);
	}
}