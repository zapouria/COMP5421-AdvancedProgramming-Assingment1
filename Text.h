//
// Created by Pouria on 2020-05-18.
//

#ifndef UNTITLED_TEXT_H
#define UNTITLED_TEXT_H

#include <iostream>
using std::ostream;

class Text {
private:
    char* pStore;   //Points to storage of the C-string
public:
    Text(); //Default constructor
    Text(const Text&);  //conversion constructor
    Text(const char*);  //copy constructor
    void assign(const char*);   //Assigns a C-string and replacing its current contents
    void assign(const Text&);   //Assigns a Text object and replacing its current contents
    Text& operator= (const Text&);  //Assignment operator= overload. Assigns the right hand side operand and replaces its current contents
    void append(const char*);   //Appends a C-string and extending its contents
    void append(const Text&);   //Appends a Text object and extending its contents
    void clear();   //Erases the contents of the C-string in this object, which becomes an empty C-string
    int length() const; //Returns the length of object’s text
    bool isEmpty() const;   //Determines whether the object represents a C-string of length zero
    const char * getCstring() const;    //returns pStore as a const pointer
    virtual ~Text();    //Releases dynamic storage in use by the object
};

ostream& operator<<( ostream &, const Text& );
#endif //UNTITLED_TEXT_H
