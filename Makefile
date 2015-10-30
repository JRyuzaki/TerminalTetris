GPP = g++
LIBS = -lncurses
SRCS = main.cpp Tetromino.cpp GameField.cpp Tetris.cpp
HEADER = Tetromino.hpp GameField.hpp Tetris.hpp
OBJS = main.o Tetromino.o GameField.o Tetris.o
ONAME = tetris
CFLAGS = -std=c++11

all: $(ONAME)

$(ONAME):$(OBJS)
	$(GPP) $(CFLAGS) -o $(ONAME) $(OBJS) $(LIBS)

%.o:%.cpp
	$(GPP) $(CFLAGS) -c -o $@ $(LIBS)
clean:
	rm -f *.o $(ONAME)
