/**
 * @brief It implements the game interface and all the associated callbacks
 * for each command
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "../include/game.h"
#include "../include/game_reader.h"


#define N_CALLBACK 14 /*!< Maximum number of callback functions*/
/**
 *   @brief Game structure
 *
 *   Stores relevant information about the different parts of the game
 *
 */
struct _Game{ 
  Player *players;    /*!<  Structure of the Player  */
  Object *objects[MAX_OBJECTS];    /*!< Structure of the Object */
  Die *dice;          /*!< Structure of the Die */
  Space* spaces[MAX_SPACES + 1];    /*!< Array of structures of Space */
  Command *cmd;    /*!< Last command */
  int last_roll; /*!<Die's last rolled value*/
  Link *links[MAX_LINK +1]; /*!<The links Game has*/
  char description[WORD_SIZE+1]; /*!<The game's description*/
};

/**
* Define the function type for the callbacks
*/
typedef void (*callback_fn)(Game* game);


/**
* List of callbacks for each command in the game
*/
void game_callback_unknown(Game* game);
void game_callback_exit(Game* game);
void game_callback_next(Game* game);
void game_callback_back(Game* game);
void game_callback_left(Game* game);
void game_callback_right(Game* game);
void game_callback_roll(Game* game);
void game_callback_pickup(Game* game);
void game_callback_drop(Game* game);
void game_callback_move(Game* game);
void game_callback_inspect(Game* game);
void game_callback_turnon(Game* game);
void game_callback_turnoff(Game* game);
void game_callback_open(Game* game);
/* */

static callback_fn game_callback_fn_list[N_CALLBACK]={
  game_callback_unknown,
  game_callback_exit,
  game_callback_next,
  game_callback_back,
  game_callback_left,
  game_callback_right,
  game_callback_roll,
  game_callback_pickup,
  game_callback_drop,
  game_callback_move,
  game_callback_inspect,
  game_callback_turnon,
  game_callback_turnoff,
  game_callback_open
  };


/*!<  Creates the game  */
STATUS game_create(Game** game) {
  int i = 0;

  *game = (Game*)malloc(sizeof(Game));

  for (i = 0; i < MAX_SPACES; i++) {
    (*game)->spaces[i] = NULL;
  }

  (*game)->players = player_create(1);
  game_set_player_location((*game),NO_ID);

  for(i=0; i<MAX_OBJECTS; i++){
    (*game)->objects[i]= NULL;
  }

  for(i=0; i<MAX_LINK; i++){
    (*game)->links[i]= NULL;
  }

  (*game)->dice = die_create(1);
  (*game)->cmd = command_create();
  (*game)->description[0] = '\0';

  return OK;
}

/* !< Creates the game from file  */

STATUS game_create_from_file(Game** game, char* filename) {
  
  if (game_create(game) == ERROR){
    return ERROR;
  }
  if (game_reader_load_spaces((*game), filename) == ERROR){
    return ERROR;
  } 
  if(game_reader_load_objects((*game), filename) == ERROR){
    return ERROR;
  }
  if(game_reader_load_links((*game), filename) == ERROR){
    return ERROR;
  }
  game_set_player_location((*game), game_get_space_id_at((*game), 0));
  
  return OK;
}



/* !< Destroys de memory peviously called  */

STATUS game_destroy(Game* game) {
  int i = 0;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
    space_destroy(game->spaces[i]);
    game->spaces[i] = NULL;
  }

  player_destroy(game->players);
  
  die_destroy(game->dice);

  for(i=0; (i<MAX_OBJECTS) && (game->objects[i] != NULL);i++){
    object_destroy(game->objects[i]);
  }

  for(i=0; (i<MAX_LINK) && (game->links[i] != NULL);i++){
    link_destroy(game->links[i]);
  }
  
  command_destroy(game->cmd);
  free(game);
  return OK;
}




/* !< Adds space to the game  */

