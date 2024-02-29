#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack 
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
    std::vector<T> st_;
};

template <typename T>
Stack<T>::Stack() {
}

template <typename T>
Stack<T>::~Stack() {
}

template <typename T>
bool Stack<T>::empty() const  {
    return size() == 0;
}

template <typename T>
size_t Stack<T>::size() const {
    return st_.size();
}

template <typename T>
void Stack<T>::pop() {
    if (empty()) throw std::underflow_error("empty stack");
    st_.pop_back();
}

template <typename T>
void Stack<T>::push(const T& item) {
    st_.push_back(item); //does this run on O(1)?
}

template <typename T>
const T& Stack<T>::top() const {
    if (empty()) throw std::underflow_error("empty stack");
    return st_[st_.size() - 1];
}

#endif