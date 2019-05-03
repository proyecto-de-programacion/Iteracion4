/** 
* @brief It defines a textual game reader
* 
* @file game_management.h
* @author Alexandra Conache
* @version 3.0 
* @date 25/02/2019
*/


#ifndef GAME_MANAGEMENT_H
#define GAME_MANAGEMENT_H

#include "command.h"
#include "game.h"



/**
*      @brief Reads and loads the spaces 
*                              
*      In charge of reading the positions of the boxes and how the are interconnected                        
*      and load the spaces required from the file
*       
*
*      @param game structure Game from file game.h 
*      @param filename necessary to load spaces 
*
*      @date  8/03/2019 
*      @author Alexandra Conache    
*      @return OK or ERROR if the function worked or not                 
*/ 
STATUS game_management_load_spaces(Game* game, char* filename);

/**
*      @brief Reads and loads the objects 
*                              
*      In charge of reading the positions of the boxes and how the are interconnected                        
*      and load the objects required from the file
*       
*
*      @param game structure Game from file game.h 
*      @param filename necessary to load objects 

*      @date  8/03/2019 
*      @author Alexandra Conache  
*      @return OK or ERROR if the function worked or not                   
*/
STATUS game_management_load_objects(Game* game, char* filename);


/**
*      @brief Reads and loads the links 
*                              
*      In charge of reading the positions of the boxes and how the are interconnected                        
*      and load the links required from the file
*       
*
*      @param game structure Game from file game.h 
*      @param filename necessary to load links 
*      @date  01/04/2019 
*      @author Alexandra Conache & Sara Erika Catana 
*      @return OK or ERROR if the function worked or not                  
*/
STATUS game_management_load_links(Game* game, char* filename);

/**
*      @brief Save the current state of the game
*                              
*      Is responsible for saving the game as it was left last time
*
*      @param game structure Game from file game.h 
*      @param filename necessary to save the game 
*      @date  03/05/2019 
*      @author Sara Erika Catana 
*      @return OK or ERROR if the function worked or not                  
*/
STATUS game_management_save (Game* game, char* filename);

/**
*      @brief Update the game
*                              
*      is responsible for loading the space as it was left last time
*
*      @param game structure Game from file game.h 
*      @param filename necessary to load the game 
*      @date  03/05/2019 
*      @author Sara Erika Catana 
*      @return OK or ERROR if the function worked or not                  
*/
STATUS gave_management_load (Game* game, char* filename);
#endif