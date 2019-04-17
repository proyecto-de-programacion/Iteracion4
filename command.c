/**
 *  @brief Implements command interpreter
 *
 *  @file command.c
 *  @date 7/04/2019
 *  @author Conache Alexandra
 */

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include "../include/command.h"

#define CMD_LENGHT 30 /*!< Maximum lenght of the command */
#define N_CMD 12 /*!< Maximum number of commands allowed*/
/**
 * @brief  Command structure
 */
struct _Command{
  Enum_command cmd; /*!< type of command*/
  char name[MAX_NAME+1]; /*!< name of command*/
};

/**
 * @brief Transformation of a long command to string
 */
char *cmd_to_str[N_CMD] = {"No command", "Unknown", "Exit", "Next", "Back", "Left","Right","Roll","Pickup", "Drop","Move","Inspect"};
/**
 * @brief Transformation of a short command to string
 */
char *short_cmd_to_str[N_CMD] = {"","","e","n","b","l","r","rll","p","d","m","i"};

/*!< Creates the structure Command */
Command *command_create(){
  Command *aux = NULL;

  aux = (Command *)malloc(sizeof(Command));
  if(!aux){
    return NULL;
  }

  aux->cmd = NO_CMD;
  strcpy(aux->name," ");

  return aux;
}

/*!< Destroys the structure Command */
void command_destroy(Command *pc){
  if(!pc){
    return;
  }
  free(pc);
}

/*!< Returns the name of the object selected */
char *command_get_name(Command *pc){
  if(!pc){
    return NULL;
  }
  return pc->name;
}

/*!< Sets the name of the structure to the name you want */
Command *command_set_name(Command *pc, const char *name){
  if(!pc || !name){
    return NULL;
  }
  if(!strcpy(pc->name, name)){
    return NULL;
  }
  return pc;
}

/*!< Returns the command we imputed */
Enum_command command_get_command(Command *pc){
  if(!pc){
    return NO_CMD;
  }
  return pc->cmd;
}

/*!< Sets the cmd of the structure to the cmd you want */
Command *command_set_command(Command *pc, Enum_command cmd){
  if( !pc ){
    return NULL;
  }
  pc->cmd = cmd;

  return pc;
}

/*!< Gets the command selected by the player */
STATUS command_get_user_input(Command *pc){
  char input[CMD_LENGHT] = "";
  char *toks = NULL;
  char cmd_name[CMD_LENGHT + 1] = "";
  char action[CMD_LENGHT] = "";

  if(pc == NULL) return ERROR;

  if(fgets(input,CMD_LENGHT,stdin) != NULL){
    if(strcmp(input,"\n") != 0){
    toks = strtok(input, " \n");
    if(toks != NULL){
      strcpy(action,toks);
      toks = strtok(NULL," \n");
      if(toks != NULL){
        strcpy(cmd_name,toks);
      }else{
        cmd_name[0]='\0';
        pc->name[0]='\0';
      }

      if(!strcasecmp(action,"e") || !strcasecmp(action,"exit")){
        pc->cmd = EXIT;
      }
      else if(!strcasecmp(action,"n") || !strcasecmp(action,"next")){
        pc->cmd = NEXT;
      }
      else if(!strcasecmp(action,"b") || !strcasecmp(action,"back")){
        pc->cmd = BACK;
      }
      else if(!strcasecmp(action,"r") || !strcasecmp(action,"right")){
        pc->cmd = RIGHT;
      }
      else if(!strcasecmp(action,"l") || !strcasecmp(action,"left")){
        pc->cmd = LEFT;
      }
      else if(!strcasecmp(action,"rll") || !strcasecmp(action,"roll")){
        pc->cmd = ROLL;
      }
      else if (!strcasecmp(action,"p") || !strcasecmp(action,"pickup")){
        pc->cmd = PICKUP;
        strcpy(pc->name,cmd_name);
      }
      else if (!strcasecmp(action,"d") || !strcasecmp(action,"drop")){
        pc->cmd = DROP;
        strcpy(pc->name,cmd_name);
      }
      else if (!strcasecmp(action,"m") || !strcasecmp(action,"move")){
        pc->cmd = MOVE;
        strcpy(pc->name,cmd_name);
      }
      else if (!strcasecmp(action,"i") || !strcasecmp(action,"inspect")){
        pc->cmd = INSPECT;
        strcpy(pc->name,cmd_name);
      }
      else{
        pc->cmd = UNKNOWN;
      }
      

    
    }else{
      pc->cmd = NO_CMD;
    }

    }else{
      return ERROR;
    }
  }
  return OK;
}
