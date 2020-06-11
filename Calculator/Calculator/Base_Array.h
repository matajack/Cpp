#pragma once

#ifndef Base_Array_H_
#define Base_Array_H_



#include <cstring>

template <typename T>
class Base_Array
{
public:
	typedef T type;

	Base_Array(void);

	Base_Array(size_t size);

	~Base_Array(void);


	/**
	* Get the character at the specified index. If the index is not
	* within the range of the array, then std::out_of_range exception
	* is thrown.
	*
	* @param[in]       index               Zero-based location
	* @exception       std::out_of_range   Invalid \a index value
	*/
	virtual T & operator [] (size_t index);

	/**
	* @overload
	*
	* The returned character is not modifiable.
	*/
	virtual const T & operator [] (size_t index) const;

	/**
	* Test the array for equality.
	*
	* @param[in]       rhs                  Right hand side of equal to sign
	* @retval          true                 Left side is equal to right side
	* @retval          false                Left side is not equal to right side
	*/
	virtual bool operator == (const Base_Array & rhs) const;

	/**
	* Test the array for inequality.
	*
	* @param[in]       rhs                  Right-hand size of not equal to sign
	* @retval          true                 Left side is not equal to right side
	* @retval          false                Left size is equal to right side
	*/
	virtual bool operator != (const Base_Array & rhs) const;

	/**
	* Get the T at the specified index. If the \a index is not within
	* the range of the array, then std::out_of_range exception is thrown.
	*
	* @param[in]       index                 Zero-based location
	* @return          T at \index
	* @exception       std::out_of_range     Invalid index value
	*/
	virtual T get(size_t index) const;

	/**
	* Locate the specified T in the array. The index of the first
	* occurrence of the T is returned. If the character is not
	* found in the array, then -1 is returned.
	*
	* @param[in]        element        T to search for
	* @return           Index value of the character
	* @retval           -1        T not found
	*/
	virtual int find(T element) const;

	/**
	* @overload
	*
	* This version allows you to specify the start index of the search. If
	* the start index is not within the range of the array, then the
	* std::out_of_range exception is thrown.
	*
	* @param[in]       ch                   Character to search for
	* @param[in]       start                Index to begin search
	* @return          Index value of first occurrence
	* @retval          -1                   Character not found
	* @exception       std::out_of_range    Invalid index
	*/
	virtual int find(T element, size_t start) const;

protected:
	// pointer to array data
	T * data_;

	// max size of the array
	size_t max_size_;

	// current size of the array
	size_t cur_size_;
};


#include "Base_Array.cpp"

#endif