#include "linked_dequeue.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedDequeue::Enqueue(Element e) {
    auto new_node = new DoublyNode(e, nullptr, nullptr);
    if (size_ == 0) {
        front_ = new_node;
    } else {
        back_->next = new_node;
        new_node->previous = back_;
    }
    back_ = new_node;
    size_++;
  // TODO: напишите здесь свой код ...
}

void LinkedDequeue::EnqueueFront(Element e) {
  // TODO: напишите здесь свой код ...
    auto new_node = new DoublyNode(e, nullptr, nullptr);
    if (size_ == 0) {
        back_ = new_node;
    } else {
        new_node->next = front_;
        front_->previous = new_node;
    }
    front_ = new_node;
    size_++;
}

void LinkedDequeue::Dequeue() {
  if (size_ == 0) {
    throw std::logic_error("cannot not dequeue from empty queue");
  }
  if (size_ > 1) {
      DoublyNode *node_to_delete = front_;
      front_ = node_to_delete->next;
      delete node_to_delete;
  } else {
      delete front_;
      front_ = nullptr;
      back_ = nullptr;
  }
  size_--;
  // TODO: напишите здесь свой код ...
}

void LinkedDequeue::DequeueBack() {
  if (size_ == 0) {
    throw std::logic_error("cannot not dequeue from empty queue");
  }
  if (size_ > 1) {
      DoublyNode *node_to_delete = back_;
      back_ = back_->previous;
      delete node_to_delete;
  } else {
      delete back_;
      front_ = nullptr;
      back_ = nullptr;
  }
  size_--;
  // TODO: напишите здесь свой код ...
}

void LinkedDequeue::Clear() {
    while (size_ > 0) DequeueBack();
  // TODO: напишите здесь свой код ...
}

// === РЕАЛИЗОВАНО ===

LinkedDequeue::~LinkedDequeue() {
  Clear();
}

std::optional<Element> LinkedDequeue::front() const {
  return front_ == nullptr ? std::nullopt : std::make_optional(front_->data);
}

std::optional<Element> LinkedDequeue::back() const {
  return back_ == nullptr ? std::nullopt : std::make_optional(back_->data);
}

bool LinkedDequeue::IsEmpty() const {
  return size_ == 0;
}

int LinkedDequeue::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedDequeue &queue) {
  os << "size: " << queue.size_ << '\n';
  for (auto current_node = queue.front_; current_node != nullptr; current_node = current_node->previous) {
    if (current_node == queue.front_) os << "[FRONT] ";
    if (current_node == queue.back_) os << "[BACK] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis
