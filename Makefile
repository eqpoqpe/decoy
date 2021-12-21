OUT = target
LIB_OUT = $(OUT)
DEBUG_OUT = $(OUT)/debug/bin
LIB = $(LIB_OUT)/libdecoy.a
DEBUG = $(DEBUG_OUT)/demo
.PHONY: all
all: $(LIB) $(DEBUG)

CC ?= gcc
CFLAGS = -std=c11 -Wall -g -I include

OBJS := \
	example/demo.o \
	src/decoy.o

deps := $(OBJS:%.o=.%.o.d)

.%.o: .%.c
	$(CC) $(CFLAGS) -c -MMD -MF .$@.d -o $@ $<

$(LIB): $(OBJS)
	@mkdir -p $(LIB_OUT)
	@ar -cvq $@ src/*.o
	@cp include/decoy.h $(LIB_OUT)

$(DEBUG): $(OBJS)
	@mkdir -p $(DEBUG_OUT)
	$(CC) $(CFLAGS) -o $@ $^

check: $(DEBUG)
	@./$(DEBUG)

clean:
	$(RM) $(LIB) $(DEBUG) $(OBJS) $(deps)

-include $(deps)
