#include <iostream>
#include <cmath>
#include "canvas.hpp"
#include "draw_to_svg.hpp"
#include <random>
using namespace std;

canvas init_canvas(canvas C,object O,composedObject Co, int height, int width, int repCol ,int repLig){
    C.O = O;
    C.Co = Co;
    C.height = height;
    C.width = width;
    C.repCol = repCol;
    C.repLig = repLig;
    return C;
}

void translate_object(object *O,int x,int y){
    if (O->e == rect or O->e == circle){
        O->cx = O->cx + x;
        O->cy = O->cy + y;
    }
    if (O->e == polygon){
        for (int i = 0 ; i < O->taille-2 ; i=i+2){
            O->tab[i] = O->tab[i] + x;
            O->tab[i+1] = O->tab[i+1] + y;
        }
    }
}

void translate_composedObject(composedObject *Co,int x,int y){
    
    for (int i = 0; i < Co->nbObject ; i++){
        if (Co->T[i].e == rect or Co->T[i].e == circle){
            Co->T[i].cx = Co->T[i].cx + x;
            Co->T[i].cy = Co->T[i].cy + y;
        }
        if (Co->T[i].e == polygon){
            for (int i = 0 ; i < Co->T[i].taille-2 ; i=i+2){
                Co->T[i].tab[i] = Co->T[i].tab[i] + x;
                Co->T[i].tab[i+1] = Co->T[i].tab[i+1] + y;
            }
        }
    }
}
string canvas_composed_to_svg(canvas C){
    string result;
    result = "<svg height=\"" + to_string(C.height) + "\" width=\"" + to_string(C.width) + "\" >";
    result = result + simpleObject_to_svg(C.O);
    result = result + composedObject_to_svg(C.Co);
    result = result + "</svg>";
    return result;
}

void dilatation_object(object *O,int x){
    if (O->e == rect){
        O->height = O->height * x;
        O->width = O->width * x;
    }
    if (O->e == circle){
        O->rayon = O->rayon * x;
    }
    if (O->e == polygon){
        for (int i = 0; i <O->taille ; i++){
            O->tab[i] = O->tab[i] * x;
        }
    }
}

void dilatation_composedObject(composedObject *Co,int x){
    for (int i = 0; i < Co->nbObject ; i++){
        dilatation_object(&Co->T[i],x);
    }
}

void reduction_object(object *O,int x){
    if (O->e == rect){
        O->height = O->height / x;
        O->width = O->width / x;
    }
    if (O->e == circle){
        O->rayon = O->rayon / x;
    }
    if (O->e == polygon){
        for (int i = 0; i <O->taille ; i++){
            O->tab[i] = O->tab[i] / x;
        }
    }
}

void reduction_composedObject(composedObject *Co,int x){
    for (int i = 0 ; i < Co->nbObject ; i++){
        reduction_object(&Co->T[i],x);
    }
}

void rotation_object(object *O, int deg, float Ox,float Oy){
    float rad = deg * M_PI / 180;
    float xnew,ynew;
    for (int i = 0 ; i < O->taille-2 ; i=i+2){
        xnew = Ox + cos(rad) * (O->tab[i] - Ox) + sin(rad) * (O->tab[i+1] - Oy);
        ynew = Oy - sin(rad) * (O->tab[i] - Ox) + cos(rad) * (O->tab[i+1] - Oy);
        O->tab[i] = xnew;
        O->tab[i+1] = ynew;
    }
}

void rotation_composedObject(composedObject *Co, int deg, float Ox, float Oy){
    float rad = deg * M_PI / 180;
    float xnew,ynew;
    for (int i = 0 ; i < Co->nbObject ; i++){
        for (int j = 0 ; j < Co->T[i].taille-2 ; j=j+2){
        xnew = Ox + cos(rad) * (Co->T[i].tab[j] - Ox) + sin(rad) * (Co->T[i].tab[j+1] - Oy);
        ynew = Oy - sin(rad) * (Co->T[i].tab[j] - Ox) + cos(rad) * (Co->T[i].tab[j+1] - Oy);
        Co->T[i].tab[j] = xnew;
        Co->T[i].tab[j+1] = ynew;
        }
    }
}

