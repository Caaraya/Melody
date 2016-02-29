OPTIMIZE=-O2
CXX=g++
CFLAGS=-std=c++14 -c $(OPTIMIZE)
LDFLAGS=-lsdl2 -lglew32 -lopengl32
all: melody.o MelodyGame.o Sprite.o GLSLProgram.o\
	Errors.o IOManager.o ImageLoader.o picoPNG.o\
	ResourceManager.o TextureCache.o
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
	
IOManager.o: IOManager.cpp
	$(CXX) $(CFLAGS) $^
	
ImageLoader.o: ImageLoader.cpp
	$(CXX) $(CFLAGS) $^
	
picoPNG.o: picoPNG.cpp
	$(CXX) $(CFLAGS) $^

ResourceManager.o: ResourceManager.cpp
	$(CXX) $(CFLAGS) $^

TextureCache.o: TextureCache.cpp
	$(CXX) $(CFLAGS) $^
	
debug:
	make all OPTIMIZE='-g'
	
clean:
	rm *.o