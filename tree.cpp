#include <iostream>
#include "tree.h"
BSTNode *root;
using namespace std;

int tree::addWordNode(string word)
{
    BSTNode *insNode = new BSTNode(word, nullptr, nullptr, nullptr);
    
    if (root == NULL) { //for first item added
        root = insNode;
        cout<<"Activity added!"<<endl;
        return 1;
    }

    BSTNode *prober = root;
    BSTNode *lagger;

    BSTNode *repeat = searchBST(word);

    if(repeat != nullptr){
        cout<<"This activity already exists!"<<endl;
        return 0;
    }

    while (prober != NULL) {
        lagger = prober;

        if (word < prober->word) {
            prober = prober->leftChild; 
        } else {
            prober = prober->rightChild;
        }
    }

    if (word < lagger->word) {
        lagger->leftChild = insNode;
        insNode->parent = lagger;
        cout<<"Activity added!"<<endl;
    } else {
        lagger->rightChild = insNode;
        insNode->parent = lagger;
        cout<<"Activity added!"<<endl;
    }
    return 1;
}

void tree::printInOrderBST()
{
    //checks if tree exists first
    if(root == nullptr){
        cout<<"You don't have any activities yet!"<<endl;
    }
    else
    {
        printBST(root);
    }
    
}

void tree::printBST(BSTNode *node)
{
    if(node != NULL){
        printBST(node->leftChild);

        if(!node->date.empty()){
            cout<<node->word<<":"<<node->date<<"  "<<endl;
        } else{
            cout<<node->word<<endl;
        }
        printBST(node->rightChild);
    }
}

BSTNode* tree::searchBST(std::string word)
{
    //finds node in tree that matches value, and returns it
    BSTNode *prober = root;
    BSTNode *lagger;

    while (prober != NULL) {
        lagger = prober;

        if (word == prober->word) {
            return prober; 
        } else if (word < prober->word) {
            prober = prober->leftChild; 
        } else {
            prober = prober->rightChild;
        }
    }
    
    return nullptr;
}


void tree::deleteNode(string key)
{
    if(searchBST(key) != nullptr){
        BSTNode *toBeDeleted = searchBST(key);
        deleteNode(toBeDeleted);
    }
    else{
        cout<<"\nYou haven't added that activity yet!\n"<<endl;
    }
}

BSTNode* tree::findMinRight(BSTNode* node)
{
    BSTNode* theNode = node;
 
    //find the smallest value on the node's right child
    while (theNode && theNode->leftChild != nullptr)
    {
        theNode = theNode->leftChild;
    }
    return theNode;
}

BSTNode* tree::findMaxLeft(BSTNode* node)
{
    BSTNode* theNode = node;
 
    //find the largest value on the node's left child
    while (theNode && theNode->rightChild != nullptr)
    {
        theNode = theNode->rightChild;
    }
    return theNode;
}
 

BSTNode* tree::deleteNode(BSTNode* node)
{

    // base case
    if (node == nullptr)
    {
        cout<<"There's no activities!"<<endl;
        return node;
    }

    //no children
    if(node->rightChild == nullptr && node->leftChild == nullptr)
    {
        if (node == root){
            root = nullptr;
        }
        else if(node->word > node->parent->word){
            node->parent->rightChild = nullptr;
        }
        else {
            node->parent->leftChild = nullptr;
        }
        delete node;
        cout<<"Activity deleted!"<<endl;
    }

    //Only left child
    else if(node->rightChild == nullptr)
    {
        if (node == root){ //if node to be deleted is root
            BSTNode* temp = findMaxLeft(node->leftChild);
            if(node->leftChild == temp){
                temp->parent = nullptr;
            }
            else{
                temp->parent->rightChild = temp->leftChild;
                temp->leftChild->parent = temp->parent;
                temp->leftChild = node->leftChild;
                temp->parent = nullptr;
            }
            root = temp;
        }
        else if(node->word > node->parent->word){ //if node to be deleted is to the right of it's parent
            node->leftChild->parent = node->parent;
            node->parent->rightChild = node->leftChild;
        }
        else { //if node to be deleted is to the left of it's parent
            node->leftChild->parent = node->parent;
            node->parent->leftChild = node->leftChild;
        }
        delete node;
        cout<<"Activity deleted!"<<endl;
    }

    //only right child
    else if(node->leftChild == nullptr)
    {
        if (node == root){ //if node to be deleted is root
            BSTNode* temp = findMinRight(node->rightChild);
            
            
            if(node->rightChild == temp){
                temp->parent = nullptr;
            }
            else{
                temp->parent->leftChild = temp->rightChild;
                temp->rightChild->parent = temp->parent;
                temp->rightChild = node->rightChild;
                temp->parent = nullptr;
            }
            root = temp;
        }
        else if(node->word > node->parent->word){ //if node to be deleted is to the right of it's parent
            node->rightChild->parent = node->parent;
            node->parent->rightChild = node->rightChild;
        }
        else { //if node to be deleted is to the left of it's parent
            node->rightChild->parent = node->parent;
            node->parent->leftChild = node->rightChild;
        }
        delete node;
        cout<<"Activity deleted!"<<endl;
    }

    //two child
    else
    {
        BSTNode* temp = findMinRight(node->rightChild);
        if(node->word > node->parent->word){
            node->parent->rightChild = temp;
        } 
        else if (node == root){ //if node to be deleted is root
            BSTNode* temp = findMinRight(node->rightChild);
            node->leftChild->parent = temp;
            temp->leftChild = node->leftChild;
            temp->rightChild = node->rightChild;
            temp->rightChild->parent = node;
            root = temp;
            delete node;
        }
        else {
            node->parent->leftChild = temp;
        }
        temp->parent->leftChild = temp->rightChild;
        temp->parent = node->parent;
        temp->leftChild = node->leftChild;
        temp->leftChild->parent = node;
        temp->rightChild = node->rightChild;
        temp->rightChild->parent = node;
        delete node;
        cout<<"Activity deleted!"<<endl;
    }
    return node;
}

void tree::addDate(string change, string n)
{
    if(searchBST(n) != nullptr){
        BSTNode *activity = searchBST(n);
        activity->date = change;
    }
    else{
        cout<<"\nYou haven't added that activity yet!\n"<<endl;
    }
}

void tree::deleteDate(string n)
{
    if(searchBST(p) != nullptr){
        BSTNode *activity = searchBST(n);
        activity->date = "";
    }
    else{
        cout<<"\nYou haven't added that activity yet!\n"<<endl;
    }
}
