#ifndef _file_hpp
#define _file_hpp

#include <iostream>
#include <draw_to_svg.hpp>
#include <object.hpp>

using namespace std;

/* Seance 1-2 */

void canvas_to_file(string x,string nom);

void canvas_exemple_to_file(string x,string nom,int exemple);

void read_txt(string nomfichier,read c);

/* Seance 3 */

object file_to_object(object O,string nomfichier);

void object_to_file(object O,string nomfichier); 

// Seance 4 //

composedObject file_to_composedObject(composedObject Co,string nomfichier);

void composedObject_to_file(composedObject Co,string nomfichier);

#endif