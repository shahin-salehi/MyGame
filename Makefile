GAMEFILE = game.cpp
GAMENAME = game

# not sure I understand this line
all : $(GAMEFILE)
		g++ ./keyboard/keyboard.cpp $(GAMEFILE) -o $(GAMENAME) `pkg-config sdl3 --cflags --libs` 