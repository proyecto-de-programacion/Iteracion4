/**
 * @brief It defines a screen
 *
 * @file screen.h
 * @author AlexandraConache & CiroAlonso
 * @version 1.0
 * @date 07-04-2019
 * @copyright GNU Public License
 */

#ifndef __SCREEN__
#define __SCREEN__

/**
 * Definition of constant values
 */
#define SCREEN_MAX_STR 80 /*!< Maximum string of screen*/

/**
 * Definition of data structure
 */
typedef struct _Area Area;


/**
 *  @brief initializes the screen structure
 *
 *
 *  @date 07/04/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @return it's a void function, it has no return value   
 */
void  screen_init();

/**
 *  @brief destroys the screen structure
 *
 *
 *  @date 07/04/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @return it's a void function, it has no return value   
 */
void  screen_destroy();

/**
 *  @brief paints the game in the screen
 *
 *
 *  @date 07/04/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *
 *  @return it's a void function, it has no return value   
 */
void  screen_paint();

/**
 *  @brief initializes the screen
 *
 *
 *  @date 07/04/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *  @param str the string to copy
 *  @return it's a void function, it has no return value   
 */
void  screen_gets(char *str);

/**
 *  @brief initializes the screen area
 *
 *
 *  @date 07/04/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *  @param x
 *  @param y
 *  @param width the width of the game display
 *  @param height the height of the game display
 *  @return it's a void function, it has no return value   
 */
Area* screen_area_init(int x, int y, int width, int height);

/**
 *  @brief destroys the screen area 
 *
 *
 *  @date 07/04/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *  @param area the area you want to destroy
 *  @return it's a void function, it has no return value   
 */
void  screen_area_destroy(Area* area);

/**
 *  @brief destroys all the information of that area 
 *
 *
 *  @date 07/04/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *  @param area the area you want to eliminate the information
 *  @return it's a void function, it has no return value   
 */
void  screen_area_clear(Area* area);

/**
 *  @brief neccesary to eliminate the information in screen_clear
 *
 *
 *  @date 07/04/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *  @param area the area you want to eliminate the information
 *  @return it's a void function, it has no return value   
 */
void  screen_area_reset_cursor(Area* area);

/**
 *  @brief prints out the information 
 *          screen_area_puts prints out the information of the char * str
 *              in the area of the screen you want to display it
 *
 *  @date 07/04/2019
 *  @author Alonso Aquino Ciro, Conache Alexandra
 *  @param area the area you want to print out
 *  @param str the information you want to display
 *  @return it's a void function, it has no return value   
 */
void  screen_area_puts(Area* area, char *str);

#endif
