
#include <iostream>
#include "LL.h"
#include "tree.h"

LList *head;
LList *tmp;
int numBoxes = 0;
int numComparisons = 0;

void LL::addWord(string name)
{
    //checks if list is empty
    if (head == nullptr){
        LList *n = new LList(name, nullptr, nullptr);
        head = n;
        tmp = n;
    } 
    //adds place to list
    else if (repeat(name) == false){
        LList *n = new LList(name, nullptr, tmp);
        tmp->next = n;
        tmp = n;
        cout<<"Location added!"<<endl;
    }
}


void LL::printList()
{
    LList *temp;

    //make sure the list was made properly
    if(head == NULL){
        cout<<"no list"<<endl;
    }

    //goes through the list and prints the place and date
    temp = head;
    while(temp != NULL){
        if(!temp->date.empty()){
            cout<<temp->place<<":"<<temp->date<<"  "<<endl;
        } else{
            cout<<temp->place<<endl;
        }
        temp = temp->next;
    }
}

bool LL::repeat(string name)
{
    LList *temp2;
    temp2 = head;

    //makes sure still in linked list and needs to be looking
    while(temp2 != nullptr){

        if(temp2->place == name){
            cout<<"This already exists!"<<endl;
            return true;
        }
        //moves down the list
        temp2 = temp2->next;
    } return false;
}

LList * LL::findPlace(string p)
{
    LList *temp2;
    temp2 = head;

    //makes sure still in linked list and needs to be looking
    while(temp2 != nullptr){

        if(temp2->place == p){
            return temp2;
        }
        //moves down the list
        temp2 = temp2->next;
    } 
    return NULL;
}

void LL::addActivity(string n, string p)
{
    // if statement makes sure that the place you entered exists in list, then executes function
    if(findPlace(n) != NULL){
        LList *node = findPlace(n);
        node->Tree.addWordNode(p);
    }
    else{
        cout<<"\nThat place isn't in your itinerary!\n"<<endl;
    }
    
}

void LL::printActivities(string n)
{
    // if statement makes sure that the place you entered exists in list, then executes function
    if(findPlace(p) != NULL){
        LList *node = findPlace(n);
        node->Tree.printInOrderBST();
    }
    else{
        cout<<"\nThat location isn't in your itinerary!\n"<<endl;
    }
}

void LL::deletePlace(string p)
{
    LList *temp2;
    temp2 = head;
    bool notFound = true;

    //makes sure still in linked list and needs to be looking
    while(temp2 != nullptr && notFound)
    {
        if(temp2->place == p)
        {
            if(temp2 == head && temp2->next == nullptr) //when place to delete in the head and the only item
            {
                head = nullptr;
                delete temp2;
                notFound = false;
                cout<<"Place deleted.\n"<<endl;
            }
            else if(temp2 == head) //when place to delete is the head
            {
                temp2->next->prev = nullptr;
                head = temp2->next;
                cout<<"Place deleted.\n"<<endl;
                delete temp2;
                notFound = false;
            } 
            else if (temp2->next == nullptr) //when place to delete is the last item
            {
                temp2->prev->next = nullptr;
                tmp = temp2->prev;
                cout<<"Place deleted.\n"<<endl;
                delete temp2;
                notFound = false;
            } 
            else 
            {
                temp2->prev->next = temp2->next;
                temp2->next->prev = temp2->prev;
                cout<<"Place deleted.\n"<<endl;
                delete temp2;
                notFound = false;
            }
        }
        //moves down the list
        temp2 = temp2->next;
    }
    if(notFound == true)
    {
        cout<<"This place is not in your itinerary!\n"<<endl;
    }
}

void LL::addDate(string p, string n)
{
    // if statement makes sure that the place you entered exists in list, then executes function
    if(findPlace(p) != NULL)
    {
        LList *node = findPlace(p);
        node->date = n;
    }
    else
    {
        cout<<"\nThat location isn't in your itinerary!\n"<<endl;
    }
}

void LL::deleteDate(string p)
{
    // if statement makes sure that the place you entered exists in list, then executes function
    if(findPlace(p) != NULL)
    {
        LList *node = findPlace(p);
        node->date = "";
    }
    else
    {
        cout<<"\nThat location isn't in your itinerary!\n"<<endl;
    }
    
}

void LL::editDate(string p, string n)
{
    // if statement makes sure that the place you entered exists in list, then executes function
    if(findPlace(p) != NULL){
        LList *node = findPlace(p);
        node->date = n;
    }
    else{
        cout<<"\nThat location isn't in your itinerary!\n"<<endl;
    }
    
}

void LL::deleteActivity(string p, string n)
{
    // if statement makes sure that the place you entered exists in list, then executes function
    if(findPlace(p) != NULL){
        LList *node = findPlace(p);
        node->Tree.deleteNode(n);
    }
    else{
        cout<<"\nThat location isn't in your itinerary!\n"<<endl;
    }
    
}

void LL::addActivityDate(string p, string n, string change)
{
    // if statement makes sure that the place you entered exists in list, then executes function
    if(findPlace(p) != NULL){
        LList *node = findPlace(p);
        node->Tree.addDate(change, n);
    }
    else{
        cout<<"\nThat location isn't in your itinerary!\n"<<endl;
    }
    
}

void LL::deleteActivityDate(string p, string n)
{
    // if statement makes sure that the place you entered exists in list, then executes function
    if(findPlace(p) != NULL){
        LList *node = findPlace(p);
        node->Tree.deleteDate(n);
    }
    else{
        cout<<"\nThat location isn't in your itinerary!\n"<<endl;
    }

}
