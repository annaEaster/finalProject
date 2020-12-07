#include<iostream>
#include <iostream>
#include<string>
#include <vector>
#include <algorithm>
#include "LL.h"

using namespace std;

int main(int argc, char *argv[]){
    LL ll;

    bool Exit = false;

    string dmenu = "\n======Main Menu=====\n"
                    "Do not use spaces when entering information!\n"
                    "If you enter the wrong number, type 0 to cancel!\n\n"
					"1. Add places to itinerary\n"
					"2. Edit places\n"
                    "3. Print places\n"
                    "4. Edit a place's activities\n"
                    "5. quit\n"
                    "\nEnter a number: ";

    int choice;
    bool exit = false;
    
    cout << dmenu << endl;
    
    while(cin >> choice){
        cin.clear();
        cin.ignore();

        switch (choice){
            case 1:
            {
                cout<<"\nEnter location: "<<endl;
                string word;
                cin >> word;

                if(word == "0")
                {
                    break;
                }

                ll.addWord(word);
                break;
            }
            case 2:
            {
            /////////////////////////////////////////////////////////////
            //Start of submenu

            string dmenu2 = "\n======Edit Places Menu=====\n"
                "Do not use spaces when entering information!\n"
                "If you enter the wrong number, type 0 to cancel!\n\n"
				"1. Delete place\n"
				"2. Add date\n"
                "3. Edit date\n"
                "4. Delete date\n"
                "5. Back\n"
                "\nEnter a number: \n";

                int choice2;
                bool exit2 = false;
    
                cout << dmenu2 << endl;
    
                while(cin >> choice2){
                    cin.clear();
                    cin.ignore();

                    switch (choice2){
                        case 1:
                        {
                            cout<<"\nenter place you want to delete"<<endl;
                            string word;
                            cin >> word;

                            if(word == "0"){
                                break;
                            }

                            ll.deletePlace(word);
                            break;
                        }
                        case 2:
                        {
                            cout<<"\nenter place you want to add a date to"<<endl;
                            string word;
                            cin >> word;

                            cout<<"\nenter the date (no spaces)"<<endl;
                            string word2;
                            cin >> word2;

                            if(word == "0" || word2 == "0"){
                                break;
                            }

                            ll.addDate(word, word2);
                            break;
                        }
                        case 3:
                        {
                            cout<<"\nenter place whose date you want to edit"<<endl;
                            string word;
                            cin >> word;

                            cout<<"\nenter the date (no spaces)"<<endl;
                            string word2;
                            cin >> word2;

                            if(word == "0" || word2 == "0"){
                                break;
                            }

                            ll.editDate(word, word2);
                            break;
                        }
                        case 4:
                        {
                            cout<<"\nenter place whose date you want to delete"<<endl;
                            string word;
                            cin >> word;

                            if(word == "0"){
                                break;
                            }

                            ll.deleteDate(word);
                            break;
                        }
                        case 5:
                        {
                            exit2 = true;
                            break;
                        }
                        }
                        if(exit2){
                            cin.clear();
                            break;
                        }

                        cout<<dmenu2<<endl;
                        }
                        break;
            }
            /////////////////////////////////////////////////////////
            //end of submenu

            case 3:
            {
                ll.printList();
                break;
            }
            case 4:
            {

            ////////////////////////////////////////////////////////
            //start of second submenu

                cout<<"\nenter place that you want to add activities to"<<endl;
                string word;
                cin >> word;

                if(ll.findPlace(word) == nullptr){
                    cout<<"sorry, that place isn't in your itinerary"<<endl;
                    break;
                }

                string dmenu3 = "\n======Activity Editor=====\n"
                "Do not use spaces when entering information!\n"
                "If you enter the wrong number, type 0 to cancel!\n\n"
				"1. Add activity\n"
                "2. Delete activity\n"
                "3. Add activity date\n"
                "4. Delete activity date\n"
                "5. Print activities\n"
                "6. Back\n"
                "\nEnter a number: \n";

                int choice3;
                bool exit3 = false;
    
                cout << dmenu3 << endl;
    
                while(cin >> choice3){
                    cin.clear();
                    cin.ignore();

                    switch (choice3){
                        case 1:
                        {
                            cout<<"\nEnter name of the activity"<<endl;
                            string word2;
                            cin >> word2;

                            if(word2 == "0"){
                                break;
                            }

                            ll.addActivity(word, word2);
                            break;
                        }
                        case 2:
                        {
                            cout<<"\nEnter name of the activity"<<endl;
                            string word2;
                            cin >> word2;

                            if(word2 == "0"){
                                break;
                            }

                            ll.deleteActivity(word, word2);
                            break;
                        }
                        case 3:
                        {
                            cout<<"\nEnter name of the activity"<<endl;
                            string word2;
                            cin >> word2;

                            cout<<"\nEnter time of the activity"<<endl;
                            string word3;
                            cin >> word3;

                            if(word2 == "0" || word3 == "0"){
                                break;
                            }

                            ll.addActivityDate(word, word2, word3);
                            break;
                        }
                        case 5:
                        {
                            ll.printActivities(word);
                            break;
                        }
                        case 6:
                        {
                            exit3 = true;
                            break;
                        }
                        }
                        if(exit3){
                            cin.clear();
                            break;
                        }
                        cout<<dmenu3<<endl;
                        } 
                        break;
                        }

            ///////////////////////////////////////////////////
            //end of second sub menu

            case 5:
            {
                exit = true;
                break;
            }
        }
        if(exit){
            break;
        }
        cout<<dmenu<<endl;
    }
    
}