/*
 * =====================================================================================
 *
 *       Filename:  twilio.h
 *
 *    Description:  Twilio library header file
 *
 *        Version:  1.0
 *        Created:  07/28/2012 01:25:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Dignazio (slackwill), slackwill@csh.rit.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#include <curl/curl.h>

#ifndef TWILIO_GAURD_H
#define TWILIO_GARUD_H

#define VERSION "2010-04-01"; 

#define OK 0

#define BASEURL "https://%s:%s@api.twilio.com%s"

/*#############################################################################
 *#                           REST API MACROS                                 #
 *#############################################################################
 */
#define POST_SMS "/2010-04-01/Accounts/%s/SMS/Messages.json" //TODO: extension

/*###########################################################################*/

extern CURL *handle; 
extern char* asid; //Account sid
extern char* atoken; 

typedef int twilio_status; 

typedef struct twilio_post_t { 
    char *asid; 
    char *version; 
    char *body; 
    char *created; 
    char *sent; 
    char *updated; 
    char *direction; 
    char *from; 
    char *price; 
    char *sid;
    char *status; 
    char *to; 
    char *uri; 
} twilio_post_t; 

typedef struct twilio_request_t { 
} twilio_request_t;  

twilio_status init_twilio_api(char*, char*); 

void post_sms(char*,char*,char*); 

#endif 
