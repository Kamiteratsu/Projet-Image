#include "Image.h"
#include "Pixel.h"
#include <iostream>
#include <string>
#include <assert.h>
#include <fstream>

using namespace std;


Image::Image() : dimx(0), dimy(0), tab(NULL) {}

Image::Image(unsigned int x, unsigned int y){
    assert(x >= 0 && y >= 0);
    dimx = x;
    dimy = y;
    tab = new Pixel[dimx*dimy];
    assert(tab != NULL);
}

Image::~Image(){
    delete [] tab;
}

Pixel& Image::getPix(unsigned int x,unsigned int y) const{
    assert(x >= 0 && y >= 0 && x < dimx && y < dimy);
    return tab[y*dimx+x];
}

void Image::setPix(unsigned int x, unsigned int y, const Pixel & couleur){
    assert(x >= 0 && y >= 0 && x < dimx && y < dimy);
    tab[y*dimx+x] = couleur;
}

void Image::dessinerRectangle (unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, const Pixel couleur){
    assert(Xmin >= 0 && Xmax < dimx && Ymin >= 0 && Ymax < dimy);
    assert(Xmin <= Xmax && Ymin <= Ymax);
    unsigned int i,j;
    for(i = Xmin ; i <= Xmax ; i++) {
        for(j = Ymin ; j <= Ymax ; j++) {
            setPix(i,j,couleur);
        }
    }
}

void Image::effacer(Pixel couleur){
    dessinerRectangle(0, 0, dimx-1, dimy-1, couleur);
}

void Image::testRegression(){
    Image im;   
    assert(im.dimx == 0 && im.dimy == 0);
    assert(im.tab == NULL);
    Image im1(35,50);
    assert(im1.dimx == 35 && im1.dimy == 50);
    assert(im1.tab != NULL);
    for(unsigned int x = 0; x < im1.dimx ; x++) {
        for(unsigned int y = 0 ; y < im1.dimy ; y++) {
            Pixel p = im1.getPix(x,y);
            assert(p.getRouge() == 0);
            assert(p.getVert() == 0);
            assert(p.getBleu() == 0);
        }
    }
    Image * im2 = new Image(5, 5);
    delete im2;
    im2 = NULL;
    Pixel couleur(10, 10, 10);
    Pixel p1 = im1.getPix(0, 0);
    assert(p1.getRouge() == im1.tab[0].getRouge());
    assert(p1.getVert() == im1.tab[0].getVert());
    assert(p1.getBleu() == im1.tab[0].getBleu()); 
    im1.setPix(10, 10, couleur);
    Pixel p2 = im1.getPix(10, 10);
    assert(p2.getRouge() == couleur.getRouge());
    assert(p2.getVert() == couleur.getVert());
    assert(p2.getBleu() == couleur.getBleu()); 
    Image im3(30,30);
    im3.dessinerRectangle(1, 1, 10, 10, couleur); 
    for(unsigned int x=0; x<im3.dimx; x++) {
        for(unsigned int y=0; y<im3.dimy; y++) {
        Pixel p = im3.getPix(x,y);
            if (x>=1 && x<=10 && y>=1 && y<=10) {
                assert(p.getRouge() == couleur.getRouge());
                assert(p.getVert() == couleur.getVert());
                assert(p.getBleu() == couleur.getBleu());
            }
	    }
    }
    couleur.setRouge(9);
    couleur.setVert(9);
    couleur.setBleu(9);
    im3.effacer(couleur);
    for(unsigned int x=0; x<im3.dimx; x++) {
        for(unsigned int y=0; y<im3.dimy; y++) {
        Pixel p = im3.getPix(x,y);
        assert(p.getRouge() == couleur.getRouge());
        assert(p.getVert() == couleur.getVert());
        assert(p.getBleu() == couleur.getBleu());
        }
    }
}

