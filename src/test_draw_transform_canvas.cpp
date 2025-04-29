#include <iostream>
#include <fstream>
#include "canvas.hpp"
#include "draw_to_svg.hpp"
using namespace std;

int main(int argc , char *argv[]){

    // Tableau 1 //

    
    object O,O2,O3;
    canvas C;
    string x;
    int Max = 8;
    composedObject Co;
    int T[9] = {25,25,75,25,75,75,25,75};
    O = init_object(O,polygon,"blue","none",0,0,0,0,0,9,T);
    O2 = init_object(O2,rect,"red","none",0,0,0,100,100,0,T);
    object Ta[18];
    for (int i = 0 ; i < 6 ; i++){
        Ta[i] = init_object(Ta[i],rect,"lightseagreen","none",0,0,0,100,100,0,T);
    }
    for (int j = 6 ; j < 12 ; j++){
        Ta[j] = init_object(Ta[j],polygon,"black","none",0,0,0,0,0,9,T);
    }
    for (int p = 12 ; p < 18 ; p++){
        Ta[p] = init_object(Ta[p],circle,"orange","none",20,50,50,0,0,0,T);
    }
    // Carré Rouge //
    translate_object(&Ta[1],105,0);
    translate_object(&Ta[2],105*2,0);
    translate_object(&Ta[3],0,105);
    translate_object(&Ta[4],105,105);
    translate_object(&Ta[5],105*2,105);
    // 
    // Carré bleu //
    translate_object(&Ta[7],105,0);
    translate_object(&Ta[8],105*2,0);
    translate_object(&Ta[9],0,105);
    translate_object(&Ta[10],105,105);
    translate_object(&Ta[11],105*2,105);
    //
    // Rotation carré bleu //
    rotation_object(&Ta[6],45,50,50);
    rotation_object(&Ta[7],45,155,50);
    rotation_object(&Ta[8],45,260,50);
    rotation_object(&Ta[9],45,50,155);
    rotation_object(&Ta[10],45,155,155);
    rotation_object(&Ta[11],45,260,155);
    //
    // Carré orange //
    translate_object(&Ta[12],105,0);
    translate_object(&Ta[13],105*2,0);
    translate_object(&Ta[14],0,105);
    translate_object(&Ta[15],105,105);
    translate_object(&Ta[16],105*2,105);
    //
    Co = init_composedObject(Co,18,Ta);
    C = init_canvas(C,O,Co,1000,1000,2,2);
    x = canvas_transform_composed_to_svg(C);
    cout << x;
    ofstream f(argv[1]);
    if (f){
        f << "<!DOCTYPE html>" << endl;
        f << "<html>" << endl;
        f << "<body>" << endl;
        f << x << endl;
        f << "</body>" << endl;
        f << "</html>";
    }
    f.close();
    

    // Tableau 2 //


    /*
    canvas C1;
    int i = 0;
    int w = 0;
    composedObject Co1;
    string x;
    int t[1];
    object Ta[20];
    int T[10] = {25,25,100,25,100,100,25,100};
    object O;
    Ta[0] = init_object(Ta[0],rect,"firebrick","black",0,0,0,1000,500,0,t);
    for (int i = 1 ; i < 17 ; i=i+3){
        Ta[i] = init_object(Ta[i],polygon,"forestgreen","none",0,0,0,0,0,10,T);
    }
    for (int i = 2 ; i < 17 ; i = i+3){
        Ta[i] = init_object(Ta[i],polygon,"gold","none",0,0,0,0,0,10,T);
    }
    for (int i = 3 ; i < 17 ; i =i+3){
        Ta[i] = init_object(Ta[i],polygon,"dodgerblue","none",0,0,0,0,0,10,T);
    }
    
    translate_object(&Ta[0],30,0);
    translate_object(&Ta[1],45,0);
    for (int j = 2 ; j < 5 ; j++){
        translate_object(&Ta[j],45,120+(120*i));
        i++;
    }    
    i = 0;
    for (int j = 5 ; j < 9 ; j++){
        translate_object(&Ta[j],155,120+(120*(i-1)));
        i++;
    }
    i = 0;
    for (int j = 9 ; j < 13 ; j++){
        translate_object(&Ta[j],265,120+(120*(i-1)));
        i++;
    }
    
    i = 0;
    for (int j = 13 ; j < 17 ; j++){
        translate_object(&Ta[j],375,120+(120*(i-1)));
        i++;
    }
    for (int j = 1 ; j <= 13 ; j=j+4){
        rotation_object(&Ta[j],-5,255,120);
    }
    for (int j = 2 ; j <= 14 ; j=j+4){
        rotation_object(&Ta[j],5,255,120);
    }
    for (int j = 3 ; j <= 15 ; j=j+4){
        rotation_object(&Ta[j],-5,255,120);
    }
    for (int j = 4 ; j <= 17 ; j=j+4){
        rotation_object(&Ta[j],5,255,120);
    }
    Co1 = init_composedObject(Co1,17,Ta);
    
    //for (int w = 0 ; w < 16 ; w++){
    //    rotation_composedObject(&Co1,10*w,310,310);
    //}
    

    C1 = init_canvas(C1,O,Co1,1000,1000,2,2);
    x = canvas_transform_composed_to_svg(C1);
    //cout << x;
    ofstream f(argv[1]);
    if (f){
        f << "<!DOCTYPE html>" << endl;
        f << "<html>" << endl;
        f << "<body>" << endl;
        f << x << endl;
        f << "</svg>" << endl;
        f << "</body>" << endl;
        f << "</html>";
    }
    f.close();
    */
    
}