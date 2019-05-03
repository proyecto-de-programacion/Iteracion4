/**
 *  @brief An implementation to use 'space' data type
 *
 *  Here all functions related to 'space' data types are implemented as well as the structure Object
 *
 *  @file space.c
 *  @version 1.0
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/space.h"

#include "../include/set.h"

/**
 *   @brief Space structure
 *
 *   Stores relevant information about the space the game is held in
 *
 */

struct _Space {
  Id id;                      /*!< The ID the space has assigned */
  char name[WORD_SIZE + 1];   /*!< The name we can assign to the space */
  Id north_link;                   /*!< The upper part of the space */
  Id south_link;                   /*!< The downwards part of the space */
  Id east_link;                    /*!< The right part of the space */
  Id west_link;                    /*!< The left part of the space */
  Id up_link;
  Id down_link;
  Set *objects;               /*!< What object is currently on the space */
  char gdesc[ROWS][COLUMNS];             /*!< campo gdesc*/
  char description[WORD_SIZE+1];   /*!< brief description of the space*/
  char detaildescription[WORD_SIZE+1];
  BOOL iluminated;
};


Space* space_create(Id id) {
  Space *newSpace = NULL;
  int i = 0;
  if (id == NO_ID)
    return NULL;

  newSpace = (Space *)malloc(sizeof(Space));

  if (newSpace == NULL) {
    return NULL;
  }
  newSpace->id = id;

  newSpace->name[0] = '\0';
  newSpace->description[0] = '\0';
  newSpace->detaildescription[0] = '\0';

  newSpace->north_link = NO_ID;
  newSpace->south_link = NO_ID;
  newSpace->east_link = NO_ID;
  newSpace->west_link = NO_ID;
  newSpace->up_link = NO_ID;
  newSpace->down_link = NO_ID;
  newSpace->iluminated = FALSE;
  
  newSpace->objects = set_create();
 
  for( i = 0; i < ROWS; i++){
    newSpace->gdesc[i][0] = '\0';
  }

  return newSpace;
}

STATUS space_destroy(Space* space) {
  if (!space) {
    return ERROR;
  }
  set_destroy(space->objects);
  free(space);

  return OK;
}

STATUS space_set_name(Space* space, char* name) {

  /* This code makes sure a player exists and if it does it has a name */

  if (!space || !name) {
    return ERROR;
  }

  if (!strcpy(space->name, name)) {
    return ERROR;
  }

  return OK;
}

STATUS space_set_iluminated(Space* space, BOOL iluminated){
    if(!space){
        return ERROR;
    }
    
    space->iluminated = iluminated;
    
    return OK;
}


STATUS space_set_north_link(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  
  space->north_link = id;
  return OK;
}

STATUS space_set_up_link(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  
  space->up_link = id;
  return OK;
}

STATUS space_set_down_link(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  
  space->down_link = id;
  return OK;
}


STATUS space_set_south_link(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->south_link = id;
  return OK;
}



STATUS space_set_east_link(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->east_link = id;
  return OK;
}

STATUS space_set_west_link(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->west_link = id;
  return OK;
}

STATUS space_set_object(Space* space, Id id) {
  
  if (!space || id == NO_ID) {
    return ERROR;
  }
  
  if(set_add(space->objects,id) == ERROR) return ERROR;

  return OK;
}


const char * space_get_name(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->name;
}


Id space_get_id(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->id;
}

BOOL space_get_iluminated(Space *space){
    if (!space) {
    return FALSE;
  }
    return space->iluminated;
}


Id space_get_north_link(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->north_link;
}

Id space_get_up_link(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->up_link;
}

Id space_get_down_link(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->down_link;
}

Id space_get_south_link(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->south_link;
}

Id space_get_east_link(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->east_link;
}


Id space_get_west_link(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->west_link;
}

STATUS space_del_object(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  if(set_Id_inArray(space->objects, id)==TRUE){
    if(set_del(space->objects, id) == ERROR){
      return ERROR;
    }
    return OK;
  }
  
  return ERROR;  
}

STATUS space_print(Space* space) {
  Id idaux = NO_ID;
  if (!space) {
    return ERROR;
  }

  if(space->iluminado == FALSE){
      return ERROR;
  }
  
  
  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  idaux = space_get_north_link(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }

  idaux = space_get_south_link(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }

  idaux = space_get_east_link(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }

  idaux = space_get_west_link(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }
  
  idaux = space_get_up_link(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Up link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No up link.\n");
  }
  
  idaux = space_get_down_link(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Down link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No down link.\n");
  }
  
  return OK;
}


STATUS space_set_gdesc(Space* space, char *string, int i) {
  
  if ((!space) ||(!string)) {
    return ERROR;
  }
  
  strncpy(space->gdesc[i],string,COLUMNS-1);

  
  return OK;
}

char* space_get_gdesc1(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->gdesc[0];
}

char* space_get_gdesc2(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->gdesc[1];
}

char* space_get_gdesc3(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->gdesc[2];
}


/*  Returns True if the object is in the space, false if everything else  */
BOOL space_object_is_in(Space* space, Id id){
  if(!space || id == NO_ID){
    return FALSE;
  }
  if(set_Id_inArray(space->objects, id) == TRUE){
    return TRUE;
  }
  return FALSE;
}

STATUS space_set_description(Space* space, char* description){
  if(!space || !description) return ERROR;
  
  if(strcpy(space->description,description) == ERROR){
    return ERROR;
  }
  return OK;
}

char* space_get_description(Space* space){
  if(!space) return NULL;
  return space->description;
}

STATUS space_set_detail_description(Space* space, char* detaildescription){
  if(!space || detaildescription) return ERROR;
  
  if(strcpy(space->detaildescription,detaildescription) == ERROR){
    return ERROR;
  }
  return OK;
}

char* space_get_detail_description(Space* space){
  if(!space) return NULL;
  return space->detaildescription;
}


