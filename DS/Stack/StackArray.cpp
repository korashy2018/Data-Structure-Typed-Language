#include <iostream>
using namespace std;
namespace DS {
template <typename T> class Stack {
private:
  T *dataList;
  int topIndex;
  int initialSize;
  int currentSize;
  void resizeStack() {
    if (this->topIndex < this->currentSize - 1)
      return;
    T *newArray = new T[this->currentSize + this->initialSize];
  std:
    copy(this->dataList, this->dataList + this->currentSize, newArray);
    cout << "Stack Reized :D "
         << "\n";
    this->currentSize += this->initialSize;
    delete[] this->dataList;
    this->dataList = newArray;
  }

public:
  Stack() {
    this->initialSize = 2;
    this->dataList = new T[this->initialSize];
    this->topIndex = -1;
    this->currentSize = this->initialSize;
  }
  void push(T _data) {
    this->resizeStack();
    this->dataList[topIndex + 1] = _data;
    this->topIndex++;
  }
  T peek() {
    if (this->topIndex == -1)
      return NULL;
    return this->dataList[this->topIndex];
  }
  T pop() {
    if (this->topIndex == -1)
      return NULL;
    T headOfStack = this->dataList[this->topIndex];
    this->dataList[this->topIndex] = 0;
    this->topIndex--;
    return headOfStack;
  }
  int size() { return this->topIndex + 1; }
  bool isEmpty() { return this->topIndex == -1; }
  void print() {
    if (this->topIndex == -1)
      return;
    for (int i = this->topIndex; i >= 0; i--) {
      cout << this->dataList[i];
      if (i != 0) {
        cout << " -> ";
      }
    }
    cout << "\n";
  }
};
} // namespace DS
