GPP = g++
LIBS = -lncurses
SRCS = main.cpp Tetromino.cpp
OBJS = main.o Tetromino.o
ONAME = tetris
CFLAGS = -std=c++11

all: $(ONAME)

$(ONAME) : $(OBJS)
	$(GPP) $(CFLAGS) -o $(ONAME) $(OBJS) $(LIBS)

%.o : %.c
	$(GPP) $(CFLGAS) -c -o $@ $< $(LIBS)

clean:
	rm -f *.o $(ONAME)
