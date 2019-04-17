/**
 * @brief It defines a Set
 *
 * @file set.h
 * @author AlexandraConache & CiroAlonso
 * @version 1.0
 * @date 13-03-19
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
/**
 * Definition of data structures
 */
typedef struct _Set Set;

#define TAM_ID 4 /*!< Maximum number of elements in the array*/

/**
 *  @brief creates the set 
 *
 *  @date 01/04/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param -
 *  @return Set* the set structure created 
 */
Set* set_create();

/**
 *  @brief destroys the set 
 *
 *  @date 01/04/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param set the set to destroy
 *  @return it's a void function, it has no return value     
 */
void set_destroy(Set* set);

/**
 *  @brief Adds an element to the set
 *
 *  @date 17/03/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param set is the set we created
 *  @param id the id of the element thats is add to the set 
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS set_add(Set* set,Id id);

/**
 *  @brief Deletes an element of the set
 *
 *  @date 17/03/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param set is the set we created
 *  @param id the id of the element thats is deleted from the set 
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS set_del(Set* set,Id id);

/**
 *  @brief Prins out the set structure
 *
 *  @date 17/03/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param set is the set we created
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS set_print(Set *set);

/**
 *  @brief get the id of the position selected
 *
 *
 *  @date 14/03/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param set is the set we created
 *  @param position is te position of the array
 *  @return Id the id of the postion of the array
 */
Id set_get_id (Set *set ,int position);

/**
 *  @brief Checks if the set structure is Full
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param set is the set we created
 *  @return BOOL TRUE or FALSE depending on the state of the set
 */
BOOL set_is_full(Set* set);

/**
 *  @brief Checks if the set structure is empty
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param set is the set we created
 *  @return BOOL TRUE or FALSE depending on the state of the set
 */
BOOL set_is_empty(Set* set);

/**
 *  @brief Checks if the element is in the set
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param set is the set we created
 *  @param id the id of the the element 
 *  @return BOOL TRUE or FALSE if the element is in he structure or not
 */
BOOL set_Id_inArray(Set *set, Id id);


/**
 *  @brief realizes a copy of the set
 *
 *  @date 17/02/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @param ps is the set we created
 *  @return BOOL TRUE or FALSE depending on the state of the set
 */
Set *set_copy(Set *ps);