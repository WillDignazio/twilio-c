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
 *       Filename:  rest.c
 *
 *    Description:  Rest api functions for twilio c libraries. 
 *
 *        Version:  1.0
 *        Created:  07/28/2012 04:26:45 PM
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
#include <curl/curl.h> 
#include <twilio.h> 

/* Buils the entire resource uri for the twilio api function */
char*
build_uri(char *resource) {
    char *base = malloc(strlen(BASEURL)+
            strlen(asid) + 
            strlen(atoken) + 
            strlen(resource)); 
    sprintf(base, BASEURL, asid, atoken, resource); 
    char *uri = malloc(strlen(base)+strlen(asid)); 
    sprintf(uri, base, asid); 
    /* Make sure you free the memory later after using this. */
    return uri;
}

/* POST message to send a sms message to the desired recpient */
void 
post_sms(char *snd, char *rec, char *msg) {
    char *uri = build_uri(POST_SMS); 
    char *bodybase = "From=%s&To=%s&Body=%s"; 
    char *buf = malloc(strlen(bodybase)+
            strlen(snd) + 
            strlen(rec) + 
            strlen(msg));
    sprintf(buf, bodybase, snd, rec, msg); 
   
    /* Set the proper fields for posting. */
    curl_easy_setopt(handle, CURLOPT_URL, uri); 
    curl_easy_setopt(handle, CURLOPT_POSTFIELDS, buf);  
    curl_easy_perform(handle); 
    
    free(buf); 
    free(uri); 
}

