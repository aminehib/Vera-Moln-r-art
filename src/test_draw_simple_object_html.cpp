#include <iostream>
#include <file.hpp>
#include <object.hpp>
#include <fstream>
using namespace std;

int main(int argc , char *argv[]){
    object O;
    string x;
    O = file_to_object(O,argv[1]);
    x = simpleObject_to_svg(O);
    ofstream f(argv[2]);
    if (f){
        f << "<!DOCTYPE html>" << endl;
        f << "<html>" << endl;
        f << "<body>" << endl;
        f << "<svg height=200 width=600>" << x << endl;
        f << "</svg>" << endl;
        f << "</body>" << endl;
        f << "</html>";
    }
    f.close();
}