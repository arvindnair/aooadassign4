//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EVAL_EXPR_TREE_
#define _EVAL_EXPR_TREE_

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <exception>
#include <cstdlib>
#include "Expr_Node_Visitor.h"

/**
* @class Eval_Expr_Tree
*
* Basic implementation of Eval_Expr_Tree.
*/
class Eval_Expr_Tree : public Expr_Node_Visitor
{
public:

	/// Default constructor.
	Eval_Expr_Tree (void);

	/// Destructor.
	virtual ~Eval_Expr_Tree (void);

	/**
	* Used to visit a Number node. Visit the number node and 
	* store its value in result.
	* 
	* @param[in]      node                  Number node reference passed.
	*/
	virtual void Visit_Number_Node (const Number_Node & node);

	/**
	* Used to visit a Unary node. Visit the Unary node child and 
	* perform Unary operation and store in result.
	* 
	* @param[in]       node                  Unary node reference passed.
	* @exception       std::runtime_error    Invalid Expression.
	*/
	virtual void Visit_Unary_Node (const Unary_Node & node);

	/**
	* Used to visit a Addition node. Visit the Addition node left and 
	* right child and perform Addition operation and store in result.
	* 
	* @param[in]       node                  Addition node reference passed.
	* @exception       std::runtime_error    Invalid Expression.
	*/
	virtual void Visit_Addition_Node (const Add_Node & node);

	/**
	* Used to visit a Subtraction node. Visit the Subtraction node left and 
	* right child and perform Subtraction operation and store in result.
	* 
	* @param[in]       node                  Subtraction node reference passed.
	* @exception       std::runtime_error    Invalid Expression.
	*/
	virtual void Visit_Subtraction_Node (const Subtract_Node & node);

	/**
	* Used to visit a Multiplication node. Visit the Multiplication node left and 
	* right child and perform Multiplication operation and store in result.
	* 
	* @param[in]       node                  Addition node reference passed.
	* @exception       std::runtime_error    Invalid Expression.
	*/
	virtual void Visit_Multiplication_Node (const Multiply_Node & node);

	/**
	* Used to visit a Division node. Visit the Division node left and 
	* right child and perform Division operation and store in result.
	* 
	* @param[in]       node                  Division node reference passed.
	* @exception       std::runtime_error    Invalid Expression.
	*/
	virtual void Visit_Division_Node (const Divide_Node & node);

	/**
	* Used to visit a Modulus node. Visit the Modulus node left and 
	* right child and perform Modulus operation and store in result.
	* 
	* @param[in]       node                  Modulus node reference passed.
	* @exception       std::runtime_error    Invalid Expression.
	*/
	virtual void Visit_Modulus_Node (const Modulus_Node & node);

	/**
	* Used to get the final result after visits.
	* 
	* @return         Final result of all visits.
	*/
	int result (void) const;

private:

	/// Copy Constructor.
	Eval_Expr_Tree (const Eval_Expr_Tree &);

	/// Assignment Operator.
	const Eval_Expr_Tree & operator = (const Eval_Expr_Tree &);

	// A variable to store the result.
	int result_;

};


#endif // !_EVAL_EXPR_TREE_
