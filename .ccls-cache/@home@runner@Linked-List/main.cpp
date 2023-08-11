#include <iostream>
using namespace std;

class LinkedListNode {
public:
  int data;
  LinkedListNode *next;
  LinkedListNode *back;
  LinkedListNode(int _data) {
    this->data = _data;
    this->next = NULL;
    this->back = NULL;
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

  void insertLast(int _data) {
    LinkedListNode *newNode = new LinkedListNode(_data);
    if (this->tail == NULL) {
      this->head = this->tail = newNode;
    } else {
      newNode->back = this->tail;

      this->tail->next = newNode;
      this->tail = newNode;
    }
  }
  void insertAfter(LinkedListNode *node, int _data) {
    if (node == NULL)
      return;
    // create new node
    LinkedListNode *newNode = new LinkedListNode(_data);
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
  void insertBefore(LinkedListNode *node, int _data) {
    // check if node is null and return if it
    if (node == NULL)
      return;

    LinkedListNode *newNode = new LinkedListNode(_data);
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
  void deleteNode(LinkedListNode *node) {
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
int main() {

  LinkedList *list = new LinkedList();
  list->insertLast(10);
  list->insertLast(20);
  list->insertLast(50);
  list->insertLast(70);

  list->printList();

  LinkedListNode *nodeAfter = list->find(20);
  list->insertAfter(nodeAfter, 6);
  list->printList();

  list->insertAfter(list->find(50), 98);
  list->printList();

  list->insertBefore(list->find(10), 500);
  list->printList();
  list->insertBefore(list->find(98), 600);
  list->printList();
  list->insertBefore(list->find(1000), 999);
  list->printList();
  list->deleteNode(list->find(70));
  list->printList();

  // cout << list->head->data << "\n";
  // cout << list->tail->data << "\n";
}