// $Id: Array.cpp 1473 2014-01-20 15:48:07Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.



//
// Array
//
template <typename T>
Array<T>::Array (void)
	// Arvind, initial each member variable on its own line in the base member
	// initialization section. This way, it statement has its own distinct line
	// for error reporting and debugging purposes.

	// Dr.Hill, I have done initialization of each member variable on its own 
	// line in the base member initialization section.
	: data_(0),
	cur_size_(0),
	max_size_(0)
{ }

//
// Array (size_t)
//
template <typename T>
Array<T>::Array (size_t length)
	// Arvind, initial each member variable on its own line in the base member
	// initialization section. This way, it statement has its own distinct line
	// for error reporting and debugging purposes.

	// Dr.Hill, I have done initialization of each member variable on its own 
	// line in the base member initialization section.
	: data_(new T[length]),
	cur_size_(length),
	max_size_(length)
{ }

//
// Array (size_t, char)
//
template <typename T>
Array<T>::Array (size_t length, T fill)
	// Arvind, initial each member variable on its own line in the base member
	// initialization section. This way, it statement has its own distinct line
	// for error reporting and debugging purposes.

	// Dr.Hill, I have done initialization of each member variable on its own 
	// line in the base member initialization section.
	: data_(new T[length]),
	cur_size_(length),
	max_size_(length)
{
	for(size_t i=0;i<cur_size_;i++)
	{
		data_[i]=fill;
	}
}

//
// Array (const Array &)
//
template <typename T>
Array<T>::Array (const Array<T> & array)
	// Arvind, initial each member variable on its own line in the base member
	// initialization section. This way, it statement has its own distinct line
	// for error reporting and debugging purposes.

	// Dr.Hill, I have done initialization of each member variable on its own 
	// line in the base member initialization section.
	: data_(new T[array.max_size_]),
	cur_size_(array.cur_size_),
	max_size_(array.max_size_)
{
	for(size_t i=0;i<cur_size_;i++)
	{
		data_[i]=array.data_[i];
	}
}

//
// ~Array
//
template <typename T>
Array<T>::~Array (void)
{
	// Arvind, you should check if data_ is 0 before calling delete
	// to prevent unnecessary system-level calls. For example, when
	// the default constructor is used and the array is never resized.

	// Dr.Hill, I have included a check to ensure data_ is 0 before 
	// calling delete to prevent unnecessary system-level calls.
	if(0!=data_)
	{
		delete [] data_;
	}

	// Arvind, there is no need to reset the member variables in this
	// method. This is becasue after this method returns, none of its
	// data is accessible.

	// Dr.Hill, I have removed the resetting of the member variables 
	// in this method i.e., data_=0.
}

//
// operator =
//
template <typename T>
const Array<T> & Array<T>::operator = (const Array<T> & rhs)
{
	// if lhs array is not equal to rhs array perform assignment
	if(*this!=rhs)
	{

		// Arvind, instead of explicitly calling the destructor, you only
		// need to delete the original array if this array is too small to
		// hold the contents of rhs. Right now, you are making a system call
		// each time, which may not be necessary.

		// Dr.Hill, I am now swapping the addresses if the array is smaller than
		// the buffer(i.e., max_size_) which also maintains data consistency. Also,
		// if the array is larger than rhs then I do not perform reallocation and
		// destruction. Thus, I have eliminated unnecessary system calls.

		// if max_size_ is greater than or equal to the rhs cur_size_ no need 
		// for reallocation.
		if(max_size_>=rhs.cur_size_)
		{
			cur_size_=rhs.cur_size_;
			for (size_t i = 0; i < rhs.cur_size_; i++)
			{
				data_[i]=rhs.data_[i];
			}
		}

		// when max_size is lesser than rhs cur_size_ there is 
		// need for reallocation. 
		else
		{
			cur_size_=rhs.cur_size_;
			max_size_=rhs.cur_size_;

			// create a temporary array for reallocation.
			T * temp=new T[rhs.cur_size_];
			for (size_t i = 0; i < rhs.cur_size_; i++)
			{
				temp[i]=rhs.data_[i];
			}

			// perform a swap of the addresses of temp and data_.
			std::swap(temp,data_);
			delete [] temp;
		}
	}
	return *this;
}

