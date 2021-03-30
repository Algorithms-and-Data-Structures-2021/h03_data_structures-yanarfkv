#include "array_stack.hpp"

#include <algorithm>  // copy, fill
#include <cassert>    // assert
#include <stdexcept>  // logic_error, invalid_argument

namespace itis {

ArrayStack::ArrayStack(int capacity) {
  if (capacity <= 0) {
    throw std::invalid_argument("initial capacity must be greater than zero");
  }
data_ = new Element[capacity];
  capacity_ = capacity;
  // TODO: напишите здесь свой код ...
}

ArrayStack::~ArrayStack() {
    delete[] data_;
    data_ = nullptr;
    capacity_ = size_ = 0;
  // TODO: напишите здесь свой код ...
}

void ArrayStack::Push(Element e) {
    if (size_ == capacity_) {
        resize(capacity_ + kCapacityGrowthCoefficient);
    }
    data_[size_] = e;
    size_++;
  // TODO: напишите здесь свой код ...
}

void ArrayStack::Pop() {
  if (size_ == 0) {
    throw std::logic_error("cannot pop out from empty stack");
  }
  size_--;
  data_[size_] = Element::UNDEFINED;
  // TODO: напишите здесь свой код ...
}

void ArrayStack::Clear() {
    for (int i = size_; size_ > 0; i--) {
        Pop();
    }
  // TODO: напишите здесь свой код ...
}

void ArrayStack::resize(int new_capacity) {
  assert(new_capacity > size_);
  auto new_data = new Element[new_capacity];
  std::copy(data_, data_ + capacity_, new_data);
  delete[]data_;
  data_ = new_data;
  capacity_ = new_capacity;
    for (int i = size_; i < new_capacity; i++) {
        data_[i] = Element::UNDEFINED;
    }
  // TODO: напишите здесь свой код ...
}

// === РЕАЛИЗОВАНО ===

std::optional<Element> ArrayStack::Peek() const {
  // возвращаем вершину стека или ничего (nullopt), если стек пустой
  return size_ == 0 ? std::nullopt : std::make_optional(data_[size_ - 1]);
}

bool ArrayStack::IsEmpty() const {
  return size_ == 0;
}

int ArrayStack::size() const {
  return size_;
}

int ArrayStack::capacity() const {
  return capacity_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const ArrayStack &stack) {
  os << "size: " << stack.size_ << '\n';
  if (stack.data_ != nullptr) {
    // выводим элементы сверху вниз
    for (int index = stack.size_ - 1; index >= 0; index--) {
      if (index == stack.size_ - 1) os << "[TOP] ";
      os << enum2str(stack.data_[index]) << '\n';
    }
  }
  return os;
}

}  // namespace itis