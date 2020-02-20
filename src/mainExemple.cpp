#include "Image.h"
 
int main() {
 
   Pixel blanc (255, 255, 255);
   Pixel rose (255, 0, 128);
   Pixel bleu (0, 128, 255);
 
   Image image1 (64,48);
   image1.effacer(bleu);
   image1.dessinerRectangle(20, 30, 40, 45, blanc);
   image1.setPix(5,8,rose);
   image1.setPix(30,37,rose);
   image1.sauver("./data/image1.ppm");
 
   Image image2;
   image2.ouvrir("./data/image1.ppm");
   image2.dessinerRectangle(18, 5, 31, 47, blanc);
   image2.dessinerRectangle(2, 32, 10, 41, rose);
   image2.sauver("./data/image2.ppm");
 
   return 0;
}
