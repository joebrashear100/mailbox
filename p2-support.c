////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// A menu driven email client. The email client displays the inbox, displays email, 
// searches emails by keyword, sorts inbox emails in inbox by sender, sorts emails 
// in inbox by ID, and deletes emails inbox by ID.
//
// Joe Brashear, VCU CMSC257
// Date of Last Edit: 11/12/2022
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p2-support.h"
 
void
initialize (struct Mailbox *ib)
{
  //allocate memory for 2000 emails
  ib->emails = malloc (sizeof (struct Email) * MAILBOX_SIZE);
  ib->size = 0;
 
 
  create_email ("asonmez@mail.com", user_email, "Welcome to your inbox.",
                "Welcome to your inbox, just wanted to say hi. Here's hoping you get all your code done.",
                 11,20,2020, ib);
  create_email ("mmartinez@mail.com", user_email, "Padding out your inbox.",
                "Yet another email just to pad out your inbox, have fun!",
                 11,30,2020, ib);
  create_email ("dboyle@mail.com", user_email, "3rd email!",
                "Alright, time for another email for your inbox. Not going too lie, it's a bit of a pain coming up with stuff for these strings. Anyways, have fun with your code!",
                 12,2,2020, ib);
  create_email ("cbluer@mail.com", user_email, "4th email!",
                "Content of fourth email. More coding, more fun!",
                 12,8,2020, ib);
  create_email ("cboyle@mail.com", user_email, "5th email!",
                "Content of fifth email. Coding is fun-tastic!",
                 12,18,2020, ib);
  create_email ("sblack@mail.com", user_email, "6th email!",
                "Content of fifth email. Coding is fun-tastic!",
                 1,1,2021, ib);
  create_email ("sblack@mail.com", user_email, "7th email!",
                "Body of sixth email. Coding is fun-tastic!",
                 1,5,2021, ib);
  create_email ("sblack@mail.com", user_email, "8th email!",
                "Body of eighth email. Coding is fun-tastic!",
                 2,15,2021, ib);
  create_email ("sblack@mail.com", user_email, "9th email!",
                "Body of ninth email. Coding is fun-tastic!",
                 2,25,2021, ib);
  create_email ("dboyle@mail.com", user_email, "Last email!",
                "Body of tentth email. Coding is fun-tastic!",
                 3,15,2021, ib);
 
}



void display_inbox_menu(struct Mailbox *ib) 
{
  int user_option = 0;
  while(user_option != 7)
  {
    printf("\n\n\n");
    printf("***************   %s INBOX   ***************\n", user_email);
    printf("***************   Total Inbox: %04d   ***************\n", ib->size);
    printf("1. Show Inbox\n");
    printf("2. Show Email by ID\n");
    printf("3. Sort Inbox by Sender\n");
    printf("4. Sort inbox by ID\n");
    printf("5. Search Inbox by Keyword\n");
    printf("6. Delete\n");
    printf("7. Exit\n");

    scanf("%d", &user_option);
    switch(user_option)
    {
      case 1:
        print_inbox(ib, ib->emails);
        break;

      case 2:
        print_by_ID(ib, ib->emails);
        break;

      case 3:
	sender_sort(ib, ib->emails);
        break;

      case 4:
	ID_sort(ib, ib->emails);
        break;

      case 5:
	keyword_search(ib, ib->emails);
        break;

      case 6:
        delete_email(ib, ib->emails);
        break; 
     }
   }
   free(ib->emails);
   printf("Exiting e-mail client - Good Bye!\n");

}


void create_email(char* sender, char* receiver, char* subject, char* body, int month, int day, int year, struct Mailbox *ib){
    strncpy(ib->emails[ib->size].sender, sender, ADDRESS_SIZE);
    strncpy(ib->emails[ib->size].receiver, receiver, ADDRESS_SIZE);
    strncpy(ib->emails[ib->size].subject, subject, SUBJECT_SIZE);
    strncpy(ib->emails[ib->size].body, body, BODY_SIZE);
    ib->emails[ib->size].sent_date.month = month;
    ib->emails[ib->size].sent_date.day = day;
    ib->emails[ib->size].sent_date.year = year;
    ib->emails[ib->size].ID = ib->size;
    ib->size++;
}

