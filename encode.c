/**
 * Copyright 2015, William Dignazio
 */
#include <stdlib.h>
#include <stdio.h> 
#include <string.h> 

/* Calculates the size of the html encoded string counterpart to
 * the string passed into the arguments. */
int
html_encoded_size(char *in) { 
  	int sz=0; 
	int i; 
	for(i=0; i<strlen(in); i++) { 
	  	switch(in[i]) { 
			case ';': 
				sz+=3; 
				break;
			case '?': 
				sz+=3;
				break;
			case '/': 
				sz+=3; 
			case ':': 
				sz+=3;
			case '#': 
				sz+=3; 
				break; 
			case '&': 
				sz+=3; 
				break; 
			case '=': 
				sz+=3; 
				break; 
			case '+': 
				sz+=3; 
				break;
			case '$': 
				sz+=3; 
				break; 
			case ' ': 
				sz+=1; 
				break; 
			case '%': 
				sz+=3; 
				break; 
			case '<': 
				sz+=3; 
				break; 
			case '>':
				sz+=3; 
				break; 
			case '~': 
				sz+=3; 
				break; 
			case '!': 
				sz+=3; 
				break; 
			default: 
				sz+=1; 
		}
	}
	return sz; 
}

/* Encodes a C string into an html encoded string. */
void 
html_encode(char *str, char **out) { 
  	int offset = 0;
  	int i; 
	char buf[strlen(str)+1]; 
	strcpy(buf, str); 
	*out = malloc(html_encoded_size(str));
	for(i=0; i<strlen(buf); i++) { 
	  	switch(buf[i]) { 
		  	case ';':
			  	strcat(*out, "%3B"); 
				offset+=2;
				break; 
			case '?': 
				strcat(*out, "%3F"); 
				offset+=2;
				break; 
			case '/': 
				strcat(*out, "%2F");
				offset+=2;
				break; 
			case ':': 
				strcat(*out, "%3A"); 
				offset+=2; 
				break; 
			case '#': 
				strcat(*out, "%23"); 
				offset+=2; 
				break; 
			case '&': 
				strcat(*out, "%26"); 
				offset+=2; 
				break; 
			case '=': 
				strcat(*out, "%3D");
				offset+=2; 
				break; 
			case '+': 
				strcat(*out, "%2B"); 
				offset+=2; 
				break; 
			case '$': 
				strcat(*out, "%24"); 
				offset+=2; 
				break; 
			case ',': 
				strcat(*out, "%2C"); 
				offset+=2; 
				break; 
			case ' ': 
				strcat(*out, "+"); 
				break; 
			case '%': 
				strcat(*out, "%25"); 
				offset+=2; 
				break; 
			case '<': 
				strcat(*out, "%3C"); 
				offset+=2; 
				break;
			case '>': 
				strcat(*out, "%3E"); 
				offset+=2; 
				break; 
			case '~': 
				strcat(*out, "%7E"); 
				offset+=2; 
				break; 
			case '!': 
				strcat(*out, "%21"); 
				offset+=2;
				break; 
			default: 
				(*out)[offset+i] = buf[i];
		}
	}
}
