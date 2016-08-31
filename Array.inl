// -*- C++ -*-
// $Id: Array.inl 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// size
//
template <typename T>
inline
	size_t Array<T>::size (void) const
{
	// return the current size of the array.
	return cur_size_;
}

//
// max_size
//
template <typename T>
inline
	size_t Array<T>::max_size (void) const
{
	// return the maximum size of the array.
	return max_size_;
}

//
// is_valid_index (size_t)
//
template <typename T>
inline
	bool Array<T>::is_valid_index (size_t i) const
{
	// if the index is in legal range return true i.e., it is valid.
	if(i>=0 && i<cur_size_)
	{
		return true;
	}
	// else index is not in legal range i.e., return false.
	else
	{
		return false;
	}
}