#include <iostream>

#include <object.hpp>
#include <draw_to_svg.hpp>
#include <file.hpp>

#include <fstream>
using namespace std;


/* Seance 1-2 */

void carre_concentrique_to_svg(){
    ofstream f("carre_concentrique.html");
    if (f){
        f << "<!DOCTYPE html>" << endl
          << "<html>" << endl
          << "<body>" << endl
          << "<svg height=\"600\" width=\"600\">" << "<rect x=\"0\" y=\"0\" height=\"150\" width=\"150\" fill=\"brown\"/>" << endl
          << "<rect x=\"151\" y=\"0\" height=\"150\" width=\"150\" fill=\"brown\"/>" << endl
          << "<rect x=\"302\" y=\"0\" height=\"150\" width=\"150\" fill=\"brown\"/>" << endl
          << "<rect x=\"0\" y=\"151\" height=\"150\" width=\"150\" fill=\"gray\"/>" << endl
          << "<rect x=\"151\" y=\"151\" height=\"150\" width=\"150\" fill=\"gray\"/>" << endl
          << "<rect x=\"302\" y=\"151\" height=\"150\" width=\"150\" fill=\"gray\"/>" << endl
          << "<rect x=\"20\" y=\"20\" height=\"112.5\" width=\"112.5\" fill=\"black\"/>" << endl
          << "<rect x=\"170\" y=\"20\" height=\"112.5\" width=\"112.5\" fill=\"black\"/>" << endl
          << "<rect x=\"320\" y=\"20\" height=\"112.5\" width=\"112.5\" fill=\"black\"/>" << endl
          << "<rect x=\"20\" y=\"170\" height=\"112.5\" width=\"112.5\" fill=\"black\"/>" << endl
          << "<rect x=\"170\" y=\"170\" height=\"112.5\" width=\"112.5\" fill=\"black\"/>" << endl
          << "<rect x=\"320\" y=\"170\" height=\"112.5\" width=\"112.5\" fill=\"black\"/>" << endl
          << "<rect x=\"40\" y=\"40\" height=\"75\" width=\"75\" fill=\"white\"/>" << endl
          << "<rect x=\"190\" y=\"40\" height=\"75\" width=\"75\" fill=\"white\"/>" << endl
          << "<rect x=\"340\" y=\"40\" height=\"75\" width=\"75\" fill=\"white\"/>" << endl
          << "<rect x=\"40\" y=\"190\" height=\"75\" width=\"75\" fill=\"white\"/>" << endl
          << "<rect x=\"190\" y=\"190\" height=\"75\" width=\"75\" fill=\"white\"/>" << endl
          << "<rect x=\"340\" y=\"190\" height=\"75\" width=\"75\" fill=\"white\"/>" << endl
          << "<rect x=\"60\" y=\"60\" height=\"37.5\" width=\"37.5\" fill=\"purple\"/>" << endl
          << "<rect x=\"210\" y=\"60\" height=\"37.5\" width=\"37.5\" fill=\"blue\"/>" << endl
          << "<rect x=\"360\" y=\"60\" height=\"37.5\" width=\"37.5\" fill=\"green\"/>" << endl
          << "<rect x=\"60\" y=\"210\" height=\"37.5\" width=\"37.5\" fill=\"red\"/>" << endl
          << "<rect x=\"210\" y=\"210\" height=\"37.5\" width=\"37.5\" fill=\"orange\"/>" << endl
          << "<rect x=\"360\" y=\"210\" height=\"37.5\" width=\"37.5\" fill=\"yellow\"/>" << endl
          << "</svg>" << endl
          << "</body>" << endl
          << "</html>";
    }
    f.close();
}

/* Seance 3 */

object init_object(object O, nom nomfig, string couleur, string bordercouleur, int rayon, int cx, int cy, int height, int width, int taille, int t[]){
    O.e = nomfig;
    O.taille=taille;
    if (nomfig == rect){
        O.height = height;
        O.width = width;
        O.cx = cx;
        O.cy = cy;
    }
    if (nomfig == circle){
        O.rayon = rayon;
        O.cx = cx;
        O.cy = cy;
    }
    if (nomfig == polygon){
        O.tab = new int[O.taille];
        for (int i = 0;i<taille;i++){
            O.tab[i] = t[i];
        }
    }
    O.couleur = couleur;
    O.bordercouleur = bordercouleur;
    return O;
}

void afficher_object(object O){
    if (O.e == rect){
        cout << "nom : rectangle "<< endl;
        cout << "height : " << O.height << endl;
        cout << "width : " << O.width << endl;
        cout << "couleur : " << O.couleur << endl;
        cout << "couleur des bandes : " << O.bordercouleur << endl;
        cout << O.cx << " " << O.cy << endl;
    }
    if (O.e == circle){
        cout << "nom : cercle "<< endl;
        cout << "rayon : " << O.rayon << endl;
        cout << "cx : " << O.cx << endl;
        cout << "cy : " << O.cy << endl;
        cout << "couleur : " << O.couleur << endl;
        cout << "couleur des bandes : " << O.bordercouleur << endl;
    }
    if (O.e == polygon){
        cout << "nom : polygon "<< endl;
        cout << "points : ";
        for (int i = 0;i<O.taille-2;i=i+2){
            cout << O.tab[i] << "," << O.tab[i+1] << " ";
        }
        cout << endl;
        cout << "couleur : " << O.couleur << endl;
        cout << "couleur des bandes : " << O.bordercouleur << endl;
    }
}

objectV2 copie_objetc(object O, objectV2 copie){
    copie.e = O.e;
    copie.couleur = O.couleur;
    copie.bordercouleur = O.bordercouleur;
    copie.cx = O.cx;
    copie.cy = O.cy;
    copie.height = O.height;
    copie.width = O.width;
    copie.rayon = O.rayon;
    copie.taille = O.taille;
    copie.tab = new int[O.taille];
    for (int i = 0;i<O.taille;i++){
        copie.tab[i] = O.tab[i];
    }
    return copie;
}

// Seance 4 //

composedObject init_composedObject(composedObject Co, int nbObject, object O[]){
    Co.T = new object[nbObject];
    Co.nbObject = nbObject;
    for (int i = 0 ; i < Co.nbObject ; i++){
        Co.T[i] = O[i];
    }
    return Co;
}

composedObjectV2 copie_composedObject(composedObject Co, composedObjectV2 copie){
    copie.T = new object[Co.nbObject];
        for (int i = 0 ; i < Co.nbObject ; i++){
            copie.T[i] = Co.T[i];
        }
    return copie;
}

void afficher_composedObject(composedObject Co){
    for (int i = 0 ; i < Co.nbObject ; i++){
        afficher_object(Co.T[i]);
        cout << endl;
    }
}