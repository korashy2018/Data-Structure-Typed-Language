#include <iostream>
using namespace std;

class LinkedListNode {
public:
  int data;
  LinkedListNode *next;
  LinkedListNode(int _data) {
    this->data = _data;
    this->next = NULL;
  }
};
class LinkedListIterator {
private:
  LinkedListNode *currentNode;

public:
  LinkedListIterator() { currentNode = NULL; }
  LinkedListIterator(LinkedListNode *node) { currentNode = node; }
  int data() { return this->currentNode->data; }
  LinkedListIterator next() {
    this->currentNode = this->currentNode->next;
    return *this;
  }
  LinkedListNode *current() { return this->currentNode; }
};

class LinkedList {
public:
  LinkedListNode *head = NULL;
  LinkedListNode *tail = NULL;
  LinkedListIterator begin() {
    LinkedListIterator itr(this->head);
    return itr;
  }
  void printList() {
    for (LinkedListIterator itr = this->begin(); itr.current() != NULL;
         itr.next()) {
      cout << itr.data();
      if (itr.current()->next != NULL)
        cout << " -> ";
    }
    cout << "\n";
  }
  LinkedListNode *find(int _data) {
    for (LinkedListIterator itr = this->begin(); itr.current() != NULL;
         itr.next()) {
      if (itr.data() == _data) {
        return itr.current();
      }
    }
    return NULL;
  }
  LinkedListNode *findParent(LinkedListNode *node) {
    for (LinkedListIterator itr = this->begin(); itr.current() != NULL;
         itr.next()) {
      if (itr.current()->next == node) {
        return itr.current();
      }
    }
    return NULL;
  }

  void insertLast(int _data) {
    LinkedListNode *newNode = new LinkedListNode(_data);
    if (this->head == NULL) {
      this->head = newNode;
      this->tail = newNode;
    } else {
      this->tail->next = newNode;
      this->tail = newNode;
    }
  }
  void insertAfter(LinkedListNode *node, int _data) {
    LinkedListNode *newNode = new LinkedListNode(_data);
    newNode->next = node->next;
    node->next = newNode;
    if (node->next == NULL) {
      this->tail = newNode;
    }
  }
  void insertBefore(LinkedListNode *node, int _data) {
    LinkedListNode *newNode = new LinkedListNode(_data);
    newNode->next = node;
    LinkedListNode *parent = this->findParent(node);

    if (parent == NULL) {
      this->head = newNode;
    } else {
      parent->next = newNode;
    }
  }
  void deleteNode(LinkedListNode *node) {
    if (node == NULL) {
      return;
    } else if (this->head == this->tail) {
      this->head = this->tail = NULL;
    } else if (this->head == node) {
      this->head = node->next;
    } else {
      LinkedListNode *parent = this->findParent(node);
      if (node == this->tail) {
        this->tail = parent;
      } else {
        parent->next = node->next;
      }
    }
    delete node;
  }
};
int main() {

  LinkedList *list = new LinkedList();
  list->insertLast(5);
  list->insertLast(6);
  list->insertLast(7);
  list->printList();

  LinkedListNode *nodeAfter = list->find(6);
  list->insertAfter(nodeAfter, 6);
  list->printList();

  list->insertAfter(list->find(6), 98);
  list->printList();

  list->insertBefore(list->find(5), 1000);
  list->printList();

  list->deleteNode(list->find(1000));
  list->deleteNode(list->find(5));
  // list->deleteNode(list->find(7));
  list->printList();

  cout << list->head->data << "\n";
    cout << list->tail->data << "\n";

}