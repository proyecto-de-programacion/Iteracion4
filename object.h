/**
 *  @brief A definition to use 'object' data type
 *
 *  Here all functions related to 'object' data types are defined as well as the structure Object
 *
 *  @file object.h
 *  @version 1.0
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 */
#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

/**
 * Definition of constant values
 */

#define MAX_OBJECTS 4 /*!< Maximum number of objects*/

/**
 * Definition of data structures
 */

typedef struct _Object Object;



/**
 *  Delcaration of public functions
 */

/**
 *  @brief Creates the Object
 *
 *  object_create Reserves enough memory to create the object
 *                it assigns it an id, a name and a location
 *                as well as making sure everything is working
 *                properly
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param id is the Id the object has assigned and will be used to identify it
 *  @return object* the object created
 *
 */
Object* object_create(Id id);

/**
 *  @brief Destroys the object by freeing the allocated memory
 *
 *  object_destroy Frees the memory we reserved with the function object_create
 *                 it also assigns it a NULL value to tie up loose ends
 *                 furthermore it has a control code to prevent possible
 *                 errors
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param object the object created that's going to be destroyed
 *  @return STATUS OK or ERROR if the function worked or not
 *
 */
STATUS object_destroy(Object* object);

/**
 *  @brief Returns the object's id
 *
 *  object_get_id   Is a function that assesses whether the object exists and
 *                  it calls the object's structure to get its id
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param object is the object we created
 *  @return Id the id of the object
 */
Id object_get_id(Object* object);

/**
 *  @brief Assigns a name to the object
 *
 *  object_set_name Gives the object a name to differentiate it
 *                  from another player's
 *
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param object is the object we created
 *  @param name is the name we're going to assign to the object
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS object_set_name(Object* object, char* name);

/**
 *  @brief Gets the object's name
 *
 *  object_get_name Is a constant function so it can't be changed.
 *                  Makes sure object exists and gets it's assigned name
 *
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param object is the object we created
 *  @return char* the name of the object
 */
char* object_get_name(Object* object);

/**
 *  @brief Prints the object on screen
 *
 *  object_print   Is a simple function that prints the object on screen with
 *                 its name and id after making sure it exists. It also prints on
 *                 screen wether the object is where it's supposed to be
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param object is the object we created
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS object_print(Object* object);
/**
 *  @brief Assigns a description to the object
 *
 *  object_set_description Gives the object a description to differentiate it
 *                  from another player's
 *
 *
 *  @date 7/04/2019
 *  @author Sara Erika Catana && Alexandra Conache
 *
 *  @param object is the object we created
 *  @param description is the description we're going to assign to the object
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS object_set_description(Object* object, char* description);
/**
 *  @brief Gets the object's description
 *
 *  object_get_description Is a constant function so it can't be changed.
 *                  Makes sure object exists and gets it's assigned description
 *
 *
 *  @date 7/04/2019
 *  @author Conache Alexandra
 *
 *  @param object is the object we created
 *  @return char* the description of the object
 */
char* object_get_description(Object* object);

/**
 *  @brief Sets the object open attribute
 *
 *
 *  @date 18/04/2019
 *  @author Ciro Alonso
 *
 *  @param obj is the object we created
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS object_set_open_link(Object *obj, Id id);

/**
 *  @brief Gets the object's open attribute
 *
 *
 *  @date 18/04/2019
 *  @author Ciro Alonso
 *
 *  @param obj is the object we created
 *  @return Id the id of the link to open
 */
Id object_get_open_link(Object *obj);

/**
 *  @brief Gets the object's illuminate
 *
 *
 *  @date 18/04/2019
 *  @author Ciro Alonso
 *
 *  @param obj is the object we created
 *  @return BOOL TRUE or FALSE depending on the state of the object
 */
BOOL object_get_illuminate(Object *obj);

/**
 *  @brief Sets the illuminate of the object
 *
 *
 *  @date 18/04/2019
 *  @author Ciro Alonso
 *
 *  @param obj is the object we created
 *  @param state the state you want the illuminate to be
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS object_set_illuminate(Object *obj, BOOL state);

/**
 *  @brief Gets the object's turnedon
 *
 *  @date 18/04/2019
 *  @author Ciro Alonso
 *
 *  @param obj is the object we created
 *  @return BOOL TRUE or FALSE depending on the state of the object
 */
BOOL object_get_turnedon(Object *obj);


/**
 *  @brief turns on the object if possible
 *
 *
 *  @date 18/04/2019
 *  @author Ciro Alonso
 *
 *  @param obj is the object we created
 *  @return STATUS OK or ERROR if the function worked or not 
 */
STATUS object_set_turnedon(Object *obj,  BOOL state);

#endif
