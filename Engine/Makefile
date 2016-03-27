OPTIMIZE=-O2
CXX=g++
CFLAGS=-std=c++14 -c $(OPTIMIZE)
LDFLAGS=-lsdl2 -lglew32 -lopengl32
all: Sprite.o GLSLProgram.o\
	Errors.o IOManager.o ImageLoader.o picoPNG.o\
	ResourceManager.o TextureCache.o
	ar rcs libMelody.a $^
	ranlib libMelody.a
	mkdir -p ../bin
	cp ./libMelody.a ../bin
	
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
	
debug: OPTIMIZE=-g
debug: all	
	
clean:
	rm -rf *.o