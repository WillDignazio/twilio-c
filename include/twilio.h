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

#ifndef TWILIO_GAURD_H
#define TWILIO_GARUD_H

#define OK 0

#define BASEURL "https://api.twilio.com/2010-04-01/%s"

/*#############################################################################
 *#                           REST API                                        #
 *#############################################################################
 */
#define POST_SMS "/2010-04-01/Accounts/%s/SMS/Messages"

/*###########################################################################*/

extern char* asid; 
extern char* atoken; 

typedef int twilio_status; 

typedef struct twilio_request_t { 
} twilio_request_t;  


twilio_status init_twilio_api(char*, char*); 

#endif 
