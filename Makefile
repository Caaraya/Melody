OPTIMIZE=-O2
CXX=g++
CFLAGS=-std=c++14 -c $(OPTIMIZE)
LDFLAGS=-lsdl2 -lglew32 -lopengl32
all: 
	make -C Engine
	make -C ZombieGame

debug:
	make -C Engine debug
	make -C ZombieGame debug
	
clean:
	make -C Engine clean
	make -C ZombieGame clean
	rm -rf ./bin