/*
 * =====================================================================================
 *
 *       Filename:  encode.c
 *
 *    Description:  Set of encoding tools that can be used to translate strings into and 
 *    				eventually out of different coding types. Might port this later to 
 *    				it's own seperate library or utility, it could be useful in a
 *    				variety of situations. 
 *
 *        Version:  1.0
 *        Created:  07/29/2012 06:16:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Dignazio (slackwill), slackwill@csh.rit.edu
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h> 
#include <string.h> 

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


void 
html_encode(char *str, char **out) { 
  	int i; 
	char *buf = (char*)malloc(strlen(str)); 
	strcpy(buf, str); 
	*out = malloc(html_encoded_size(str));
	for(i=0; i<strlen(buf); i++) { 
	  	switch(buf[i]) { 
		  	case ';':
			  	strcat(*out, "%3B"); 
				break; 
			case '?': 
				strcat(*out, "%3F"); 
				break; 
			case '/': 
				strcat(*out, "%2F");
				break; 
			case ':': 
				strcat(*out, "%3A"); 
				break; 
			case '#': 
				strcat(*out, "%23"); 
				break; 
			case '&': 
				strcat(*out, "%26"); 
				break; 
			case '=': 
				strcat(*out, "%3D");
				break; 
			case '+': 
				strcat(*out, "%2B"); 
				break; 
			case '$': 
				strcat(*out, "%24"); 
				break; 
			case ',': 
				strcat(*out, "%2C"); 
				break; 
			case ' ': 
				strcat(*out, "+"); 
				break; 
			case '%': 
				strcat(*out, "%25"); 
				break; 
			case '<': 
				strcat(*out, "%3C"); 
				break;
			case '>': 
				strcat(*out, "%3E"); 
				break; 
			case '~': 
				strcat(*out, "%7E"); 
				break; 
			case '!': 
				strcat(*out, "%21"); 
				break; 
			default: 
				(*out)[i] = buf[i];
		}
	}
}
