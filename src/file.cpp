#include <iostream>
#include <file.hpp>
#include <object.hpp>
#include <fstream>

/* Seance 1-2 */

void canvas_to_file(string x,string nom){
    ofstream f(nom);
    if (f){
        f << "<!DOCTYPE html>" << endl
          << "<html>" << endl
          << "<body>" << endl
          << "<svg "  << x << endl << "</svg>" << endl
          << "</body>" << endl
          << "</html>";
    }
    f.close();
}

void canvas_exemple_to_file(string x,string nom,int exemple){
    ofstream f(nom);
    if (f){
        f << "<!DOCTYPE html>" << endl
          << "<html>" << endl
          << "<body>" << endl
          << "<svg " << x << endl
          << "</svg>" << endl
          << "</body>" << endl
          << "</html>";
    }
    f.close();
}


void read_txt(string nomfichier,read c){
    string result;
    int nbP;
    string nom;
    ifstream f(nomfichier);
    f >> c.nom;
    if (c.nom=="circle" or c.nom=="Circle"){
        f >> c.cx >> c.cy >> c.r;
        result = "<circle cx=\"" + to_string(c.cx) + "\" cy=\"" + to_string(c.cy) + "\" r=\"" + to_string(c.r) + "\"/>";
    } 
    if (c.nom=="rect" or c.nom=="Rect"){
        f >> c.width >> c.height >> c.x >> c.y;
        result = "<rect width=\"" + to_string(c.width) + "\" height=\"" + to_string(c.height) + "\" x=\"" + to_string(c.x) + "\" y=\"" + to_string(c.y) +"\"/>";
    }
    if (c.nom == "polygon" or c.nom == "Polygon"){
            f >> nbP;
            c.t=new float[nbP];
            for (int i = 0;i < nbP;i++){
                f >> c.t[i];
            }
        result = "<polygon points=\"";
        for (int j = 0;j<nbP;j++){
            result = result + to_string(c.t[j]) + " ";
        }
        result = result + "\" />";
    }
    f.close();
    cout << "nom du fichier à créé ?";
    cin >> nom;
    ofstream fic(nom);
    if (fic){
        fic << "<!DOCTYPE html>" << endl
          << "<html>" << endl
          << "<body>" << endl
          << "<svg height=\"200\" width=\"600\">" << result << endl
          << "</svg>" << endl
          << "</body>" << endl
          << "</html>";
    }
    fic.close();
}

/* Seance 3 */

object file_to_object(object O,string nomfichier){
    string forme;
    ifstream f(nomfichier);
    f >> forme;
    if (forme == "rectangle" or forme == "Rectangle"){
        O.e = rect;
        f >> O.height;
        f >> O.width;
    }
    if (forme == "circle" or forme == "Circle"){
        O.e = circle;
        f >> O.cx;
        f >> O.cy;
        f >> O.rayon;
    }
    if (forme == "polygon" or forme == "Polygon"){
        O.e = polygon;
        f >> O.taille;
        O.tab = new int[O.taille];
        for (int i = 0;i<O.taille;i++){
            f >> O.tab[i];
        }
    }
    f >> O.couleur;
    f >> O.bordercouleur;
    f.close();
    return O;
}

void object_to_file(object O,string nomfichier){
    ofstream f(nomfichier);
    if (f){
        if (O.e == rect){
            f << "rectangle" << " ";
            f << O.height << " ";
            f << O.width << " ";
        }
        if (O.e == circle){
            f << "circle" << " ";
            f << O.cx << " ";
            f << O.cy << " ";
            f << O.rayon << " ";
        }
        if (O.e == polygon){
            f << "polygon" << " ";
            f << O.taille << " ";
            for (int i = 0 ; i < O.taille ; i++){
                f << O.tab[i] << " ";
            }
        }
        f << O.couleur << " "; 
        f << O.bordercouleur << " ";
    }
}

// Seance 4 //

composedObject file_to_composedObject(composedObject Co,string nomfichier){
    string forme;
    ifstream f(nomfichier);
    f >> Co.nbObject;
    Co.T = new object[Co.nbObject];
    for(int i = 0 ; i < Co.nbObject ; i++){
        f >> forme;
        if (forme == "rectangle" or forme == "Rectangle"){
            Co.T[i].e = rect;
            f >> Co.T[i].height;
            f >> Co.T[i].width;
        }
        if (forme == "circle" or forme == "Circle"){
            Co.T[i].e = circle;
            f >> Co.T[i].cx;
            f >> Co.T[i].cy;
            f >> Co.T[i].rayon;
        }
        if (forme == "polygon" or forme == "Polygon"){
            Co.T[i].e = polygon;
            f >> Co.T[i].taille;
            Co.T[i].tab = new int[Co.T[i].taille];
            for (int j = 0;i<Co.T[i].taille;j++){
                f >> Co.T[i].tab[j];
            }
        }
        f >> Co.T[i].couleur;
        f >> Co.T[i].bordercouleur;
    }
    f.close();
    return Co;
}

void composedObject_to_file(composedObject Co,string nomfichier){
    ofstream f(nomfichier);
    if (f){
        for (int i = 0 ; i < Co.nbObject ; i++){
            if (Co.T[i].e == rect){
            f << "rectangle" << " ";
            f << Co.T[i].height << " ";
            f << Co.T[i].width << " ";
            }
            if (Co.T[i].e == circle){
                f << "circle" << " ";
                f << Co.T[i].cx << " ";
                f << Co.T[i].cy << " ";
                f << Co.T[i].rayon << " ";
            }
            if (Co.T[i].e == polygon){
                f << "polygon" << " ";
                f << Co.T[i].taille << " ";
                for (int j = 0 ; j < Co.T[i].taille ; j++){
                    f << Co.T[i].tab[j] << " ";
                }
            }
            f << Co.T[i].couleur << " "; 
            f << Co.T[i].bordercouleur << " ";
            f << endl;
        }
    }
}

