CC=gcc 
CFLAGS= -Wall -I/usr/include -I./include -L/usr/lib -L$(BIN) -lcurl
LD=ld 
BIN=bin
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
		echo "CC	$(BIN)/$${util:7:-2}"; \
		$(CC) $(CFLAGS) -ltwilio -o $(BIN)/$${util:7:-2} $$util; \
	done;

devinstall: all
	ln -sf $(CURDIR)/$(BIN)/libtwilio.so.$(VERSION) /usr/lib/libtwilio.so
	ln -sf $(CURDIR)/include/twilio.h /usr/include/twilio.h
	ln -sf $(CURDIR)/include/encode.h /usr/include/encode.h


install: all
	cp $(BIN)/libtwilio.$(VERSION) /usr/lib/
	cp include/twilio.h /usr/include
	cp include/encode.h /usr/include
	ln -sf /usr/lib/libtwilio.so.$(VERSION) /usr/lib/libtwilio.so

clean: 
	rm -f ./*.o
	rm -f ./src/*.o
	rm -f ./util/*.o
	rm -f ./util/curltest
	rm -f ./libtwilio.so*
	rm -rf $(BIN)
