#include <iostream>
#include <fstream>
#include "canvas.hpp"
#include "draw_to_svg.hpp"

using namespace std;

int main(int argc, char *argv[]){
    
    int t[1];
    object O; 
    composedObject Co;
    canvas C; 
    string x;
    O = init_object(O,circle,"none","black",50,0,0,0,0,0,t);
    C = init_canvas(C,O,Co,10000,10000,5,7);
    //transform m[1]; 
    //m[0] = init_transform(m[0],rotation,40,50,50,0,0,0,O,Co);
    //ListTransform *T = create_list(&T,1,m);
    x = canvas_james_bond(C);
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