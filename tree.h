#ifndef BST_H
#define BST_H

#include <string>

struct BSTNode{
    std::string word;
    std::string date;
    BSTNode* parent;
    BSTNode* leftChild;
    BSTNode* rightChild;


    
    BSTNode(std::string in_word, BSTNode *p, BSTNode *lc, BSTNode *rc)
    {
        word = in_word;
        date = "";
        parent = p;
        leftChild = lc;
        rightChild = rc;
    };
};


class tree
{
    
public:
    // BST();
    void printInOrderBST();
    int addWordNode(std::string word);
    void deleteNode(std::string key);
    BSTNode* findMinRight(BSTNode* node);
    BSTNode* findMaxLeft(BSTNode* node);
    BSTNode* deleteNode(BSTNode* node);
    void addDate(std::string change, std::string n);
    void deleteDate(std::string n);
    
protected:
    
private:
    void printBST(BSTNode * node);
    BSTNode* searchBST(std::string word); //use this function to find pointer to node in BST
        
    // BSTNode* root;
};

#endif // BST_H
