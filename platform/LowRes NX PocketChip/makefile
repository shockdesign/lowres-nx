# Declaration of variables
CC = gcc
CC_FLAGS =  -D __POCKET_CHIP__-w -I ../../core -I ../../core/machine -I ../../core/accessories -I ../../core/datamanager -I ../../core/interpreter -I ../../core/libraries -I ../../core/overlay -lSDL2main -lSDL2 -lm -std=c11
CC_FLAGS_MAIN =  -D __POCKET_CHIP__ -lSDL2main `sdl2-config --cflags --static-libs` -std=c11

# File names
EXEC = output/LowResNX
SOURCES = $(wildcard ../../core/*.c) $(wildcard ../../core/*/*.c) $(wildcard ../../sdl/*.c)
OBJECTS = $(SOURCES:.c=.bc)

# Main target
$(EXEC): $(OBJECTS)
	@mkdir -p $(@D)
	$(CC) $(OBJECTS) -o $(EXEC) $(CC_FLAGS_MAIN)

# To obtain object files
%.bc: %.c
	$(CC) -c $(CC_FLAGS) $< -o $@

# To remove generated files
clean:
	rm -f $(OBJECTS)