void swap(int swapOne, int swapTwo, struct Mailbox* ib, struct Email *emails)
{
  struct Email temp = ib->emails[swapOne];
  ib->emails[swapOne] = ib->emails[swapTwo];
  ib->emails[swapTwo] = temp;
}

void print_inbox(struct Mailbox* ib, struct Email *emails)
{
  printf("\n\n\n");
  printf("ID   Sender---------------   MM/DD/YYYY   SUBJECT--------\n");
  printf("--   ---------------------   --/--/----   ---------------\n");
  int i;
  for(i = 0; i < ib->size; i++)
  {
    printf("-%02d - %-20s - %02d/%02d/%d - %.15s \n",ib->emails[i].ID ,ib->emails[i].sender, ib->emails[i].sent_date.month, ib->emails[i].sent_date.day, ib->emails[i].sent_date.year, 	
	    ib->emails[i].subject);
  }

}

void print_by_ID(struct Mailbox* ib, struct Email *emails)
{
  printf("\n\n\n");
  printf("Enter the ID of the email you want to read\n");
  int IDnum;
  scanf("%d", &IDnum);
  printf("\n%-15s - %-s\n",ib->emails[IDnum].sender, ib->emails[IDnum].subject);
  printf("Email received on: %02d/%02d/%d\n",ib->emails[IDnum].sent_date.month, ib->emails[IDnum].sent_date.day, ib->emails[IDnum].sent_date.year);
  printf("\n%-s", ib->emails[IDnum].body);
}

void sender_sort(struct Mailbox* ib, struct Email *emails)
{
  int i, j;
  for(i = 0; i < ib->size; i++)
  {
    for(j = i+1; j < ib-> size; j++)
    {
      if(strcmp(ib->emails[i].sender, ib->emails[j].sender) > 0)
      {
        swap(i, j, ib, ib->emails);
      }
    }
  }
}

void ID_sort(struct Mailbox* ib, struct Email *emails)
{
  int i, j;
  for(i = 0; i < ib->size; i++)
  {
    for(j = i+1; j < ib-> size; j++)
    {
      if(ib->emails[i].ID > ib->emails[j].ID)
      {
        swap(i, j, ib, ib->emails);
      }
    }
  }
}


void keyword_search(struct Mailbox* ib, struct Email *emails)
{
  int i;
  char keyword[10];

  printf("\n\n\n");
  printf("Enter the keyword you are searching for:\n");
  scanf("%s", keyword);

  printf("ID   Sender---------------   MM/DD/YYYY   SUBJECT-------- \n");
  printf("--   ---------------------   --/--/----   --------------- \n");

  for(i=0; i< ib->size; i++)
  {
    if(strstr(ib->emails[i].sender, keyword) != NULL || strstr(ib->emails[i].subject, keyword) != NULL || strstr(ib->emails[i].body, keyword) != NULL)
    {
      printf("-%02d - %-20s - %02d/%02d/%d - %.15s \n",ib->emails[i].ID ,ib->emails[i].sender, ib->emails[i].sent_date.month, ib->emails[i].sent_date.day, 
             ib->emails[i].sent_date.year, ib->emails[i].subject);
    }
  }

}

void delete_email(struct Mailbox* ib, struct Email *emails)
{
  int i, j, del_ID;
  bool delete = false;

  printf("\n\n\n");
  printf("Enter the ID of the e-mail you want to delete:\n");
  scanf("%d", &del_ID);
  for(i = 0; i < ib->size; i++)
  {
    if(ib->emails[i].ID == del_ID)
    {
      delete = true;
      for(j = i; j < ib->size - 1; j++)
      {
        ib->emails[j] = ib->emails[j + 1];
      } 
    }
  }
  
  if(delete == false)
  {
    printf("Sorry, that email does not exist...");
  }
  else
  {
    ib->size--;
    printf("Email with ID = %d is deleted\n", del_ID);
  }
}








