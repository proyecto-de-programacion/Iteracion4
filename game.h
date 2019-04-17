/** 
 * @brief It defines the game interface
 * for each command
 * 
 * @file game.h
 * @author Alexandra Conache y CiroAlonso
 * @version 2.0 
 * @date 17/02/2019
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "player.h"
#include "types.h"
#include "die.h"
#include "object.h"
#include "link.h"
/**
 * @brief The game structure
 * @author Alonso Aquino Ciro, Conache Alexandra, Catana Sara Erika
 */
/**
 * Definition of data structures
 */
typedef struct _Game Game;

/**
*      @brief Adds space to the game
*                                   
*      @param game structure Game from file game.c
*      @param space struct Space from file space.c  
*      @author Alexandra Conache & CiroAlonso 
*      @return OK or ERROR if the function worked or not                      
*/
STATUS game_add_space(Game* game, Space* space);

/**
*      @brief Adds links to the game
*                                   
*      @param game structure Game from file game.c
*      @param link struct Link from file space.c  
*      @author Alexandra Conache & CiroAlonso
*      @return OK or ERROR if the function worked or not                        
*/
STATUS game_add_link(Game* game, Link* link);

/**
*      @brief Creates the game
*                              
*      It creates the game, load the spaces to NULL, creates the player
*           and the array of objects and initializes and initializes their Id 
*                     to the local variable i last_cmd to no command                     
*                                      
*      @param game structure Game from file game.c
*
*      @author Alexandra Conache & CiroAlonso  
*      @return OK or ERROR if the function worked or not                      
*/
STATUS game_create(Game** game);

/**
*      @brief Creates the game from file
*                              
*      It creates the game, load the spaces and set the                                 
*             locations of the player and the object                         
*                                      
*      @param game structure Game from file game.c
*      @param filename necessary to load spaces  
*      @author Alexandra Conache & CiroAlonso   
*      @return OK or ERROR if the function worked or not                     
*/
STATUS game_create_from_file(Game** game, char* filename);

/**
*      @brief Updates the game 
*                              
*      Updates the game using the callback functions                        
*                                      
*      @param game structure Game from file game.c
*      @param cmd Enum_command to choose which callback function you want  
*      @author Alexandra Conache & CiroAlonso 
*      @return OK or ERROR if the function worked or not                       
*/
STATUS game_update(Game* game, Command *cmd);

/**
*     @brief Destroys de memory peviously called   

*     Destroys the memroy created for each space, the player                                
*                         and the object             
*     param: game structure Game from file game.c                                
*     @author Alexandra Conache & CiroAlonso 
*      @return OK or ERROR if the function worked or not                                 
*/
STATUS game_destroy(Game* game);

/**
*      @brief The game is finished 
*                              
*      @param game structure Game from file game.c 
*      @author Alexandra Conache & CiroAlonso  
*      @return TRUE or FALSE if the game is over or not                      
*/
BOOL   game_is_over(Game* game);

/**
*      @brief Print out the game
*                              
*      Print out the player location as well as the object location                         
*                                      
*      @param game structure Game from file game.c  
*      @author Alexandra Conache & CiroAlonso  
*      @return it's a void function, it has no return value                     
*/
void game_print_data(Game* game);

/**
*      @brief Get the space he is reading 
*                                    
*      @param game structure Game from file game.c 
*      @param id structure Id of the space 
*      @date  17/02/2019 
*      @author Alexandra Conache & CiroAlonso 
*      @return space* that has the id of the second argument                      
*/
Space* game_get_space(Game* game, Id id);

/**
*      @brief Returns the last command
*                                                              
*      @param game structure Game from file game.c  
*      @author Alexandra Conache & CiroAlonso  
*      @return Enum_command the last command imputed                      
*/
Enum_command game_get_last_command(Game* game);

/**
*      @brief Returns the id of the space
*                              
*      Checks for errors, if not returns the id of the space of the game
*                 thanks to the finction space_get_id
*      @param game structure Game from file game.c
*      @param  position int the position of the space
*      @author Alexandra Conache & CiroAlonso   
*      @return Id of the space that's in the position we passed as second argument                 
*/
Id game_get_space_id_at(Game* game, int position);
/**
*      @brief Set the player location he is reading 
*                                    
*      @param game structure Game from file game.c 
*      @param  id structure Id for the player
*      @date  17/02/2019 
*      @author Alexandra Conache & CiroAlonso
*      @return OK or ERROR if the function worked or not                        
*/
STATUS game_set_player_location(Game* game, Id id);
/**
*      @brief Get the player location he is reading 
*                                    
*      @param game structure Game from file game.c 
*      
*      @date  17/02/2019 
*      @author Alexandra Conache & CiroAlonso 
*      @return Id of the space the player is located                      
*/
Id game_get_player_location(Game* game);
/**
*      @brief Get the object location he is reading 
*                                    
*      @param game structure Game from file game.c 
*      @param object structure Object from file object.c
*      @date  17/02/2019 
*      @author Alexandra Conache & CiroAlonso 
*      @return Id of the space the object is located                      
*/
Id game_get_object_location(Game* game,Object* object);

