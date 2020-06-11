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
#pragma once

#ifndef _CS507_STACK_H_
#define _CS507_STACK_H_

#include <exception>
#include <iostream>
#include "Array.h"

// COMMENT You should use aggregation instead of inheritance since logically a
// stack is not an array.

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

  // COMMENT You are to refactor this exception so that the Queue and
  // Stack can use the same exception, thereby increasing the portablity
  // of this exception.

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
      : std::exception () {
		std::cerr << "Empty exception was thrown.\n" << std::endl;
	}

    /**
     * Initializing constructor.
     *
     * @param[in]      msg         Error message.
     */
    empty_exception (const char * msg)
      : std::exception() {
		std::cerr << msg << std::endl;
	}
  };

  /// Default constructor.
  Stack (void);

  /// Copy constructor.
  Stack (const Stack & s);

  /// Destructor.
  ~Stack (void);

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

private:
	// Pointer to Array class object
	Array<T> * data_array_;

	// Location to enqueue
	size_t queue_next_;

	// Current size of the queue
	size_t cur_size_;

	// Max amount of elements T the queue can hold
	size_t max_size_;
};

// include the inline files
#include "Stack.inl"

// include the source file since template class
#include "Stack.cpp"

#endif  // !defined _CS507_STACK_H_
