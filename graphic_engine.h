/** 
 * @brief It defines a textual graphic engine
 * 
 * @file graphic_engine.h
 * @author Alexandra Conache && Sara Erika Catana
 * @version 3.0 
 * @date 4/03/2019
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"
#include "screen.h"
#include "game_reader.h"
#include "object.h"
#include "player.h"
#include "inventory.h"
/**
 * @brief The graphic engine structure
 * @author Alonso Aquino Ciro, Conache Alexandra, Catana Sara Erika
 */
/**
 * Definition of data structures
 */
typedef struct _Graphic_engine Graphic_engine;

/**
*      @brief Creates the graphic part of the game
*                              
*      It creates the graphic engine which is in charge of creating memroy for graphic       
*         part and initialize the screen parts and return the structure 
*
*      @author Alexandra Conache  
*      @param -
*      @return Graphic_engine* we created                      
*/
Graphic_engine* graphic_engine_create();
/**
*      @brief Destroys the graphics of the game
*                              
*      In charge of calling the functions neccessary to destroy the screen parts
*           and the total screen and then liberating the structure                   
*                                      
*      @param ge structure Graphic_engine from graphic_engine.c
*
*      @author Alexandra Conache          
*                   
*/
void graphic_engine_destroy(Graphic_engine *ge);
/**
*      @brief Paints the game in the screen
*                              
*      Initializes variables, checks for errors and then creates the part in the screen 
*           in which the game s going to be played                  
*                                      
*      @param ge structure Graphic_engine from graphic_engine.c
*      @param game structure Game from game.c
*      @author Alexandra Conache
*      @return void function, no return value                      
*/
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);


#endif
