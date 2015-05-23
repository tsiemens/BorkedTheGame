LIBS=-lsfml-graphics -lsfml-window -lsfml-system
OUT=thegame

CC=g++

CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS=
CC_FLAGS=-W

all: $(OUT)

$(OUT): $(OBJ_FILES)
	mkdir bin
	$(CC) $(LD_FLAGS) $^ $(LIBS) -o bin/$@

obj/%.o: src/%.cpp
	mkdir obj
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	rm -f $(OUT)
	rm -rf obj/
	rm -rf bin/
