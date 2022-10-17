#include <iostream>
#include "barchartanimate.h"
#include <fstream>
#include <sstream>
#include <map>
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
bool NumOnetestBarParamConstructor() {
    Bar b("NYC", 90000000, "US");
    if (b.getName() != "NYC") {
        cout << "testBarParamConstructor: getName failed" << endl;
        return false;
    } else if (b.getValue() != 90000000) {
        cout << "testBarParamConstructor: getValue failed" << endl;
        return false;
    } else if (b.getCategory() != "US") {
        cout << "testBarParamConstructor: getCategory failed" << endl;
        return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}
//GreaterThan test
bool testBarOperators(){
    Bar Chicago("Chicago", 1000, "Illinois");
    Bar Atlanta("Atlanta", 1000, "Georgia");
    Bar LA("LA", 2000, "California");
    if(Chicago>LA){
        cout<<"testBarOperators: returns false"<<endl;
        return false;
    }
    else if(Atlanta>LA){
        cout<<"testBarOperators: returns false"<<endl;
        return false;
    }
    cout<<"testBarOperators: returns true"<<endl;
    return true;
}
bool NumOnetestBarOperators(){
    Bar Chicago("Chicago", 1000, "Illinois");
    Bar Atlanta("Atlanta", 1000, "Georgia");
    Bar LA("LA", 2000, "California");
    if(Chicago>=LA){
        cout<<"testBarOperators: returns false"<<endl;
        return false;
    }
    else if(Atlanta>=LA){
        cout<<"testBarOperators: returns false"<<endl;
        return false;
    }
    cout<<"testBarOperators: returns true"<<endl;
    return true;
}
bool NumTwotestBarOperators(){
    Bar Chicago("Chicago", 1000, "Illinois");
    Bar Atlanta("Atlanta", 1000, "Georgia");
    Bar LA("LA", 2000, "California");
    if(LA<Chicago){
        cout<<"testBarOperators: returns false"<<endl;
        return false;
    }
    else if(LA<Atlanta){
        cout<<"testBarOperators: returns false"<<endl;
        return false;
    }
    cout<<"testBarOperators: returns true"<<endl;
    return true;
}
bool testBarChartDefault(){
    BarChart bc;
    if(bc.getSize() != 0){
        cout << "testBarChartDefault: getSize failed" << endl;
        return false;
    }
    else if(bc.getFrame() != ""){
        cout << "testBarChartDefault: getCapacity failed" << endl;
        return false;
    }
    cout << "testBarChartDefault: all passed!" << endl;
    return true;
}
bool testBarChart(){
    BarChart bc(10);
    if(bc.getFrame() != ""){
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
bool testBarChartCompare(){

    BarChart bc1;
    BarChart bc2(10);
    if(bc1.getSize() != bc2.getSize()){
        cout << "testBarChartCompare: getSize failed" << endl;
        return false;
    }
    cout << "testBarChartCompare: all passed!" << endl;
    return true;

}
void testBarChartClear(){
    BarChart bc(10);
    bc.addBar("hello", 10, "goodbye");
    bc.clear();
    if(bc.getSize() == 0){
        cout << "testBarChartClear: passed!" << endl;
    }
    else {
        cout << "testBarChartClear: failed" << endl;
    }
}
void testBarChartGetSize(){
    BarChart b(10);
    b.addBar("",10,"");
    b.addBar("",10,"");
    b.addBar("",10,"");
    b.addBar("",10,"");
    b.addBar("",10,"");
    b.addBar("",10,"");
    b.addBar("",10,"");
    b.addBar("",10,"");
    b.addBar("",10,"");
    b.addBar("",10,"");
    if(b.getSize() == 10){
        cout<<"testBarChartGetSize: passed!"<<endl;
    }
    else{
        cout<<"testBarChartGetSize: failed!"<<endl;
    }
}
bool testBarChartAddBar(){

    BarChart bc(10);
    bc.addBar("Chicago", 1020, "US");
    bc.addBar("NYC", 1300, "US");
    bc.addBar("Paris", 1200, "France");
    if(bc.getSize() != 3){
        cout<<"testBarChartAddBar: getSize failed"<<endl;
        return false;
    }
    else if(bc[0].getName() != "Chicago"||bc[0].getValue() != 1020||bc[0].getCategory() != "US"){
        cout<<"testBarChartAddBar: Chicago failed"<<endl;
        return false;
    }
    else if(bc[1].getName() != "NYC"||bc[1].getValue() != 1300||bc[1].getCategory() != "US"){
        cout<<"testBarChartAddBar: NYC failed"<<endl;
        return false;
    }
    else if(bc[2].getName() != "Paris"||bc[2].getValue() != 1200||bc[2].getCategory() != "France"){
        cout<<"testBarChartAddBar: Paris failed"<<endl;
        return false;
    }
    cout<<"testBarChartAddBar: all passed"<<endl;
    return true;
}
bool testBarChartDump(){
    BarChart bc(10);
    bc.setFrame("");
    bc.addBar("Chicago", 1020, "US");
    bc.dump(cout);


    BarChart bc1(2);
    bc1.addBar("Chicago", 1020, "US");
    bc1.addBar("NYC", 1300, "US");
    bc1.setFrame("1950");
    stringstream ss1("");
    bc1.dump(ss1);
    cout<<ss1.str()<<endl;

}
void testBarChartGraph(){
    BarChart bc(3);
   bc.addBar("Paris", 1200, "France");
   bc.addBar("Chicago", 1020, "US");
   bc.addBar("NYC",1300,"US");
   bc.setFrame("1950");
   bc.getFrame();
   string red("\033[1;36m");
   string blue("\033[1;33m");
   map<string, string>colorMap;
   colorMap["US"]= red;
   colorMap["France"]= blue;
   bc.graph(cout,colorMap,3);
}
void NumTwotestBarChartGraph() {
    BarChart b(10);
    b.addBar("Chicago", 400000, "US");
    b.addBar("Paris", 500000, "France");
    b.addBar("New York", 450000, "US");
    b.addBar("LA", 425000, "US");
    b.addBar("Miami", 350000, "US");
    b.addBar("Rome", 700000, "Italy");
    b.addBar("Florence", 200000, "Italy");
    string red("\033[1;36m");
    string blue("\033[1;33m");
    string green("\033[1;35m");
    map<string, string> colorMap;
    colorMap["US"] = red;
    colorMap["France"] = blue;
    colorMap["Italy"] = green;
    b.graph(cout, colorMap, 8);
}
void barcharttestanimation(){
    string filename = "cities.txt";
    ifstream inFile(filename);
    string title;
    getline(inFile, title);
    string xlabel;
    getline(inFile, xlabel);
    string source;
    getline(inFile, source);

    BarChartAnimate bca(title, xlabel, source);

    while (!inFile.eof()) {
        bca.addFrame(inFile);
    }

    bca.animate(cout, 12, -1);
}
int main() {
	testBarDefaultConstructor();
	testBarParamConstructor();
    NumOnetestBarParamConstructor();
    testBarChartDefault();
    testBarChart();
    testBarOperators();
    NumTwotestBarOperators();
    NumOnetestBarOperators();
    testBarChartCompare();
    testBarChartClear();
    testBarChartGetSize();
    testBarChartAddBar();
    testBarChartDump();
    testBarChartGraph();
    NumTwotestBarChartGraph();
    //barcharttestanimation();
    return 0;
}