

INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR 	= obj
LIBRARY_DIR = ../lib

CC=g++
CCFLAGS=-I$(INCLUDE_DIR) -g -Wall -Wextra -Werror
LDFLAGS=-lm -lncurses

# DEPS == Dependências
_DEPS=defs.h Vector2.h Vector3.h Vector4.h
#! patsubst pega cada palavra de _DEPS
#! separa por "espaco em branco"  e 
#! concatena com o conteúdo de INCLUDE_DIR
DEPS=$(patsubst %,$(INCLUDE_DIR)/%,$(_DEPS))
# $(info    DEPS is = $(DEPS))

_OBJ=main.o Vector2.o Vector3.o Vector4.o
#! patsubst pega cada palavra de _OBJ
#! separa por "espaco em branco"  e 
#! concatena com o conteúdo de OBJ_DIR
OBJ=$(patsubst %,$(OBJ_DIR)/%,$(_OBJ))
# $(info    OBJ is = $(OBJ))

$(OBJ_DIR)/%.o: %.cpp $(DEPS)
	@$(CC) -c -o $@ $< $(CCFLAGS)

all: $(OBJ)
	@$(CC) -o $@ $^ $(CCFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	-rm -f $(OBJ_DIR)/*.o *- core $(INCLUDE_DIR)/*-
	-rm all

run: all
	@./all