#include "../LinkedList/SinglyLinkedList.cpp";
#include <iostream>
using namespace std;
namespace DS {
template <typename T> class Queue {
private:
  DS::LinkedList::Singly::LinkedList<T> *dataList;

public:
  Queue() { this->dataList = new DS::LinkedList::Singly::LinkedList<T>(); }
  void enqueue(T _data) { this->dataList->insertLast(_data); }
  T dequeue() {
    T headData = this->dataList->head->data;
    this->dataList->deleteHead();
    return headData;
  }
  T peek() {
    if (this->size() == 0) {
      return NULL;
    }
    return this->dataList->head->data;
  }
  int size() { return this->dataList->size(); }
  bool isEmpty() { return this->dataList->size() == 0; }
  void print() { return this->dataList->printList(); }
};
} // namespace DS
