OPTIMIZE=-O2
CXX=g++
CFLAGS=-std=c++14 -c $(OPTIMIZE) -I../Engine
LDFLAGS=-L../bin -lMelody -lsdl2 -lglew32 -lopengl32
all: MainGame.o Bullet.o Zombie.o Player.o main.o Human.o\
 Gun.o Agent.o
	g++ $^ $(LDFLAGS) -o zombiegame.exe
	mkdir -p ../bin
	cp ./zombiegame.exe ../bin
	
MainGame.o: MainGame.cpp
	$(CXX) $(CFLAGS) $^
	
Bullet.o: Bullet.cpp
	$(CXX) $(CFLAGS) $^
	
Zombie.o: Zombie.cpp
	$(CXX) $(CFLAGS) $^

Player.o: Player.cpp
	$(CXX) $(CFLAGS) $^

main.o: main.cpp
	$(CXX) $(CFLAGS) $^

Level.o: Level.cpp
	$(CXX) $(CFLAGS) $^

Human.o: Human.cpp
	$(CXX) $(CFLAGS) $^

Gun.o: Gun.cpp
	$(CXX) $(CFLAGS) $^

Agent.cpp: Agent.o
	$(CXX) $(CFLAGS) $^
	
debug: OPTIMIZE=-g
debug: all	
	
clean:
	rm -rf *.o