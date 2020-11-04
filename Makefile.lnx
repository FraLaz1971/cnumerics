CC=gcc -g -O2
SRC = $(wildcard *.c)
OBJ = *.o *.obj
CPPFLAGS = -Iinclude
LDFLAGS = -Llib -lm
TARGET0 = accuracy
TARGET1 = doublevec
TARGET2 = loopint
TARGET3 = precision
TARGETS = precision loopint doublevec accuracy
all: $(TARGETS)
$(TARGET0).o: accuracy.c
	$(CC) -c   $< -o accuracy.o $(CPPFLAGS)
$(TARGET0): accuracy.o
	$(CC) -o accuracy $< $(LDFLAGS)
$(TARGET1).o: doublevec.c
	$(CC) -c   $< -o doublevec.o $(CPPFLAGS)
$(TARGET1): doublevec.o
	$(CC) -o doublevec $< $(LDFLAGS)
$(TARGET2).o: loopint.c
	$(CC) -c   $< -o loopint.o $(CPPFLAGS)
$(TARGET2): loopint.o
	$(CC) -o loopint $< $(LDFLAGS)
$(TARGET3).o: precision.c
	$(CC) -c   $< -o precision.o $(CPPFLAGS)
$(TARGET3): precision.o
	$(CC) -o precision $< $(LDFLAGS)
install: all
	mv $(TARGETS) bin
.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGETS)
distclean: clean
	rm -f bin/* Makefile
