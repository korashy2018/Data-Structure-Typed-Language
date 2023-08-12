#include "DS/LinkedList/DoublyLinkedList.cpp"
#include "DS/Queue/Queue.cpp"
#include "DS/Stack/StackArray.cpp"
#include <iostream>
using namespace std;
using namespace DS;

int main() {
  DS::LinkedList::Singly::LinkedList<int> *list =
      new DS::LinkedList::Singly::LinkedList<int>();
  list->insertLast(10);
  list->insertLast(20);
  list->insertLast(50);
  list->insertLast(70);

  list->printList();

  DS::LinkedList::Singly::LinkedListNode<int> *nodeAfter = list->find(20);
  list->insertAfter(nodeAfter, 6);
  list->printList();

  list->insertAfter(list->find(50), 98);
  list->printList();

  list->insertBefore(list->find(10), 500);
  list->printList();

  cout << "List Head " << list->head->data << "\n";
  list->deleteHead();
  cout << "List Head after Deletion " << list->head->data << "\n";

  cout << "List Tail " << list->tail->data << "\n";
  cout << "List size " << list->size() << "\n";

  cout << "-------------------------------------- "
       << "\n";

  DS::LinkedList::Doubly::DoublyLinkedList<int> *list2 = new DS::LinkedList::Doubly::DoublyLinkedList<int>();
  list2->insertLast(300);
  list2->insertLast(96);
  list2->insertLast(23);
  list2->insertLast(423);

  list2->printList();

  DS::LinkedList::Doubly::DoublyLinkedListNode<int> *nodeAfter2 = list2->find(96);
  list2->insertAfter(nodeAfter2, 200);
  list2->printList();

  list2->insertAfter(list2->find(23), 50);
  list2->printList();

  list2->insertBefore(list2->find(300), 2);
  list2->printList();

  cout << "Doubly List Head " << list2->head->data << "\n";
  cout << "Doubly List Tail " << list2->tail->data << "\n";
  cout << "-------------------------------------- "
       << "\n";
  Stack<int> stack;
  cout << "Stack Size: " << stack.size() << "\n";
  stack.push(5);
  stack.push(6);
  stack.push(7);
  stack.push(8);
  stack.push(9);
  stack.push(10);
  stack.push(11);
  stack.push(12);
  stack.print();
  cout << "Stack peek: " << stack.peek() << "\n";
  cout << "Stack Size: " << stack.size() << "\n";
  while (!stack.isEmpty()) {
    cout << "pop: " << stack.pop() << "\n";
    cout << "Stack peek: " << stack.peek() << "\n";
    cout << "Stack Size: " << stack.size() << "\n";
  }
  cout << "-------------------------------------- "
       << "\n";
  Queue<int> queue;
  queue.enqueue(5);
  queue.enqueue(6);
  queue.enqueue(7);
  queue.print();

  while (!queue.isEmpty()) {
    cout << "Queue peek: " << queue.peek() << "\n";
    cout << "Dequeu: " << queue.dequeue() << "\n";
    cout << "Queue Size: " << queue.size() << "\n";
  };
}