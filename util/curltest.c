/*
 * =====================================================================================
 *
 *       Filename:  curltest.c
 *
 *    Description:  simple curl test utility to make sure I know what I'm doing. 
 *
 *        Version:  1.0
 *        Created:  07/28/2012 12:14:50 PM
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

size_t
write_function(void *buffer, size_t size, size_t rmemb, void *userp) { 
    return 0; 
}

int main(int argc, char *argv[]) { 
    
    printf(curl_version()); 

    /* Initialize curl, args is flags */
    curl_global_init(CURL_GLOBAL_NOTHING);
    CURL *handle = curl_easy_init(); 
    curl_easy_setopt(handle, CURLOPT_VERBOSE, 1); 
    curl_easy_setopt(handle, CURLOPT_URL, "http://www.google.com/"); 
    /* Not Setting this goes to stdout */
    //curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_function); 
    
    return curl_easy_perform(handle); 
}