STATUS game_add_space(Game* game, Space* space) {
  int i = 0;

  if (space == NULL) {
    return ERROR;
  }

  while ( (i < MAX_SPACES) && (game->spaces[i] != NULL)){
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}



/* !< Returns the id of the space  */


Id game_get_space_id_at(Game* game, int position) {

  if (position < 0 || position >= MAX_SPACES) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}



/* !< Updates the game  */
STATUS game_update(Game* game, Command *pc) {
  Enum_command last_cmd;
  last_cmd = command_get_command(pc);
  if (command_set_command(game->cmd, last_cmd) == NULL) return ERROR;
  if (command_set_name(game->cmd, command_get_name(pc)) == NULL) return ERROR;
  (*game_callback_fn_list[last_cmd])(game);
  
  return OK;
}



/* !< Returns the last command */

Enum_command game_get_last_command(Game* game){

  return command_get_command(game->cmd);
}
  
  



/* !<  Print out the game  */

void game_print_data(Game* game) {
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }
  printf("=> Player location: %d\n", (int) game_get_player_location(game));
  printf("prompt:> ");
}




/* !< The game is finished  */

BOOL game_is_over(Game* game) {
  return FALSE;
}
/**
*      @brief Rolls the die
*                              
*
*      @param game structure Game from file game.h 
*      @author Alexandra Conache                       
*/
void game_callback_roll(Game* game){


  
  die_roll(game->dice);
  game->last_roll = die_get_lastRoll(game->dice);

  
  return;
}


/**
*      @brief Pick up the object from the player location
*
*      @param game structure Game from file game.h 
*      @author Alexandra Conache & CiroAlonso                       
*/


void game_callback_pickup(Game *game){
  Id object_id = NO_ID; /* El id del objeto del nombre pasado*/ 
	int i = 0;
  char pName[MAX_NAME+1] = " ";

  strcpy(pName, command_get_name(game->cmd));

  if(!game || pName == NULL){
    return;
  }
  

  for(i=0; i< MAX_OBJECTS && i< inventory_get_maxObjects(player_get_inventory(game->players)) && game->objects[i] != NULL; i++){
	  /*  Si existe un objeto con ese nombre comprueba que este en el espacio del jugador  */
    if((strcasecmp(object_get_name(game->objects[i]), pName) == 0)) {
      object_id = object_get_id(game->objects[i]);

      /*  Si esta el objeto en el espacio del jugador lo elimina del espacio y se lo da al jugador */ 
      if(game_space_take_object(game, object_id)==OK){
        player_set_inventory(game->players, object_id);
      }else{
        return;
      }
      
      
  
    }

  }
  return;
}


/**
*     @brief Drop in the object from the player location
*                              
*
*      @param game structure Game from file game.h 
*      @author Alexandra Conache & Ciro Alonso                       
*/



void game_callback_drop(Game *game){
  Id object_id = NO_ID;
  int i;
  char *pName;

  pName = command_get_name(game->cmd);

  if(!game || pName == NULL){
    return;
  }

  for(i=0; i < MAX_OBJECTS && game->objects[i] != NULL; i++){
    if(strcasecmp (object_get_name(game->objects[i]), pName) == 0){
      object_id = object_get_id(game->objects[i]);
      if(player_drop_object(game->players,object_id) == ERROR) return;
      if(game_space_set_object(game, object_id) == ERROR) return;
      
    }
  }

}
/**
*      @brief It moves the player location one further box 
*                              
*      @date: 07/04/2019
*      @param game structure Game from file game.h 
*      @author Alexandra Conache                       
*/
void game_callback_move(Game* game){
  Id space_id = NO_ID;

  char* pName;

  pName = command_get_name(game->cmd);
  if(!game || pName == NULL) return;

  space_id = game_get_player_location(game);
  if(space_id == NO_ID) return;

  if(strlen(pName) == 1){
    if(strcasecmp(&pName[0],"n")==0){
     game_callback_back(game);
     return;
    }
    else if(strcasecmp(&pName[0],"s")==0){
      game_callback_next(game);
      return;
    }
    else if(strcasecmp(&pName[0],"e")==0){
      game_callback_right(game);
      return;
    }
    else if(strcasecmp(&pName[0],"w")==0){
      game_callback_left(game);
      return;
    }
  }
  else if(strlen(pName) > 1){
    if(strcasecmp(pName,"north")==0){
      game_callback_back(game);
      return;
    }
    else if(strcasecmp(pName,"south")==0){
      game_callback_next(game);
      return;
    }
    else if(strcasecmp(pName,"east")==0){
      game_callback_right(game);
      return;
    }
    else if(strcasecmp(pName,"west")==0){
      game_callback_left(game);
      return;
    }
  }
}

