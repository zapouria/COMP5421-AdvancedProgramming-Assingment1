#include <iostream>
#include "Text.h"
#include "Menu.h"

using std::ostream;
using std::cout;
using std::endl;

// Function prototypes (declarations)
void demoText();     // demonstrates Text objects
void demoMenu();     // demonstrates Menu objects
void myTextTest();  // some extra tests for Text
void myMenuTest();  // some extra tests for Menu

int main(){
//    demoText();
//    demoMenu();
//    myTextTest();
//    myMenuTest();
    return 0;
}
void demoMenu(){
    Menu menu;
    cout << menu << endl;
    int choice = menu.read_option_number();
    cout << "you entered: " << choice << endl;
    menu.push_back("Pepsi");
    cout << menu << endl;
    menu.push_back("Apple juice");
    menu.push_back("Root beer");
    choice = menu.read_option_number();
    cout << "you entered: " << choice << endl;
    menu.set_top_message("Choose your thirst crusher");
    menu.set_bottom_message("Enter a drink number");
    cout << menu << endl;
    menu.pop_back();
    menu.insert(2, "Iced tea with lemon");
    choice = menu.read_option_number();
    cout << "you entered: " << choice << endl;
    menu.pop_back();
    menu.remove(1);
    cout << menu << endl;
    menu.pop_back();
    cout << menu << endl;
    menu.clear_bottom_message();
    menu.set_top_message("Who Says You Can’t Buy Happiness?\n"
                         "Just Consider Our Seriously Delicious Ice Cream Flavors");
    menu.set_bottom_message("Enter the number of your Happiness! ");
    menu.push_back("Bacon ice cream!");
    menu.push_back("Strawberry ice cream");
    menu.push_back("Vanilla ice cream");
    menu.push_back("Chocolate chip cookie dough ice cream");
    choice = menu.read_option_number();
    cout << "you entered: " << choice << endl;
}
void demoText(){
    Text t1;// default constructor
    Text t2("quick brown fox");// conversion constructor
    Text t3{ t2 };// copy constructor
    cout << "t1: " << t1 << endl; // operator<< overload
    cout << "t2: " << t2 << endl;
    cout << "t3: " << t3 << endl;

    t1.append("The "); // append a given C-string to t1’s C-string
    cout << "t1: " << t1 << endl;
    t1.append(t2); // append t2’s C-string to t1’s C-string
    cout << "t1: " << t1 << endl;

    t2 = Text(" jumps over ");    // assignment operator overload
    cout << "t2: " << t2 << endl;

    t3.assign("a lazy dog"); // assign a given C-string to t3’s C-string
    cout << "t3: " << t3 << endl;

    t1.append(t2); // assign t2’s C-string to t1’s C-string
    cout << "t1: " << t1 << endl;
    t1.append(t3); // append t3’s C-string to t1’s C-string
    cout << "t1: " << t1 << endl;
    return;
}

void myTextTest() {
    Text t1;// default constructor
    Text t2("first text:");// conversion constructor
    t2.append("second text");   //append the second text to t2
    cout << "-------Test append -------" << endl;
    cout << "t2: " << t2 << endl;   //show the t2 after appending

    cout << "-------Test operator= overload-------" << endl;
    cout << "before assigning:" << endl;
    cout << "t1: " << t1 << endl;   //show the t1 before assigning
    cout << "t2: " << t2 << endl;   //show the t2 before assigning

    cout << "after assigning(t1=t2):" << endl;
    t1 = t2;
    cout << "t1: " << t1 << endl;   //show the t1 after assigning
    cout << "t2: " << t2 << endl;   //show the t2 after assigning

    cout << "-------Test clear()-------" << endl;
    t1.clear(); //clear the contents of t1
    cout << "t1: " << t1 << endl;
    cout << "t2: " << t2 << endl;

}

void myMenuTest(){
    Menu menu1, menu2;
    menu1.set_top_message("Top message");   //set top message
    menu1.set_bottom_message("Bottom message"); //set bottom message
    menu1.push_back("option1"); //add option1 to menue1
    menu1.push_back("option2");//add option2 to menue1

    cout << "-------menu2:Test operator= overload-------" << endl;
    menu2 = menu1;
    cout << menu2 << endl;

    cout << "-------menu3:Test copy constructor-------" << endl;
    Menu menu3 {menu1}; //copy constructor
    cout << menu3 << endl;

    cout << "-------menu3:Test push_back with Text& argument-------" << endl;
    Text t1("first text option");
    menu3.push_back(t1);    //push_back Text t1 to menu3
    cout << menu3 << endl;

    cout << "-------menu3:Test get() function-------" << endl;
    cout <<"menu3.get(3) = "<< menu3.get(3) << endl;

    cout << "-------menu3:Test insert() with Text& argument-------" << endl;
    Text t2("second text option");
    menu3.insert(3,t2); //insert Text t2 to the 3th position of menu
    cout << menu3 << endl;

    cout << "-------menu3:Test clear_top_message() and clear_bottom_message()-------" << endl;
    menu3.clear_top_message();  //clear the top_message
    menu3.clear_bottom_message();   //clear the bottom_message
    cout << menu3 << endl;

}