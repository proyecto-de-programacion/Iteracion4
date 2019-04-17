/**
 * @brief It implements the die
 *
 * @file die.h
 * @author Catana Sara Erika, Conache Alexandra
 * @version 3.0
 * @date 01/04/2019
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "types.h"

#define MAX_DIE 7 /*!< Maximum number of die we can have */

/**
 * @brief The die structure
 * @author Catana Sara Erika, Conache Alexandra
 */
/**
 * Definition of data structures
 */
typedef struct _Die Die;

/**
 *  @brief Creates a die
 *
 *  die_create     Reserves enough memory to create the die and assigns it an ID
 *
 *  @date 23/02/2019
 *  @author Catana Sara Erika
 *
 *  @param id is the id assigned to the die so it can be identified
 *  @return Die* of the die created
 *
 */
Die* die_create(Id id);

/**
 *  @brief Destroys the die by freeing the allocated memory
 *
 *  die_destroy    Frees the memory we reserved with the function die_create
 *                 it also assigns it a NULL value to tie up loose ends
 *                 furthermore it has a control code to prevent possible
 *                 errors
 *
 *  @date 23/02/2019
 *  @author Catana Sara Erika
 *
 *  @param die the die created that's going to be destroyed
 *  @return OK or ERROR if the function worked or not 
 *
 */
STATUS die_destroy(Die* die);

/**
 *  @brief Rolls the die
 *
 *  die_roll        It randomly generates a value between 1 and 6 for the die
 *
 *  @date 23/02/2019
 *  @author Conache Alexandra
 *
 *  @param die the die created that we're going to roll
 *  @return result of the rolled die
 *
 */
int die_roll(Die *die);

/**
 *  @brief Prints the values the die rolled
 *
 *  die_print      Prints on screen the value the die rolled
 *
 *  @date 23/02/2019
 *  @author Conache Alexandra
 *
 *  @param die the die value that's going to be printed
 *  @return OK or ERROR if the function worked or not 
 *
 */
STATUS die_print(Die* die);

/** 
 *  @brief Prints the values the die rolled
 *
 *  die_get_lastRoll   Prints on screen the value the die last_rolled
 *
 *  @date 23/02/2019
 *  @author Conache Alexandra
 *
 *  @param d the die created that's going to be destroyed
 *  @return value of the last roll field of the Die structure
 */
int die_get_lastRoll(Die *d);

/**
 *  @brief  Returns the die's id
 *
 *  @date 19/03/2019
 *  @author Alexandra Conache
 *
 *  @param die we want to return the id of
 *  @return Id of the die
 */
Id die_get_id(Die* die);