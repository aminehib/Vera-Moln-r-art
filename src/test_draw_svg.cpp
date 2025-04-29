#include <file.hpp>
#include <draw_to_svg.hpp>
#include <object.hpp>
#include <iostream>
using namespace std;

int main() {
    
    // seance 1-2 //

    /*
    Point centre;
    int r;
    string caracC;
    string canvasC;
    string nomC;
    cout << "Centre du cercle x,y?";
    cin >> centre.x >> centre.y;
    cout << "rayon du cercle ?";
    cin >> r;
    cout << "nom du fichier ?";
    cin >> nomC;
    caracC=circle_to_svg(centre,r);
    canvasC=canvas_to_svg(200,600,caracC);
    canvas_to_file(canvasC,nomC);
    
    
    Point *c;
    string caracP;
    string canvasP;
    string nomP;
    int nbP;
    cout << "combien de points ?";
    cin >> nbP;
    c=new Point[nbP];
    for (int i = 0;i < nbP; i++){
        cout << "Coordonnée x,y ?";
        cin >> c[i].x >> c[i].y;
    }
    cout << "nom du fichier ?";
    cin >> nomP;
    caracP = polygon_to_svg(nbP,c);
    canvasP = canvas_to_svg(200,600,caracP);
    canvas_to_file(canvasP,nomP);

    string x;
    string nom;
    int exe;
    cout << "nom du fichier et exemple ?";
    cin >> nom >> exe;
    if (exe == 1){
        x = exemple1_to_svg(1000,1000);
        canvas_exemple_to_file(x,nom,exe);
    }
    if (exe == 2){
        x = exemple2_to_svg(1000,1000);
        canvas_exemple_to_file(x,nom,exe);
    }
    if (exe == 3){
        x = exemple3_to_svg(1000,1000);
        canvas_exemple_to_file(x,nom,exe);
    }


    read c1;
    read c2;
    read c3;
    read_txt("circle.txt",c1);
    read_txt("rectangle.txt",c2);
    read_txt("polygon.txt",c3);

    carre_concentrique_to_svg();

    */

   // seance 3 //

    object c;
    objectV2 O;
    //int t[20] = { 0,9, 2,4, 7,3, 6,4, 2,13, 6,20 ,15,0 , 7,6, 8,18, 25,13};
    //c=init_object(c,rect,"red","white",0,0,0,250,250,0,t); 
    //cout << c.e;   

    //cout << simpleObject_to_svg(c);
    
    c=file_to_object(c,"rect-generique.txt");
    if (c.e == rect){
        cout << "rectangle" << " ";
        cout << c.height << " ";
        cout << c.width << " ";
        cout << c.couleur << " ";
        cout << c.bordercouleur;
    }
    if (c.e == circle){
        cout << "cirlce" << " ";
        cout << c.cx << " ";
        cout << c.cy << " ";
        cout << c.rayon << " ";
        cout << c.couleur << " ";
        cout << c.bordercouleur;
    }
    if (c.e == polygon){
        cout << "polygon" << " ";
        for (int i=0;i<c.taille;i=i+2){
            cout << c.tab[i] << "," << c.tab[i+1] << " ";
        }
        cout << c.couleur << " ";
        cout << c.bordercouleur;
    }
    
    /*
    c.e = polygon;
    c.taille = 4;
    c.tab = new int[c.taille];
    c.tab[0] = 3;
    c.tab[1] = 10;
    c.tab[2] = 9;
    c.tab[3] = 8;
    c.couleur = "red";
    c.bordercouleur = "black";
    object_to_file(c,"nouveau-fichier.txt");
    */
    return 0;
}