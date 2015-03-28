/**
 * Copyright 2015, William Dignazio
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
