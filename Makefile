CC=gcc 
CFLAGS= -Wall -I/usr/include -I./include -L/usr/lib -L./ -lcurl
LD=ld 

VERSION=1.0.1

UTIL=$(wildcard ./util/*.c)
SRC=$(wildcard ./src/*.c)
OBJ=$(wildcard ./src/*.o) 

# make/link all files within the twilio c bindings. 
# TODO: Remove the util label 
all: link

link: lib
	@$(CC) -shared -Wl,-soname,libtwilio.so \
		-o libtwilio.so.$(VERSION) $(OBJ)
	@echo "CC	libtwilio.so"

lib: 
	@for file in $(SRC); do \
		echo "CC	$${file:0:-2}.o"; \
		$(CC) $(CFLAGS) -fPIC -g -o $${file:0:-2}.o -c $$file; \
	done; 

utilities:  link 
	@for util in $(UTIL); do \
		echo "CC	$${util:0:-2}"; \
		$(CC) $(CFLAGS) -o $${util:0:-2} -ltwilio $$util; \
	done;

clean: 
	rm -f ./*.o
	rm -f ./src/*.o
	rm -f ./util/*.o
	rm -f ./util/curltest
	rm -f ./libtwilio.so*
