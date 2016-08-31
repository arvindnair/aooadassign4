//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#include <iostream>
#include <stdexcept>
#include <exception>
#include "Eval_Expr_Tree.h"

//
// Eval_Expr_Tree
//
// Set result to zero.
Eval_Expr_Tree::Eval_Expr_Tree (void)
	:result_(0)
{}

//
// ~Eval_Expr_Tree
//
Eval_Expr_Tree::~Eval_Expr_Tree (void)
{}

//
// Visit_Number_Node (const Number_Node &)
//
void Eval_Expr_Tree::Visit_Number_Node (const Number_Node & node)
{
	// get the number and add to result.
	int num_result=node.get_value();
	result_=result_+num_result;
}

//
// Visit_Unary_Node (const Unary_Node &)
//
void Eval_Expr_Tree::Visit_Unary_Node (const Unary_Node & node)
{
	Eval_Expr_Tree Child_Eval;
	if (node.is_child_null())
	{
		throw std::runtime_error("Invalid Expression");
	}
	// visit child and get result to perform unary and add to result.
	node.get_child()->accept(Child_Eval);
	int child_result=Child_Eval.result();
	result_=result_+(0-child_result);
}

//
// Visit_Addition_Node (const Add_Node &)
//
void Eval_Expr_Tree::Visit_Addition_Node (const Add_Node & node)
{
	Eval_Expr_Tree Left_Eval;
	if (node.is_left_null())
	{
		throw std::runtime_error("Invalid Expression");
	}
	// visit left node of Add Node
	node.get_left_child()->accept(Left_Eval);
	int left_result=Left_Eval.result();
	Eval_Expr_Tree Right_Eval;
	if (node.is_right_null())
	{
		throw std::runtime_error("Invalid Expression");
	}
	// visit right node of Add Node
	node.get_right_child()->accept(Right_Eval);
	int right_result=Right_Eval.result();
	// perform addition of left and right result and add to result.
	result_=result_+(left_result+right_result);
}

//
// Visit_Subtraction_Node (const Subtract_Node &)
//
void Eval_Expr_Tree::Visit_Subtraction_Node (const Subtract_Node & node)
{
	Eval_Expr_Tree Left_Eval;
	if (node.is_left_null())
	{
		throw std::runtime_error("Invalid Expression");
	}
	// visit left node of Subtract Node
	node.get_left_child()->accept(Left_Eval);
	int left_result=Left_Eval.result();
	Eval_Expr_Tree Right_Eval;
	if (node.is_right_null())
	{
		throw std::runtime_error("Invalid Expression");
	}
	// visit right node of Subtract Node
	node.get_right_child()->accept(Right_Eval);
	int right_result=Right_Eval.result();
	// perform subtraction of left and right result and add to result.
	result_=result_+(left_result-right_result);
}

//
// Visit_Multiplication_Node (const Multiply_Node &)
//
void Eval_Expr_Tree::Visit_Multiplication_Node (const Multiply_Node & node)
{
	Eval_Expr_Tree Left_Eval;
	if (node.is_left_null())
	{
		throw std::runtime_error("Invalid Expression");
	}
	// visit left node of Multiply Node
	node.get_left_child()->accept(Left_Eval);
	int left_result=Left_Eval.result();
	Eval_Expr_Tree Right_Eval;
	if (node.is_right_null())
	{
		throw std::runtime_error("Invalid Expression");
	}
	// visit right node of Multiply Node
	node.get_right_child()->accept(Right_Eval);
	int right_result=Right_Eval.result();
	// perform multiplication of left and right result and add to result.
	result_=result_+(left_result*right_result);
}

//
// Visit_Division_Node (const Divide_Node &)
//
void Eval_Expr_Tree::Visit_Division_Node (const Divide_Node & node)
{
	Eval_Expr_Tree Left_Eval;
	if (node.is_left_null())
	{
		throw std::runtime_error("Invalid Expression");
	}
	// visit left node of Divide node
	node.get_left_child()->accept(Left_Eval);
	int left_result=Left_Eval.result();
	Eval_Expr_Tree Right_Eval;
	if (node.is_right_null())
	{
		throw std::runtime_error("Invalid Expression");
	}
	// visit right node of Divide node
	node.get_right_child()->accept(Right_Eval);
	int right_result=Right_Eval.result();
	if (right_result==0)
	{
		throw std::runtime_error("Division By Zero : Undefined");
	}
	// perform division of left and right result and add to result.
	result_=result_+(left_result/right_result);
}

//
// Visit_Modulus_Node (const Modulus_Node &)
//
void Eval_Expr_Tree::Visit_Modulus_Node (const Modulus_Node & node)
{
	Eval_Expr_Tree Left_Eval;
	if (node.is_left_null())
	{
		throw std::runtime_error("Invalid Expression");
	}
	// visit left node of Modulus node
	node.get_left_child()->accept(Left_Eval);
	int left_result=Left_Eval.result();
	Eval_Expr_Tree Right_Eval;
	if (node.is_right_null())
	{
		throw std::runtime_error("Invalid Expression");
	}
	// visit right node of Modulus node
	node.get_right_child()->accept(Right_Eval);
	int right_result=Right_Eval.result();
	if (right_result==0)
	{
		throw std::runtime_error("Modulus By Zero : Undefined");
	}
	// perform modulus of left and right result and add to result.
	result_=result_+(left_result%right_result);
}

//
// result
//
int Eval_Expr_Tree::result (void) const
{
	return this->result_;
}