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
    char *uri = malloc(strlen(BASEURL)+strlen(resource)+strlen(asid)); 
    sprintf(uri, BASEURL, resource); 
    sprintf(uri, uri, asid); 
    return uri;
}

/* POST message to send a sms message to the desired recpient */
void 
post_sms(void) {
    char *uri = build_uri(POST_SMS); 
    curl_easy_setopt(handle, CURLOPT_URL, uri); 
    printf(uri);
    printf("\n"); 
}