/**
 * @brief sets the callback to UNKNOWN
 * @param game structure Game
 * @author Prof PPROG
 * 
 */
void game_callback_unknown(Game* game) {
}
/**
 * @brief EXITS the game
 * @param game structure Game
 * @author Prof PPROG
 * 
 */
void game_callback_exit(Game* game) {
}


/**
*      @brief It moves the player location one further box 
*                              
*      It moves the player one box futher from his actual position
*
*      @param game structure Game from file game.h 
*      @author Alexandra Conache                       
*/


void game_callback_next(Game* game) {
  int i = 0, j=0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  Id link_id = NO_ID;
  Id south_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      link_id = space_get_south_link(game->spaces[i]);
      for(j = 0; j<MAX_LINK;j++){
        if(link_get_id(game->links[j]) == link_id){
          if(link_get_link1(game->links[j]) == current_id){
            south_id = link_get_link2(game->links[j]);
            break;
          }else{
            south_id = link_get_link1(game->links[j]);
            break;
          }
        }else{
          south_id = NO_ID;
        }
      }
      if(south_id != NO_ID){
        game_set_player_location(game, south_id);
      }else{
        return;
      }
    }
  }
  return;
}

/**
*      @brief It moves the player one box back
*
*      It moves the player one box back from his actual position
*                              
*      @param game structure Game from file game.h 
*      @author Alexandra Conache & CiroAlonso                       
*/


void game_callback_back(Game* game) {
  int i = 0, j=0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  Id link_id = NO_ID;
  Id north_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      link_id = space_get_north_link(game->spaces[i]);
      for(j = 0; j<MAX_LINK;j++){
        if(link_get_id(game->links[j]) == link_id){
          if(link_get_link1(game->links[j]) == current_id){
            north_id = link_get_link2(game->links[j]);
            break;
          }else{
            north_id = link_get_link1(game->links[j]);
            break;
          }
        }else{
          north_id = NO_ID;
        }
      }
      if(north_id != NO_ID){
        game_set_player_location(game, north_id);
      }else{
        return;
      }
    }
  }
  return;
}


/**
*      @brief It moves the player to the box linked on the left
*
*      It moves the player to the left box from his actual position
*
*      @param game structure Game from file game.h
*      @author Alexandra Conache & CiroAlonso
*/
void game_callback_left(Game* game) {

  int i = 0, j=0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  Id link_id = NO_ID;
  Id west_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      link_id = space_get_west_link(game->spaces[i]);
      for(j = 0; j<MAX_LINK;j++){
        if(link_get_id(game->links[j]) == link_id){
          if(link_get_link1(game->links[j]) == current_id){
            west_id = link_get_link2(game->links[j]);
            break;
          }else{
            west_id = link_get_link1(game->links[j]);
            break;
          }
        }else{
          west_id = NO_ID;
        }
      }
      if(west_id != NO_ID){
        game_set_player_location(game, west_id);
      }else{
        return;
      }
    }
  }
  return;
}

/**
*      @brief It moves the player to the box linked on the right
*
*      It moves the player to the right box from his actual position
*
*      @param game structure Game from file game.h
*      @author Alexandra Conache & CiroAlonso
*/
void game_callback_right(Game* game) {

  int i = 0, j=0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  Id link_id = NO_ID;
  Id east_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      link_id = space_get_east_link(game->spaces[i]);
      for(j = 0; j<MAX_LINK;j++){
        if(link_get_id(game->links[j]) == link_id){
          if(link_get_link1(game->links[j]) == current_id){
            east_id = link_get_link2(game->links[j]);
            break;
          }else{
            east_id = link_get_link1(game->links[j]);
            break;
          }
        }else{
          east_id = NO_ID;
        }
      }
      if(east_id != NO_ID){
        game_set_player_location(game, east_id);
      }else{
        return;
      }
    }
  }
  return;
}