void Image::sauver(const string &filename) const {
    ofstream fichier (filename.c_str());
    assert(fichier.is_open());
    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;
    for(unsigned int y=0; y<dimy; ++y){
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel pix = getPix(x,y);
            fichier << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
    }
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

void Image::ouvrir(const string & filename){
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());
	unsigned int r,g,b;
	string mot;
	dimx = dimy = 0;
	fichier >> mot >> dimx >> dimy >> mot;
	assert(dimx >= 0 && dimy >= 0);
	if (tab != NULL) delete [] tab;
    if(dimx > 0 && dimy > 0)
	tab = new Pixel [dimx*dimy];
    else{tab = NULL;}
    for(unsigned int y=0; y<dimy; ++y){
        for(unsigned int x=0; x<dimx; ++x) {
            fichier >> r >> g >> b;
            Pixel p(r,g,b);
            setPix(x,y,p);
        }
    }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

void Image::afficherConsole(){
    cout << dimx << " " << dimy << endl;
    for(unsigned int y=0; y<dimy; ++y) {
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel pix = getPix(x,y);
            cout << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
        cout << endl;
    }
}


void Image::afficherInit() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;SDL_Quit();exit(1);
    }
	int DIMX = 200;
	int DIMY = 200;
    window = SDL_CreateWindow("Module Image", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DIMX, DIMY, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; SDL_Quit(); exit(1);
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 200, 200);
}

void Image::afficherBoucle(){
	SDL_Event events;
	bool isOpen = true;
	SDL_Rect rect;
	rect.w = 200;
	rect.h = 200;
	rect.x = (int)(200/2 - rect.w/2);
	rect.y = (int)(200/2 - rect.h/2);
	assert(rect.x >= 0 && rect.y >= 0);
	while(isOpen){
	if(SDL_PollEvent(&events)){
		switch(events.type){
			case SDL_WINDOWEVENT: {
				if(events.window.event == SDL_WINDOWEVENT_CLOSE){
					isOpen = false;
				}
				break;
			}
			case SDL_KEYDOWN: {
				if(events.key.keysym.scancode == SDL_SCANCODE_ESCAPE || events.key.keysym.sym == SDLK_ESCAPE) {
					isOpen = false;
				}
				else if(events.key.keysym.scancode == SDL_SCANCODE_T ||
				events.key.keysym.sym == SDLK_t ||
				events.key.keysym.scancode == SDL_SCANCODE_G ||
				events.key.keysym.sym == SDLK_g){
				if(events.key.keysym.scancode == SDL_SCANCODE_T || events.key.keysym.sym == SDLK_t) {
					if(rect.h < 200)
            rect.h++;
					if(rect.w < 200 )
						rect.w ++;
				}
					else if( events.key.keysym.scancode == SDL_SCANCODE_G || events.key.keysym.sym == SDLK_g){
						if(rect.h > 0) rect.h--;
						if(rect.w > 0 )rect.w --;
					}

					rect.x = (int)(200/2 - rect.w/2);
					rect.y = (int)(200/2 - rect.h/2);
					assert(rect.x >= 0 && rect.y >= 0);
				}
				break;
			}
			default: break;
		}
	}
	draw(rect);
	}
}

        void Image::draw(SDL_Rect& imageRect){
	SDL_SetRenderDrawColor(renderer,211,211,211,255);
	SDL_RenderClear(renderer);
	SDL_Texture* pImgTexture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,dimx,dimy);
	SDL_SetRenderTarget(renderer,pImgTexture);
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);
	for(unsigned int y=0; y<dimy; ++y){
		for(unsigned int x=0; x<dimx; ++x) {
			Pixel pix = getPix(x,y);
			SDL_SetRenderDrawColor(renderer,pix.getRouge(),pix.getVert(),pix.getBleu(),255);
			SDL_RenderDrawPoint(renderer,x,y);
		}
	}
	SDL_SetRenderTarget(renderer, nullptr);
	SDL_RenderCopy(renderer,pImgTexture,nullptr,&imageRect);
	SDL_RenderPresent(renderer);
}

void Image::afficherDetruit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(texture);
    SDL_Quit();

}

void Image::afficher(){
     afficherInit();
     afficherBoucle();
     afficherDetruit();
    }