/**
*      @brief Set the object he is reading 
*                                    
*      @param game structure Game from file game.c 
*      @param id structure Id of the space
*      @date  17/02/2019 
*      @author Alexandra Conache & CiroAlonso 
*      @return OK or ERROR if the function worked or not                       
*/
STATUS game_space_set_object(Game *game, Id id);

/**
*      @brief Get the object he is reading 
*                                    
*      @param game structure Game from file game.c 
*      @param id strcture Id of the object
*      @date  17/02/2019 
*      @author Alexandra Conache & CiroAlonso
*      @return OK or ERROR if the function worked or not                        
*/
STATUS game_space_take_object(Game *game, Id id);

/**
*      @brief Sets an object in a specific space
*                                    
*      @param game structure Game from file game.c 
*      @param spaceID structure Id of the space
*      @param objectId structure Id of the object
*      @date  17/02/2019 
*      @author Alexandra Conache & CiroAlonso  
*      @return OK or ERROR if the function worked or not                      
*/
STATUS game_set_object_space(Game *game, Id spaceID, Id objectId);
/**
*      @brief Returns the object found in the space inquired
*                                    
*      @param game structure Game from file game.c  
*      @param spaceID structure Id of the space
*      @param objectId structure Id of the object
*      
*      @date  17/02/2019 
*      @author Alexandra Conache & CiroAlonso
*      @return TRUE or FALSE if there's an object in the space inquired or not                        
*/
BOOL game_get_object_space(Game *game, Id spaceID, Id objectId);
/**
*      @brief Adds objects to the game
*                                   
*      @param game structure Game from file game.c
*      @param object struct Object from file space.c  
*      @author Alexandra Conache & CiroAlonso   
*      @return OK or ERROR if the function worked or not                     
*/
STATUS game_add_object(Game* game, Object* object);
/**
*      @brief Returns the field player from Game's structure
*                                   
*      @param game structure Game from file game.c
*
*      @author Alexandra Conache  
*      @return Player from the game structure                    
*/
Player* game_get_player(Game *game);
/**
*      @brief Returns the field die from Game's structure
*                                   
*      @param game structure Game from file game.c
*
*      @author Alexandra Conache 
*      @return Die from the game structure                     
*/
Die* game_get_die(Game *game);
/**
*      @brief Returns the field object from Game's structure
*                                   
*      @param game structure Game from file game.c
*      @param id structure id of the object
*      @author Alexandra Conache 
*      @return Object of the game structure                     
*/
Object* game_get_object(Game* game, Id id);
/**
*      @brief Get the link he is reading 
*                                    
*      @param game structure Game from file game.c 
*      @param position of the link  
*      @date  17/02/2019 
*      @author Alexandra Conache & CiroAlonso
*      @return Id of the link in the position we passed as an argument                       
*/
Id game_get_link_id_at(Game* game, int position);
/**
*      @brief Returns the field link from Game's structure
*                                   
*      @param game structure Game from file game.c
*      @param id of the link
*
*      @author Alexandra Conache    
*      @return Link of the game structure                  
*/
Link* game_get_link(Game* game, Id id);
/**
*      @brief Returns the object the player is holding in their inventory
*                                   
*      @param game structure Game from file game.c
*      @param player structure Player from file player.c
*
*      @author Alexandra Conache      
*      @return Object of the game structure that the player is holding                
*/
Object* game_get_player_object(Game* game, Player* player);

/**
*      @brief Returns the field description from Game's structure
*                                   
*      @param game structure Game from file game.c
*
*      @author Alexandra Conache  
*      @return char* or string of the game's description field of its structure                    
*/
char* game_get_description(Game* game);

/**
 *      @brief Return the name of one of player's objects
 *  
 *      @param game structure Game and the object's id
 *      @param id of the object
 *      @author Alexandra Conache
 *      @return char* or string of the player's object's name
 */
char* game_get_player_object_name(Game* game, Id id);
#endif
