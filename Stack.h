// -*- C++ -*-
// $Id: Stack.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _CS507_STACK_H_
#define _CS507_STACK_H_

#include <string>               // for printing std::string definition.
#include <iostream>             // for printing I/O messages.
#include <stdexcept>            // for throwing exceptions.
#include <cstring>              // for size_t definition.
#include <exception>            // for throwing run_time error and logic_error exceptions.
#include <cstdlib>              // for printing exception message.
#include <sstream>              // for istringstream and stringstream definition.
#include "Array.h"              // for Array ADT inclusion.

#define DEFAULT_SIZE 10         // specify a buffer size to avoid resizing every 
// time an enqueue is made.

/**
* @class Stack
*
* Basic stack for abitrary elements.
*/
template <typename T>
class Stack
{
public:
	/// Type definition of the type.
	typedef T type;

	/**
	* @class empty_exception
	*
	* Exception thrown to indicate the stack is empty.
	*/
	class empty_exception : public std::exception
	{
	public:
		/// Default constructor.
		empty_exception (void)
			: std::exception () 
		{
			//print out the message stack is empty.
			std::cout<<"The stack is empty"<<std::endl; 
		}
	};

	/// Default constructor.
	Stack (void);

	/// Copy constructor.
	Stack (const Stack & s);

	/// Destructor.
	~Stack (void);

	/**
	* Assignment operator
	*
	* @param[in]      rhs           Right-hand side of operator
	* @return         Reference to self
	*/
	const Stack & operator = (const Stack & rhs);

	/**
	* Push a new \a element onto the stack. The element is inserted
	* before all the other elements in the list.
	*
	* @param[in]      element       Element to add to the list
	*/
	void push (T element);

	/**
	* Remove the top-most element from the stack.
	*
	* @exception      empty_exception    The stack is empty.
	*/
	void pop (void);

	/**
	* Get the top-most element on the stack. If there are no element 
	* on the stack, then the stack_is_empty exception is thrown.
	*
	* @return         Element on top of the stack.
	* @exception      empty_exception    The stack is empty
	*/
	T top (void) const;

	/**
	* Test if the stack is empty
	*
	* @retval         true          The stack is empty
	* @retval         false         The stack is not empty
	*/
	bool is_empty (void) const;

	/**
	* Number of element on the stack.
	*
	* @return         Size of the stack.
	*/
	size_t size (void) const;

	/// Remove all elements from the stack.
	void clear (void);

	/**
	* Test the stack for equality.
	*
	* @param[in]       rhs                  Right hand side of equal to sign
	* @retval          true                 Left side is equal to right side
	* @retval          false                Left side is not equal to right side
	*/

	bool operator == (const Stack<T> & rhs) const;

	/**
	* Test the stack for inequality.
	*
	* @param[in]       rhs                  Right-hand size of not equal to sign
	* @retval          true                 Left side is not equal to right side
	* @retval          false                Left size is equal to right side
	*/

	bool operator != (const Stack<T> & rhs) const;

private:
	// add member variable here

	//Current maximum length of the stack.
	size_t stack_maxlen_;

	//Points to the topmost element of the stack.
	size_t top_;

	//Using Array as Wrapper (Facade) for stack ADT.
	Array <T> stack_data_;
};

// include the inline files
#include "Stack.inl"

// include the source file since template class
#include "Stack.cpp"

#endif  // !defined _CS507_STACK_H_
