/**
 * Copyright 2012, William Dignazio
 *
 * This file is part of the twilio-c library.
 *
 * twilio-c is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * twilio-c is distributed in the hope that it will be useful,
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
