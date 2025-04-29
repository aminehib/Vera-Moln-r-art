#include <iostream>
#include <fstream>
#include "canvas.hpp"
using namespace std;

int main(int argc,char *argv[]){
    /*
    object O;
    composedObject Co;
    string x;
    canvas C;
    transform T;
    int t[0];
    O = init_object(O,rect,"red","black",0,0,0,100,100,0,t);
    T = init_transform(T,dilatation,0,0,0,0,0,2,O,Co);
    C = init_canvas(C,O,Co,1000,1000,2,2);
    x = canvas_list_transform_simpleObject_to_svg(T,C);
    ofstream f(argv[1]);
    if (f){
        f << "<!DOCTYPE html>" << endl;
        f << "<html>" << endl;
        f << "<body>" << endl;
        f << x << endl;
        f << "</body>" << endl;
        f << "</html>";
    }
    f.close();
    */
    string x;
    ListTransform *p;
    object O;
    canvas C;
    object h[1];
    int t[9] = {25,25,75,25,75,75,25,75};
    O = init_object(O,polygon,"red","none",0,0,0,0,0,9,t);
    h[0] = init_object(h[0],rien,"none","none",0,0,0,0,0,0,t);
    composedObject Co = init_composedObject(Co,1,h);
    int MAX = 3;
    transform tr[MAX];
    tr[0] = init_transform(tr[0],dilatation,0,0,0,0,0,2,O,Co);
    tr[1] = init_transform(tr[1],translation,0,0,0,20,75,0,O,Co);
    tr[2] = init_transform(tr[2],rotation,45,50,50,0,0,0,O,Co);    
    p = create_list(&p,MAX,tr);
    C = init_canvas(C,O,Co,1000,1000,2,2);
    x = canvas_list_listTransform_simpleObject_to_svg(p,C,MAX);
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
    f.close();
}
