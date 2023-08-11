#include "LinkedList/DoublyLinkedList.cpp"
#include "LinkedList/SinglyLinkedList.cpp"
#include <iostream>
using namespace std;

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

  cout << "List Head " << list->head->data << "\n";
  cout << "List Tail " << list->tail->data << "\n";

  DoublyLinkedList *list2 = new DoublyLinkedList();
  list2->insertLast(300);
  list2->insertLast(96);
  list2->insertLast(23);
  list2->insertLast(423);

  list2->printList();

  DoublyLinkedListNode *nodeAfter2 = list2->find(20);
  list2->insertAfter(nodeAfter2, 96);
  list2->printList();

  list2->insertAfter(list2->find(23), 50);
  list2->printList();

  list2->insertBefore(list2->find(300), 2);
  list2->printList();

  cout << "Doubly List Head " << list2->head->data << "\n";
  cout << "Doubly List Tail " << list2->tail->data << "\n";
}