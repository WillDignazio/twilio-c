CC=gcc 
CFLAGS=-I/usr/include -I./include -L/usr/lib -lcurl
LD=ld 

UTIL=$(wildcard ./util/*.c)
SRC=$(wildcard ./src/*.c)

# make/link all files within the twilio c bindings. 
# TODO: Remove the util label 
all: link utilities

link: lib
	@echo "Building shared library...";

lib: 
	@for file in $(SRC); do \
		echo "CC	$${file:0:-2}.o"; \
		$(CC) $(CFLAGS) -o $${file:0:-2}.o -c $$file; \
	done; 

utilities: 
	@for util in $(UTIL); do \
		echo "CC	$${util:0:-2}"; \
		$(CC) $(CFLAGS) -o $${util:0:-2} $$util; \
	done;

clean: 
	rm -f ./*.o
	rm -f ./src/*.o
	rm -f ./util/*.o
	rm -f ./util/curltest
