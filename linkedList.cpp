#include "linkedList.hpp"
#include <iostream>

//constructor
linkedList::linkedList(int rows, int columns)
{
    this->head = nullptr;
    this->rows = rows;
    this->columns = columns;
};

linkedList::~linkedList() {

    //check if list is already empty
    if(!this->head)
    {
        return;
    }

    //check if head node is only element in list
    if(!this->head->nextNode) {
        delete this->head;
        return;
    }

    //else delete all nodes in list
    node* currNode = this->head;
    node* nextNode = currNode->nextNode;

    while(nextNode)
    {
        delete currNode;
        currNode = nextNode;
        nextNode = nextNode->nextNode;
    }
    delete currNode;
};

void linkedList::appendNode(int row, int column, int value)
{
    
    node* currNode = this->head;
    node* newNode;
    newNode = new node();
    newNode->row = row;
    newNode->column = column;
    newNode->value = value;
    newNode->nextNode = nullptr;


    //check if head node is null
    if(currNode==nullptr)
    {
        this->head = newNode;
        return;
    }
    currNode = this->head;

    //travel to last node in linked list
    while(currNode->nextNode)
    {
        currNode = currNode->nextNode;
    }
    //add node to end of linked list
    currNode->nextNode = newNode;
    return;
};

void linkedList::deleteNextNode(node* node)
{  
    struct node* deleteNode = node;
    deleteNode = node->nextNode;

    //move linked list to jump over deleteNode
    node->nextNode=deleteNode->nextNode;

    delete deleteNode;
    return;
};

void linkedList::deleteHeadNode() {
    node* currNode = this->head;

    //continue deleting head node until head node has a value > 0
    while(this->head != nullptr && this->head->value == 0)
    {
        //check to see if head node is null
        if(currNode==nullptr)
        {
            return;
        }
        //locate 2nd node
        currNode = currNode->nextNode;

        delete this->head;

        //set 2nd node as head
        this->head=currNode;
    }  
    return;
};

void linkedList::deleteAllZeroNodes() {
    node* currNode = this->head;

    //check if head node is null
    if(currNode==nullptr)
    {
        return;
    }

    //check if head node must be deleted
    if(currNode->value == 0)
    {
        this->deleteHeadNode();
    }
    
    while (currNode != nullptr && currNode->nextNode != nullptr) {
        
        //check if next node can be deleted
        if (currNode->nextNode->value == 0) 
        {
            deleteNextNode(currNode);
        } 

        //otherwise continue to next node
        else 
        {
            currNode = currNode->nextNode;
        }
    }
};

void linkedList::printLinkedList() {
    node* currNode = this->head;
        while(currNode != nullptr)
        {
            std::cout << currNode->value << "->";
            currNode = currNode->nextNode;
        }
        std::cout << std::endl;
    return;
};

void linkedList::printMatrix() {
    node* currNode = this->head;
    for(int i = 0; i < this->rows; i++)
    {
        for(int j = 0; j < this->columns; j++)
        {
            if(currNode != nullptr && currNode->column == j && currNode->row == i)
            {
                std::cout << currNode->value << " ";
                currNode = currNode->nextNode;
            }
            else 
            {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
    return;
};