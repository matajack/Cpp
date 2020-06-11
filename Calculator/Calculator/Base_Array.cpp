#include <stdexcept>


//
// Base_Array
//
template <typename T>
Base_Array<T>::Base_Array(void)
	:data_(nullptr),
	cur_size_(0),
	max_size_(10)
{
	data_ = new T[max_size_];
}

template <typename T>
Base_Array<T>::Base_Array(size_t size) 
	:data_(nullptr),
	cur_size_(0),
	max_size_(size)
{
	data_ = new T[max_size_];
}

//
// ~Base_Array
//
template <typename T>
Base_Array<T>::~Base_Array(void)
{
	delete[] data_;
}

//
// operator []
//
template <typename T>
T & Base_Array <T>::operator [] (size_t index)
{
	// Return stored char at index element of the array
	// Throwing any out_of_range exceptions
	if (index < this->cur_size_ && index >= 0) {
		return this->data_[index];
	}
	else throw std::out_of_range("Input out of range.");
}

//
// operator [] 
//
template <typename T>
const T & Base_Array <T>::operator [] (size_t index) const
{
	if (index < this->cur_size_ && index >= 0) {
		return this->data_[index];
	}
	else throw std::out_of_range("Input out of range.");
}

//
// get
//
template <typename T>
T Base_Array <T>::get(size_t index) const
{
	// Return stored T at index element of the array
	// Throwing any out_of_range exceptions
	if (index <= this->cur_size_ && index >= 0) {
		return this->data_[index];
	}
	else throw std::out_of_range("Input out of range.");
}



//
// find (T)
//
template  <typename T>
int Base_Array <T>::find(T value) const
{
	// Incrementing through the T array to return first instance of T input
	return this->find(value, 0);
}

//
// find (T, size_t) 
//
template <typename T>
int Base_Array <T>::find(T val, size_t start) const
{
	if (start < this->max_size_ && start > 0) {
		for (size_t i = start; i < this->max_size_; i++) {
			if (val = this->data_[i]) {
				return i;
			}
		}
	}
	else return -1;
}

//
// operator ==
//
template <typename T>
bool Base_Array <T>::operator == (const Base_Array & rhs) const
{
	// Overloading operator == by comparison of values pointed to by data_
	// and comparison of max sizes and current sizes

	// self check
	if (this == &rhs) {
		return true;
	}
	if (this->cur_size_ == rhs.cur_size_) {
		for (size_t i = 0; i < rhs.max_size_; i++) {
			if (data_[i] != rhs.data_[i]) {
				return false;
			}
		}
		return true;
	}
}

//
// operator !=
//
template <typename T>
bool Base_Array <T>::operator != (const Base_Array & rhs) const
{
	// Overloading operator != by comparison of values pointed to by data_
	// Returns true if the Arrays are not equal and false if they are equal
	return !(*this == rhs);
}