string canvas_transform_simple_to_svg(canvas C){
    string result;
    string x;
    object O;
    O = C.O;
    if (C.O.e == rect){
        for (int i = 0 ; i < C.repCol ; i++){
            O.cx = -C.O.width-5;
            O.cy = (C.O.width+5)*i;
            for (int j = 0 ; j < C.repLig ; j++){
                translate_object(&O,C.O.height+5,0);
                x = x + simpleObject_to_svg(O);
            }
        }
    }
    if (C.O.e == circle){
        for (int i = 0 ; i < C.repCol ; i++){
            O.cx = C.O.cx;
            O.cy = (C.O.cy+C.O.rayon)+((C.O.rayon*2)*i);
            for (int j = 0 ; j < C.repLig ; j++){
                translate_object(&O,C.O.rayon+C.O.rayon,0);
                x = x + simpleObject_to_svg(O);
            }
        }
    }
    if (C.O.e == polygon){
        for (int i = 0 ; i < C.repCol ; i++){
            O.tab = C.O.tab;
            for (int j = 0 ; j < C.repLig ; j++){
                translate_object(&O,O.tab[2],(50*i));
                x = x + simpleObject_to_svg(O);
            }
        }
    }
    result = "<svg height=\"" + to_string(C.height) + "\" width=\"" + to_string(C.width) + "\">" + x + "</svg>";
    return result;
}

string canvas_transform_composed_to_svg(canvas C){
    string result;
    string x;
    composedObject Co;
    Co = C.Co;
    if (C.Co.T->e == circle){
        for (int i =0 ; i < C.Co.nbObject ; i++){
            for (int w = 0 ; w < C.repCol ; w++){
                Co.T[i].cx = C.Co.T[i].cx;
                Co.T[i].cy = (C.Co.T[i].cy+C.Co.T[i].rayon)+((C.Co.T[i].rayon*2)*w);
                for (int j = 0 ; j < C.repLig ; j++){
                    translate_object(&Co.T[i],C.Co.T[i].rayon+C.Co.T[i].rayon,0);
                    x = x + simpleObject_to_svg(Co.T[i]);
                }
            }
        }
    }
    //cout << x << endl << endl;
    result = "<svg height=\"" + to_string(C.height) + "\" width=\"" + to_string(C.width) + "\">" + x
    + "</svg>";
    return result;
}

// Séance 6 //

transform init_transform(transform t, type nom , int deg,int Ox, int Oy, int x, int y, int prct, object O, composedObject Co){
    t.nom = nom;
    t.O = O;
    t.Co = Co;
    if (nom == rotation){
        t.deg = deg;
        t.Ox = Ox;
        t.Oy = Oy;
    }
    if (nom == translation){
        t.x = x;
        t.y = y;
    }
    if (nom == dilatation or nom == reduction){
        t.prct = prct;
    }
    return t;
}

ListTransform* create_list(ListTransform **T,int nb,transform t[]){
    ListTransform *tmp;
    int i = 0;
    tmp = new ListTransform;
    *T = tmp;
    tmp->T = t[i]; 
    nb--;
    i++;
    while (nb != 0){
        tmp->next = new ListTransform;
        tmp = tmp->next;
        tmp->T = t[i];
        i++;
        nb--;
    }
    tmp->next = NULL;
    return *T;
}


string canvas_list_transform_simpleObject_to_svg(transform t,canvas C){
    string result;
    cout << C.O.tab[0] << " " << C.O.tab[1] << endl;
    if (t.nom == rotation){
        cout << "rotation" << endl;
        rotation_object(&C.O,t.deg,t.Ox,t.Oy);
        rotation_composedObject(&C.Co,t.deg,t.Ox,t.Oy);
    }
    if (t.nom == translation){
        cout << "translation" << endl;
        translate_object(&C.O,t.x,t.y);
        translate_composedObject(&C.Co,t.x,t.y);
    }
    if (t.nom == dilatation){
        cout << "dilatation" << endl;
        dilatation_object(&C.O,t.prct);
        dilatation_composedObject(&C.Co,t.prct);
    }
    if (t.nom == reduction){
        cout << "reduction" << endl;
        reduction_object(&C.O,t.prct);
        dilatation_composedObject(&C.Co,t.prct);
    }
    cout << C.O.tab[0] << " " << C.O.tab[1] << endl;
    result = "<svg height=\"" + to_string(C.height) + "\" width=\"" + to_string(C.width) + "\" >" +
    simpleObject_to_svg(C.O) + composedObject_to_svg(C.Co) + "</svg>";
    return result;
}

