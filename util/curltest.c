/**
 * Copyright 2015, William Dignazio
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
