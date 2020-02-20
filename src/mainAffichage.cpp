#include "Image.h"
 
int main (int argc, char** argv) {
 
   Image image (10,10);
 
   Pixel noir (0, 0, 0);
   Pixel vert (0, 192, 0);
   Pixel cyan (128, 255, 255);
 
   image.effacer(noir);
   image.dessinerRectangle(3, 0, 5, 2, vert);
   image.dessinerRectangle(1, 4, 7, 4, vert);
   image.dessinerRectangle(4, 3, 4, 6, vert);
   image.dessinerRectangle(3, 6, 3, 9, vert);
   image.dessinerRectangle(5, 6, 5, 9, vert);
   image.setPix(1,2,vert);
   image.setPix(1,3,vert);
   image.setPix(7,2,vert);
   image.setPix(7,3,vert);
   image.setPix(2,9,vert);
   image.setPix(6,9,vert);
   image.setPix(3,1,cyan);
   image.setPix(5,1,cyan);
 
   image.afficher(); 
 
   return 0;    
}
