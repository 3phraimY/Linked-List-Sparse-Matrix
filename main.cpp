#include <iostream>
#include "linkedList.hpp"

using namespace std;

int main() {
    int rows, columns;

    //ask user for matrix data
    cout << "How many rows should be in the matrix" << endl;
    cin >> rows;
    if(rows <= 0)
    {
       cout << "cannot have negative or zero rows";
       return 1;
    }
    cout << "How many columns should be in the matrix" << endl;
    cin >> columns;
     if(columns <= 0)
    {
       cout << "cannot have negative or zero columns";
       return 1;
    }

    //create linked list
    linkedList* myList = new linkedList(rows,columns);
    int value = 0;
    
    //ask user for each position in matrix
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cout << "Current Matrix:" << endl;
            
            //append node for each user input
            myList->printLinkedListAsMatrix();
            cin >> value;
            myList->appendNode(i,j,value);
        }
    }
    cout << endl << "=======================================" << endl << "Final Matrix" << endl;

    //remove all nodes with values of 0
    myList->deleteAllZeroNodes();
    myList->printMatrix();

    cout << endl << "Linked list" << endl;
    myList->printLinkedList();
}