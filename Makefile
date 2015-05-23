LIBS=-lsfml-graphics -lsfml-window -lsfml-system
OUT=thegame

CC=g++

CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS=
CC_FLAGS=-W -std=c++1y -g

all: $(OUT)

$(OUT): $(OBJ_FILES)
	@mkdir -p bin
	$(CC) $(LD_FLAGS) $^ $(LIBS) -o bin/$@

obj/%.o: src/%.cpp
	@mkdir -p obj
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	@rm -rf obj/
	@rm -rf bin/
