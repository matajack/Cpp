// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array<T>::Array () : Base_Array<T>()
{

}

//
// Array (size_t)
//
template <typename T>
Array<T>::Array (size_t length) : Base_Array<T>(length)
{

}

//
// Array (size_t, T)
//
template <typename T>
Array<T>::Array (size_t length, T fill) : Base_Array<T>(length)
{
	// Filling array with user input T
	this->fill(fill);
}

//
// Array (const Array &)
//
template <typename T>
Array<T>::Array (const Array<T> & array) : Base_Array<T>(array.max_size())
{
	// Allocating new array to store the input Array
	// using data_
	for (int i = 0; i < array.max_size(); i++) {
		this->data_[i] = array[i];
	}
	this->max_size_ = array.max_size_;
	this->cur_size_ = array.cur_size_;
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{

}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array<T> & rhs)
{
	// Performing deep copy on the right hand side array through the use of the resize method
	// and incrementing through array values
	this->resize(rhs.max_size_);
	for (size_t i = 0; i < rhs.max_size_; i++) {
		this->data_[i] = rhs.data_[i];
	}
	this->max_size_ = rhs.max_size_;
	this->cur_size_ = rhs.cur_size_;
	return *this;
}

//
// set
//
template <typename T>
void Array <T>::set (size_t index, T value)
{
	// Receiving user input T to replace the stored T at specific index
	// Throwing any out_of_range exceptions
	if (index <= cur_size_) {
		this->data_[index] = value;
	}
	else throw std::out_of_range("Input out of range.");

}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	// Truncating current size to input
	if ((new_size < cur_size_ && new_size > 0) || (new_size > cur_size_ && new_size <= max_size_)) {
		cur_size_ = new_size;
	}
	// Copying array values into new array with larger size allocation
	if (new_size > cur_size_ && new_size > max_size_) {
		T * temp = new T[new_size];
		this->max_size_ = new_size;
		this->cur_size_ = new_size;
		std::swap(data_, temp);
		delete [] temp;
	}
}

//
// fill
//
template <typename T>
void Array <T>::fill (T value)
{
	// Filling array up to current size with input T
	for (size_t i = 0; i < this->cur_size_; i++) {
		this->data_[i] = value;
	}
}


