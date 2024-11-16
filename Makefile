GAMEFILE = game.cpp
GAMENAME = game

# not sure I understand this line
all : $(GAMEFILE)
		g++ -o $(GAMENAME) $(GAMEFILE) `pkg-config sdl3 --cflags --libs` 