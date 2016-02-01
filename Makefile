CXX=g++
CFLAGS=-std=c++14 -c
LDFLAGS=-lsdl2 -lglew32 -lopengl32
all: melody.o MelodyGame.o Sprite.o
	g++ $^ $(LDFLAGS) -o melody.exe

melody.o: melody.cpp
	$(CXX) $(CFLAGS) $^
	
MelodyGame.o: MelodyGame.cpp
	$(CXX) $(CFLAGS) $^
	
Sprite.o: Sprite.cpp
	$(CXX) $(CFLAGS) $^
	
clean:
	rm *.o