/** 
* @brief It defines a textual game reader
* 
* @file game_reader.h
* @author Alexandra Conache
* @version 3.0 
* @date 25/02/2019
*/


#ifndef GAME_READER_H
#define GAME_READER_H

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
STATUS game_reader_load_spaces(Game* game, char* filename);

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
STATUS game_reader_load_objects(Game* game, char* filename);


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
STATUS game_reader_load_links(Game* game, char* filename);

/**
*      @brief Saves the play 
*                              
*      In a new file, writes the info ,as a data.dat, of the spaces, the objects
*             the links and the player
*
*      @param game structure Game from file game.h 
*      @param filename necessary to load links 
*      @date  07/05/2019 
*      @author Ciro Alonso
*      @return OK or ERROR if the function worked or not                  
*/
STATUS game_management_save(Game *game, char *filename);
#endif