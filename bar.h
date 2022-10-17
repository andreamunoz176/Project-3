// bar.h
// This function this file creates the most basic properties of the individual bars such as the name, value and category. It also includes the comparison operator definitons

#include <iostream>
#include <string>
#include "myrandom.h" // used in graders, do not remove
using namespace std;

//
// Bar
//
class Bar {
 private:
    // Private member variables for a Bar object
    // TO DO:  Define private member variables for this class
    // NOTE: You should not be allocating memory on the heap for this class.
    int value;
    string category;
    string name;
 public:
    // default constructor:
    //Setting the values to empty string or zero
    Bar() {
         name = "";
         category = "";
        value = 0;
    }

    //
    // a second constructor:
    //
    // Parameter passed in constructor Bar object.
    Bar(string name, int value, string category) {
        this->name = name;
        this->value = value;
        this->category = category;
       
    }

    // destructor:
    virtual ~Bar() {
    }

    // getName:
	string getName() {
        return name;
	}

    // getValue:
	int getValue() {
        return value;
	}

    // getCategory:
	string getCategory() {
        return category;
	}

	// operators
   // This allows you to compare two Bar
    // objects.  Comparison should be based on the Bar's value.  For example:
    //GreaterThan Function
	bool operator<(const Bar &other) const {
        return(value < other.value);
	}
//GreaterThan OR Equal To Function
	bool operator<=(const Bar &other) const {
        return(value <= other.value);
	}
//LessThan Function
	bool operator>(const Bar &other) const {
        return(value > other.value);
	}
//LessThanOrEqualTo Function
	bool operator>=(const Bar &other) const {
        return(value >= other.value);
	}
};

