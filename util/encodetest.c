/*
 * =====================================================================================
 *
 *       Filename:  encodetest.c
 *
 *    Description:  Encoding test app
 *
 *        Version:  1.0
 *        Created:  07/29/2012 08:08:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Dignazio (slackwill), slackwill@csh.rit.edu
 *   Organization:  
 *
 * =====================================================================================
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

