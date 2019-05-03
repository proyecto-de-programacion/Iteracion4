/** 
 * @brief It implements the game_management interface 
 * 
 * @file game_management.c
 * @author Alexandra Conache
 * @version 3.0 
 * @date 8/03/2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/game_management.h"
#include "../include/link.h"
#include "../include/space.h"
#include "../include/object.h"




/*!< Load the spaces required from the file */
STATUS game_management_load_spaces(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char* toks = NULL;
  char firstrow[7];
  char secondrow[7];
  char thirdrow[7];
  char description[WORD_SIZE] = "";
  char illum_description[WORD_SIZE] = "";
  
  Space* space = NULL;
  STATUS status = OK;
  
  Id id = NO_ID,
    north_id_link = NO_ID,
    south_id_link = NO_ID,
    east_id_link = NO_ID,
    west_id_link = NO_ID,
    up_id_link = NO_ID,
    down_id_link = NO_ID;


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
      up_id_link = atol(toks);

      toks = strtok(NULL, "|");
      down_id_link = atol(toks);

      toks = strtok(NULL, "|");
      strcpy(firstrow,toks);

      toks = strtok(NULL, "|");
      strcpy(secondrow,toks);

      toks = strtok(NULL, "|");
      strcpy(thirdrow,toks);

      toks = strtok(NULL,"|");
      strcpy(description,toks);

      toks = strtok(NULL,"|");
      strcpy(illum_description,toks);

      

	#ifdef DEBUG 
      	printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|%ld|%ld|%s\n", id, name, north_id_link, east_id_link, south_id_link, west_id_link, up_id_link,down_id_link, description,illum_description);
	#endif

        
        
      space = space_create(id);
      if (space != NULL) {
        space_set_name(space, name);
        space_set_north_link(space, north_id_link);
        space_set_east_link(space, east_id_link);
        space_set_south_link(space, south_id_link);
        space_set_west_link(space, west_id_link);
        space_set_up_link(space, up_id_link);
        space_set_down_link(space, down_id_link);
        space_set_gdesc(space,firstrow,0);
        space_set_gdesc(space,secondrow,1);
        space_set_gdesc(space,thirdrow,2);
        space_set_description(space,description);
        space_set_detail_description(space,illum_description);
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
STATUS game_management_load_objects(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char descript[WORD_SIZE] = "";
  char moved_descript[WORD_SIZE] = "";
  char* toks = NULL;
  Id object_id = NO_ID;
  Id space_id = NO_ID;
  Id og_space_id = NO_ID;
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
      og_space_id = atol(toks);

      toks = strtok(NULL,"|");
      strcpy(name, toks);

      toks = strtok(NULL,"|");
      strcpy(descript,toks);

      toks = strtok(NULL,"|");
      strcpy(moved_descript,toks);


	#ifdef DEBUG 
      	printf("Leido: %ld|%ld|%ld|%s|%s|%s\n", object_id,space_id, og_space_id, name, descript,moved_descript);
	#endif
        object = object_create(object_id);
        if(object != NULL){
          
          object_set_name(object,name);
          object_set_description(object,descript);
          /* Posicionar el objeto donde diga el datat.dat */
          game_set_object_space(game,space_id,object_id);
          object_set_original_location(object,og_space_id);
          object_set_moved_description(object,moved_descript);
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
STATUS game_management_load_links(Game* game, char* filename) {
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


/*!< Saves the state of the game to be able to resume it at another time >!*/
STATUS game_management_save (Game* game, char* filename){
  
  FILE* file = NULL;
  
  int i=0;
  int j=0;

  STATUS status = OK;

  if (!filename) {
    return ERROR;
  }
  
  file = fopen(filename, "w");
  if (file == NULL) {
    return ERROR;
  }
  
 

  //Se guardan el jugador
  fprintf(file, "#p: %l|%l|%s|%l|%d|%d|", game->players->id,game->players->player_location,game->players->name,
                                      game->players->inventory->id,game->players->inventory->maxObjects,
                                      game->players->inventory->set->numArrays);
    for(i=0; i<game->players->inventory->set->numArrays;i++){
        fprintf(file, "%d|", game->players->inventory->set->arId[i]);
    }
    fprintf(file, "\n");
  
    
  //Se guardan los objetos
  for(i=0; i<MAX_OBJECTS && game->objects[i] != NULL; i++){
    fprintf(file, "#o: %l|%s|%s|%d|%d|%d|%l|%s|%l|%d|%d|\n", game->objects[i]->id,game->objects[i]->name,game->objects[i]->description,
            game->objects[i]->movable,game->objects[i]->moved,game->objects[i]->hidden,game->objects[i]->original_location,
            game->objects[i]->moved_descript,game->objects[i]->open,game->objects[i]->illuminate,game->objects[i]->turnedon);

  }
   
    //Se guardan los links
  for(i=0; i<MAX_LINK && game->links[i] != NULL ; i++){
       fprintf(file, "#l: %l|%s|%l|%l|%d|\n", game->links[i]->link_id,game->links[i]->name,game->links[i]->link1,game->links[i]->link2,game->links[i]->state);
  }
    
 
 //Se guardan spaces 
  for(i=0; i<MAX_SPACES && game->spaces[i] != NULL ; i++){
       fprintf(file, "#s: %l|%s|%l|%l|%l|%l|%l|%l|%s|%s|%s|%d|%d|", game->spaces[i]->id,game->spaces[i]->name,
               game->spaces[i]->north_link,game->spaces[i]->south_link,game->spaces[i]->east_link,game->spaces[i]->west_link,
               game->spaces[i]->up_link,game->spaces[i]->down_link,game->spaces[i]->gdesc,game->spaces[i]->description,
               game->spaces[i]->detaildescription,game->spaces[i]->illuminated,game->spaces[i]->objects->numArrays);
       
       for(j=0;j<game->spaces[i]->objects->numArrays; j++){
           fprintf(file, "%d|", game->spaces[i]->objects->arId[i]);
       }
        fprintf(file, "\n");
       
  }
  
  
  fclose(file);
  
  return status;
    
}


/*!< Load the game from where it was left last time >!*/
STATUS gave_management_load (Game* game, char* filename){
    
  FILE* file = NULL;
  char line[WORD_SIZE] = " ";
  char name[WORD_SIZE] = " ";
  char* toks = NULL;
  
  Id id_player;
  Id id_inventory; 
  int maxObjects;
  Id player_location; 
  int numArrayPlayers;
  Player *player = NULL;
  
  
  char descript[WORD_SIZE] = "";
  char moved_descript[WORD_SIZE] = "";
  Id object_id = NO_ID;
  Id space_id = NO_ID;
  Id og_space_id = NO_ID;
  Id original_location = NO_ID;
  Id open = NO_ID;
  BOOL illuminate = FALSE;
  BOOL turnedon = FALSE;
  Object* object = NULL;
  BOOL movable = FALSE;
  BOOL moved = FALSE;
  BOOL hidden = FALSE;
  
  char gdesc[WORD_SIZE] = "";
  char detaildescription[WORD_SIZE] = "";
  char description[WORD_SIZE] = "";
  Space* space = NULL;  
  Id id = NO_ID,
    north_id_link = NO_ID,
    south_id_link = NO_ID,
    east_id_link = NO_ID,
    west_id_link = NO_ID,
    up_id_link = NO_ID,
    down_id_link = NO_ID;
  int numArraysSpaces = 0;
  Id  arId[4 + 1];

  Id link_id = NO_ID;
  Id space_link1 = NO_ID;
  Id space_link2 = NO_ID;
  STATE state = DESCONOCIDO;
  Link *link = NULL;
  
  STATUS status = OK;
  

  if (!filename) {
    return ERROR;
  }
  
  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }
 
  while (fgets(line, WORD_SIZE, file)) {
    
    if (strncmp("#o:", line, 3) == 0){
      toks = strtok(line + 3, "|");
      id = atol(toks);
      
      toks = strtok(NULL, "|");
      strcpy(name, toks);

      toks = strtok(NULL, "|");
      north_id_link = atol(toks);

      toks = strtok(NULL, "|");
      south_id_link = atol(toks);

      toks = strtok(NULL, "|");
      east_id_link = atol(toks);

      
      toks = strtok(NULL, "|");
      west_id_link = atol(toks);

      toks = strtok(NULL, "|");
      up_id_link = atol(toks);

      toks = strtok(NULL, "|");
      down_id_link = atol(toks);
      
      toks = strtok(NULL,"|");
      strcpy(gdesc,toks);

      toks = strtok(NULL,"|");
      strcpy(description,toks);

      toks = strtok(NULL,"|");
      strcpy(detaildescription,toks);
      
      toks = strtok(NULL,"|");
      illuminate = atoi(toks);    

      toks = strtok(NULL,"|");
      numArraysSpaces = atoi(toks);
      
      int m=0;
      for(m=0; m<numArraysSpaces; m++){
          toks = strtok(NULL,"|");
          arId[m]= atoi(toks);
      }
     
      space = space_create(id);
      if (space != NULL) {
        space_set_name(space, name);
        space_set_north_link(space, north_id_link);
        space_set_east_link(space, east_id_link);
        space_set_south_link(space, south_id_link);
        space_set_west_link(space, west_id_link);
        space_set_up_link(space, up_id_link);
        space_set_down_link(space, down_id_link);
        
        space_set_gdesc(space, gdesc);
        space_set_illuminated(space, illuminate);
        
        int l=0;
        for(l=0; l<numArraysSpaces; l++){
            space_set_object(space,arId[l]);
        }
        
        space_set_description(space,description);
        space_set_detail_description(space,detaildescription);
        game_add_space(game,space);
      }
    }
        
        
    
      
    }else if(strncmp("#o:", line, 3) == 0){
      
        
      toks = strtok(line + 3, "|");
      object_id = atol(toks);
   
      toks = strtok(NULL,"|");
      strcpy(name, toks);

      toks = strtok(NULL,"|");
      strcpy(descript,toks);
      
      toks = strtok(NULL,"|");
      movable = atoi(toks);

      toks = strtok(NULL,"|");
      moved = atoi(toks);
        
      toks = strtok(NULL,"|");
      hidden = atoi(toks);

      toks = strtok(NULL,"|");
      movable = atoi(toks);
            
      toks = strtok(NULL,"|");
      original_location = atol(toks);
      
      toks = strtok(NULL,"|");
      strcpy(moved_descript,toks);
      
      toks = strtok(NULL,"|");
      open = atol(toks);
      
      toks = strtok(NULL,"|");
      illuminate = atoi(toks);
      
      toks = strtok(NULL,"|");
      turnedon = atoi(toks);
      
	
        object = object_create(object_id);
        if(object != NULL){
          
          object_set_name(object,name);
          object_set_description(object,descript);
          /* Posicionar el objeto donde diga el datat.dat */
          //game_set_object_space(game,space_id,object_id);
          object_set_original_location(object,og_space_id);
          object_set_moved_description(object,moved_descript);
          object_set_hidden(object,hidden);
          object_set_illuminate(object,illuminate);
          object_set_movable(object,movable);
          object_set_moved(object,moved);
          object_set_open_link(object,open);
          object_set_turnedon(object,turnedon);
          game_add_object(game, object);
          
        }
      
        
        
    }else if(strncmp("#l:", line, 3) == 0){

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

        link = link_create(link_id);
        if(link != NULL){
          link_set_name(link,name);
          link_set_link1(link, space_link1);
          link_set_link2(link, space_link2);
          link_set_state(link, state);
          game_add_link(game,link);
        }
        
          
    }else{
    
       toks = strtok(line + 3, "|");
        id_player = atol(toks);
        
        toks = strtok(NULL, "|");
        player_location = atol(toks);
        
        toks = strtok(NULL, "|");
        strcpy(name, toks);
      
        toks = strtok(NULL, "|");
        id_inventory = atol(toks);
          
        toks = strtok(NULL, "|");
        maxObjects = atoi(toks);
        
        toks = strtok(NULL, "|");
        numArrayPlayers = atoi(toks);
        
        int i=0;
        for(i=0; i<numArrayPlayers; i++){
          toks = strtok(NULL,"|");
          arId[i]= atoi(toks);
        }
        
        player = player_create(id_player);
        if (player != NULL) {
            player_set_name(player, name);
            player_set_location(player,player_location);
            Inventory inv = inventory_create(id_inventory);
            inventory_set_maxObjects(inv, maxObjects);
            int l=0;
            for(l=0; l<numArrayPlayers; l++){
                inventory_add_object(inv,arId[l]);
        }
        
        player_set_inventory(player,inv);
        
        
        (*game)->players = player;
      }
        
        
        
        
         int l=0;
        for(l=0; l<numArraysSpaces; l++){
            space_set_object(space,arId[l]);
        }
        
    
    
    }
  if (ferror(file)) {
    status = ERROR;
  }
  
  fclose(file);
  
  return status;
    
    
}