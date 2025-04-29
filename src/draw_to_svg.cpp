#include <iostream>
#include "draw_to_svg.hpp"
#include "object.hpp"

/* Seance 1-2 */

string circle_to_svg(Point C,int r){
    string result;
    result = "<circle cx=\"" + to_string(C.x) + "\" cy=\"" + to_string(C.y) + "\" r=\"" + to_string(r) + "\">";
    return result; 
}

string polygon_to_svg(int nbP,Point C[]){
    string result;
    result = "<polygon points=\"";
    for (int i = 0 ; i < nbP ; i++){
        result = result + to_string(C[i].x) + "," + to_string(C[i].y) + " ";
    }
    result = result + "\"/>";
    return result; 
}

string canvas_to_svg(int height,int width,string carac){
    string result;
    result = "height=\"" + to_string(height) + "\" width=\"" + to_string(width) + "\"xmlns=\"http://www.w3.org/2000/svg\">" + carac;
    return result;
}

string exemple1_to_svg(int height,int width){
    string result;
    result = "height=\"" + to_string(height) + "\" width=\"" + to_string(width) + "\">"
    + "<rect width=\"250\" height=\"250\" fill=\"gray\"/>"
    + "<circle cx=\"50\" cy=\"50\" r=\"40\" fill=\"yellow\" stroke=\"red\"/>"
    + "<polygon points=\"100,50 225,100 250,20 120,230\" fill=\"green\" />";
    return result;
}

string exemple2_to_svg(int height,int width){
    string result;
    result = "height=\"" + to_string(height) + "\" width=\"" + to_string(width) + "\">"
    + "<rect width=\"250\" height=\"250\" fill=\"gray\"/>"
    + "<circle cx=\"50\" cy=\"50\" r=\"40\" fill=\"yellow\" stroke=\"red\"/>"
    + "<polygon points=\"50,50 175,100 200,20 70,230\" fill=\"green\" />";
    return result;
}

string exemple3_to_svg(int height,int width){
    string result;
    result = "height=\"" + to_string(height) + "\" width=\"" + to_string(width) + "\">"
    + "<rect width=\"250\" height=\"250\" fill=\"gray\"/>"
    + "<polygon points=\"50,50 175,100 200,20 70,230\" fill=\"green\" />"
    + "<circle cx=\"50\" cy=\"50\" r=\"40\" fill=\"yellow\" stroke=\"red\"/>";
    return result;
}

/* Seance 3 */

string simpleObject_to_svg(object O){
    string result;
    if (O.e == rect){
        result = "<rect x=\"" + to_string(O.cx) + "\" y=\"" + to_string(O.cy) + "\" height=\"" + to_string(O.width) + "\" width=\"" + to_string(O.width) + "\" fill=\"" + O.couleur + "\" stroke=\"" + O.bordercouleur + "\"/>";

    }
    if (O.e == circle){
        result = "<circle cx=\"" + to_string(O.cx) + "\" cy=\"" + to_string(O.cy) + "\" r=\"" + to_string(O.rayon) + "\" fill=\"" + O.couleur + "\" stroke=\"" + O.bordercouleur + "\"/>";
    }
    if (O.e == polygon){
        result = "<polygon points=\"";
        for (int i=0;i<O.taille-2;i=i+2){
            result = result + to_string(O.tab[i]) + "," + to_string(O.tab[i+1]) + " ";
        }
        result = result + "\" fill=\"" + O.couleur + "\" stroke=\"" + O.bordercouleur + "\"/>";
    }
    return result;
}

// Seance 4 //

string composedObject_to_svg(composedObject Co){
    string result;
    for (int i = 0 ; i < Co.nbObject ; i++){
        result = result + simpleObject_to_svg(Co.T[i]);
    }
    return result;
}

