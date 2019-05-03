
/**
 *  @brief An implementation to use 'link' data type
 *
 *  Here all functions related to 'link' data types are implemented as well as the structure Link
 *
 *  @file link.c
 *  @date 7/04/2019
 *  @author Conache Alexandra
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/link.h"

/**
 *   @brief Link structure
 *
 *   Stores relevant information about the Link of spaces
 *
 */
struct _Link {
  Id link_id;  /*!< id of the link*/
  char name[WORD_SIZE + 1]; /*!< name of the link*/
  Id link1;  /*!< id of the first link done*/
  Id link2;  /*!< id of the second link done*/
  STATE state; /*!< state of the link*/
};
/* Creates a link */
Link* link_create(Id id){
  Link *newLink = NULL;
    
  newLink = (Link *)malloc(sizeof(Link));

  if (newLink == NULL || id == NO_ID) {
    return NULL;
  }
    
  newLink->link_id = id;
  newLink->name[0] = '\0';
  newLink->link1= NO_ID;
  newLink->link2= NO_ID;
  newLink->state= DESCONOCIDO;
    
  return newLink;
}

/* Destroys a link */
void link_destroy(Link* link){
  if (!link) {
    return;
  }
  free(link);

  return;
}

/* Gets the ID of the link */
Id link_get_id(Link* link) {
  if (!link) {
    return NO_ID;
  }
  return link->link_id;
}

/* Gets the first link */
Id link_get_link1(Link* link) {
  if (!link) {
    return NO_ID;
  }
  return link->link1;
}

/* Gets the second link */
Id link_get_link2(Link* link) {
  if (!link) {
    return NO_ID;
  }
  return link->link2;
}

/* Gets the name of the link */
const char * link_get_name(Link* link) {
  if (!link) {
    return NULL;
  }
  return link->name;
}

/* Gets the state of the link */
STATE link_get_state(Link* link) {
  if (!link) {
    return DESCONOCIDO;
  }
  return link->state;
}

/* Sets the name of the link */
STATUS link_set_name(Link* link, char* name) {
  if (!link || !name) {
    return ERROR;
  }

  if (!strcpy(link->name, name)) {
    return ERROR;
  }

  return OK;
}

/* Sets the first link */
STATUS link_set_link1(Link* link, Id id) {
  if (!link || id == NO_ID) {
    return ERROR;
  }
  link->link1 = id;
  return OK;
}

/* Sets the second link */
STATUS link_set_link2(Link* link, Id id) {
  if (!link || id == NO_ID) {
    return ERROR;
  }
  link->link2 = id;
  return OK;
}

/* Sets the state of the link */
STATUS link_set_state(Link* link, STATE state) {
  if (!state || state == DESCONOCIDO) {
    return ERROR;
  }
  link->state = state;
  return OK;
}

/* Prints the link */
STATUS link_print(Link* link) {

  if (!link) {
    return ERROR;
  }

  fprintf(stdout, "--> Link (Id: %ld; Name: %s)\n", link->link_id, link->name);

  
  fprintf(stdout, "---> Link 1: %ld.\n", (long)link->link1);
  fprintf(stdout, "---> Link 2: %ld.\n", (long)link->link2);
  fprintf(stdout, "---> STATE: %d.\n", link->state);
  return OK;
}
