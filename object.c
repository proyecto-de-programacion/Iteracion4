/**
 *  @brief An implementation to use 'object' data type
 *
 *  Here all functions related to 'object' data types are implemented as well as the structure Object
 *
 *  @file object.c
 *  @version 1.0
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/object.h"


/**
 *   @brief Object structure
 *
 *   Stores relevant information about the object players use to play the game
 *
 */


struct _Object {
  Id id;                     /*!< The ID the object has assigned */
  char name[WORD_SIZE + 1];  /*!< The name we can assign to the object */
  char description[WORD_SIZE +1];  /*!< brief description of the object*/
  Id open;  /*!< the id of the link it can open */
  BOOL illuminate;  /*!< if the object can illuminate a space */
  BOOL turnedon;  /*!< if the object can illuminate a space, then if the object is turned on */
 };



Object* object_create(Id id) {

  Object *newObject = NULL;

  newObject = (Object *) malloc(sizeof (Object)+1);

  if (newObject == NULL) {
    return NULL;
  }
  newObject->id = id;

  newObject->name[WORD_SIZE+1] = '\0';
  newObject->description[WORD_SIZE+1] = '\0';
  newObject->open = NO_ID;
  newObject->illuminate = FALSE;
  newObject->turnedon = FALSE;

  return newObject;
  }



STATUS object_destroy(Object* object) {
    if (!object) {
      return ERROR;
    }

    free(object);

  return OK;
}



STATUS object_set_name(Object* object, char* name) {

  /* This code makes sure an object exists and if it does it has a name */

  if (!object || !name) {
    return ERROR;
  }

  if (!strcpy(object->name, name)) {
    return ERROR;
  }

  return OK;
}



char * object_get_name(Object* object) {
  if (!object) {
    return NULL;
  }
  return object->name;
}




Id object_get_id(Object* object) {
  if (!object) {
    return NO_ID;
  }
  return object->id;
}




STATUS object_print(Object* object) {

  if (!object) {
    return ERROR;
  }

  fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);

  return OK;
}

STATUS object_set_description(Object* object, char* description){
  if(object == NULL || description == NULL) return ERROR;
  if(strcpy(object->description,description) == ERROR) return ERROR;
  return OK;
}

char* object_get_description(Object* object){
  if(!object) return NULL;
  return object->description;
}

/* gets the id of the open attribute  -ciro*/
Id object_get_open_link(Object *obj){
  if(!obj || obj->open == NO_ID){
    return NO_ID;
  }

  return obj->open;
}

/*  turns on the object if possible -ciro*/
STATUS object_set_open_link(Object *obj, Id id){
  if(!obj || id <= -1){
    return ERROR;
  }

  obj->open = id;
  return OK;
}

/*  gets the state of the illuminate attribute -ciro*/
BOOL object_get_illuminate(Object *obj){
  if(!obj){
    return FALSE;
  }

  return obj->illuminate;
}

/*  sets the illuminate of the object -ciro*/
STATUS object_set_illuminate(Object *obj, BOOL state){
  if(!obj){
    return ERROR;
  }

  obj->illuminate = state;
  return OK;
}

/*  gets the state of the turnedon attribute -ciro*/
BOOL object_get_turnedon(Object *obj){
  if(!obj){
    return FALSE;
  }

  return obj->turnedon;
}

/*  turns on or off the object if possible -ciro*/
STATUS object_set_turnedon(Object *obj,  BOOL state){
  if(!obj || obj->illuminate == FALSE ){
    return ERROR;
  }

  obj->turnedon = state;
  return OK;
}