//
// operator []
//
template <typename T>
T & Array<T>::operator [] (size_t index)
{
	// if index is legal then retrieve the value at that particular position.
	if(is_valid_index(index))
	{
		return data_[index];
	}
	// if index is not in legal range then throw exception.
	else
	{
		throw std::out_of_range("Invalid \a index value");
	}


}

//
// operator [] 
//
template <typename T>
const T & Array<T>::operator [] (size_t index) const
{
	// if index is legal then retrieve the value at that particular position.
	if(is_valid_index(index))
	{
		return data_[index];
	}
	// if index is not in legal range then throw exception.
	else
	{
		throw std::out_of_range("Invalid \a index value");
	}

}

//
// get
//
template <typename T>
T Array<T>::get (size_t index) const
{
	// if index is legal then retrieve the value at that particular position.
	if(is_valid_index(index))
	{
		return data_[index];
	}
	// if index is not in legal range then throw exception.
	else
	{
		throw std::out_of_range("Invalid \a index value");
	}

}

//
// set
//
template <typename T>
void Array<T>::set (size_t index, T value)
{
	// if index is legal then set the value at that particular position.
	if(is_valid_index(index))
	{
		data_[index]=value;
	}
	// if index is not in legal range then throw exception.
	else
	{
		throw std::out_of_range("Invalid \a index value");
	}
}

//
// resize
//
template <typename T>
void Array<T>::resize (size_t new_size)
{
	// if new size is not equal to current size, perform resize.
	if(new_size!=cur_size_)
	{
		// Arvind, instead of explicitly calling the destructor, you only
		// need to delete the original array the new size if larger than
		// the number of elements this array can hold. Right now, you are making
		// a system call each time, which may not be necessary. Also, your
		// implemenation is more complex than it needs to be.

		// Dr.Hill, I am now swapping the addresses if the new_size specified is
		// greater than the buffer(i.e.,max_size_). If the new_size specified is
		// smaller than the buffer then the reallocation and destruction is not
		// performed. Hence, I have prevented unnecessary system calls and made 
		// implementation more simple.

		// if max_size_ is lesser than the new size then perform the resize.
		if(max_size_<new_size)
		{
			// create a temporary array for reallocation.
			T * temp=new T[new_size];
			for (size_t i = 0; i < cur_size_; i++)
			{
				temp[i]=data_[i];
			}
			cur_size_=new_size;
			max_size_=new_size;

			// perform a swap of the addresses of temp and data_.
			std::swap(temp,data_);
			delete [] temp;
		}
		// if max_size_ is greater than or equal to the new_size then 
		// no need for reallocation.
		else
		{
			cur_size_=new_size;
		}
	}
}

//
// find (char)
//
template <typename T>
int Array<T>::find (T ch) const
{
	for(size_t i=0;i<cur_size_;i++)
	{

		// if character is found return the index.
		if(data_[i]==ch)
		{
			return i;
		}
	}
	// if character is not found return -1.
	return -1;
}

//
// find (char, size_t) 
//
template <typename T>
int Array<T>::find (T ch, size_t start) const
{
	// if start position is in legal range then perform search.
	if (is_valid_index(start))
	{
		for(size_t i=start;i<cur_size_;i++)
		{

			// if character is found return the index.
			if(data_[i]==ch)
			{
				return i;
			}
		}
		// if character is not found return -1.
		return -1;
	}
	// if start position is not in legal range then throw exception.
	else
	{
		throw std::out_of_range("Invalid \a index value");
	}

}

//
// operator ==
//
template <typename T>
bool Array<T>::operator == (const Array<T> & rhs) const
{
	// if current and max size are equal, check individual
	// data elements.
	if(cur_size_==rhs.cur_size_)
	{
		for(size_t i=0;i<cur_size_;i++)
		{

			// if any one of the elements are not equal, arrays 
			// are not same.
			if(data_[i]!=rhs.data_[i])
			{
				return false;
			}
		}
		return true;
	}

	// current and max size are not equal, so arrays compared 
	// are not same.
	else
	{
		return false;
	}


}

//
// operator !=
//
template <typename T>
bool Array<T>::operator != (const Array<T> & rhs) const
{
	// Arvind, it is easier to write this in terms of ==. For example,
	// return !(*this == rhs).

	// Dr.Hill, I have changed the implementation to return !(*this == rhs).
	return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Array<T>::fill (T ch)
{
	// setting each element inside the array as the value of ch.
	for(size_t i=0;i<cur_size_;i++)
	{
		data_[i]=ch;
	}
}
