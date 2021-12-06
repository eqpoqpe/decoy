OUT = build
EXEC = $(OUT)/libdecoy.a
DEMO = $(OUT)/demo
.PHONY: all
all: $(EXEC) $(DEMO)

CC ?= gcc
CFLAGS = -std=c11 -Wall -g -I include

OBJS := \
	example/demo.o \
	src/decoy.o \
	src/extension/setval.o

deps := $(OBJS:%.o=.%.o.d)

./src%.o: ./src%.c
	$(CC) $(CFLAGS) -c -MMD -MF .$@.d -o $@ $<

$(EXEC): $(OBJS)
	@mkdir -p $(OUT)
	@ar -cvq $@ src/*.o

$(DEMO): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

check: $(DEMO)
	@./$(DEMO)

clean:
	$(RM) $(EXEC) $(DEMO) $(OBJS) $(deps)

-include $(deps)
