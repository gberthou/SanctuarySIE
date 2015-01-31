BINDIR=bin
OBJDIR=obj

BINNAME=SanctuarySIE
BIN=$(BINDIR)/$(BINNAME)
CLEAN=clean

DEBUGDIR=Debug
RELEASEDIR=Release

DEBUG=debug
RELEASE=release

GPP=g++
CFLAGS=-Wall

CPPFILES=Gmain.cpp Accessory.cpp Armor.cpp Item.cpp Tradable.cpp PickUpItem.cpp Stuff.cpp ItemFactory.cpp Weapon.cpp Consumable.cpp Permanent.cpp Inventory.cpp Stats.cpp Level.cpp LevelBg.cpp LevelFactory.cpp Map.cpp Character.cpp Merchant.cpp Mob.cpp Path.cpp Gold.cpp Mana.cpp Resources.cpp Physics.cpp Entity.cpp

OBJ=$(CPPFILES:.cpp=.o)
OBJABS=$(addprefix $(OBJDIR)/,$(OBJ))

OBJDEBUG=$(addprefix $(DEBUGDIR)/,$(OBJABS))
OBJRELEASE=$(addprefix $(RELEASEDIR)/,$(OBJABS))

BINDEBUG=$(addprefix $(DEBUGDIR)/,$(BIN))
BINRELEASE=$(addprefix $(RELEASEDIR)/,$(BIN))

FLAGSDEBUG=-g -pg
FLAGSRELEASE=-O2

LIBS=-lsfml-system -lsfml-window -lsfml-graphics

$(DEBUG): $(OBJDEBUG)
	$(GPP) $(CFLAGS) $(FLAGSDEBUG) $(LIBS) -o $(BINDEBUG) $(OBJDEBUG)

$(RELEASE): $(OBJRELEASE)
	$(GPP) $(CFLAGS) $(FLAGSRELEASE) $(LIBS) -o $(BINRELEASE) $(OBJRELEASE)

$(CLEAN):
	rm -f $(BINDEBUG) $(BINRELEASE) $(OBJDEBUG) $(OBJRELEASE)

$(DEBUGDIR)/$(OBJDIR)/%.o: %.cpp
	$(GPP) $(CFLAGS) $(FLAGSDEBUG) -c -o $@ $<

$(RELEASEDIR)/$(OBJDIR)/%.o: %.cpp
	$(GPP) $(CFLAGS) $(FLAGSRELEASE) -c -o $@ $<

