// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//

template <typename T>
Stack <T>::Stack (void)
	:data_array_(nullptr),
	cur_size_(0),
	max_size_(10)
{
	data_array_ = new Array<T>(max_size_);
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
	:data_array_(nullptr),
	cur_size_(stack.cur_size_),
	max_size_(stack.max_size_)
{
	data_array_ = new Array<T>(stack.cur_size_);
	for (int i = 0; i < stack.cur_size_; i++) {
		data_array_->data_[i] = stack[i];
	}
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
	delete data_array_;
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
	if (this->cur_size_ < this->max_size_) {
		this->data_array_->data_[cur_size_] = element;
		cur_size_++;
	}
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
	// removing stored input last to first
	if (cur_size_ == 0) {
		throw empty_exception("The Stack is empty.");
	}
	else {
		cur_size_ -= 1;
	}
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
  // COMMENT Just reset the variables. This will also have a compilation
  // error of T cannot be assign the value 0 (e.g., a Point class).
  
	cur_size_ = 0;
}


