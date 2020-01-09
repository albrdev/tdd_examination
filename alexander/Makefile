APP_BIN		:= tdd_examination

CC_C		:= gcc -std=c99
CC_CPP		:= g++ -std=c++11
CC_FLAGS	:= -pedantic -Wall -Wextra -Wconversion
CC_LIBS		:= 

FLAGS_DBG	:= -g -Wno-unused-parameter
FLAGS_RLS	:= -DNDEBUG

DIR_INC		:= inc
DIR_SRC		:= src
DIR_OBJ		:= obj
DIR_BIN		:= bin
DIR_TEST	:= test

CMD_CP		:= cp -f
CMD_RM		:= rm -f
CMD_MKDIR	:= mkdir -p
CMD_PRINT	:= @echo
MAKE		?= make

SRCS_C		:= $(wildcard $(DIR_SRC)/*.c)
OBJS_C		:= $(patsubst $(DIR_SRC)/%.c,$(DIR_OBJ)/%.o,$(SRCS_C))
SRCS_CPP	:= $(wildcard $(DIR_SRC)/*.cpp)
OBJS_CPP	:= $(patsubst $(DIR_SRC)/%.cpp,$(DIR_OBJ)/%.o,$(SRCS_CPP))
OBJS		:= $(OBJS_C) $(OBJS_CPP)

TRG_BIN		:= $(DIR_BIN)/$(APP_BIN)

.PHONY: all
all: debug

.PHONY: release
release: CC_FLAGS += $(FLAGS_RLS)
release: mkdirs $(TRG_BIN)

.PHONY: debug
debug: CC_FLAGS += $(FLAGS_DBG)
debug: mkdirs $(TRG_BIN)

.PHONY: clean
clean:
	$(CMD_RM) $(DIR_OBJ)/*.o
	$(CMD_RM) $(TRG_BIN) $(patsubst %,%.out,$(TRG_BIN)) $(patsubst %,%.exe,$(TRG_BIN))

.PHONY: test
test:
	$(MAKE) -C $(DIR_TEST)

.PHONY: vars
vars:
	$(CMD_PRINT) "C compiler:       " $(CC_C)
	$(CMD_PRINT) "C++ compiler:     " $(CC_CPP)
	$(CMD_PRINT) "Compiler flags:   " $(CC_FLAGS) -I$(DIR_INC) $(CC_LIBS)
	$(CMD_PRINT) "C sources:        " $(SRCS_C)
	$(CMD_PRINT) "C objects:        " $(OBJS_C)
	$(CMD_PRINT) "C++ sources:      " $(SRCS_CPP)
	$(CMD_PRINT) "C++ objects:      " $(OBJS_CPP)
	$(CMD_PRINT) "Executable:       " $(TRG_BIN)

.PHONY: run
run: test all
	./$(TRG_BIN) $(args)

.PHONY: mkdirs
mkdirs: $(DIR_OBJ) $(DIR_BIN)

# Directories
$(DIR_OBJ):
	$(CMD_MKDIR) $@

$(DIR_BIN):
	$(CMD_MKDIR) $@

# Executable
$(TRG_BIN): $(OBJS)
	$(CC_CPP) $(CC_LIBS) $^ -o $@

# Main
$(DIR_OBJ)/main.o: $(DIR_SRC)/main.cpp
	$(CC_CPP) $(CC_FLAGS) -Wno-unused-parameter -I$(DIR_INC) -c $< -o $@

# Objects
$(DIR_OBJ)/calculator.o: $(DIR_SRC)/calculator.cpp $(DIR_INC)/calculator.hpp
	$(CC_CPP) $(CC_FLAGS) -I$(DIR_INC) -c $< -o $@

$(DIR_OBJ)/generic.o: $(DIR_SRC)/generic.cpp $(DIR_INC)/generic.hpp
	$(CC_CPP) $(CC_FLAGS) -I$(DIR_INC) -c $< -o $@

$(DIR_OBJ)/geometry.o: $(DIR_SRC)/geometry.c $(DIR_INC)/geometry.h
	$(CC_C) $(CC_FLAGS) -I$(DIR_INC) -c $< -o $@
