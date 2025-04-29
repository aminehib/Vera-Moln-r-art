#include <iostream>
#include <fstream>
#include "canvas.hpp"
using namespace std;

int main(int argc , char *argv[]){
    canvas C;
    object O;
    object Ta[4];
    int T[0];
    composedObject Co;
    Ta[0]= init_object(O,rect,"red","black",0,5,5,150,150,0,T);
    Ta[1]= init_object(O,rect,"red","black",0,5,5,150,150,0,T);
    Ta[2]= init_object(O,rect,"red","black",0,5,5,150,150,0,T);
    Ta[3]= init_object(O,rect,"red","black",0,5,5,150,150,0,T);
    Co = init_composedObject(C.Co,5,Ta);
    string x;
    O = init_object(O,rien,"none","none",0,0,0,0,0,0,T);
    C = init_canvas(C,O,Co,200,200,2,2);
    x = canvas_composed_to_svg(C);
    cout << x;
    ofstream f(argv[1]);
    if (f){
        f << "<!DOCTYPE html>" << endl;
        f << "<html>" << endl;
        f << "<body>" << endl;
        f << x << endl;
        f << "</body>" << endl;
        f << "</html>";
    }
}