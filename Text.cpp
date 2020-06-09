//
// Created by Pouria on 2020-05-18.
//

#include "Text.h"
using std::ostream;
#include <cstring>
using std::cout;
using std::endl;

//Default constructor
Text::Text() : Text("") {}

//conversion constructor, which delegates its tasks to copy constructor
Text::Text(const Text &txt) : Text(txt.pStore){}

//copy constructor
Text::Text(const char *pCstr) {
    this->pStore = new char[strlen(pCstr) + 1];
    strcpy(this->pStore, pCstr);
}

//Assigns a C-string and replacing its current contents
void Text::assign(const char *pCstr) {
    delete[] this->pStore;  //Releases dynamic storage in use by this object

    this->pStore = new char[strlen(pCstr) + 1]; //Create a new object with size of pCstr

    strcpy(this->pStore, pCstr);    //Copy content of pCstr to pStore of new object
}

//Assigns a Text object and replacing its current contents
void Text::assign(const Text &txt) {
    this->assign(txt.pStore);    //Delegates its task to the assign with argument of char*
}

//Assignment operator= overload. Assigns the right hand side operand and replaces its current contents
Text& Text::operator=(const Text &txt) {
    //Checks if the object is not itself otherwise will return itself.
    if (this != &txt) {
        this->assign(txt);
    }
    return *this;
}

//Appends a C-string and extending its contents
void Text::append(const char *pCstr) {
    char* temp = new char[this->length() + strlen(pCstr) + 1];   //Creates an empty temp object with the size of existing characters + new ones

    strcpy(temp, this->pStore); //Copy existing characters to the temp

    strcat(temp, pCstr);    //concat new characters to the temp

    delete[] this->pStore;   //Releases dynamic storage in use by the old object

    this->pStore = temp;    //Assign the temp object
}

//Appends a Text object and extending its contents by delegating its task to the append with argument of char*
void Text::append(const Text &txt) {
    this->append(txt.pStore);
}

//Erases the contents of the C-string in this object, which becomes an empty C-string
void Text::clear() {
    this->assign("");  //Creates an empty empty C-string
}

//Returns the length of object’s text
int Text::length() const {
    return strlen(this->pStore);
}

//Determines whether the object represents a C-string of length zero
bool Text::isEmpty() const {
    //Returns true if the length is zero, otherwise returns false
    return this->length() == 0;
}

//returns pStore as a const pointer
const char* Text::getCstring() const {
    return this->pStore;
}

ostream& operator<<(ostream & sout, const Text& txt)
{
    sout << txt.getCstring();
    return sout;
}

Text::~Text() {
    delete[] pStore;
}