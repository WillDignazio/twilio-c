CC=gcc 
CFLAGS= -Wall -I/usr/include -I./include -L/usr/lib -L$(BIN) -lcurl
LD=ld 
BIN=./bin
VERSION=1.0.1

UTIL=$(wildcard ./util/*.c)
SRC=$(wildcard ./src/*.c)
OBJ=$(wildcard ./src/*.o) 

# make/link all files within the twilio c bindings. 
# TODO: Remove the util label 
all: link

link: lib
	@mkdir -p $(BIN)
	@$(CC) -shared -Wl,-soname,libtwilio.so \
		-o $(BIN)/libtwilio.so.$(VERSION) $(OBJ)
	ln -sf libtwilio.so.$(VERSION) $(BIN)/libtwilio.so
	@echo "CC	libtwilio.so"

lib: 
	@for file in $(SRC); do \
		echo "CC	$${file:0:-2}.o"; \
		$(CC) $(CFLAGS) -fPIC -g -o $${file:0:-2}.o -c $$file; \
	done; 

utilities:  link 
	@for util in $(UTIL); do \
		echo "CC	$${util:0:-2}"; \
		$(CC) $(CFLAGS) -ltwilio -o $${util:0:-2} $$util; \
	done;

clean: 
	rm -f ./*.o
	rm -f ./src/*.o
	rm -f ./util/*.o
	rm -f ./util/curltest
	rm -f ./libtwilio.so*
	rm -rf $(BIN)