/**
*      @brief It turns on an object
*
*      It turns on the object the player has in possesion
*
*      @param game structure Game from file game.h
*      @author Ciro Alonso
*/
void game_callback_turnon(Game* game){
  Id object_id = NO_ID; /* El id del objeto del nombre pasado*/ 
	int i = 0;
  char pName[MAX_NAME+1] = " ";

  if(!game){
    return;
  }

  strcpy(pName, command_get_name(game->cmd));

  if(pName == NULL){
    return;
  }
  

  for(i=0; i< MAX_OBJECTS && i< inventory_get_maxObjects(player_get_inventory(game->players)) && game->objects[i] != NULL; i++){
	  /*  comprueba de que el jugador tenga un objeto  */
    if((strcasecmp(object_get_name(game->objects[i]), pName) == 0)) {
      object_id = object_get_id(game->objects[i]);

      /*  Si el jugador tiene el objeto, lo encendemos */ 
      if(player_has_object(game->players, object_id) == OK){
        object_set_turnedon(game->objects[i], TRUE);
      }else{
        return;
      }
      
      
  
    }

  }
  return;

}

/**
*      @brief It turns off an object
*
*      It turns off the object the player has in possesion
*
*      @param game structure Game from file game.h
*      @author Ciro Alonso
*/
void game_callback_turnoff(Game* game){
  Id object_id = NO_ID; /* El id del objeto del nombre pasado*/ 
	int i = 0;
  char pName[MAX_NAME+1] = " ";

  if(!game){
    return;
  }

  strcpy(pName, command_get_name(game->cmd));

  if(pName == NULL){
    return;
  }
  

  for(i=0; i< MAX_OBJECTS && i< inventory_get_maxObjects(player_get_inventory(game->players)) && game->objects[i] != NULL; i++){
	  /*  comprueba de que el jugador tenga un objeto  */
    if((strcasecmp(object_get_name(game->objects[i]), pName) == 0)) {
      object_id = object_get_id(game->objects[i]);

      /*  Si el jugador tiene el objeto, lo apagamos */ 
      if(player_has_object(game->players, object_id) == OK){
        object_set_turnedon(game->objects[i], FALSE);
      }else{
        return;
      }
      
      
  
    }

  }
  return;

}

/**
*      @brief It opens a link
*
*      It opens the link if the player's object open id is the same as the link id
*
*      @param game structure Game from file game.h
*      @author Ciro Alonso
*/
void game_callback_open(Game* game){
  Link *pl = NULL;
  char *pName[MAX_NAME+1] = " ";
  char *l_name[MAX_NAME+1] = " ";
  Id open_link = NO_ID;
  int i = 0;

  if(!game){
    return;
  }

  strcpy(pName, command_get_name(game->cmd));

  if(pName == NULL){
    return;
  }

  for(i=0; i< MAX_OBJECTS && i< inventory_get_maxObjects(player_get_inventory(game->players)) && game->objects[i] != NULL; i++){
	  /*  comprueba de que el jugador tenga el objeto  */
    if((strcasecmp(object_get_name(game->objects[i]), pName) == 0)) {
      open_link = object_get_open_link(game->objects[i]);

      pl = game_get_link(game, open_link);

      /*  Si el nombre del Link del open coincide con el del Link que queremos abrir, cambiamos el estado */ 
      strcpy(l_name, command_get_link_name(game->cmd));
      if(!strcasecmp(l_name, link_get_name(pl)) ){
        link_set_state(pl, ABIERTO);
      }else{
        return;
      }
      
      
  
    }

  } 
  return;

}


/* !<  Get the space the game is reading  */

Space* game_get_space(Game* game, Id id){
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }
    
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i])){
      return game->spaces[i];
    }
  }
    
  return NULL;
}


