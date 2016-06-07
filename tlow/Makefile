###############################################################################
##  The Lords of War Makefile
## 
##  Short istructions
##  make - create executable
##  make clean - clean objects and program
###############################################################################

TARGET = tlow
LIBS = -lstdc++
#LINK = -pg
CC = g++
CFLAGS = -Wall -std=c++11 -pedantic -Werror -g
#CFLAGS += -O2 -pg

SOURCE=./source
INCLUDE=./include

.PHONY: default all clean help

default: $(TARGET)
all: default

help:
	@echo "make - to compile spellcheck"
	@echo "make clean - to remove objs and bin"

OBJECTS = $(patsubst ${SOURCE}/%.cpp, $(SOURCE)/%.o, $(wildcard ${SOURCE}/*.cpp))
HEADERS = $(wildcard ${INCLUDE}*.hpp)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) $(LINK) -o $@

clean:
	-rm -f ${SOURCE}/*.o
	-rm -f $(TARGET)