string canvas_list_listTransform_simpleObject_to_svg(ListTransform *p,canvas C,int nb){
    string result;
    ListTransform *tmp;
    tmp = p;
    cout << C.O.tab[0]  << " " << C.O.tab[1] << endl;

    for (int i = 0 ; i < nb ; i++){
        if (tmp->T.nom == rotation){
            cout << "rotation" << endl;
            rotation_object(&C.O,tmp->T.deg,tmp->T.Ox,tmp->T.Oy);
            rotation_composedObject(&C.Co,tmp->T.deg,tmp->T.Ox,tmp->T.Oy);
        }
        if (tmp->T.nom == translation){
            cout << "translation" << endl;
            translate_object(&C.O,tmp->T.x,tmp->T.y);
            translate_composedObject(&C.Co,tmp->T.x,tmp->T.y);
        }
        if (tmp->T.nom == dilatation){
            cout << "dilatation" << endl;
            dilatation_object(&C.O,tmp->T.prct);
            dilatation_composedObject(&C.Co,tmp->T.prct);
        }
        if (tmp->T.nom == reduction){
            cout << "reduction" << endl;
            reduction_object(&C.O,tmp->T.prct);
            reduction_composedObject(&C.Co,tmp->T.prct);
        }
        
        cout << C.O.tab[0]  << " " << C.O.tab[1] << endl;
        tmp = tmp->next;
    }    
    
    result = "<svg height=\"" + to_string(C.height) + "\" width=\"" + to_string(C.width) + "\" >" +
    simpleObject_to_svg(C.O) + composedObject_to_svg(C.Co) + "</svg>";
    
    cout << C.O.tab[0]  << " " << C.O.tab[1] << endl;
    return result;
}

string canvas_james_bond(canvas C){
    object O = C.O;
    string x;
    string result;
    int r = alea(1,5);
        if (r == 4){
        couleur(&O,"red");
    }
    if (r == 5){
        couleur(&O,"black");
    }
    if (r == 1){
        couleur(&O,"yellow");
    }
    if (r == 3){
        couleur(&O,"none");
    }
    if (r == 2){
        couleur(&O,"blue");
    }
    for (int i = 0 ; i < C.repLig ; i++){
        O.cx = C.O.cx;
        O.cy = (C.O.cy+C.O.rayon)+((C.O.rayon*2)*i);
        for (int j = 0 ; j < C.repCol ; j++){
            translate_object(&O,C.O.rayon+C.O.rayon,0);
            x = x + simpleObject_to_svg(O);
        }
    }
    O = C.O;
        if (r == 1){
        couleur(&O,"red");
    }
    if (r == 2){
        couleur(&O,"black");
    }
    if (r == 3){
        couleur(&O,"yellow");
    }
    if (r == 4){
        couleur(&O,"none");
    }
    if (r == 5){
        couleur(&O,"blue");
    } 
    reduction_object(&O,2);
        for (int i = 0 ; i < C.repLig ; i++){
        O.cx = C.O.cx;
        O.cy = (C.O.cy+C.O.rayon)+((C.O.rayon*2)*i);
        for (int j = 0 ; j < C.repCol ; j++){
            translate_object(&O,C.O.rayon+C.O.rayon,0);
            x = x + simpleObject_to_svg(O);
        }
    }
    O = C.O;
        if (r == 3){
        couleur(&O,"red");
    }
    if (r == 4){
        couleur(&O,"black");
    }
    if (r == 5){
        couleur(&O,"yellow");
    }
    if (r == 2){
        couleur(&O,"none");
    }
    if (r == 1){
        couleur(&O,"blue");
    }
    reduction_object(&O,3);
    for (int i = 0 ; i < C.repLig ; i++){
        O.cx = C.O.cx;
        O.cy = (C.O.cy+C.O.rayon)+((C.O.rayon*2)*i);
        for (int j = 0 ; j < C.repCol ; j++){
            translate_object(&O,C.O.rayon+C.O.rayon,0);
            x = x + simpleObject_to_svg(O);
        }
    }
    O = C.O;
        if (r == 2){
        couleur(&O,"red");
    }
    if (r == 1){
        couleur(&O,"black");
    }
    if (r == 4){
        couleur(&O,"yellow");
    }
    if (r == 5){
        couleur(&O,"none");
    }
    if (r == 3){
        couleur(&O,"blue");
    }
    reduction_object(&O,4);
    for (int i = 0 ; i < C.repLig ; i++){
        O.cx = C.O.cx;
        O.cy = (C.O.cy+C.O.rayon)+((C.O.rayon*2)*i);
        for (int j = 0 ; j < C.repCol ; j++){
            translate_object(&O,C.O.rayon+C.O.rayon,0);
            x = x + simpleObject_to_svg(O);
        }
    }
    /*
    O = C.O;
    dilatation_object(&O,2);
    translate_object(&O,800,0);
    for (int i = 0 ; i < C.repLig ; i++){
        O.cx = C.O.cx + 800;
        O.cy = (C.O.cy+C.O.rayon)+((C.O.rayon*2)*i*2);
        for (int j = 0 ; j < C.repCol ; j++){
            translate_object(&O,C.O.rayon+C.O.rayon*3,0);
            x = x + simpleObject_to_svg(O);
        }
    }
    */
    result = "<svg height=\"" + to_string(C.height) + "\" width=\"" + to_string(C.width) + "\">" + x
    + "</svg>";
    
    return result;
    
}

void couleur(object *O,string x){
    O->couleur = x;
}

int alea(int n1,int n2){
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<> dist(n1,n2);
    return dist(rng);
}