/**
 *  @brief A definition to use 'player' data type
 *
 *  Here all functions related to 'player' data types are defined as well as the structure Object
 *
 *  @file player.h
 *  @version 1.0
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "space.h"
#include "object.h"
#include "inventory.h"

/**
 * Definition of constant values
 */

#define MAX_PLAYERS 4 /*!< Maximum number of players */

/**
 * Definition of data structures
 */

typedef struct _Player Player;

/**
 *  Delcaration of public functions
 */

/**
 *  @brief Creates the player
 *
 *  player_create Reserves enough memory to create the player
 *                it assigns it an id, a name and a location
 *                as well as making sure everything is working
 *                properly
 * 
 *  @param id the id of the player
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *
 *
 */
Player* player_create(Id id);

/**
 *  @brief Destroys the player by freeing the allocated memory
 *
 *  player_destroy Frees the memory we reserved with the function player_create
 *                 it also assigns it a NULL value to tie up loose ends
 *                 furthermore it has a control code to prevent possible
 *                 errors
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param player the player created that's going to be destroyed
 *  @return STATUS OK or ERROR if the function worked or not
 *
 */

STATUS player_destroy(Player* player);

/**
 *  @brief returns the id of the player
 *
 
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param player is the player we created
 *  @return Id the id of the player
 */
Id player_get_id(Player* player);


/**
 *  @brief Assigns a name to the player
 *
 *  player_set_name Gives the player a name to differentiate it
 *                  from another player
 *
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param player is the player we created
 *  @param name is the name we're going to assign to the player
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS player_set_name(Player* player, char* name);

/**
 *  @brief Gets the player's name
 *
 *  player_get_name Is a constant function so it can't be changed.
 *                  Makes sure player exists and gets it's assigned name
 *
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param player is the player we created
 *  @return char* the name of the player
 */
const char* player_get_name(Player* player);

/**
 *  @brief Adds an object to the inventary
 *
 *
 *  @date 09/04/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param player is the player we created
 *  @param id the id of the object
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS player_set_inventory(Player* player, Id id);

/**
 *  @brief Returns the player's inventory
 *
 *  player_get_inventory   Is a function that assesses whether the player exists and
 *                         it calls the player's structure to get its inventory
 *
 *  @date 07/04/2019
 *  @author Sara Erika Catana && Alexandra Conache
 *
 *  @param player is the player we created
 *  @return Inventory* the inventory of the player
 */
Inventory* player_get_inventory(Player* player);

/**
 *  @brief Prints the player on screen
 *
 *  player_print   Is a simple function that prints the player on screen with
 *                 its name and id after making sure it exists. It also prints on
 *                 screen wether the player is where it's supposed to be
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param player is the player we created
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS player_print(Player* player);

/**
 *  @brief Returns the player's location
 *
 *  player_get_location It calls upon the location set by the game_set_player_location function
 *                           and returns it
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param player is the player we created
 *  @return Id the id of the player location
 */
Id player_get_location(Player* player);

/**
 *  @brief Player drops the object
 *
 *  player_drop_object    
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param player is the player we created
 *  @param object_id the id of the object to drop
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS player_drop_object(Player* player, Id object_id);

/**
 *  @brief Assigns a location to the player
 *
 *  player_set_location Is a function that assigns the plauer a location in space
 *                           It calls to Player's structure to set the location
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param player is the player we created
 *  @param id is the player's id
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS player_set_location(Player* player, Id id);

/**
 *  @brief Checks to see if the player has a specific object
 *  
 *
 *  @date 06/04/2019
 *  @author Conache Alexandra
 *
 *  @param player is the player we created
 *  @param id the id of the object you are searching 
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS player_has_object(Player* player, Id id);


#endif
