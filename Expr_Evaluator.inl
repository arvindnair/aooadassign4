// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// is_operator  (const std::string &)
//
inline
	bool Expr_Evaluator::is_operator (const std::string & token) const
{
	// if the token is +, -, *, /, or % it is an operator then return true.
	if (token=="+" || token=="-" || token=="*" || token=="/" || token=="%" || token=="u-")
	{
		return true;
	}
	// otherwise it is not then return false.
	else
	{
		return false;
	}
}
