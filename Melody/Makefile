OPTIMIZE=-O2
CXX=g++
CFLAGS=-std=c++14 -c $(OPTIMIZE) -I../Engine
LDFLAGS=-L../bin -lMelody -lsdl2 -lglew32 -lopengl32
all: melody.o MelodyGame.o Bullet.o
	g++ $^ $(LDFLAGS) -o melody.exe
	mkdir -p ../bin
	cp ./melody.exe ../bin

melody.o: melody.cpp
	$(CXX) $(CFLAGS) $^
	
MelodyGame.o: MelodyGame.cpp
	$(CXX) $(CFLAGS) $^
	
Bullet.o: Bullet.cpp
	$(CXX) $(CFLAGS) $^
	
debug: OPTIMIZE=-g
debug: all	
	
clean:
	rm -rf *.o