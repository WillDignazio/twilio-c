/**
 * This file is part of the twilio-c library.
 *
 * twilio is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * twilio is distributed in the hope that it will be useful,
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
 *       Filename:  sms.c
 *
 *    Description:  SMS test app
 *
 *        Version:  1.0
 *        Created:  07/28/2012 06:55:31 PM
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
#include <unistd.h> 
#include <pwd.h> 
#include <twilio.h> 

/* This is a simple sms utility for sending out text messages 
 * through the command line. You need to have a file in your 
 * home directory with three lines, one for sid, token, and 
 * sending phone number, in that order. The text will be 
 * charged from your twilio account. 
 */
int main(int argc, char *argv[]) { 

	char *sid; 
	char *token;
	char *from_number; 

  	struct passwd *pw = getpwuid(getuid());
	char path[strlen(pw->pw_dir)+strlen("/.smsrc")]; 
	sprintf(path, "%s%s", pw->pw_dir, "/.smsrc"); 
	FILE *fp = fopen(path, "r"); 

	char buffer[50]; 
	int stage; 
	for(stage=0; fgets(buffer, 80, fp); stage++) { 
	  	char *newseek; 
	  	switch(stage) { 
		  	case 0: // SID
			  	sid = malloc(strlen(buffer));
				sprintf(sid, "%s", buffer);
				if((newseek = strchr(sid, '\n')))
				  	*newseek = '\0';
				//printf("Read sid: %s\n", sid);
				break; 
			case 1: // Token

				token = malloc(strlen(buffer)); 
				sprintf(token, "%s", buffer); 
				if((newseek = strchr(token, '\n')))
				  	*newseek = '\0';
				//printf("Read token: %s\n", token); 
				break;
			case 2: // Sending phone number
				from_number = malloc(strlen(buffer)); 
				sprintf(from_number, "%s", buffer);
				if((newseek = strchr(from_number, '\n')))
				  	*newseek = '\0'; 
				//printf("Read number: %s\n", buffer); 
				break;
		}
		/* Zero out the buffer for the next run. */ 
		bzero(buffer, sizeof(buffer)); 
	}

	/* Initialize the C twilio library */
  	init_twilio_api(sid, token); 

	char number[20]; 
	printf("To: "); 
	if(fgets(number, sizeof(number), stdin) != NULL) { 
		char *newline = strchr(number, '\n'); 
		if(newline != NULL) { 
			*newline = '\0'; 
		}
	}

	char text[160]; 
	printf("Text: "); 
	if(fgets(text, sizeof(text), stdin) != NULL) { 
		char *newline = strchr(text, '\n'); 
		if(newline != NULL) { 
			*newline = '\0'; 
		}
	}

	/* Twilio only accepts encoded numbers, maybe later 
	 * I will make an encoded number a structure itself. 
	 * That way you'd have to TRY to screw up your 
	 * numbers. 
	 */
	char *number_encoded; 
	html_encode(number, &number_encoded); 
	//printf("Encoded To Number: %s\n", number_encoded); 

	char *from_encoded; 
	html_encode(from_number, &from_encoded); 
	//printf("From Encoded: %s\n", from_encoded); 

	char *encoded_text; 
	html_encode(text, &encoded_text); 
	//printf("Text Encoded: %s\n", encoded_text); 

	post_sms(from_encoded, number_encoded, encoded_text);

    return 0; 
}

