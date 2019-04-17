/** 
 * @brief It implements the graphic_engine functions
 * 
 * @file graphic_engine.c
 * @author Alexandra Conache && Sara Erika Catana && Ciro Alonso Aquino
 * @version 3.0 
 * @date 4/03/2019
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "../include/graphic_engine.h"
/*usar strcat y strlen para lo de los espacios en blanco*/
/**
 * @brief Graphic engine structure
 */
struct _Graphic_engine{
  Area  *map, /*!< the map area*/
        *descript, /*!<the description area*/
        *banner, /*!<the banner area*/
        *help, /*!<the help area*/
        *feedback;   /*!< Different type of pointers of structures of Area */
};





Graphic_engine *graphic_engine_create(){
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;

  screen_init();
  ge = (Graphic_engine *) malloc(sizeof(Graphic_engine));

  ge->map      = screen_area_init( 1, 1, 58, 28);
  ge->descript = screen_area_init(60, 1, 39, 28);
  ge->banner   = screen_area_init(38,30, 24,  1);
  ge->help     = screen_area_init( 1,31, 98,  3);
  ge->feedback = screen_area_init( 1,35, 98,  4);

  return ge;
}





void graphic_engine_destroy(Graphic_engine *ge){
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}





void graphic_engine_paint_game(Graphic_engine *ge, Game *game){
  Id id_act = NO_ID, 
  id_back = NO_ID, 
  id_next = NO_ID, 
  id_left = NO_ID,
  id_right = NO_ID,
  object_id = NO_ID;
  Space* space_act = NULL;
  Space* space_next = NULL;
  Space* space_back = NULL;
  int i = 0;
  char obj_name[WORD_SIZE] = " ";
  char obj_aux[WORD_SIZE] = " ";
  char str[255] = " ";
  char str_back[30] = " ";
  char str_act[30] = " ";
  char str_next[30] = " ";
  char str_aux[30] = " ";
  Enum_command last_cmd = UNKNOWN;
  extern char *cmd_to_str[];
  char gdesc1[COLUMNS] = " ";
  char gdesc2[COLUMNS] = " ";
  char gdesc3[COLUMNS] = " ";
  int last_roll = 0;
  Link *north_link = NULL,
    *south_link = NULL,
    *east_link = NULL,
    *west_link = NULL;

  Id link_id = NO_ID,
    id_space_north_link1 = NO_ID,
    id_space_south_link2 = NO_ID,
    id_space_east_link2 = NO_ID,
    id_space_west_link2 = NO_ID;

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = player_get_location(game_get_player(game))) != NO_ID){
    space_act = game_get_space(game, id_act);

    id_back = space_get_north_link(space_act);
    id_next = space_get_south_link(space_act);
    id_left = space_get_west_link(space_act);
    id_right = space_get_east_link(space_act);

    north_link = game_get_link(game,id_back);
    south_link = game_get_link(game,id_next);
    east_link = game_get_link(game,id_right);
    west_link = game_get_link(game,id_left);


    /* Miramos como se haria con el nuevo object without location*/
    for(i=0; i <MAX_OBJECTS; i++){
      object_id = object_get_id(game_get_object(game,i));
      if(game_get_object_space(game, id_back , object_id)==TRUE){
        strcpy(obj_name, object_get_name(game_get_object(game,i)));
        break;
      }
      else{
        strcpy(obj_name, " ");
      }
    }


    if (id_back != NO_ID) {
      
      link_id = link_get_id(north_link);
      id_space_north_link1 = link_get_link1(north_link);

      space_back = game_get_space(game,id_space_north_link1);

      sprintf(str_back, " ");
      for(i = 1; i<= MAX_OBJECTS; i++){
        if(space_object_is_in(space_back,i)){
          sprintf(str_aux, "%s", object_get_name(game_get_object(game,i)));
          strcat(str_back,str_aux);
        }
        else{
          sprintf(str_aux,"  ");
          strcat(str_back, str_aux);
        }
      }
      strncpy(gdesc1, space_get_gdesc1(space_back), COLUMNS - 1);
      strncpy(gdesc2, space_get_gdesc2(space_back), COLUMNS - 1);
      strncpy(gdesc3, space_get_gdesc3(space_back), COLUMNS - 1);
      
      sprintf(str, "      |           %2d|",(int) id_space_north_link1);
      screen_area_puts(ge->map, str);
      sprintf(str, "      |      %s|",gdesc1);
      screen_area_puts(ge->map, str);
      sprintf(str, "      |      %s|",gdesc2);
      screen_area_puts(ge->map, str);
      sprintf(str, "      |      %s|",gdesc3);
      screen_area_puts(ge->map, str);
      if(strcmp(obj_name," ") != 0){
        sprintf(str, "      |%s    |",str_back);
      }else{
        sprintf(str, "      |             |");
      }
      screen_area_puts(ge->map, str);
      sprintf(str, "      +-------------+");
      screen_area_puts(ge->map, str);
      if(link_id !=NO_ID){
        sprintf(str, "            ^%2d",(int)link_id);
      }else{
        sprintf(str, "            ^");
      }
      screen_area_puts(ge->map, str);
    }

    
    for(i=0; i <MAX_OBJECTS; i++){
      object_id = NO_ID;

      object_id = object_get_id(game_get_object(game,i));
      if(game_get_object_space(game, id_act , object_id)==TRUE){
        strcpy(obj_name, object_get_name(game_get_object(game,i)));
        break;
      }
      else{
        strcpy(obj_name," ");
      }
    }
    
    if (id_act != NO_ID) {
      space_act = game_get_space(game,id_act);
      id_space_west_link2 = link_get_link2(west_link);
      id_space_east_link2 = link_get_link2(east_link);

      sprintf(str_act, " ");
      for(i = 1; i<= MAX_OBJECTS; i++){
        if(space_object_is_in(space_act,i)){
          sprintf(str_aux, "%s", object_get_name(game_get_object(game,i)));
          strcat(str_act,str_aux);
        }
        else{
          sprintf(str_aux,"  ");
          strcat(str_act, str_aux);
        }
      }

      strncpy(gdesc1, space_get_gdesc1(space_act), COLUMNS - 1);
      strncpy(gdesc2, space_get_gdesc2(space_act), COLUMNS - 1);
      strncpy(gdesc3, space_get_gdesc3(space_act), COLUMNS - 1);
      if(id_left != NO_ID && id_right != NO_ID){
        sprintf(str, "   %2d +-------------+ %2d",(int)id_left,(int)id_right);
      }else{
        sprintf(str, "      +-------------+");
      }
      screen_area_puts(ge->map, str);
      if (id_act != NO_ID && id_left != NO_ID && id_right !=NO_ID){
        sprintf(str, "  %2d<-| uwu      %2d |->%2d",(int)id_space_west_link2,(int) id_act,(int)id_space_east_link2);
      }
      else if(id_act !=NO_ID && id_left == NO_ID && id_right != NO_ID){
        sprintf(str, "      | uwu      %2d |->%2d",(int) id_act,(int)id_space_east_link2);
      }
      else if(id_act !=NO_ID && id_left != NO_ID && id_right == NO_ID){
        sprintf(str, "     %2d<-| uwu     %2d |",(int)id_space_west_link2,(int) id_act);
      }
      else {
        sprintf(str, "      | uwu      %2d |",(int) id_act);
      }
      screen_area_puts(ge->map, str);
      sprintf(str, "      |      %s|",gdesc1);
      screen_area_puts(ge->map, str);
      sprintf(str, "      |      %s|",gdesc2);
      screen_area_puts(ge->map, str);
      sprintf(str, "      |      %s|",gdesc3);
      screen_area_puts(ge->map, str);
      sprintf(str, "      |%s    |",str_act);
      screen_area_puts(ge->map, str);
      sprintf(str, "      +-------------+");
      screen_area_puts(ge->map, str);
    }

    

    for(i=0; i <MAX_OBJECTS; i++){
      object_id = NO_ID;

      object_id = object_get_id(game_get_object(game,i));
      if(game_get_object_space(game, id_next , object_id)==TRUE){
        strcpy(obj_name, object_get_name(game_get_object(game,i)));
        break;
      }
      else{
        strcpy(obj_name, " ");
      }
    }
    
    if (id_next != NO_ID) {

      link_id = link_get_id(south_link);
      id_space_south_link2 = link_get_link2(south_link);
      
      space_next = game_get_space(game,id_space_south_link2);

      sprintf(str_next, " ");
      for(i = 1; i<= MAX_OBJECTS; i++){
        if(space_object_is_in(space_next,i)){
          sprintf(str_aux, "%s", object_get_name(game_get_object(game,i)));
          strcat(str_next,str_aux);
        }
        else{
          sprintf(str_aux,"  ");
          strcat(str_next, str_aux);
        }
      }
      strncpy(gdesc1, space_get_gdesc1(space_next), COLUMNS - 1);
      strncpy(gdesc2, space_get_gdesc2(space_next), COLUMNS - 1);
      strncpy(gdesc3, space_get_gdesc3(space_next), COLUMNS - 1);
      if(link_id != NO_ID){
        sprintf(str, "            v%2d",(int)link_id);
      }else{
        sprintf(str, "            v");
      }
      screen_area_puts(ge->map, str);
      sprintf(str, "      +-------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "      |           %2d|",(int) id_space_south_link2);
      screen_area_puts(ge->map, str);
      sprintf(str, "      |      %s|",gdesc1);
      screen_area_puts(ge->map, str);
      sprintf(str, "      |      %s|",gdesc2);
      screen_area_puts(ge->map, str);
      sprintf(str, "      |      %s|",gdesc3);
      screen_area_puts(ge->map, str);
      if(strcmp(obj_name," ") != 0){
        sprintf(str, "      |%s    |",str_next);
      }else{
        sprintf(str, "      |             |");
      }
      screen_area_puts(ge->map, str);
}
  }

  /* Paint the in the description area */

  /*  Prints in the description all the objects of the game  */ 
  screen_area_clear(ge->descript);
  sprintf(str,"Object Location:");
  screen_area_puts(ge->descript, str);
  for(i=1; i<= MAX_OBJECTS && game_get_object(game,object_id)!= NULL ;i++){
    sprintf(str, "Object %ld: %ld" ,object_get_id(game_get_object(game,i)),game_get_object_location(game,game_get_object(game,i)));
    screen_area_puts(ge->descript, str);
  }

  /*  Prints the objects the player has in his possesion  */

  
  sprintf(str," ");
  screen_area_puts(ge->descript, str);
  sprintf(str,"Player's inventory: ");
  screen_area_puts(ge->descript, str);

  for(i = 1; i<= MAX_OBJECTS; i++){
    if(player_has_object(game_get_player(game),i)==OK){
      sprintf(obj_name, "[%s] ", game_get_player_object_name(game, i));
      strcat(obj_aux,obj_name);
      
      
    }
    else{
      sprintf(obj_name,"  ");
      strcat(obj_aux, obj_name);
    }
  }
  screen_area_puts(ge->descript, obj_aux);

  
    
  
  

  


  sprintf(str," ");
  screen_area_puts(ge->descript, str);
  sprintf(str,"Description: %s",game_get_description(game));
  screen_area_puts(ge->descript,str);
  strcpy(game_get_description(game)," ");
  
  
  /* Paints the last roll of the dice */
  sprintf(str," ");
  screen_area_puts(ge->descript, str);
  last_roll = die_get_lastRoll(game_get_die(game));
  sprintf(str, "Last roll : %d", last_roll);
  screen_area_puts(ge->descript, str);

  /* Paint the in the banner area */
  screen_area_puts(ge->banner, " The game of the Goose ");

  /* Paint the in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, " next or n, back or b, left or l, right or r, roll or rll, pickup or p, drop or d, exit or e, move or m , inspect or i");
  screen_area_puts(ge->help, str);

  /* Paint the in the feedback area */
  last_cmd = game_get_last_command(game);
  sprintf(str, " %s", cmd_to_str[last_cmd-NO_CMD]);
  screen_area_puts(ge->feedback, str);
  

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}

