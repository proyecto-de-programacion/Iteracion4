/**
 * @brief It implements the command interpreter
 *
 * @file command.h
 * @author Alonso Aquino Ciro, Conache Alexandra
 * @version 5.0
 * @date 06/04/2019
 * 
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"
/*!<  Enumeration of the commands and their values  */

#define MAX_NAME 32 /*!< Length of the name */


/**
 *  @brief The command enumeration
 * 
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *  @version  3.0
 * 
 */
typedef enum Enum_Command {
  NO_CMD = -1,  
  UNKNOWN, /*!< 0 */
  EXIT,	/*!< 1 */
  NEXT,	/*!< 2 */
  BACK,	/*!< 3 */
  LEFT,	/*!< 4 */
  RIGHT,/*!< 5 */
  ROLL,	/*!< 6 */
  PICKUP,/*!< 7 */
  DROP,	/*!< 8 */
  MOVE,	/*!< 9 */
  INSPECT/*!< 10 */
  }Enum_command;
/**
 * @brief The command structure
 * 
 * @author Alonso Aquino Ciro, Conache Alexandra
 * 
 */
/**
 * Definition of data structures
 */
typedef struct _Command Command; 


/**
*      @brief   Creation of the command
*                              
*           
*      @param -
*      @date  11/03/2019 
*      @author AlexandraConache & CiroAlonso 
*      @return Command* pointer                      
*/
Command *command_create();

/**
*      @brief Destruction of the command
*               
*           
*      @param pc command we want to destroy
*      @date  11/03/2019 
*      @author AlexandraConache & CiroAlonso 
*      @return void function, no return value                      
*/
void command_destroy(Command *pc);

/**
*      @brief Get the name
*                              
*           
*      @param  pc command inquired about
*      @date  11/03/2019 
*      @author AlexandraConache & CiroAlonso 
*      @return char* or string of the command                      
*/
char *command_get_name(Command *pc);

/**
*      @brief Get the command
*                              
*            
*      @param pc command inquired about
*      @date  11/03/2019 
*      @author AlexandraConache & CiroAlonso 
*      @return Enum_command field of the Command structure                      
*/
Enum_command command_get_command(Command *pc);


/**
*      @brief Gets the user input of the commands
*                              
*           
*      @param pc command character we imput
*      @date  6/04/2019 
*      @author AlexandraConache
*      @return OK or ERROR if the function worked or not                        
*/
STATUS command_get_user_input(Command *pc);

/**
*      @brief Set the command
*                              
*            
*      @param pc command structure 
*      @param cmd command we want to set
*
*      @date  11/03/2019 
*      @author AlexandraConache & CiroAlonso     
*      @return Command* of the command we passed the cmd field of it's structure to                
*/
Command *command_set_command(Command *pc, Enum_command cmd);

/**
*      @brief Set the name
*                              
*           
*      @param pc command we want to change 
*      @param name we imput
*      @date  11/03/2019 
*      @author AlexandraConache & CiroAlonso   
*      @return Command* of the command we set the name to                    
*/
Command *command_set_name(Command *pc, const char *name);

#endif
