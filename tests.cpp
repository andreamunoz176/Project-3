#include <iostream>
#include "barchartanimate.h"
using namespace std;


bool testBarDefaultConstructor() {
	Bar b;
    if (b.getName() != "") {
    	cout <<"testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout <<"testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}
bool testBarChartDefault(){
    BarChart bc;
    if(bc.getSize() != 0){
        cout << "testBarChartDefault: getSize failed" << endl;
        return false;
    }
    else if(bc.getCapacity() != 0){
        cout << "testBarChartDefault: getCapacity failed" << endl;
        return false;
    }
    cout << "testBarChartDefault: all passed!" << endl;
    return true;
}
bool testBarChart(){
    BarChart bc(10);
    if(bc.getCapacity() != 10){
        cout << "testBarChartDefault: getCapacity failed" << endl;
        return false;
    }
    else if(bc.getSize() != 0){
        cout << "testBarChartDefault: getSize failed" << endl;
        return false;
    }
    cout << "testBarChart: all passed!" << endl;
    return true;
}
bool testBarChartCopy(){
    BarChart bc(10);
    BarChart bcCopy(bc);
    // loop throguh bar value
    // checking if each value matches
    if(bcCopy.getCapacity() != 10){
        cout << "testBarChartDefault: getCapacity failed" << endl;
        return false;
    }
    else if(bcCopy.getSize() != 0){
        cout << "testBarChartDefault: getSize failed" << endl;
        return false;
    }
    cout << "testBarChartCopy: all passed!" << endl;
    return true;

}
bool testBarChartCompare(){

    BarChart bc1;
    BarChart bc2(10);
    if(bc1.getCapacity() != bc2.getCapacity()){
        cout << "testBarChartCompare: getCapacity failed" << endl;
        return false;
    }
    if(bc1.getSize() != bc2.getSize()){
        cout << "testBarChartCompare: getSize failed" << endl;
        return false;
    }
    cout << "testBarChartCompare: all passed!" << endl;
    return true;

}
bool testBarChartClear(){
    BarChart bc(10);
    bc.clear();
    if(bc.getSize() != 0){
        cout << "testBarChartDefault: getSize failed" << endl;
        return false;
    }
    else if(bc.getCapacity() != 0){
        cout << "testBarChartDefault: getCapacity failed" << endl;
        return false;
    }
    cout << "testBarChartDefault: all passed!" << endl;
    return true;

}

//BarChart bc(10);
//BarChart bc(10);
//BarChart bcCopy(bc);
//BarChart bc1;
//BarChart bc2(10);
//bc1 = bc2;
//BarChart bc(10);
//bc.clear();
//
//
//BarChart bc(3);
//bc.setFrame(“1950”);
//bc.getFrame();
//bc.addBar("Chicago", 1020, "US");
//bc.addBar("NYC", 1300, "US");
//bc.addBar("Paris", 1200, "France");
//int n = bc.getSize();
//for (int i = 0; i < n; i++) {
//cout << bc[i].getName() << " ";
//cout << bc[i].getValue() << " ";
//cout << bc[i].getCategory();
//cout << endl;
//}
//Option 1:
//bc.dump(cout);
//Option 2:
//stringstream ss("");
//bc.dump(ss);
//cout << ss.str();


int main() {

	testBarDefaultConstructor();
	testBarParamConstructor();
    testBarChartDefault();
    testBarChart();
    testBarChartCopy();
    testBarChartCompare();
    map<string, string> colorMap;
BarChart bc(3);
bc.setFrame("1950");
bc.getFrame();
bc.addBar("Chicago", 1020, "US");
bc.addBar("NYC", 1300, "US");
bc.addBar("Paris", 1200, "France");
bc.graph(cout, colorMap,10);
stringstream ss("");
bc.dump(ss);
    return 0;
}