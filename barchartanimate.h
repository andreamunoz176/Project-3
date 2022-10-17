// barchartanimate.h
// This file contains the functions that will create an animation of the moving data of the txt file using bar.h and barchart.h files

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used by graders, do not remove
#include "barchart.h"
  
using namespace std;

//
// BarChartAnimate
//
class BarChartAnimate {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    string title;
    string xlabel;
    string source;
    map<string, string> colorMap;
    int unsigned colorIndex = 0;
    void setColor(string category) {
        if(colorMap.find(category) == colorMap.end()) {
            int variable = COLORS.size();
            if(colorIndex == variable) {
                colorIndex = 0;
            }
            colorMap[category] =  COLORS[colorIndex];
            colorIndex++;
        }
    }
    // private helper function help parse the lines in the .txt files to get
    // the proper variables needed to add bars to the frame
    void parseLine(string line, BarChart& b) {
        stringstream word(line);
        string frame, name, blank, tempvalue, category;
        getline(word, frame, ',');
        getline(word, name, ','); //name
        getline(word, blank, ','); //not needed
        getline(word, tempvalue, ','); //value
        int value = stoi(tempvalue);
        getline(word, category, '\n'); // category
        b.setFrame(frame);
        b.addBar(name, value, category);
        setColor(category);
    }
 public:

    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
        capacity = 4;
        size = 0;
        barcharts = new BarChart[4];
        this->title = title;
        this->xlabel = xlabel;
        this->source = source;
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() {
        if(barcharts != nullptr){
            delete[] barcharts;
        }
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    void addFrame(ifstream &file) {
        string throwaway, line;
        getline(file, throwaway);
        if (!file.fail()) {
            string sizeTemp;
            getline(file, sizeTemp);
            int size = stoi(sizeTemp);
            BarChart b(size);
            if (this->size == capacity)
            {
                int Capa = capacity * 2;
                BarChart* temp = new BarChart[Capa];
                for (int i = 0; i < this->size; ++i)
                {
                    temp[i] = barcharts[i];
                }
                delete[] barcharts;
                barcharts = temp;
                capacity = Capa;
            }
            for(int i = 0; i < size; i++) {
                getline(file, line);
                parseLine(line,b);
            }
            this->barcharts[this->size] = b;
            this->size++;
        }
    }

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;
        int num = endIter;
        if(endIter == -1){
            num = size;
        }

        for (int i = 0; i < endIter; ++i) {
            usleep(3*microsecond);
            output << CLEARCONSOLE;
            output << WHITE << title << endl;
            output << WHITE << source << endl;
            barcharts[i].graph(output, colorMap, top);
            output << WHITE << xlabel << endl;
            output << WHITE <<"Frame: " << barcharts[i].getFrame() << endl;
        }
	}

    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize(){
        
        return size;
        
    }

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //

    BarChart& operator[](int i){
        if(i<0 ||i>= size){
            throw out_of_range("barchartanimate: i out of bounds");
        }
        return barcharts[i];
    }
};
