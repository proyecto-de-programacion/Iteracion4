/**
 *  @brief An implementation to use 'player' data type
 *
 *  Here all functions related to 'player' data types are implemented as well as the structure Object
 *
 *  @file player.c
 *  @version 1.0
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/player.h"


/**
 *   @brief Player structure
 *
 *   Stores relevant information about the players playing the game
 *
 */

struct _Player {
  Id id;                        /*!< The ID the player has assigned */
  Id player_location;           /*!< The specific location the player is in */
  char name[WORD_SIZE + 1];     /*!< The name we can assign to the player */
  Inventory* inventory;         /*!< The player's inventory */
};



Player* player_create(Id id) {

  Player *newPlayer = NULL;
  if(id == NO_ID) return NULL;
  
  newPlayer = (Player *)malloc(sizeof(Player));

  if (newPlayer == NULL) {
    return NULL;
  }
  newPlayer->id = id;
  newPlayer->inventory = inventory_create(id);
  inventory_set_maxObjects(newPlayer->inventory, MAX_OBJECTS);

  newPlayer->name[0] = '\0';
  newPlayer->player_location = NO_ID;
  

  return newPlayer;
}




STATUS player_destroy(Player* player) {
  if (!player) {
    return ERROR;
  }
  inventory_destroy(player->inventory);
  free(player);

  return OK;
}


STATUS player_set_name(Player* player, char* name) {

  /* This code makes sure a player exists and if it does it has a name */

  if (!player || !name) {
    return ERROR;
  }

  if (!strcpy(player->name, name)) {
    return ERROR;
  }

  return OK;
}



STATUS player_set_inventory(Player* player, Id id) {
  
  if (!player || id == NO_ID) {
    return ERROR;
  }

  return set_add(inventory_get_set(player->inventory),id);
}


const char * player_get_name(Player* player) {
  if (!player) {
    return NULL;
  }
  return player->name;
}


Id player_get_id(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->id;
}


Inventory* player_get_inventory(Player* player){
  if(!player){
    return NULL;
  }
  
  return player->inventory;
}



STATUS player_print(Player* player) {

  if (!player) {
    return ERROR;
  }

  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);


  if (FALSE != player_get_inventory(player)) {
    fprintf(stdout, "---> Player holds object inventory %ld.\n",(long)player_get_inventory(player));
  } else {
    fprintf(stdout, "---> Player has no objects.\n");
  }
  if (NO_ID != player_get_location(player)) {
    fprintf(stdout, "---> Player's location is %ld.\n",(long)player->player_location);
  } else {
    fprintf(stdout, "---> No location.\n");
  }
  return OK;
}



STATUS player_set_location(Player *player, Id id) {

  if (id == NO_ID) {
    return ERROR;
  }

  player->player_location = id;

  return OK;

}



Id player_get_location(Player* player) {
  if (!player) return NO_ID;
  
  return player->player_location;
}


/* El jugador se desprende de uno de los objetos que tiene */ 
STATUS player_drop_object(Player* player, Id object_id){
  if(!player || object_id == NO_ID){
    return ERROR;
  }

  if(inventory_delete_object(player->inventory, object_id)==ERROR){
    return ERROR;
  }

  return OK;
}

STATUS player_has_object(Player* player, Id id){
  if(!player || id == NO_ID) return ERROR;

  if(inventory_ask_id(player->inventory, id) == TRUE){
    return OK;
  }
  return ERROR;
}
