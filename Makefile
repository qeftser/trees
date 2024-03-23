
# compilers
CC := gcc
JJ := javac

# other variables
OUTPUT := tst.e
CC_FLAGS := -g -O3 -Wall -Wextra -Wpedantic -mavx2 -mfma -mcx16
LD_FLAGS := -O3


C_FILES := $(wildcard src/c/*.c) 
H_FILES := $(wildcard src/c/*.h)
OBJ_FILES := $(C_FILES:.c=.o)
J_FILES := $(wildcard src/java/*.java)

all: $(OUTPUT)

$(OUTPUT): $(OBJ_FILES) Makefile
	$(CC) $(OBJ_FILES) $(H_FILES) $(LD_FLAGS) -o ./bin/c_$@ && $(JJ) $(J_FILES) -d ./bin/

.c.o:
	$(CC) -c $(CC_FLAGS) $< -o $@

clean:
	rm -f $(OBJ_FILES) ./bin/*.class ./bin/*.e

c: $(OBJ_FILES) Makefile 
	$(CC) $(OBJ_FILES) $(H_FILES) $(LD_FLAGS) -o ./bin/c_tst.e

java: $(J_FILES) Makefile
	$(JJ) $(J_FILES) -d ./bin/

