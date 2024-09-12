#include <iostream>
#include "linkedList.hpp"

using namespace std;

int main() {
    linkedList* myList = new linkedList(4,4);
    myList->appendNode(1,1,2);
    myList->appendNode(2,2,0);

    myList->printLinkedList();
    myList->deleteAllZeroNodes();
    myList->printLinkedList();
    myList->printMatrix();
}