/* !< Set the player location the game is reading  */
STATUS game_set_player_location(Game* game, Id id){
  if(!game || id == NO_ID){
    return ERROR;
  }
  player_set_location(game->players,id);

  return OK;
}

/* !<  Get the player location the game is reading  */
Id game_get_player_location(Game* game){
  return player_get_location(game->players);
}
/* !<  Get the object location the game is reading  */
Id game_get_object_location(Game* game, Object *object){
  int j = 0;
  Id obj_id = NO_ID;
  if(!game)return NO_ID;

  
  for(j=0; j<MAX_SPACES ; j++){
    obj_id = object_get_id(object);
    if((space_object_is_in(game->spaces[j], obj_id)) == TRUE){
      return space_get_id(game->spaces[j]);
      
    } 
  }
  return NO_ID;
}


/*    Set an object to the space of the player   */
STATUS game_space_set_object(Game *game, Id id){
  Id player_loc = NO_ID;
  int i;
  if(!game || id == NO_ID){
    return ERROR;
  }
  player_loc = game_get_player_location(game);

  for(i=0; i<MAX_SPACES && game->spaces[i] != NULL; i++){
    if(space_get_id(game->spaces[i])==player_loc){

      if(space_set_object(game->spaces[i], id)== ERROR){
        return ERROR;
      }
      
      return OK;
    }
  }

  return ERROR;

}


/*  Returns TRUE if deleted properly the object from the space the player is in  */
STATUS game_space_take_object(Game *game, Id id){
  Id player_loc = NO_ID;
  int i;
  if(!game || id == NO_ID){
    return ERROR;
  }
  player_loc = game_get_player_location(game);

  for(i=0; i<MAX_SPACES && game->spaces[i] != NULL; i++){
    if(space_get_id(game->spaces[i]) == player_loc){
      /* This function (space_del_object) returns OK if deleted properly the object */
      if(space_del_object(game->spaces[i], id)==OK){
        return OK;
      }
      else{
        return ERROR;
      }
      
      return ERROR;
    }
  }
  return ERROR;
}

/* !< Sets the object to the space you want */
STATUS game_set_object_space(Game *game, Id spaceID, Id objectId){
  int i;

  for(i=0; i<MAX_SPACES && game->spaces[i] != NULL; i++){
      if(space_get_id(game->spaces[i]) == spaceID){
      space_set_object(game->spaces[i], objectId);
      return OK;
    }
  }

  return ERROR;
}

/*  Gets the object to the space you want */
BOOL game_get_object_space(Game *game, Id spaceID, Id objectId){
  int i;
  if(objectId == NO_ID){
    return FALSE;
  }
  for(i=0; i<MAX_SPACES && game->spaces[i] != NULL; i++){
    if(space_get_id(game->spaces[i]) == spaceID){     
      if(space_object_is_in(game->spaces[i], objectId)){
        return TRUE;
      }
    }
  }

  return FALSE;
}
/* !< Adds objects to the game  */
STATUS game_add_object(Game* game, Object* object) {
  int i = 0;

  if (object == NULL) {
    return ERROR;
  }

  while ( (i < MAX_OBJECTS) && (game->objects[i] != NULL)){
    i++;
  }

  if (i >= MAX_OBJECTS) {
    return ERROR;
  }

  game->objects[i] = object;

  return OK;
}
/* !< Returns player from the game's structure  */
Player* game_get_player(Game *game){
  if(!game) return NULL;

  return game->players;
}
/* !< Returns die from the game's structure  */
Die* game_get_die(Game *game){
  if(!game)return NULL;
  return game->dice;
}
/* !< Returns object from the game's structure  */
Object* game_get_object(Game* game, Id id){
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }
    
  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++) {
    if (id != NO_ID && id == object_get_id(game->objects[i])){
      return game->objects[i];
    }
  }
    
  return NULL;
}
/* !< Adds link to the game  */
STATUS game_add_link(Game* game, Link* link) {
  int i = 0;

  if (game == NULL || link == NULL) {
    return ERROR;
  }

  while ( (i < (MAX_LINK)) && (game->links[i] != NULL)){
    i++;
  }

  if (i >= (MAX_LINK) ){
    return ERROR;
  }

  game->links[i] = link;

  return OK;
}
/* !< Returns the link's id from a specific position  */
Id game_get_link_id_at(Game* game, int position) {

  if (position < 0 || position >= MAX_SPACES) {
    return NO_ID;
  }

  return link_get_id(game->links[position]);
}
/* !< Returns link from the game's structure  */
Link* game_get_link(Game* game, Id id){
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }
    
  for (i = 0; i < MAX_SPACES && game->links[i] != NULL; i++) {
    if (id == link_get_id(game->links[i])){
      return game->links[i];
    }
  }
    
  return NULL;
}
/* !< Returns player's held object from the inventory  */
Object* game_get_player_object(Game* game, Player* player){
  Inventory* inventory = NULL;
  Id object_id = NO_ID;
  int i=0;

  if(!game||!player) return NULL;
  inventory = player_get_inventory(player);
  if( inventory != NULL){
    for(i=0;i<MAX_OBJECTS;i++){
    object_id = set_get_id(inventory_get_set(inventory),i);
    if(inventory_ask_id(inventory,object_id) == TRUE){
    return game_get_object(game, object_id);
      }
    }
  }
  return NULL;
}


