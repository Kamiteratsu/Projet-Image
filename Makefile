all : bin/affichage bin/exemple bin/test

bin/affichage : obj/mainAffichage.o obj/Image.o obj/Pixel.o
	g++ -g obj/mainAffichage.o obj/Image.o obj/Pixel.o -o bin/affichage -lSDL2 -lSDL2_image

bin/exemple : obj/mainExemple.o obj/Image.o obj/Pixel.o
	g++ -g obj/mainExemple.o obj/Image.o obj/Pixel.o -o bin/exemple -lSDL2 -lSDL2_image

bin/test : obj/mainTest.o obj/Image.o obj/Pixel.o
	g++ -g obj/mainTest.o obj/Image.o obj/Pixel.o -o bin/test -lSDL2 -lSDL2_image

obj/mainAffichage.o : src/mainAffichage.cpp src/Image.h src/Pixel.h
	g++ -g -Wall -I/usr/include/SDL2 -c src/mainAffichage.cpp -o obj/mainAffichage.o

obj/mainExemple.o : src/mainExemple.cpp src/Image.h src/Pixel.h
	g++ -g -Wall -I/usr/include/SDL2 -c src/mainExemple.cpp -o obj/mainExemple.o

obj/mainTest.o : src/mainTest.cpp src/Image.h src/Pixel.h
	g++ -g -Wall -I/usr/include/SDL2 -c src/mainTest.cpp -o obj/mainTest.o

obj/Image.o : src/Image.h src/Image.cpp src/Pixel.h
		g++ -g -Wall -I/usr/include/SDL2 -c src/Image.cpp -o obj/Image.o

obj/Pixel.o : src/Pixel.h src/Pixel.cpp
		g++ -g -Wall -c src/Pixel.cpp -o obj/Pixel.o

clean :
	rm obj/*.o && rm bin/*
