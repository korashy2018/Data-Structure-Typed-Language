#include <iostream>
using namespace std;

template <typename T> class LinkedListNode {
public:
  T data;
  LinkedListNode *next;
  LinkedListNode(T _data) {
    this->data = _data;
    this->next = NULL;
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
  int Length = 0;
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
  LinkedListNode<T> *findParent(LinkedListNode<T> *node) {
    for (LinkedListIterator<T> itr = this->begin(); itr.current() != NULL;
         itr.next()) {
      if (itr.current()->next == node) {
        return itr.current();
      }
    }
    return NULL;
  }

  void insertLast(int _data) {
    LinkedListNode<T> *newNode = new LinkedListNode<T>(_data);
    if (this->head == NULL) {
      this->head = newNode;
      this->tail = newNode;
    } else {
      this->tail->next = newNode;
      this->tail = newNode;
    }
    this->Length++;
  }
  void insertAfter(LinkedListNode<T> *node, int _data) {
    LinkedListNode<T> *newNode = new LinkedListNode<T>(_data);
    newNode->next = node->next;
    node->next = newNode;
    if (node->next == NULL) {
      this->tail = newNode;
    }
    this->Length++;
  }
  void insertBefore(LinkedListNode<T> *node, int _data) {
    LinkedListNode<T> *newNode = new LinkedListNode<T>(_data);
    newNode->next = node;
    LinkedListNode<T> *parent = this->findParent(node);

    if (parent == NULL) {
      this->head = newNode;
    } else {
      parent->next = newNode;
    }
    this->Length++;
  }
  void deleteNode(LinkedListNode<T> *node) {
    if (node == NULL) {
      return;
    } else if (this->head == this->tail) {
      this->head = this->tail = NULL;
    } else if (this->head == node) {
      this->head = node->next;
    } else {
      LinkedListNode<T> *parent = this->findParent(node);
      if (node == this->tail) {
        this->tail = parent;
      } else {
        parent->next = node->next;
      }
    }
    delete node;
    this->Length--;
  }
  void deleteHead() { this->deleteNode(this->head); }
  int size() { return this->Length; }
};