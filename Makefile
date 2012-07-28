CC=gcc 
CFLAGS=-I/usr/include -L/usr/lib -lcurl
LD=ld 

UTIL=$(wildcard ./util/*.c)

# make/link all files within the twilio c bindings. 
# TODO: Remove the util label 
all: utilities

utilities: 
	@for util in $(UTIL); do \
		echo "CC	$${util:0:-2}"; \
		$(CC) $(CFLAGS) -o $${util:0:-2} $$util; \
	done;

clean: 
	rm -f ./*.o
	rm -f ./util/*.o
	rm -f ./util/curltest
