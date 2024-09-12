#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <stdlib.h>


struct node {    
    int row;
    int column;
    int value;
    node* nextNode;

    node()
    {
        this->row=0;
        this->column=0;
        this->value=0;
        this->nextNode=nullptr;
    }
};

class linkedList {
    private:
        node* head;
        int rows;
        int columns;        
    public:
        linkedList(int rows, int columns);
        ~linkedList();
        void appendNode(int row, int column, int value);
        void deleteNextNode(node* node);
        void deleteHeadNode();
        void deleteAllZeroNodes();
        void printLinkedList();
        void printMatrix();
        void printLinkedListAsMatrix();    
};


#endif
