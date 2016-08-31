// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
// setting all the data members to zero initially.
template <typename T>
Stack <T>::Stack (void)
	: stack_maxlen_(0),
	top_(0)
{}

//
// Stack
//
// copying the data members of stack into this stack.
template <typename T>
Stack <T>::Stack (const Stack<T> & stack)
	: stack_maxlen_(stack.stack_maxlen_),
	top_(stack.top_)
{
	// resizing the current stack to the size of the passed stack.
	stack_data_.resize(stack.stack_maxlen_);

	// if passed stack is not empty then copy its contents to the current stack. 
	if (!(stack.is_empty()))
	{
		for (size_t i = 0; i < stack.top_; i++)
		{
			stack_data_[i]=stack.stack_data_[i];
		}
	}
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
	// clearing the queue contents. Array class automatically 
	// takes care of destruction.
	clear();
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
	// if the top is greater than or equal to the max length 
	// of the stack check with inner conditions.
	if (top_>=stack_maxlen_)
	{
		// if max length of the stack is lesser than the array's size then make 
		// the stack max length as size of array, no need to perform resize.
		if (stack_maxlen_<stack_data_.size())
		{
			stack_maxlen_=stack_data_.size();
		}
		// if max length of the stack is lesser than the array's size then 
		// perform resize by adding 10 as default size to stack max length.
		else
		{
			stack_data_.resize(stack_maxlen_+DEFAULT_SIZE);
			stack_maxlen_=stack_data_.size();
		}
	}
	// incrementing top and adding the element to the stack after required 
	// check conditions.
	top_++;
	stack_data_.set(top_-1,element);
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
	// if stack is not empty remove the topmost element of the stack and 
	// decrement top.
	if (!(is_empty()))
	{
		stack_data_[top_-1];
		top_--;
	}
	//else throw stack is empty exception.
	else
	{
		throw empty_exception();
	}

}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	if (*this!=rhs)
	{
		// if array's size is lesser than the rhs stack max length then resize 
		// the stack data array else resize is not necessary.
		if (stack_data_.size()<rhs.stack_maxlen_)
		{
			stack_data_.resize(rhs.stack_maxlen_);
		}
		// setting the data members of lhs stack equal to rhs stack members.
		top_=rhs.top_;
		stack_maxlen_=rhs.stack_maxlen_;
		// if rhs stack is not empty then copy the contents of rhs into lhs stack.
		if (!(rhs.is_empty()))
		{
			for (size_t i = 0; i < rhs.top_; i++)
			{
				stack_data_[i]=rhs.stack_data_[i];
			}
		}
	}
	return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
	// setting the top to zero.
	top_=0;
}

//
// operator ==
//
template <typename T>
bool Stack<T>::operator == (const Stack<T> & rhs) const
{
	// if both the stacks are empty then return stacks are same.
	if ((this->is_empty()) && (rhs.is_empty()))
	{
		return true;
	}
	else
	{
		// check if both the stacks are not empty and their tops are equal.
		if ((!(this->is_empty())) && (!(rhs.is_empty())) && (top_==rhs.top_))
		{
			// check if each element until top is same, else return that the stacks are not same. 
			for (size_t i = 0; i < top_; i++)
			{
				if (stack_data_[i]!=rhs.stack_data_[i])
				{
					return false;
				}
			}
			// if all elements are same then the stacks are same.
			return true;
		}
		// if any one of the stacks are empty or their tops are not equal 
		// then stacks are not the same.
		return false;
	}
}

//
// operator !=
//
template <typename T>
bool Stack<T>::operator != (const Stack<T> & rhs) const
{
	// returning the opposite of == operation.
	return !(*this==rhs);
}