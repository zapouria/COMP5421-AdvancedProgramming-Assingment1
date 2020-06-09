//
// Created by Pouria on 2020-05-18.
//

#include "Menu.h"
using namespace std;

// Default constructor
Menu::Menu() :
    option_list(new Text[1]),
    capacity(1),
    count(0),
    top_message(),
    bottom_message(){}

// Copy constructor
Menu::Menu(const Menu& mnu) {
    this->capacity=mnu.capacity;
    this->count=mnu.count;
    this->top_message=mnu.top_message;
    this->bottom_message=mnu.bottom_message;
    this->option_list=new Text[this->capacity];

    for (int i = 0; i < count; i++) {
        this->option_list[i] = mnu.option_list[i];
    }
}

//Doubles the current capacity of the options list
void Menu::double_capacity() {
    int twice_cap = 2 * this->getCapacity();    // Make the capacity double size.
    Text* new_list = new Text[twice_cap]; //Create a temp list with new size
    for (size_t i = 0; i < this->getCapacity(); i++)  //Copy Text objects to the new list
        new_list[i] = this->option_list[i];
    delete[] this->option_list; //Releases dynamic storage in use by option_list
    this->option_list = new_list;   //Assign the option_list to the new list
    this->capacity = twice_cap;
}

//Inserts option at position index, shifting all options at or past index over to the right by one position.
void Menu::insert(int index, const Text& option) {
    if (index > 0 && index <= this->count + 1) {    // check if the index is on the range
        index--;    //index should starts from 0
        if (this->size() == this->getCapacity())    //Doubles the current capacity in case of count==capacity
        {
            double_capacity();
        }
        Text *temp_list = new Text[this->getCapacity()];
        for (size_t i = 0; i < this->getCapacity(); i++) {
            if (i < index)  //Copies the data until index to the temp
                temp_list[i] = this->option_list[i];
            else if (i > index) //Copies the data after index to the temp
                temp_list[i] = this->option_list[i - 1];
            else // i == index
                temp_list[i] = option;  //Copies the new data to the position of index
        }
        delete[] this->option_list;
        this->option_list = temp_list;
        this->count++;
        cout << "Option inserted successfully!" << endl;
    }
}

//Inserts option at position index, shifting all options at or past index over to the right by one position.
void Menu::insert(int index, const char * option) {
    this->insert(index, Text(option));  //Delegates its task to the insert with argument of Text
}

//Adds supplied option to the end of the option list
void Menu::push_back(const char* pOption) {
    this->insert(this->size() + 1, pOption);    //Delegates its task to the insert with argument of Text with the index of last element(count+1)
}

//Adds supplied option to the end of the option list
void Menu::push_back(const Text& option) {
    this->insert(this->size() + 1, option); //Delegates its task to the insert with argument of Text with the index of last element(count+1)
}

//Removes an option from the list at given index; shifts all options to the right of index left by one position.
void Menu::remove(int index) {
    if (index > 0 && index <= this->count) {    // check if the index is on the range
        Text *new_list = new Text[this->getCapacity()]; //Creates a new list with the size of capacity
        //Copies all options to the new list except the option with the position of index
        for (size_t i = 0; i < this->size(); i++) {
            if (i < index - 1)
                new_list[i] = this->option_list[i];
            else if (i > index - 1)
                new_list[i - 1] = this->option_list[i];
        }
        delete[] this->option_list; //Releases dynamic storage in use by option_list
        this->option_list = new_list;   //Assign the option_list to the new list
        this->count--;
    }
}
//Returns the number of options in the option list.
int Menu::size() const {
    return this->count;
}

//Returns the current capacity if the options list
int Menu::getCapacity() const {
    return this->capacity;
}

//Removes the last option in the list
void Menu::pop_back() {
    this->remove(this->size()); //Delegates its task to the remove with the index of last element(count)
}

//Return the k’th option
Text Menu::get(int k) {
    if (k < 1 || k > count)
    {
        throw out_of_range( "No such option" );
    }
    return this->option_list[k -1];
}

//Returns a Text object storing a string representation of this menu
Text Menu::toString() const {
    //Creates a new pointer to Text as temp and append corresponding data and option_list to it. Afterward return the temp.
    Text* data = new Text();
    data->append("\n");
    if (!this->top_message.isEmpty()) {
        data->append(this->top_message);
        data->append("\n");
    }
    for (size_t i = 0; i < count; i++) {
        data->append("\t");
        data->append(to_string(i + 1).c_str());
        data->append(":");
        data->append(this->option_list[i]);
        data->append("\n");
    }
    if (!this->bottom_message.isEmpty()) {
        data->append(this->bottom_message);
        data->append("\n");
    }
    data->append("??");
    data->append("\t");
    return *data;
}

//Displays this menu and then reads and returns a valid option number
int Menu::read_option_number() {
    int option;
    //While loop until it will capture a correct input from user
    while (true) {
        cout << this->toString();
        cin >> option;
        if ((this->isEmpty()) || this->check_input(option)) //Checks if the input is in the range or option list is empty
            return option;
        else {
            cout << "Invalid choice " << option << ". It must be in the range [1, " << this->size() << "]" << endl
                 << endl;
        }
    }
}

//Checks if user's inputs are in range.
bool Menu::check_input(int input) const {
    return !((input < 1) || (input > count));
}

//Sets top message to m
void Menu::set_top_message(const Text& m) {
    this->top_message = m;
}

//Sets bottom message to m
void Menu::set_bottom_message(const Text& m) {
    this->bottom_message = m;
}

//Sets top message to empty text
void Menu::clear_top_message() {
    this->top_message = "";
}

//Sets bottom message to empty text
void Menu::clear_bottom_message() {
    this->bottom_message = "";
}

//Determines whether this menu’s option list is empty
bool Menu::isEmpty() const {
    return (this->size() == 0);
}

//Assignment operator= overload. Deep copies the right hand side operand into the object.
Menu& Menu::operator=(const Menu& m){
    //Checks if the object is not itself. If no it will copy otherwise will return itself
    if (this != &m) {
        this->count = m.count;
        this->capacity = m.capacity;
        this->set_top_message(m.top_message);
        this->set_bottom_message(m.bottom_message);
        this->option_list=new Text[this->getCapacity()];
        for (size_t i = 0; i < m.count; i++)
        {
            this->option_list[i] = m.option_list[i];
        }
    }
    return *this;
}

ostream& operator<< (ostream& sout, const Menu& m) {
    return sout << m.toString();
}

// Destructor
Menu::~Menu() {
    delete[] option_list;
    option_list = nullptr;
}


