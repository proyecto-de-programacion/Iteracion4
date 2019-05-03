/** 
 * @brief It implements the game_reader interface 
 * 
 * @file game_reader.c
 * @author Alexandra Conache
 * @version 3.0 
 * @date 8/03/2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/game_reader.h"
#include "../include/link.h"
#include "../include/space.h"
#include "../include/object.h"




/*!< Load the spaces required from the file */
STATUS game_reader_load_spaces(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char* toks = NULL;
  char firstrow[7];
  char secondrow[7];
  char thirdrow[7];
  char description[WORD_SIZE] = "";
  char descriptionDetallada[WORD_SIZE] = "";
  
  Space* space = NULL;
  STATUS status = OK;
  
  Id id = NO_ID,
    north_id_link = NO_ID,
    south_id_link = NO_ID,
    east_id_link = NO_ID,
    west_id_link = NO_ID;


  if (!filename) {
    return ERROR;
  }
  
  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }
  /**
 *      What this while does is set where the string read is going to get copied
 *      and it scans the whole file going line by line until it maximum value and 
 *      saves it in "line"
 */ 
  while (fgets(line, WORD_SIZE, file)) {
    /**
     *  The if makes sure the first 3 characters are "#s:" 
     */
    if (strncmp("#s:", line, 3) == 0) {
      /**
       *    Here we cut the string using the character "|"
       *    Here is also where the variables get assigned the right value read from the file
       */
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);

      toks = strtok(NULL, "|");
      north_id_link = atol(toks);

      toks = strtok(NULL, "|");
      east_id_link = atol(toks);

      toks = strtok(NULL, "|");
      south_id_link = atol(toks);

      toks = strtok(NULL, "|");
      west_id_link = atol(toks);

      toks = strtok(NULL, "|");
      strcpy(firstrow,toks);

      toks = strtok(NULL, "|");
      strcpy(secondrow,toks);

      toks = strtok(NULL, "|");
      strcpy(thirdrow,toks);

      toks = strtok(NULL,"|");
      strcpy(description,toks);

      toks = strtok(NULL,"|");
      strcpy(descriptionDetallada,toks);

	#ifdef DEBUG 
      	printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north_id_link, east_id_link, south_id_link, west_id_link, description);
	#endif
      space = space_create(id);
      if (space != NULL) {
        space_set_name(space, name);
        space_set_north_link(space, north_id_link);
        space_set_east_link(space, east_id_link);
        space_set_south_link(space, south_id_link);
        space_set_west_link(space, west_id_link);
        space_set_gdesc(space,firstrow,0);
        space_set_gdesc(space,secondrow,1);
        space_set_gdesc(space,thirdrow,2);
        space_set_description(space,description);
        space_set_descriptionDetallada(space, descriptionDetallada);
        game_add_space(game,space);
      }
    }
  }
  
  if (ferror(file)) {
    status = ERROR;
  }
  
  fclose(file);
  
  return status;
}

/*!< Load the objects required from the file */
STATUS game_reader_load_objects(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char descript[WORD_SIZE] = "";
  char* toks = NULL;
  Id object_id = NO_ID;
  Id space_id = NO_ID;
  Object* object = NULL;
  STATUS status = OK;
  int num_objects = 0;

  if (!filename) {
    return ERROR;
  }
  
  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }
  /**
 *      What this while does is set where the string read is going to get copied
 *      and it scans the whole file going line by line until it maximum value and 
 *      saves it in "line"
 */ 
  while (fgets(line, WORD_SIZE, file) && num_objects < MAX_OBJECTS) {
    /**
     *  The if makes sure the first 3 characters are "#o:" 
     */
    if (strncmp("#o:", line, 3) == 0) {
      /**
       *    Here we cut the string using the character "|"
       *    Here is also where the variables get assigned the right value read from the file
       */
      toks = strtok(line + 3, "|");
      object_id = atol(toks);
      toks = strtok(NULL,"|");
      space_id = atol(toks);
      toks = strtok(NULL,"|");
      strcpy(name, toks);
      toks = strtok(NULL,"|");
      strcpy(descript,toks);


	#ifdef DEBUG 
      	printf("Leido: %ld|%ld|%s|%s\n", object_id,space_id, name, descript);
	#endif
        object = object_create(object_id);
        if(object != NULL){
          
          object_set_name(object,name);
          object_set_description(object,descript);
          /* Posicionar el objeto donde diga el datat.dat */
          game_set_object_space(game,space_id,object_id);
          game_add_object(game, object);
          
        }
        num_objects++;
      }
    }
  
  if (ferror(file)) {
    status = ERROR;
  }
  
  fclose(file);
  
  return status;
}

/*!< Load the links required from the file */
STATUS game_reader_load_links(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = " ";
  char name[WORD_SIZE] = " ";
  char* toks = NULL;

  Id link_id = NO_ID;
  Id space_link1 = NO_ID;
  Id space_link2 = NO_ID;
  STATE state = DESCONOCIDO;
  Link *link = NULL;
  /*!< We trust the status is OK */
  STATUS status = OK;

  if (!filename) {
    return ERROR;
  }
  
  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }
  /**
 *      What this while does is set where the string read is going to get copied
 *      and it scans the whole file going line by line until it maximum value and 
 *      saves it in "line"
 */ 
  while (fgets(line, WORD_SIZE, file)) {
    /**
     *  The if makes sure the first 3 characters are "#l:" 
     */
    if (strncmp("#l:", line, 3) == 0) {
      /**
       *    Here we cut the string using the character "|"
       *    Here is also where the variables get assigned the right value read from the file
       */
      toks = strtok(line + 3, "|");
      link_id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);

      toks = strtok(NULL, "|");
      space_link1 = atol(toks);

      toks = strtok(NULL, "|");
      space_link2 = atol(toks);

      toks = strtok(NULL, "|");
      state = atoi(toks);

      #ifdef DEBUG
             printf("Leido: %ld|%s|ld|%ld|%d\n",link_id,name,space_link1,space_link2,state);
      #endif
      
       link = link_create(link_id);
        if(link != NULL){
          link_set_name(link,name);
          link_set_link1(link, space_link1);
          link_set_link2(link, space_link2);
          link_set_state(link, state);
          game_add_link(game,link);
        }
      
      }
    }
  if (ferror(file)) {
    status = ERROR;
  }
  
  fclose(file);
  
  return status;
}