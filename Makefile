CXX=g++
CFLAGS=-std=c++14 -c
LDFLAGS=-lsdl2 -lglew32 -lopengl32
all: melody.o MelodyGame.o Sprite.o GLSLProgram.o Errors.o
	g++ $^ $(LDFLAGS) -o melody.exe

melody.o: melody.cpp
	$(CXX) $(CFLAGS) $^
	
MelodyGame.o: MelodyGame.cpp
	$(CXX) $(CFLAGS) $^
	
Sprite.o: Sprite.cpp
	$(CXX) $(CFLAGS) $^
	
GLSLProgram.o: GLSLProgram.cpp
	$(CXX) $(CFLAGS) $^
	
Errors.o: Errors.cpp
	$(CXX) $(CFLAGS) $^
	
clean:
	rm *.o