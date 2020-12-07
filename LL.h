#include <iostream>
#include "tree.h"


using namespace std;

struct LList{
    string place;
    string date;
    LList *next;
    LList *prev;
    tree Tree;

    // LList();

    LList(string Place, LList *n, LList *p){
        place = Place;
        date = "";
        next = n;
        prev = p;
        tree Tree;
    }
};
class LL
{
    public:
    void addWord(string n);
    void deletePlace(string p);
    void addDate(string p, string n);
    void deleteDate(string p);
    void editDate(string p, string n);
    void printList();
    bool repeat(string n);
    LList * findPlace(string p);
    void addActivity(string p, string n);
    void deleteActivity(string p, string n);
    void printActivities(string n);
    void addActivityDate(string p, string n, string change);
    void deleteActivityDate(string p, string n);
};