// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
	size_t Stack <T>::size (void) const
{
	// returning the top shows the number of elements in the stack.
	return top_;
}

//
// top
//
template <typename T>
inline
	T Stack <T>::top (void) const
{
	// if stack is not empty return the topmost element.
	if (!(is_empty()))
	{
		return stack_data_[top_-1];
	}
	// else throw exception stack is empty.
	else
	{
		throw empty_exception();
	}
}

//
// is_empty
//
template <typename T>
inline
	bool Stack <T>::is_empty (void) const
{
	// returns the evaluation of top wrt zero.
	// if top is zero return true i.e. stack has no elements, 
	// else return false stack has atleast one element left.
	return (top_==0);
}
