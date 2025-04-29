#include <iostream>
using namespace std;
#include "object.hpp"
#ifndef _draw_to_svg_hpp
#define _draw_to_svg_hpp

/* Seance 1-2 */

string circle_to_svg(Point C,int r);

string polygon_to_svg(int nbP,Point C[]);

string canvas_to_svg(int height,int width,string carac);

string exemple1_to_svg(int height,int width);

string exemple2_to_svg(int height,int width);

string exemple3_to_svg(int height,int width);

/* Seance 3 */

string simpleObject_to_svg(object O);

/* Seance 4 */

string composedObject_to_svg(composedObject Co);

#endif