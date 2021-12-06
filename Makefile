EXEC = libdecoy.a
DEMO = demo
.PHONY: all
all: $(EXEC) $(DEMO)

CC ?= gcc
CFLAGS = -std=c11 -Wall -g

OBJS := \
	example/demo.o \
	src/decoy.o \
	src/decmap.o \
	src/setval.o

deps := $(OBJS:%.o=.%.o.d)

./src%.o: ./src%.c
	$(CC) $(CFLAGS) -c -MMD -MF .$@.d -o $@ $< -I ./include

$(EXEC): $(OBJS)
	@ar -cvq $@ src/*.o

$(DEMO): $(OBJS)
	$(CC) -o $@ $^ -I include

check: $(DEMO)
	@./$(DEMO)

clean:
	$(RM) $(EXEC) $(DEMO) $(OBJS) $(deps)

-include $(deps)
