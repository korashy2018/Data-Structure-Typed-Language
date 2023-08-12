#include <iostream>
using namespace std;
namespace DS {
namespace LinkedList {
namespace Doubly {
template <typename T> class LinkedListNode {
public:
  T data;
  LinkedListNode *next;
  LinkedListNode *back;
  LinkedListNode(T _data) {
    this->data = _data;
    this->next = NULL;
    this->back = NULL;
  }
};
template <typename T> class LinkedListIterator {
private:
  LinkedListNode<T> *currentNode;

public:
  LinkedListIterator() { currentNode = NULL; }
  LinkedListIterator(LinkedListNode<T> *node) { currentNode = node; }
  int data() { return this->currentNode->data; }
  LinkedListIterator next() {
    this->currentNode = this->currentNode->next;
    return *this;
  }
  LinkedListNode<T> *current() { return this->currentNode; }
};

template <typename T> class LinkedList {
public:
  LinkedListNode<T> *head = NULL;
  LinkedListNode<T> *tail = NULL;
  LinkedListIterator<T> begin() {
    LinkedListIterator<T> itr(this->head);
    return itr;
  }
  void printList() {
    for (LinkedListIterator<T> itr = this->begin(); itr.current() != NULL;
         itr.next()) {
      cout << itr.data();
      if (itr.current()->next != NULL)
        cout << " -> ";
    }
    cout << "\n";
  }
  LinkedListNode<T> *find(T _data) {
    for (LinkedListIterator<T> itr = this->begin(); itr.current() != NULL;
         itr.next()) {
      if (itr.data() == _data) {
        return itr.current();
      }
    }
    return NULL;
  }

  void insertLast(int _data) {
    LinkedListNode<T> *newNode = new LinkedListNode<T>(_data);
    if (this->tail == NULL) {
      this->head = this->tail = newNode;
    } else {
      newNode->back = this->tail;

      this->tail->next = newNode;
      this->tail = newNode;
    }
  }
  void insertAfter(LinkedListNode<T> *node, int _data) {
    if (node == NULL)
      return;
    // create new node
    LinkedListNode<T> *newNode = new LinkedListNode<T>(_data);
    if (this->tail == node) {
      this->tail = newNode;
      newNode->back = node;
      node->next = newNode;
    }
    // make the newNode next the node next
    newNode->next = node->next;
    // make the back of the newNode is the node
    newNode->back = node;
    // make the next of the node to be the newNode
    node->next = newNode;
    // make the back of the next node to be the newNOde
    newNode->next->back = newNode;
  }
  void insertBefore(LinkedListNode<T> *node, T _data) {
    // check if node is null and return if it
    if (node == NULL)
      return;

    LinkedListNode<T> *newNode = new LinkedListNode<T>(_data);
    newNode->next = node;

    // check if node is head
    if (this->head == node) {
      // make this head back is newnode
      this->head->back = newNode;
      newNode->next = this->head;
      this->head = newNode;
    } else {
      node->back->next = newNode;
    }
    node->back = newNode;
  }
  void deleteNode(LinkedListNode<T> *node) {
    if (node == NULL) {
      return;
    } else if (this->head == node) {
      this->head = node->next;
      this->head->back = NULL;
    } else if (this->tail == node) {
      this->tail = node->back;
      node->back->next = this->tail;
      this->tail->next = NULL;
    } else {
      node->back->next = node->next;
      node->next->back = node->back;
    }
    delete node;
  }
};
} // namespace Doubly
} // namespace LinkedList

} // namespace DS
