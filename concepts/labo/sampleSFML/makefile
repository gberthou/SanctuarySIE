BINDIR=./bin
OBJDIR=./obj

BINNAME=sampleSFML
BIN=$(BINDIR)/sampleSFML
CLEAN=clean

GPP=g++
CFLAGS=-Wall

CPPFILES=main.cpp

OBJ=$(CPPFILES:.cpp=.o)
OBJABS=$(addprefix $(OBJDIR)/,$(OBJ))

LIBS=-lsfml-system -lsfml-window -lsfml-graphics

$(BIN): $(OBJABS)
	$(GPP) $(CFLAGS) $(LIBS) -o $(BIN) $(OBJABS)

$(CLEAN):
	rm -f $(BIN) $(OBJABS)


$(OBJDIR)/%.o: %.cpp
	$(GPP) $(CFLAGS) -c -o $@ $<

