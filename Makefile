CC = g++
CFLAGS = -Wall -g 
COMPILE = -c
OUTPUT = -o
OUTPATH = out
APPLICATION = neural
CMD_RUN = ./$(OUTPATH)/$(APPLICATION)

define run_std_compilation
	$(CC) $(CFLAGS) $(COMPILE) $< $(OUTPUT) $(OUTPATH)/$@ $(LIBS)
endef

SRCS = $(wildcard */*/*.cpp) $(wildcard */*.cpp) $(wildcard *.cpp) 
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
OBJS_FILES = $(patsubst %.o,$(OUTPATH)/%.o,$(OBJS))

all: build

start: build run

build: compile
	$(CC) $(CFLAGS) $(OUTPUT) \
		$(OUTPATH)/$(APPLICATION) \
		$(OUTPATH)/main.o

run:
	$(CMD_RUN)

compile: prepare $(OBJS)

prepare:
	mkdir -p $(OUTPATH)

%.o: %.cpp
	$(call run_std_compilation)

clean:
	rm -rf out/*