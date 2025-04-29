#include <iostream>
#include <object.hpp>
#include <file.hpp>
#include <draw_to_svg.hpp>
using namespace std;

int main(int argc, char *argv[]){
    composedObject Co1;
    Co1 = file_to_composedObject(Co1,argv[1]);
    //afficher_composedObject(Co1);
    composedObject_to_file(Co1,argv[2]);
    delete[] Co1.T; 
}