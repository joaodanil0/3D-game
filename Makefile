

INCLUDE_DIR = include
OBJ_DIR 	= obj
LIBRARY_DIR = ../lib

CC=g++
CCFLAGS=-I$(INCLUDE_DIR) -g -Wall -Wextra -Werror
LDFLAGS=-lm -lncurses

# DEPS == Dependências
_DEPS=defs.h 
#! patsubst pega cada palavra de _DEPS
#! separa por "espaco em branco"  e 
#! concatena com o conteúdo de INCLUDE_DIR
DEPS=$(patsubst %,$(INCLUDE_DIR)/%,$(_DEPS))
# $(info    DEPS is = $(DEPS))

# OBJ == Objects (arquivos .o)
_OBJ=main.o
#! patsubst pega cada palavra de _OBJ
#! separa por "espaco em branco"  e 
#! concatena com o conteúdo de OBJ_DIR
OBJ=$(patsubst %,$(OBJ_DIR)/%,$(_OBJ))
# $(info    OBJ is = $(OBJ))

$(OBJ_DIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CCFLAGS)

all: $(OBJ)
	$(CC) -o $@ $^ $(CCFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	-rm -f $(OBJ_DIR)/*.o *- core $(INCLUDE_DIR)/*-
	-rm all

run: all
	./all