#ifndef _object_hpp
#define _object_hpp
#include <iostream>
using namespace std;

/* Seance 1-2 */

struct Point{
    int x;
    int y;
};

struct read{
    string nom;
    int cx;
    int cy;
    int r;
    float *t;
    int width;
    int height;
    int x;
    int y;
    string color;
};


void carre_concentrique();

void carre_concentrique_to_svg();

/* Seance 3 */

enum nom {
    rect, circle, polygon, rien
};

struct object {
    int rayon, cx, cy;
    int height, width;
    int *tab;
    int taille;
    string couleur, bordercouleur;
    nom e;
};


struct objectV2{
    int rayon, cx, cy;
    int height, width;
    int *tab;
    int taille;
    string couleur, bordercouleur;
    nom e;
};


object init_object(object O, nom nomfig, string couleur, string bordercouleur, int rayon, int cx, int cy, int height, int width, int taille, int tab[]);

void afficher_object(object O);

objectV2 copie_objetc(object O, objectV2 copie);

// Seance 4 //

struct composedObject{
    int nbObject;
    object *T;
};

struct composedObjectV2{
    int nbObject;
    object *T;
};

composedObject init_composedObject(composedObject Co, int nbObject, object O[]);

composedObjectV2 copie_composedObject(composedObject Co, composedObjectV2 copie);

void afficher_composedObject(composedObject Co);


#endif
