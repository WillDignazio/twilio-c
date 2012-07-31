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
 * ========================================================================
 *
 *       Filename:  twilio.c
 *
 *    Description:  Twilio library functions
 *
 *        Version:  1.0
 *        Created:  07/28/2012 01:24:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Dignazio (slackwill), slackwill@csh.rit.edu
 *   Organization:  
 *
 * ========================================================================
 */
#include <stdlib.h>
#include <stdio.h> 
#include <string.h> 
#include <curl/curl.h> 
#include <twilio.h>

CURL *handle;
CURLcode res; 

char *asid; //Acount SID
char *atoken; // Account Token 

/* Should be the first function you call when you 
 * use this library. Initializes an instance of the 
 * variables required to communicate with the 
 * twilio API. 
 */
twilio_status
init_twilio_api(char *accountsid, char *token) { 
    curl_global_init(CURL_GLOBAL_SSL); 
    handle = curl_easy_init(); 
  
    /* Set account login/auth data */
    asid = accountsid; 
    atoken = token; 

    if(handle) { 
        /* They have a cert verified by Equifax */
        curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER, 1); 
        //curl_easy_setopt(handle, CURLOPT_URL, BASEURL); 
    } else { 
        printf("Unable to create curl handle"); 
        exit(1); 
    }
    return OK; 
}
