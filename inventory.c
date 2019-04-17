/**
 *  @brief An implementation to use 'inventory' data type
 *
 *  Here all functions related to 'object' data types are implemented as well as the structure Inventory
 *
 *  @file inventory.c
 *  @date 6/04/2019
 *  @author Catana Erika Sara, Conache Alexandra
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/inventory.h"

/**
 *   @brief Inventory structure
 *
 *   Stores relevant information about the objects the player has
 *
 */
struct _Inventory {
  Id id; /*!<Inventorie's Id*/
  Set *set;  /*!<Inventorie's set*/
  int maxObjects; /*!<Inventorie's maximum capacity*/
};
/*!< Creates an inventory */
Inventory* inventory_create(Id id){
    Inventory *newInventory = NULL;

    
    newInventory = (Inventory*) malloc (sizeof(Inventory));

    if (newInventory == NULL) {
      return NULL;
    }
    
    newInventory->maxObjects = 0;
    newInventory->set = set_create(NO_ID);

    return newInventory;
}
/*!<  Destroys the inventory*/
STATUS inventory_destroy(Inventory* inventory){
    if (!inventory) {
      return ERROR;
    }
    set_destroy(inventory->set);
    free(inventory);

    return OK;
}
/*!< Gets the set */
Set * inventory_get_set(Inventory* inventory){
  if (!inventory ) {
    return ERROR;
  }
  
  return inventory->set;
}
/*!< Gets the maxObjects value */
int inventory_get_maxObjects(Inventory* inventory){
  if (!inventory) {
    return ERROR;
  }
  return inventory->maxObjects;
    
}


/*!<!< Sets th new maxObjects value*/
STATUS inventory_set_maxObjects(Inventory* inventory, int new_size){
  if (!inventory || new_size < 0) {
    return ERROR;
  }
  inventory->maxObjects = new_size;
  return OK;
}
/*!< Prints the inventory */
STATUS inventory_print(Inventory* inventory){
  
  if (!inventory) {
    return ERROR; /*!< INVENTORY_H */
  }

  fprintf(stdout, "--> Inventory \n");
  
  fprintf(stdout, "--> Max objects: %d \n", inventory->maxObjects);
  
  set_print(inventory->set);

  
  
  return OK;
}
/*!< Deletes an object from the inventory */
STATUS inventory_delete_object(Inventory *inventory , Id object_id){
  if (!inventory || object_id == NO_ID){
    return ERROR;
  }
  if (set_del(inventory->set,object_id)==ERROR){
    return ERROR;
  }

  return OK;
}
/*!< Adds a new object to the inventory */
STATUS inventory_add_object(Inventory *inventory ,Id object_id){
  if (!inventory || object_id == NO_ID){
    return ERROR;
  }
  if (set_add(inventory->set,object_id)==ERROR){
    return ERROR;
  }

  return OK;
}
/*!< Asks if the object is in the inventory */
BOOL inventory_ask_id(Inventory* inventory, Id object_id){
  int i=0;
  if(!inventory || object_id == NO_ID) return FALSE;

  for(i=0; i< inventory->maxObjects;i++){
    if(set_get_id(inventory->set,i) == object_id){
      return TRUE;
    }
  }
  return FALSE;
}