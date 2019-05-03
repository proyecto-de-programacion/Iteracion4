/**
 * @brief It defines a space
 *
 * @file space.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */


 /**
  *  @brief  It defines a space
  *
  *  We modified the defined functions
  *
  *  @file space.h
  *  @version 1.5
  *  @date 17/02/2019
  *  @author Alonso Aquino Ciro, Conache Alexandr
  */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"

/**
 * Definition of constant values
 */
#define MAX_SPACES 100 /*!< Maximum number of spaces we can have*/
#define FIRST_SPACE 1 /*!< First space , start of the spaces*/
#define MAX_OBJECTS 4 /*!< Maximum number of objects a space can have*/
#define ROWS 3/*!< Maximum number of rows*/
#define COLUMNS 8/*!<Maximum number of columns*/

/**
 * Definition of data structures
 */
typedef struct _Space Space;

/**
 *  Delcaration of public functions
 */


/**
 *  @brief Creates the space
 *
 *  space_create Reserves enough memory to create the space
 *                it assigns it an id, a name, whether it has any other space adjacent,
 *                and initialize the new objects , as well as making sure everything is working
 *                properly
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param id is the id the space has assigned and will be used to identify it
 *  @return space* the new structure
 *
 */
Space* space_create(Id id);

/**
 *  @brief destroys the space selected
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS space_destroy(Space* space);

/**
 *  @brief Assigns a name to the space
 *
 *  space_set_name Gives the space a name to differentiate it
 *                  from another space
 *
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @param name is the name we're going to assign to the space
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS space_set_name(Space* space, char* name);

/**
 * @brief Links the space to another in the north direction
 *
 *  space_set_north Asks the Space structure if the space exists and if so it links it
 *                 to another space in the north direction
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @param id is the space's id
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS space_set_north_link(Space* space, Id id); 


/**
 * @brief Links the space to another in the south direction
 *
 *  space_set_south Asks the Space structure if the space exists and if so it links it
 *                 to another space in the south direction
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @param id is the space's id
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS space_set_south_link(Space* space, Id id);


/**
 * @brief Links the space to another in the east direction
 *
 *  space_set_east Asks the Space structure if the space exists and if so it links it
 *                 to another space in the east direction
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @param id is the space's id
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS space_set_east_link(Space* space, Id id);


/**
 * @brief Links the space to another in the west direction
 *
 *  space_set_west Asks the Space structure if the space exists and if so it links it
 *                 to another space in the west direction
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @param id is the space's id
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS space_set_west_link(Space* space, Id id);


/**
 *  @brief Assigns an object to the space
 *
 *  space_set_object Makes sure the space exists and it assigns it an object
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param id is identification of the object
 *  @param space is the space we created
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS space_set_object(Space* space, Id id);


/**
 *  @brief Gets the space's name
 *
 *  space_get_name Is a constant function so it can't be changed.
 *                  Makes sure space exists and gets/returns it's assigned name
 *
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @return char* the name of the space
 */
const char* space_get_name(Space* space);


/**
 *  @brief Returns the space's id
 *
 *  space_get_id    Is a function that assesses whether the space exists and
 *                  it calls the space's structure to get its id
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @return Id the id of the space
 */
Id space_get_id(Space* space);


/**
 * @brief Returns the space in the north of the box we're inquiring about
 *
 *  space_get_north Asks the Space structure whether the space or box we're inquiring about
 *                  has another space linked in its north direction
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @return Id the id of the north link
 */
Id space_get_north_link(Space* space);


/**
 * @brief Returns the space in the south of the box we're inquiring about
 *
 *  space_get_south Asks the Space structure whether the space or box we're inquiring about
 *                  has another space linked in its south direction
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 * 
 *  @return Id the id of the south link
 */
Id space_get_south_link(Space* space);


/**
 * @brief Returns the space in the east of the box we're inquiring about
 *
 *  space_get_east Asks the Space structure whether the space or box we're inquiring about
 *                  has another space linked in its east direction
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @return Id the id of the east link
 */
Id space_get_east_link(Space* space);


/**
 * @brief Returns the space in the west of the box we're inquiring about
 *
 *  space_get_west Asks the Space structure whether the space or box we're inquiring about
 *                  has another space linked in its west direction
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @return Id the id of the west link
 */
