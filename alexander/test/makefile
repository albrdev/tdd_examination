# ==========================================
#   Unity Project - A Test Framework for C
#   Copyright (c) 2007 Mike Karlesky, Mark VanderVoord, Greg Williams
#   [Released under MIT License. Please refer to license.txt for details]
# ==========================================

#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -f
	MKDIR = mkdir -p
  endif
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

C_COMPILER=g++
ifeq ($(shell uname -s), Darwin)
C_COMPILER=clang++
endif

UNITY_ROOT=../../Unity
SOURCE_ROOT=..

CFLAGS=-std=c++11
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
#CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
#CFLAGS += -Wold-style-definition
#CFLAGS += -Wno-misleading-indentation

TARGET_BASE=all_tests
TARGET = $(TARGET_BASE)$(TARGET_EXTENSION)
SRC_FILES=\
  $(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  $(SOURCE_ROOT)/src/geometry.c \
  $(SOURCE_ROOT)/src/generic.cpp \
  $(SOURCE_ROOT)/src/calculator.cpp \
  ./TestGeometry.c \
  ./runners/TestGeometry_Runner.c \
  ./TestNamespaceString.cpp \
  ./runners/TestNamespaceString_Runner.cpp \
  ./TestCalculator.cpp \
  ./runners/TestCalculator_Runner.cpp \
  ./runners/all_tests.cpp
INC_DIRS=-I$(SOURCE_ROOT)/inc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src
SYMBOLS=-DUNITY_FIXTURE_NO_EXTRAS -DUNITY_INCLUDE_DOUBLE

all: clean default

default:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES) -o $(TARGET)
	- ./$(TARGET) -v

clean:
	$(CLEANUP) $(TARGET)

ci: CFLAGS += -Werror
ci: default
