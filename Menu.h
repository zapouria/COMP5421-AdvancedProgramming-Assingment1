//
// Created by Pouria on 2020-05-18.
//

#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H
#include <iostream>
#include "Text.h"

using std::ostream;

class Menu{
private:
    Text* option_list;  //Stores a pointer to dynamic array of Text objects
    int capacity;   //The current length of the options list dynamic array
    int count;  //The actual number of options on the option list
    Text top_message;   //The opening message
    Text bottom_message;    //The closing message
    void double_capacity(); //Doubles the current capacity of the options list
    bool check_input(int) const; //Checks if user's inputs are correct.
public:
    Menu(); //Default constructor
    Menu(const Menu&);  //Copy Constructor
    Menu& operator=(const Menu& m); //Assignment operator= overload. Copies the right hand side operand into the object.
    void insert(int, const Text&);    //Inserts option at position index, shifting all options at or past index over to the right by one position.
    void insert(int, const char*);  //Inserts option at position index, shifting all options at or past index over to the right by one position.
    void push_back(const char*);    //Adds supplied option to the end of the option list
    void push_back(const Text&);    //Adds supplied option to the end of the option list
    void remove(int);   //Removes an option from the list at given index; shifts all options to the right of index left by one position.
    int size() const;   //Returns the number of options in the option list.
    int getCapacity() const;    //Returns the current capacity if the options list
    void pop_back();    //Removes the last option in the list
    Text get(int);  //Return the k’th option
    Text toString() const;  //Returns a Text object storing a string representation of this menu
    int read_option_number();   //Displays this menu and then reads and returns a valid option number
    void set_top_message(const Text&);  //Sets top message to m
    void set_bottom_message(const Text&);   //Sets bottom message to m
    void clear_top_message();   //Sets top message to empty text
    void clear_bottom_message();    //Sets bottom message to empty text
    bool isEmpty() const;   //Determines whether this menu’s option list is empty
    friend ostream& operator<< (ostream &, const Menu&);
    virtual ~Menu();    //Destructor
};
#endif //UNTITLED_MENU_H
