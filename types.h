/**
 * @brief It defines common types
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H
/**
 * Definition of constant values
 */
#define WORD_SIZE 1000 /*!< Maximum size a word can have*/
#define NO_ID -1 /*!< Default NO_ID value*/
#define INIT_VALUE 0 /*!< Default iniciation value*/


/**
 *  @brief Definition of data id
 */

typedef long Id;

/**
 * Definition of data enumerations
 */
/**
 * @brief Definition of BOOL
 */
typedef enum {
  FALSE, TRUE
} BOOL;
/**
 * @brief Definition of STATUS
 */
typedef enum {
  ERROR, OK
} STATUS;
/**
 * @brief Definition of DIRECTION
 */
typedef enum {
  N, S, E, W
} DIRECTION;
/**
 * @brief Definition of STATE
 */
typedef enum{
  ABIERTO, CERRADO, DESCONOCIDO
} STATE;


#endif
