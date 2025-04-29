#include <iostream>
#include "object.hpp"
using namespace std;
#ifndef _canvas_hpp
#define _canvas_hpp

struct canvas{
    int height;
    int width;
    composedObject Co;
    object O;
    int repLig;
    int repCol;
};

canvas init_canvas(canvas C , object O,composedObject Co, int height, int width, int repCol, int repLig);

void translate_object(object *O, int x,int y);

void translate_composedObject(composedObject *Co, int x,int y);

string canvas_composed_to_svg(canvas C);

void dilatation_object(object *O,int x);

void dilatation_composedObject(composedObject *Co,int x);

void reduction_object(object *O,int x);

void reduction_composedObject(composedObject *Co,int x);

void rotation_object(object *O, int deg, float Ox, float Oy);

void rotation_composedObject(composedObject *Co, int deg, float Ox, float Oy);

string canvas_transform_simple_to_svg(canvas C);

string canvas_transform_composed_to_svg(canvas C);

// Séance 6 //

enum type{
    rotation,dilatation,translation,reduction
};

struct transform{
    type nom;
    object O;
    composedObject Co;
    int deg,Ox,Oy,x,y,prct;
};

struct ListTransform{
    transform T;
    ListTransform *next;
};

transform init_transform(transform t, type nom , int deg,int Ox, int Oy, int x, int y, int prct, object O, composedObject Co);

ListTransform* create_list(ListTransform **T,int nb,transform t[]);

string canvas_list_transform_simpleObject_to_svg(transform t,canvas C);

string canvas_list_listTransform_simpleObject_to_svg(ListTransform *T,canvas C,int nb);

string canvas_james_bond(canvas C);

void couleur(object *O,string x);

int alea(int n1,int n2);

#endif