Id space_get_west_link(Space* space);



/**
 *  @brief Confirms the space has an object
 *
 *  space_del_object  The function checks if the object is in the set structure
 *   deletes it from the structure and returns OK if done correctly 
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @param id is the id of the object deleted
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS space_del_object(Space* space, Id id);

/**
 *  @brief Prints the space on screen
 *
 *  space_print    Is a simple function that prints the space on screen with
 *                 its name and id after making sure it exists. It also prints on
 *                 screen wether the space is where it's supposed to be and if it has
 *                 other spaces or boxes in each direction (n,s,e,w)
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS space_print(Space* space);

/**
 *  @brief set the gdesc
 *
 *  
 *  @date 26/03/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @param string the string you want to copy
 *  @param i the different gdesc
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS space_set_gdesc(Space* space, char *string, int i);

/**
 *  @brief Gets gdesc1
 *
 *  
 *  @date 26/03/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @return char gdesc1
 */
char* space_get_gdesc1(Space* space);

/**
 *  @brief Gets gdesc2
 *
 *  
 *  @date 26/03/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @return char gdesc2
 */
char* space_get_gdesc2(Space* space);

/**
 *  @brief Gets gdesc2
 *
 *  
 *  @date 26/03/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @return char gdesc2
 */
char* space_get_gdesc3(Space* space);

/**
 *  @brief Checks if the object selected is in the space
 *
 *  
 *  @date 26/03/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @param id the id of the object
 *  @return BOOL TRUE or FALSE if the objects is in the space or not
 */
BOOL space_object_is_in(Space* space, Id id);

 
 /**
 *  @brief Sets the description of that space
 *  @date 26/03/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @param description the description of the space
 *  @return STATUS OK or ERROR if the function worked or not
 */

STATUS space_set_description(Space* space,char* description);

/**
 *  @brief Gets the description of that space
 *
 *  
 *  @date 26/03/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param space is the space we created
 *  @return char* the description of that space
 */
char* space_get_description(Space* space);


 /**
 *  @brief Sets the detail description of that space
 *  @date 26/04/2019
 *  @author Sara Erika Catana
 *
 *  @param space is the space we created
 *  @param detaildescription the detail description of the space
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS space_set_detail_description(Space* space, char* detaildescription);

/**
 *  @brief Gets the detail description of that space
 *
 *  
 *  @date 26/04/2019
 *  @author Sara Erika Catana
 *
 *  @param space is the space we created
 *  @return char* the detail description of that space
 */
char* space_get_detail_description(Space* space);


/**
 *  @brief Sets the illumination of that space
 *  @date 26/04/2019
 *  @author Sara Erika Catana
 *
 *  @param space is the space we created
 *  @return BOOL TRUE or FALSE if the function worked or not
 */
STATUS space_set_illuminated(Space* space, BOOL input);

/**
 *  @brief Gets the illumiation of that space
 *
 *  
 *  @date 26/04/2019
 *  @author Sara Erika Catana
 *
 *  @param space is the space we created
 */
BOOL space_get_illuminated(Space *space);

/**
 *  @brief Set up the link
 *
 *  space_set_up_link  Sets up the link of that space 
 *  @date 26/03/2019
 *  @author Sara Erika Catana
 *
 *  @param space is the space we created
 *  @param id is the id of the object deleted
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS space_set_up_link(Space* space, Id id);

/**
 *  @brief Set down the link
 *
 *  space_set_down_link  Sets down the link of that space 
 *  @date 26/03/2019
 *  @author Sara Erika Catana
 *
 *  @param space is the space we created
 *  @param id is the id of the object deleted
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS space_set_down_link(Space* space, Id id);

/**
 *  @brief Gets up the link
 *
 *  space_get_up_link  Gets up the link of that space 
 *  @date 26/03/2019
 *  @author Sara Erika Catana
 *
 *  @param space is the space we created
 *  @param id is the id of the object deleted
 *  @return Id
 */
Id space_get_up_link(Space* space);

/**
 *  @brief Gets down the link
 *
 *  space_get_down_link  Gets down the link of that space 
 *  @date 26/03/2019
 *  @author Sara Erika Catana
 *
 *  @param space is the space we created
 *  @param id is the id of the object deleted
 *  @return Id
 */
Id space_get_down_link(Space* space);
#endif