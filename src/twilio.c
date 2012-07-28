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
#include <string.h> 
#include <curl/curl.h> 
#include <twilio.h>

CURL *handle;
CURLcode res; 

char *asid; //Acount SID
char *atoken; // Account Token 

twilio_status
init_twilio_api(char *accountsid, char *token) { 
    curl_global_init(CURL_GLOBAL_SSL); 
    handle = curl_easy_init(); 
  
    /* Set account login/auth data */
    asid = accountsid; 
    printf(asid);
    printf("\n"); 
    atoken = token; 
    printf(token); 
    printf("\n"); 

    if(handle) { 
        curl_easy_setopt(handle, CURLOPT_VERBOSE, 1); 
        /* They have a cert verified by Equifax */
        curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER, 1); 
        //curl_easy_setopt(handle, CURLOPT_URL, BASEURL); 
    } else { 
        printf("Unable to create curl handle"); 
        exit(1); 
    }
    return OK; 
}
