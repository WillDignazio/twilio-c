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
    char *uri = malloc(strlen(resource)+strlen(asid)); 
    sprintf(uri, resource, asid); 
    return uri;
}

/* POST message to send a sms message to the desired recpient */
void 
post_sms(char *snd, char *rec, char *msg) {
    char *uri = build_uri(POST_SMS); 
    curl_easy_setopt(handle, CURLOPT_URL, uri); 
    printf(uri);
    printf("\n"); 
   /*  
    twilio_post_t post; 
    post.asid = asid; 
    post.version = VERSION; 
    post.body = msg; 
    post.created = "null"; 
    post.sent = "null";
    post.updated = "null"; 
    post.direction = "outbound-api"; 
    post.from = snd;
    post.price = "null"; 
    post.sid = sid; 
    post.status = "queued"; 
    post.to = rec;
    post.uri = uri; 
    */
    char *bodybase = "From=%s&To=%s&Body=%s"; 
    char *buf = malloc(strlen(bodybase)+
            strlen(snd) + 
            strlen(rec) + 
            strlen(msg));
    sprintf(buf, snd, rec, msg); 
    curl_easy_setopt(handle, CURLOPT_POSTFIELDS, buf);  
    curl_easy_perform(handle); 
    free(buf); 
}

