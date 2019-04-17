/** 
 * @brief It defines the inventory
 * 
 * @file inventory.h
 * @author Alexandra Conache && Sara Erika Catana
 * @version 1.0 
 * @date 1/04/2019
 */
#ifndef INVENTORY_H
#define INVENTORY_H

#include "types.h"
#include "set.h"

/*!< maxObjects is written that way because it's the name we gave it in the 
Inventorie's structure */
/**
 * @brief The Inventory structure
 * @author Alonso Aquino Ciro, Conache Alexandra, Catana Sara Erika
 */
/**
 * Definition of data structures
 */
typedef struct _Inventory Inventory;

/**
 *  @brief Creates the inventory
 *
 *  inventory_create Reserves enough memory to create the inventory
 *                   it assigns it an id, a name and a location
 *                   as well as making sure everything is working
 *                   properly
 *
 *  @date 01/04/2019
 *  @author Sara Erika Catana
 *
 *  @param id of the inventory
 *  @return Inventory* created
 *
 */
Inventory* inventory_create(Id id);
/**
 *  @brief Destroys the inventory by freeing the allocated memory
 *
 *  inventory_destroy Frees the memory we reserved with the function inventory_create
 *                    it also assigns it a NULL value to tie up loose ends
 *                    furthermore it has a control code to prevent possible
 *                    errors
 *
 *  @date 01/04/2019
 *  @author Sara Erika Catana
 *
 *  @param inventory the inventory created that's going to be destroyed
 *  @return OK or ERROR if the function worked or not
 *
 */
STATUS inventory_destroy(Inventory* inventory);
/**
 *  @brief Returns the inventorie's object's identifiers
 *
 *  
 *  @date 01/04/2019
 *  @author Sara Erika Catana
 *
 *  @param inventory is the player's inventory
 *  @return Set* field of the inventory structure
 */
Set * inventory_get_set(Inventory* inventory);
/**
 *  @brief Returns the inventorie's max object's 
 *
 *  inventory_get_maxObjects           Is a function that assesses whether the inventory exists and
 *                                     it calls the inventorie's structure to get its max objects
 *
 *  @date 01/04/2019
 *  @author Sara Erika Catana
 *
 *  @param inventory is the inventory we created
 *  @return value of the maximum objects the inventory can contain
 */
int inventory_get_maxObjects(Inventory* inventory);

/**
 *  @brief Set the maxObjects value
 *
 *  inventory_set_maxObjects 
 *
 *
 *  @date 02/04/2019
 *  @author Sara Erika Catana
 *
 *  @param inventory is the inventory we created
 *  @param new_size the new number of objects the inventory can contain
 *  @return OK or ERROR if the function worked or not
 */
STATUS inventory_set_maxObjects(Inventory* inventory, int new_size);
/**
 *  @brief Prints the inventory
 *
 *  inventory_print     Prints the Inventory structure
 *
 *  @date 07/04/2019
 *  @author Alex Conache
 *
 *  @param inventory is the pointer assigned to the Inventory TAD
 *  @return OK or ERROR if the function worked or not
 *         
 */
STATUS inventory_print(Inventory* inventory);
/**
 *  @brief Deletes an object
 *
 *  inventory_delete_object     Deletes the objects with the same ID as the one given
 *
 *  @date 07/04/2019
 *  @author Alex Conache
 *
 *  @param inventory is the pointer assigned to the Inventory TAD
 *  @param object_id is the ID of the objects which is gonna get deleted
 *  @return OK or ERROR if the function worked or not
 */
STATUS inventory_delete_object(Inventory *inventory , Id object_id);
/**
 *  @brief Adds a new object
 *
 *  inventory_add_object     Adds a new object to the inventory
 *
 *  @date 07/04/2019
 *  @author Alex Conache
 *
 *  @param inventory is the pointer assigned to the Inventory TAD
 *  @param object_id is the ID of the objects which is gonna get deleted
 *  @return OK or ERROR if the function worked or not
 */
STATUS inventory_add_object(Inventory *inventory ,Id object_id);
/**
 *  @brief Asks if the object with the provided id is in the inventory
 *
 *  
 *  @date 07/04/2019
 *  @author Alex Conache
 *
 *  @param inventory is the pointer assigned to the Inventory TAD
 *  @param object_id is the ID of the object we ask about
 *  @return TRUE or FALSE if the object with the Id provided is in the inventory
 */
BOOL inventory_ask_id(Inventory* inventory, Id object_id);
#endif
