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



STATUS game_management_save(Game *game, char *filename){
  FILE* file = NULL;
  char line[WORD_SIZE] = " ";
  char name[WORD_SIZE] = " ";
  char* toks = NULL;
  char descript[WORD_SIZE] = "";
  int i = 0;
  int j = 0;
  int m = 0;
  /* Link elements needed */  
  Id link_id = NO_ID;
  Id space_link1 = NO_ID;
  Id space_link2 = NO_ID;
  STATE state = DESCONOCIDO;
  /* Objects elements needed */
  Id object_id = NO_ID;
  Id object_space_id = NO_ID;
  int num_objects = 0;
  /* Space elements needed */
  char firstrow[7];
  char secondrow[7];
  char thirdrow[7];
  char descriptionDetailed[WORD_SIZE] = "";
  Id space_id = NO_ID,
    north_id_link = NO_ID,
    south_id_link = NO_ID,
    east_id_link = NO_ID,
    west_id_link = NO_ID;
  /* Player elements needed*/
  Id player_id = NO_ID;
  Id player_location = NO_ID;
  Id player_object = NO_ID;
  Set *set = NULL;

  /*!< We trust the status is OK */
  STATUS status = OK;

  if (!filename) {
    return ERROR;
  }
  
  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  /* Easy Easy lemon squeazy, space part bitxxess*/

  for(i=0; i < MAX_SPACES && game->spaces[i] != NULL ; i++ ){
    space_id = space_get_id(game->spaces[i]);
    name = space_get_name(game->spaces[i]);
    north_id_link = space_get_north_link(game->spaces[i]);
    south_id_link = space_get_south_link(game->spaces[i]);
    east_id_link = space_get_east_link(game->spaces[i]);
    west_id_link = space_get_west_link(game->spaces[i]);
    /* importante, revisar que este up & down */
    firstrow = space_get_gdesc1(game->spaces[i]);
    secondrow = space_get_gdesc2(game->spaces[i]);
    thirdrow = space_get_gdesc3(game->spaces[i]);
    descript = space_get_description(game->spaces[i]);
    descriptionDetailed = space_get_detail_description(game->spaces[i]);

    fprintf(file, "#s:%ld|%s|%ld|%ld|%ld|%ld|%s|%s|%s|%s|%s|\n",space_id, name, north_id_link, east_id_link, south_id_link, west_id_link, firstrow, secondrow, thirdrow, descript, descriptionDetailed );
    
  }

  /* Take it easy, relax, take a deep breath, Now is the part of the O-B-J-E-C-T*/

  for(i=0; i< MAX_OBJECTS && i< inventory_get_maxObjects(player_get_inventory(game->players)) && game->objects[i] != NULL; i++){
    object_id = object_get_id(game->objects[i]);
    /* m va a ser el contador, para diferenciar si el objeto esta en el espacio, no buscarlo dentro del jugador */
    m = 0;
    for(j=0; j < MAX_SPACES && game->spaces[j] != NULL ; j++){
      if(space_object_is_in(game->spaces[j], object_id) == TRUE){
        m = 1;
        object_space_id = space_get_id(game->spaces[j]);
      }
    }
    /* Si no esta en ningun espacio, significa que lo tiene el jugador, entonces ponemos su local a NO_ID*/
    if(m == 0){
      object_space_id = NO_ID;
    }
    name = object_get_name(game->objects[i]);
    descript = object_get_description(game->objects[i]);

    fprintf(file, "#s:%ld|%ld|%s|%s|\n", object_id, object_space_id, name, descript);
  }

  /* So close, we are almost there champ, this is... The Lord of the Links*/

  for(i=0; (i<MAX_LINK) && (game->links[i] != NULL);i++){
    link_id = link_get_id(game->links[i]);
    name = link_get_name(game->links[i]);
    space_link1 = link_get_link1(game->links[i]);
    space_link2 = link_get_link2(game->links[i]);
    state = link_get_state(game->links[i]);

    fprintf(file, "#l:%ld|%s|ld|%ld|%d|\n", link_id, name, space_link1, space_link2, state);
  }

  /* Le estamos dando con sabrosura, ya tu sae, Player part*/
  player_id = player_get_id(game->players);
  name = player_get_name(game->players);
  player_location = player_get_location(game->players);

  fprintf(file, "#p:%ld|%s|%ld|", player_id, name, player_location);

  set = inventory_get_set(player_get_inventory(game->players));
  for(i=0; i< MAX_OBJECTS && i< inventory_get_maxObjects(player_get_inventory(game->players)) && game->objects[i] != NULL; i++){
    player_object = NO_ID;

    player_object = set_get_id(set, i);
    if(player_object != NO_ID){
      fprintf(file, "%ld|", player_object);
    }
  }
  

}