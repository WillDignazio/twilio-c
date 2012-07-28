CC=gcc 
CFLAGS=-I/usr/include -lcurl
LD=ld 

UTIL=$(wildcard ./util/*.c)

# make/link all files within the twilio c bindings. 
# TODO: Remove the util label 
all: utilities

utilities: 
	@echo "TEST" 
	@for util in $(UTIL); do \
		echo "CC	$${util:0:-2}.o"; \
		$(CC) $(CFLAGS) -o $${util:0:-2}.o -c $$util; \
	done;
