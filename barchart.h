// barchart.h
//This file contains the functions that will create each individual bar that is eventually used in barchartanimation.h

#include <iostream>
#include <algorithm>
#include <map>
#include "myrandom.h" // used in graders, do not remove
#include "bar.h"

using namespace std;

// Constants used for bar chart animation.  You will primarily
// use these in barchartanimate.h, but you might find some useful here.
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";
const string RESET("\033[0m");


//
// NOTE: COMMENT AND UNCOMMENT AS NEEDED BASED ON YOUR TERMINAL
//
// Color codes for light mode terminals
// const string RED("\033[1;36m");
// const string PURPLE("\033[1;32m");
// const string BLUE("\033[1;33m");
// const string CYAN("\033[1;31m");
// const string GREEN("\033[1;35m");
// const string GOLD("\033[1;34m");
// const string BLACK("\033[1;37m");
// const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

// Color codes for darker mode terminals
const string CYAN("\033[1;36m");
const string GREEN("\033[1;32m");
const string GOLD("\033[1;33m");
const string RED("\033[1;31m");
const string PURPLE("\033[1;35m");
const string BLUE("\033[1;34m");
const string WHITE("\033[1;37m");
//const string RESET("\033[0m");
const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};



//
// BarChart
//
    class BarChart {
     private:
        //
        // Private member variables for the abstraction.
        // This implementation uses a low-level C array, bars, to store a list of
        // Bars.  As a result, you must also keep track of the number of elements
        // stored (size) and the capacity of the array (capacity).  This is not a
        // dynamic array, so it does not expand.
        //
        Bar* bars;  // pointer to a C-style array
        int capacity;
        int size;
        string frame;
     public:

        // default constructor:
        BarChart() {
            capacity = 0;
            size = 0;
            bars = NULL;
            frame = "";
        }

        // parameterized constructor:
        // Parameter passed in determines memory allocated for bars.
        BarChart(int n) {
            bars = new Bar[capacity];
            capacity = n;
            size = 0;
            frame = "";
            // TO DO:  Write this constructor.

        }

        //
        // copy constructor:
        //
        // Called automatically by C++ to create an BarChart that contains
        // a copy of an existing BarChart.  Example: this occurs when passing
        // BarChart as a parameter by value.
        //
        BarChart(const BarChart& other) {
            this->bars = new Bar[other.capacity];
            this->size = other.size;
            this->capacity = other.capacity;
            this->frame = other.frame;

            for(int i = 0;i<other.size;++i){
                this->bars[i] = other.bars[i];
            }
        }
        //
        // copy operator=
        //
        // Called when you assign one BarChart into another, i.e. this = other;
        //
        BarChart& operator=( const BarChart& other) {

            if(this == &other){
                return *this;
            }
            delete[]bars;
            this->bars = new Bar[other.capacity];
            this->size = other.size;
            this->capacity = other.capacity;
            // TO DO:  Write this operator.
            for(int i = 0;i<other.size;++i){
                this->bars[i] = other.bars[i];
            }

            return *this;
        }

        // clear
        // frees memory and resets all private member variables to default values.
        void clear() {

            if(bars != nullptr){
                delete[] bars;
            }
            size = 0;
            capacity = 0;
            frame = "";
            bars = NULL;
        }

        //
        // destructor:
        //
        // Called automatically by C++ to free the memory associated by the
        // BarChart.
        //
        virtual ~BarChart() {
            if( bars != nullptr){
                delete[]bars;
            }
            bars = NULL;
        }

        // setFrame
        void setFrame(string frame) {
            frame = frame;
        }

        // getFrame()
        // Returns the frame of the BarChart oboject.
        string getFrame() {
            return frame; // TO DO:  update this, it is only here so code compiles.
        }

        // addBar
        // adds a Bar to the BarChart.
        // returns true if successful
        // returns false if there is not room
        bool addBar(string name, int value, string category) {
            if(size < capacity){
                Bar *juiceBox = new Bar(name, value, category);
                bars[size]= *juiceBox;
                size++;
                return true;
            }


            return false;
        }

        // getSize()
        // Returns the size (number of bars) of the BarChart object.
        int getSize() {
             return size;  // TO DO:  update this, it is only here so code compiles.
        }
    // operator[]
        // Returns Bar element in BarChart.
        // This gives public access to Bars stored in the Barchart.
        // If i is out of bounds, throw an out_of_range error message:
        // "BarChart: i out of bounds"
        Bar& operator[](int i) {
        if(i<0 || i>= size){
            throw out_of_range("BarChart: i out of bounds");
        }
        return bars[i];

        }

        // dump
        // Used for printing the BarChart object.
        // Recommended for debugging purposes.  output is any stream (cout,
        // file stream, or string stream).
        // Format:
        // "frame: 1
        // aname 5 category1
        // bname 4 category2
        // cname 3 category3" <-newline here
        void dump(ostream &output) {
            BarChart temp(*this);
            sort(temp.bars,temp.bars+temp.size,greater<Bar>());
            output<<"Frame: "<<this->frame<<endl;
            for(int i = 0; i < size; i++){
                output<<temp.bars[i].getName()<<" ";
                output<<temp.bars[i].getValue()<<" ";
                output<<temp.bars[i].getCategory()<<endl;
            }
        }

        // graph
        // Used for printing out the bar.
        // output is any stream (cout, file stream, string stream)
        // colorMap maps category -> color
        // top is number of bars you'd like plotted on each frame (top 10? top 12?)
        void graph(ostream &output, map<string, string> &colorMap, int top) {
            //sort
            sort(bars, bars + size, greater<Bar>());
            //setting max for top
            int lenMax = 60;
            //setting color to empty
            string color = "";
            int topVal = bars[0].getValue();
            for(int i = 0; i < top; i++) {
                string barstr = "";
                double lowVal = bars[i].getValue();
                for (int j = 0;j < static_cast<int>((lowVal / topVal) * lenMax); j++) {
                    barstr += BOX;
                }
                if (colorMap.count(bars[i].getCategory()) != 0) {
                    color = colorMap[bars[i].getCategory()];
                }
                else {
                    color = WHITE;
                }
                output << color << barstr << " ";
                output << bars[i].getName() << " ";
                output << bars[i].getValue() << endl;
                barstr = "";
            }
      }

    };