/**
*      @brief It inspects a space or an object
*
*      @param game structure Game from file game.h
*      @author Alexandra Conache
*/
void game_callback_inspect(Game* game){
  int i= 0;
  Object* object = NULL;
  Id player_location = NO_ID;
  char* pName = "";

  if(!game)return;

  player_location = game_get_player_location(game);
  if(player_location == NO_ID)return;

  pName = command_get_name(game->cmd);
  if(pName == NULL)return;

  if(strlen(pName) == 1){
    if(strcasecmp(&pName[0],"s") ==0){
      for(i=0; i<MAX_SPACES && game->spaces[i]; i++){
        if(game->spaces[i]->iluminated == TRUE){//Solo se muestra descripcion si esta iluminado
           strcpy(game->description,space_get_detail_description(game->spaces[i]));
        } 
        return;
      }
      return;
    }else{
      for(i=0;i<MAX_OBJECTS;i++){
        if(game_get_object_location(game,game->objects[i]) == player_location || player_has_object(game->players,object_get_id(game->objects[i]))==OK){
          if(object_get_name(game->objects[i]) == pName){
            object = game->objects[i];
          }
        }
      }
      if (!object) return;

      strcpy(game->description,object_get_description(object));
      return;
    }
  }
  else if(strlen(pName) > 1){
    if(strcasecmp(pName,"space")==0){
      for(i=0; i<MAX_SPACES && game->spaces[i]; i++){
        if(player_location == space_get_id(game->spaces[i])){
            if(game->spaces[i]->iluminado == TRUE){//Solo se muestra descripcion si esta iluminado
                strcpy(game->description,space_get_description(game->spaces[i]));
            }          
          return;
        }
      }
      return;
    }else{
      for(i=0;i<MAX_OBJECTS;i++){
        if(game_get_object_location(game,game->objects[i]) == player_location || player_has_object(game->players,object_get_id(game->objects[i]))==OK){
          if(strcasecmp(object_get_name(game->objects[i]),pName)==0){
            object = game->objects[i];
          }
        }
      }
      if (!object) return;

      strcpy(game->description,object_get_description(object));
      return;
    }
  }  
}

/*!< Returns the description from the game's structure */
char* game_get_description(Game* game){
  if(!game) return ERROR;
  return game->description;
}
/*!< Returns the name of the player's object by id*/
char* game_get_player_object_name(Game* game, Id id){
  int i = 0;

  if(!game || id == NO_ID);

  for(i = 0;i<MAX_OBJECTS; i++){
    if(object_get_id(game->objects[i]) == id){
      if(player_has_object(game->players,id) == OK){
        return object_get_name(game->objects[i]);
      }
    }
  }
  return NULL;
}
