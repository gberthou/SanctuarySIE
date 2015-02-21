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
CFLAGS=-Wall -Wextra -Wmissing-braces -pedantic -Werror
INCLUDE=-I"./" -I"./SerGUI/"

MAINFILE=Gmain.cpp

CPPFILES=$(MAINFILE) Accessory.cpp Armor.cpp Item.cpp Tradable.cpp PickUp.cpp Stuff.cpp ItemFactory.cpp Weapon.cpp Consumable.cpp Permanent.cpp Inventory.cpp Enchantment.cpp Stats.cpp Level.cpp LevelDoor.cpp LevelBg.cpp LevelFactory.cpp Map.cpp Fighter.cpp Character.cpp Merchant.cpp Mob.cpp MobFactory.cpp Path.cpp Gold.cpp Mana.cpp Resources.cpp Physics.cpp AABB.cpp AttackAnimation.cpp Entity.cpp EntitySoul.cpp InputController.cpp RedSoul.cpp BlueSoul.cpp YellowSoul.cpp Soul.cpp SoulManager.cpp SoulSet.cpp Camera.cpp Animation.cpp FPSClock.cpp Save.cpp SerGUI/Button.cpp SerGUI/MenuSelectSave.cpp SerGUI/MenuTitle1.cpp SerGUI/Bat.cpp SerGUI/SerGUI.cpp SerGUI/BoxExpandable.cpp SerGUI/UICharacterStatus.cpp



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
	$(GPP) $(CFLAGS) $(FLAGSDEBUG) $(INCLUDE) -c -o $@ $<

$(RELEASEDIR)/$(OBJDIR)/%.o: %.cpp
	$(GPP) $(CFLAGS) $(FLAGSRELEASE) $(INCLUDE) -c -o $@ $<

