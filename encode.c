/**
 * Copyright 2012, William Dignazio
 *
 * This file is part of the twilio-c library.
 *
 * twilio-c is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * twilio-c is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with twilio.  If not, see <http://www.gnu.org/licenses/>.kh
 *
 */
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
