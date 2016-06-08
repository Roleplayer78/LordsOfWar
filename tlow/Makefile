###############################################################################
##  The Lords of War Makefile
## 
##  Short istructions
##  make - create executable
##  make clean - clean objects and program
###############################################################################

TARGET = tlow
CPP = g++

SOURCE=./source
INCLUDE=./include
MODULE_INCLUDE = -I./include \
                 -I../SFML/include \
                 -I../SFGUI/include \
                 -I../lua/src

CPPFLAGS = $(MODULE_INCLUDE) -Wall -std=c++11 -pedantic -Werror -g
#CPPFLAGS += -O2 -pg
#LINK = -pg

LIBS = -lstdc++ \
	-L../SFML/lib -lsfml-window -lsfml-graphics -lsfml-system \
        -L../SFGUI/lib -lsfgui

.PHONY: default all clean help depend
.PRECIOUS: $(TARGET) $(OBJECTS)
	
default: $(TARGET)
all: default

help:
	@echo "make - to compile spellcheck"
	@echo "make clean - to remove objs and bin"

OBJECTS = $(patsubst $(SOURCE)/%.cpp, $(SOURCE)/%.o, $(wildcard $(SOURCE)/*.cpp))
HEADERS = $(wildcard $(INCLUDE)/*.hpp)
SOURCES = $(wildcard $(SOURCE)/*.cpp)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CPP) $(OBJECTS) -Wall $(LIBS) $(LINK) -o $@

clean:
	-rm -f $(SOURCE)/*.o
	-rm -f $(TARGET)
	-rm -f .depend
	
depend: .depend
	
.depend: $(SOURCES)
	@rm -f ./.depend
	$(CPP) $(CPPFLAGS) -MM $^ -MF $@

-include .depend
