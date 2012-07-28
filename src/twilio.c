/*
 * =====================================================================================
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
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h> 
#include <curl/curl.h> 
#include <twilio.h>

CURL *handle;

twilio_status
init_twilio_api(const char * asid, const char *token) { 

    curl_global_init(CURL_GLOBAL_NOTHING); 
    handle = curl_easy_init(); 
    if(handle) { 
        curl_easy_setopt(handle, CURLOPT_VERBOSE, 1); 
    } else { 
        printf("Unable to create curl handle"); 
        exit(1); 
    }
    return OK; 
}
