/*
 * Copyright (c) 2015, Will Dignazio
 */
#include <stdlib.h>
#include <twilio.h> 

/* Simple encoded string test utility. Makes sure that the encoded string
 * functionality I wrote works. */ 
int main(int argc, char *argv[]) { 
  	if(argv[1]) { 
	  	printf("Before html_encode: %s\n", argv[1]); 
		char *c; 
		html_encode(argv[1], &c); 
		printf("After html_encode: %s\n", c); 
		char *d; 
		html_encode(argv[1], &d); 
		printf("Repetitive html_enocode test: %s\n", d);
	}
	return 0; 
}

