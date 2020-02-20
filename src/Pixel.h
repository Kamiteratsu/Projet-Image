#ifndef pixel_hpp
#define pixel_hpp


class Pixel{
    private:
    unsigned char r, g, b; // les composantes du pixel

    public:
    Pixel();
/**
	@brief Pixel : Constructeur par défaut de la classe: initialise le pixel à la couleur noire
	@param Aucun
	*/

    Pixel(unsigned char nr, unsigned char ng, unsigned char nb);
/**
	@brief Pixel : Constructeur de la classe: initialise r,g,b avec les paramètres
	@param unsigned char nr, unsigned char ng, unsigned char nb
	*/// 

    unsigned char getRouge() const;
/**
	@brief unsigned char getRouge : Accesseur : récupère la composante rouge du pixel
	@param Aucun
	*/

    unsigned char getVert() const;
/**
	@brief unsigned char getVert : Accesseur : récupère la composante verte du pixel
	@param Aucun
	*/

    unsigned char getBleu() const;
/**
	@brief unsigned char getBleu : Accesseur : récupère la composante bleue du pixel
	@param Aucun
	*/

    void setRouge(unsigned char nr);
/**
	@brief void setRouge : Mutateur : modifie la composante rouge du pixel
	@param unsigned char nr
	*/

    void setVert(unsigned char ng);
/**
	@brief void setVert : Mutateur : modifie la composante verte du pixel
	@param unsigned char ng
	*/

    void setBleu(unsigned char nb);
/**
	@brief void setBleu : Mutateur : modifie la composante bleue du pixel
	@param unsigned char nb
	*/

};

#endif
