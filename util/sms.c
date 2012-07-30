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

int main(int argc, char *argv[]) { 
	
  	/* I'd prefer it if you didn't have to type in your sid and token 
	 * every time you wanted to send an sms, so you should be able to 
	 * read it into from file. */
  	char *path = malloc(strlen(getpwuid(getuid())->pw_dir) + strlen(".smsrc")); 
	sprintf(path, "%s/%s", getpwuid(getuid())->pw_dir, ".smsrc"); 
	FILE *fp = fopen(path, "r"); 
	char rec[30]; 
	char txt[160];
	char sid[50]; 
	char token[50]; 
	char num[50]; 
	char *lnptr;
	char *enc; 
	char *enc2; 
	char *enc3;

	if(!fp) {
	  	printf("Could not find sid/token config.\n"); 
		//TODO: Write in manual sid/token input
		exit(1);
	} else { 
	  	/* All you need to do is have the first line of the rc 
		 * file as your sid, the second as your token, and 
		 * the third as your from phone number*/
	  	
		fgets(sid, sizeof(sid), fp);
		lnptr = strchr(sid, '\n'); 
		if(lnptr) { *lnptr = '\0'; }	
		printf("sid: %s\n", sid);

		fgets(token, sizeof(token), fp); 
		lnptr = strchr(token, '\n');
		if(lnptr) { *lnptr = '\0'; }
		printf("token: %s\n", token); 
		
		fgets(num, sizeof(num), fp); 
		lnptr = strchr(num, '\n'); 
		if(lnptr) { *lnptr = '\0'; }
		printf("number: %s\n", num);

		html_encode(num, &enc); 
		printf("Encoded from number: %s\n", enc);

		printf("To: "); 
		char *buf = strchr(rec, '\n'); 
		if(fgets(rec, sizeof(rec), stdin)) { 
			if(buf) 
				*buf = '\0'; 
		}
		html_encode(buf, &enc2);

		printf("Text: ");
		char *buf2 = strchr(txt, '\n');
		if(fgets(txt, sizeof(txt), stdin)) {
		  	if(buf2) 
			  *buf2 = '\0';
		}
		html_encode(buf2, &enc3);
	
		/* Now we can actually use the API */
		init_twilio_api(sid, token);
		printf("Sending to: %s\n", enc2);
		printf("Sending from: %s\n", enc);
		post_sms(enc, enc2, enc3);
	}
  	
    return 0; 
}

