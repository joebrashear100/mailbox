#ifndef CMSC257_P2SUPPORT_INCLUDED
#define CMSC257_P2SUPPORT_INCLUDED

#define MAILBOX_SIZE 2000
#define ADDRESS_SIZE 50
#define SUBJECT_SIZE 200
#define BODY_SIZE 2000
#define NAME_SIZE 20
#define user_email "brashearjo@vcu.edu"

struct Email
{
  char sender[ADDRESS_SIZE];
  char receiver[ADDRESS_SIZE];
  char subject[SUBJECT_SIZE];
  char body[BODY_SIZE];
  int ID;
  struct sent_date
  {
    int month;
    int day;
    int year;
  }sent_date;
};

struct Mailbox
{
  int size;
  struct Email *emails;
};

///////////////////////////////////////////////////////////////////////////////
// This is a sample comment for the initialize function
// You should include a similar comment for each function declared within the 
// 	.h file
//
// Function     : initialize
// Description  : Initializes the database for CMSC257 project #2 by manually 
//                entering the records using create_email function
// Inputs       : struct Mailbox *ib - pointer to the database
// Outputs      : void
void initialize(struct Mailbox *ib);

/////////////////////////////////////////////////////////////////////////////
// This is the comment block for the function create_email
//
// Function     : create email
// Description  : Allows for the creation of an email. 
//                
// Inputs       : char* sender, char* receiver, char* subject, char* body, int month, int day, int year, struct Mailbox *ib
//                (all the different attributes of an email in our database)
// Outputs      : void
void create_email(char* sender, char* receiver, char* subject, char* body, int month, int day, int year, struct Mailbox *ib);

///////////////////////////////////////////////////////////////////////////
// This is the comment block for the function display_inbox_menu
//
// Function     : display_inbox_menu
// Description  : Creates an interactive menu for navigating the email client. 
//                
// Inputs       : struct Mailbox *ib - pointer to the database
// Outputs      : void
void display_inbox_menu(struct Mailbox *ib);

///////////////////////////////////////////////////////////////////////////
// This is the comment block for swap 
//
// Function     : swap
// Description  : Swaps the location of two emails in the database 
//                
// Inputs       : int swapOne - location of the first email to be swapped, 
//                int swapTwo - location of the second email to be swapped, 
//                struct Mailbox* ib - pointer to the database, 
//                struct Email *emails
// Outputs      : void
void swap(int swapOne, int swapTwo, struct Mailbox* ib, struct Email *emails);

/////////////////////////////////////////////////////////////////////////////
// This is the comment block for the function print_inbox
//
// Function     : print_inbox
// Description  : should print out the emails in the inbox as
//                [ID- 2 digit 0 padded] - [Sender - left aligned, truncated to 20 chars] 
//                - [Date as mm/dd/yyyy] – [Subject truncated to 15 chars and left aligned]  
//                
// Inputs       : struct Mailbox* ib - a pointer the database, struct Email *emails
// Outputs      : void
void print_inbox(struct Mailbox* ib, struct Email *emails);

///////////////////////////////////////////////////////////////////////////
// This is the comment block for the function print_by_ID
//
// Function     : print_by_ID
// Description  : given an email ID this should print out the email with the matching ID.
//                
// Inputs       : struct Mailbox* ib - a pointer the database, struct Email *emails
// Outputs      : void
void print_by_ID(struct Mailbox* ib, struct Email *emails);

//////////////////////////////////////////////////////////////////////////
// This is the comment block for the function sender_sort
//
// Function     : sender_sort
// Description  : sorts the email's list lexicographically by the sender's email address
//                
// Inputs       : struct Mailbox* ib - a pointer the database, struct Email *emails
// Outputs      : void
void sender_sort(struct Mailbox* ib, struct Email *emails);

///////////////////////////////////////////////////////////////////////////
// This is the comment block for the function ID_sort
//
// Function     : ID_sort
// Description  : sorts the email's list by the ID (lower to higher ID numbers).
//                
// Inputs       : struct Mailbox* ib - a pointer the database, struct Email *emails 
// Outputs      : void
void ID_sort(struct Mailbox* ib, struct Email *emails);

///////////////////////////////////////////////////////////////////////////
// This is the comment block for the function keyword_search
//
// Function     : keyword_search
// Description  : searches the emails in your inbox given a string and 
//                displays all the emails including that keyword within the sender, 
//                subject or body fields. Keyword will be a maximum of 10 characters.
//                
// Inputs       : struct Mailbox* ib - a pointer the database, struct Email *emails 
// Outputs      : void
void keyword_search(struct Mailbox* ib, struct Email *emails);

///////////////////////////////////////////////////////////////////////////
// This is the comment block for the function delete_email
//
// Function     : delete_email
// Description  : Allows for the deletion of an email. 
//                
// Inputs       : struct Mailbox* ib - a pointer the database, struct Email *emails  
// Outputs      : void
void delete_email(struct Mailbox* ib, struct Email *emails);

#endif // CMSC257_P2SUPPORT_INCLUDED
