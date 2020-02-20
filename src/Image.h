#ifndef image_hpp
#define image_hpp

#include "Pixel.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class Image {
    public:
    Image();
/**
	@brief Image : Constructeur par défaut de la classe: initialise dimx et dimy à 0 sans allocation de pixel
	@param Aucun
	*/

    Image(unsigned int dimx, unsigned int dimy);   /**
	@brief Image : Constructeur de la classe: initialise dimx et dimy (après vérification)
	@param unsigned int dimx, unsigned int dimy
	*/

    ~Image();
/**
	@brief ~Image : Destructeur de la classe: déallocation de la mémoire du tableau de pixels
	@param Aucun
	*/

    Pixel& getPix(unsigned int x,unsigned int y) const;
/**
	@brief Pixel& getPix : Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité
	@param unsigned int x,unsigned int y
	*/
    void setPix(unsigned int x,unsigned int y, const Pixel & couleur);
/**
	@brief void setPix : Mutateur : modifie le pixel de coordonnées (x,y)
	@param unsigned int x,unsigned int y, const Pixel & couleur
	*/

    void dessinerRectangle(unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, const Pixel couleur);
/**
	@brief void dessinerRectangle : Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris)
	@param unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, const Pixel couleur
	*/

    void effacer(Pixel couleur);
/**
	@brief void effacer : Efface l'image en la remplissant de la couleur en paramètre
	@param Pixel couleur
	*/
    void testRegression();
/**
	@brief void testRegression : Effectue une série de tests vérifiant que le module fonctionne
	@param Aucun
	*/

    void sauver(const string & filename) const;
/**
	@brief void sauver : Sauver une image dans un fichier
	@param const string & filename
	*/

    void ouvrir(const string & filmename);
/**
	@brief void ouvrir : Ouvrir une image depuis un fichier
	@param const string & filmename
	*/

    void afficherConsole();
/**
	@brief void afficherConsole : Afficher les valeurs des pixels sur la console
	@param Aucun
	*/

    void afficher();
/**
	@brief void afficher : Affiche l'image dans une fenêtre SDL2
	@param Aucun
	*/

    private:
    void afficherInit(); // Initialise les fonctions SDL2

    void afficherBoucle(); // Boucle l'affichage de l'image dans une fenêtre SDL2

    void afficherDetruit(); // Détruit l'image dans une fenêtre SDL2

    void draw(SDL_Rect& imageRect); // Dessine l'image dans une fenêtre SDL2

    unsigned int dimx, dimy; // les dimensions de l'image

    Pixel * tab; // le tableau 1D de pixel

    SDL_Texture * texture; // Texture pour le zoom SDL2
    SDL_Window * window; // Fenêtre SDL2

    SDL_Renderer * renderer; // Rendu SDL2 sur lequel l'image sera faite

};

#endif
