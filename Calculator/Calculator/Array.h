// -*- C++ -*-
// $Id: Array.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * @file       Array.h
 *
 * $Id: Array.h 380 2010-02-08 05:10:33Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================
#pragma once

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstring>          // for size_t definition
#include "Base_Array.h"

/**
 * @class Array
 *
 * Basic implementation of a standard array class for chars.
 */
template <typename T>
class Array : public Base_Array <T>
{
public:

    /// Default constructor.
    Array (void);

    /**
    * Initializing constructor.
    *
    * @param[in]      length        Initial size
    */
    Array (size_t length);

    /**
    * Initializing constructor.
    *
    * @param[in]      length        Initial size
    * @param[in]      fill          Initial value for each element
    */
    Array (size_t length, T fill);

    /**
    * Copy constructor
    *
    * @param[in]     arr         The source array.
    */
    Array (const Array <T> & arr);

    /// Destructor.
    ~Array (void);

    /**
    * Assignment operation
    *
    * @param[in]       rhs      Right-hand side of equal sign
    * @return          Reference to self
    */
    virtual const Array & operator = (const Array<T> & rhs);

    /**
    * Retrieve the current size of the array.
    *
    * @return          The current size
    */
    size_t size (void) const;

    /**
    * Retrieve the maximum size of the array.
    *
    * @return          The maximum size
    */
    size_t max_size (void) const;

    /**
    * Set the character at the specified \a index. If the \a index is not
    * within range of the array, then std::out_of_range exception is
    * thrown.
    *
    * @param[in]       index                 Zero-based location
    * @param[in]       value                 New value for character
    * @exception       std::out_of_range     Invalid \a index value
    */
    virtual void set (size_t index, T value);

    /**
    * Set a new size for the array. If \a new_size is less than the current
    * size, then the array is truncated. If \a new_size if greater then the
    * current size, then the array is made larger and the new elements are
    * not initialized to anything. If \a new_size is the same as the current
    * size, then nothing happens.
    *
    * The array's original contents are preserved regardless of whether the
    * array's size is either increased or decreased.
    *
    * @param[in]       new_size              New size of the array
    */
    virtual void resize (size_t new_size);

    /**
    * Fill the contents of the array.
    *
    * @param[in]       ch                   Fill character
    */
    virtual void fill (T element);

    // COMMENT Just move the base class members to the protected section.

    using Base_Array<T>::data_;
    using Base_Array<T>::cur_size_;
    using Base_Array<T>::max_size_;

};

#include "Array.inl"
#include "Array.cpp"

#endif   // !defined _ARRAY_H_
