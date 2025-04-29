#include <iostream>
#include <fstream>
#include <object.hpp>
#include <file.hpp>
#include <draw_to_svg.hpp>
using namespace std;

int main(int argc, char * argv[]){
    composedObject Co1;
    object O[3];
    int tab[10] = {30, 76, 42, 86, 21, 81, 01, 25, 43, 62};
    O[0] = init_object(O[0],rect,"red","black",0,0,0,250,250,0,0);
    O[1] = init_object(O[1],circle,"red","black",40,50,50,0,0,0,0);
    O[2] = init_object(O[2],polygon,"red","black",0,0,0,0,0,10,tab);
    Co1 = init_composedObject(Co1,3,O);
    afficher_composedObject(Co1);
}