#include <iostream>
#include <fstream>
#include <random>
#include "canvas.hpp"
#include "draw_to_svg.hpp"
using namespace std;


int main(int argc,char *argv[]){
    object O;
    string x;    
    int ta[8] = {0,0,40,0,40,5,0,5};
    int w = rand()%5; 
    transform t;
    ListTransform *T;
    composedObject Co;
    //object m[9];
    canvas C;
    //Co = init_composedObject(Co,9,m);
    O = init_object(O,circle,"red","none",50,0,0,0,0,0,ta);
    C = init_canvas(C,O,Co,10000,10000,5,5);
    x = canvas_transform_simple_to_svg(C);
    cout << x;
    ofstream f(argv[1]);
    if (f){
        f << "<!DOCTYPE html>" << endl;
        f << "<html>" << endl;
        f << "<body>" << endl;
        f << x << endl;
        f << "</svg>" << endl;
        f << "</body>" << endl;
        f << "</html>";
    }
    f.close();
}
