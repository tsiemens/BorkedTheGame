CC        := g++
LD        := g++

LD_FLAGS  :=
CC_FLAGS  := -W -std=c++1y -g

MODULES   := engine game
SRC_DIR   := $(addprefix src/,$(MODULES)) src
BUILD_DIR := $(addprefix build/,$(MODULES)) build

LIBS      := -lsfml-graphics -lsfml-window -lsfml-system

BINARY    := build/mygame

SRC       := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.cpp))
OBJ       := $(patsubst src/%.cpp,build/%.o,$(SRC))
INCLUDES  := $(addprefix -I,$(SRC_DIR))

vpath %.cpp $(SRC_DIR)

define make-goal
$1/%.o: %.cpp
	$(CC) $(CC_FLAGS) $(INCLUDES) -c $$< -o $$@
endef

.PHONY: all checkdirs clean

all: checkdirs $(BINARY)

$(BINARY): $(OBJ)
	$(LD) $^ -o $@ $(LIBS)


checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR)

$(foreach bdir,$(BUILD_DIR),$(eval $(call make-goal,$(bdir))))
