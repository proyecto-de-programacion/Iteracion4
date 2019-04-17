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
#include "../include/game.h"

/**
 *   @brief Object structure
 *
 *   Stores relevant information about the object players use to play the game
 *
 */


struct _Object {
  Id id;                     /*!< The ID the object has assigned */
  char name[WORD_SIZE + 1];  /*!< The name we can assign to the object */
  char description[WORD_SIZE +1];  /*!< A brief description of the object */
  BOOL movable;              /*!< Indicates if the object can be moved */
  BOOL moved;                /*!< Indicates if the object has been moved */
  BOOL hidden;               /*!< Indicates if the object is hidden from the player */
  /*vvvvvvvvvvvvvvvvvv*/
  Id original_location;       /*!< The original location of the object */
  /*^^^^^^^^^^^^^^^^^^ We read it from the data.dat file */

  char moved_descript[WORD_SIZE+1]; /*!< Object's description after being moved*/
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

  /*New structure fields*/
  newObject->original_location = NO_ID;
  newObject->movable = FALSE;
  newObject->moved = FALSE;
  newObject->hidden = FALSE;
  newObject->moved_descript[WORD_SIZE+1] = '\0';


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

/************************************* New Functions I4 **********************************/

STATUS object_set_movable(Object* object, BOOL input){
  if(!object || !input) return ERROR;
  if(input == TRUE){
    object->movable = input;
    return OK;
  }else if(input == FALSE){
    object->movable = FALSE;
    return OK;
  }else{
    return ERROR;
  }
  return ERROR;
}

BOOL object_get_movable(Object* object){
  if(!object) return FALSE;

  return object->movable;
}

STATUS object_set_moved(Object* object, Id id){
  if(!object || id == NO_ID) return ERROR;

  /* If the object can't be moved, we ignore it*/
  if(object_get_movable(object) == FALSE){
    return OK;
  }else{
    if(object_get_original_location(object) != id){
      object->moved = TRUE;
      return OK;
    }else{
      object->moved = FALSE;
      return OK;
    }
  }
  return ERROR;
}

BOOL object_get_moved(Object* object){
  if(!object) return FALSE;

  return object->moved;
}

/* Use this function in the game reader load objects */
STATUS object_set_original_location(Object* object, Id id){
  if(!object || id == NO_ID) return ERROR;

  object->original_location = id;
  return OK;
}

Id object_get_original_location(Object* object){
  if(!object) return NO_ID;
  
  return object->original_location;
}

STATUS object_set_hidden(Object* object, BOOL input){
  if(!object || !input) return ERROR;

  if(input == TRUE){
    object->hidden = input;
    return OK;
  }else if(input == FALSE){
    /*default value*/
    object->hidden = FALSE;
    return OK;
  }else{
    return ERROR;
  }
  return ERROR;
}

BOOL object_get_hidden(Object* object){
  if(!object) return TRUE;

  return object->hidden;
}

STATUS object_set_moved_description(Object* object, char* description){
  if(!object || !description) return ERROR;

  if(object_get_movable(object) == TRUE){
    if(!strcpy(object->moved_descript,description)){
      return ERROR;
    }
    
  }else{
    return ERROR;
  }
  return OK;
}

char* object_get_moved_description(Object* object){
  if(!object) return NULL;
  
  return object->moved_descript;
}