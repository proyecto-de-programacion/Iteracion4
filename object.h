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
 *  @return char* the descriptino of the object
 */
char* object_get_description(Object* object);

/**
 *  @brief Establishes if the object can be moved or not
 *  @date 16/04/2019
 *  @author Conache Alexandra
 *  @param object we want to set it to move or not
 *  @param input TRUE if it moves, FALSE if it doesn't 
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS object_set_movable(Object* object, BOOL input);
/**
 *  @brief Gets the object's mobility status
 *  @date 16/04/2019
 *  @author Conache Alexandra  
 *  @param object inquired about
 *  @return BOOL TRUE if it moves, FALSE if it doesn't
 */
BOOL object_get_movable(Object* object);
/**
 *  @brief Establishes if the object has been moved or not
 *  @date  16/04/2019
 *  @author Conache Alexandra
 *  @param object we want to change the moved status
 *  @param id of the space/location we want to see if it's from or not
 *  @return STATUS OK or ERROR if the function worked
 */
STATUS object_set_moved(Object* object, Id id);
/**
 *  @brief Gets the object's moved status (if it's been moved or not basically)
 *  @date 16/04/2019
 *  @author Conache Alexandra
 *  @param object we inquire about
 *  @return BOOL TRUE if it's been moved, FALSE if it hasn't
 */
BOOL object_get_moved(Object* object);
/**
 *  @brief Establishes the object's original location
 *  @date 16/04/2019
 *  @author Alexandra Conache
 *  @param object we want to set the OG location to
 *  @param id of the OG location aka the space's id
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS object_set_original_location(Object* object, Id id);
/**
 *  @brief Gets the id of the object's original location
 *  @date 16/04/2019
 *  @author Conache Alexandra
 *  @param object we inquire about
 *  @return Id of the space that we assigned as the object's original location
 */
Id object_get_original_location(Object* object);
/**
 *  @brief Establishes wether the object is hidden or not
 *  @date 16/04/2019
 *  @author Conache Alexandra
 *  @param object we want to set the hidden status to
 *  @param input BOOL TRUE if it's hidden, FALSE if it's not
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS object_set_hidden(Object* object, BOOL input);
/**
 *  @brief Gets the object hidden status (if it's hidden or not)
 *  @date 16/04/2019
 *  @author Conache Alexandra 
 *  @param object we inquire about
 *  @return BOOL TRUE if it's hidden, FALSE if it's not
 */
BOOL object_get_hidden(Object* object);
/**
 *  @brief Assigns a description to the object if it's been moved
 *  @date 16/04/2019
 *  @author Conache Alexandra
 *  @param object we want to assign the description to
 *  @param decription we want to assign
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS object_set_moved_description(Object* object, char* description);
/**
 *  @brief Gets the object's description (if the object's been moved)
 *  @date 16/04/2019
 *  @author Conache Alexandra
 *  @param object we want to get the description of
 *  @return char* /string of the description
 */
char* object_get_moved_description(Object* object);
#endif
