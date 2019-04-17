

/** 
 * @brief It defines the inventory
 * 
 * @file link.h
 * @author Alexandra Conache && Sara Erika Catana
 * @version 1.0 
 * @date 1/04/2019
 */
#ifndef LINK_H
#define LINK_H

#include "types.h"
#define MAX_LINK 400 /*!< Maximum number of links we can have*/
/**
 * @brief Link data structures
 */
typedef struct _Link Link;

/**
 *  @brief Creates a link
 *
 *  link_create     Reserves enough memory to create the link and assigns it an ID
 *
 *  @date 07/04/2019
 *  @author Alex Conache & Sara Erika Catana
 *  @param id is the id assigned to the die so it can be identified
 *  @return Link* the link structure
 *
 */
Link* link_create(Id id);

/**
 *  @brief Destroys a link
 *
 *  link_destroy    Destroys de link
 *
 *  @date 07/04/2019
 *  @author Alex Conache & Sara Erika Catana
 *
 *  @param link is the pointer assigned to the link TAD 
 *  @return it's a void function, it has no return value  
 *
 */
void link_destroy(Link* link);

/**
 *  @brief Gets the id from a link
 *
 *  link_get_id     GEts the ID of the link
 *
 *  @date 07/04/2019
 *  @author Alex Conache & Sara Erika Catana
 *
 *  @param link is the pointer assigned to the Link TAD
 *  @return Id the id of the link structure
 *
 */
Id link_get_id(Link* link);

/**
 *  @brief Gets the first link
 *
 *  link_get_link1     Gets the first link
 *
 *  @date 07/04/2019
 *  @author Alex Conache & Sara Erika Catana
 *
 *  @param link is the pointer assigned to the Link TAD
 *  @return Id the Id of the link1
 *
 */
Id link_get_link1(Link* link);
/**
 *  @brief Gets the second link
 *
 *  link_get_link2     Gets the second link
 *
 *  @date 07/04/2019
 *  @author Alex Conache & Sara Erika Catana
 *
 *  @param link is the pointer assigned to the Link TAD
 *  @return Id the id of link2
 *
 */
Id link_get_link2(Link* link);

/**
 *  @brief Gets the name of the link
 *
 *  link_get_name     Gets the name of the link
 *
 *  @date 07/04/2019
 *  @author Alex Conache & Sara Erika Catana
 *
 *  @param link is the pointer assigned to the Link TAD
 *  @return char the name of the link
 */
const char * link_get_name(Link* link);

/**
 *  @brief Gets the state of the link
 *
 *  link_get_state     Gets the state of the link
 *
 *  @date 07/04/2019
 *  @author Alex Conache & Sara Erika Catana
 *
 *  @param link is the pointer assigned to the Link TAD
 *  @return STATE the state of the link
 */
STATE link_get_state(Link* link);

/**
 *  @brief Sets the name given from parameters
 *
 *  link_set_name    Sets the name of the link
 *
 *  @date 07/04/2019
 *  @author Alex Conache & Sara Erika Catana
 *
 *  @param link is the pointer assigned to the Link TAD
 *  @param name is the new name of the link
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS link_set_name(Link* link, char* name);
/**
 *  @brief Sets the first link
 *
 *  link_set_link1     It sets the first link
 *
 *  @date 07/04/2019
 *  @author Alex Conache & Sara Erika Catana
 *
 *  @param link is the pointer assigned to the link TAD
 *  @param id is the id assigned to the die so it can be identified
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS link_set_link1(Link* link, Id id) ;
/**
 *  @brief Sets the second link
 *
 *  link_set_link2     It sets the second link
 *
 *  @date 07/04/2019
 *  @author Alex Conache & Sara Erika Catana
 *
 *  @param id is the id assigned to the die so it can be identified
 *  @param link is the pointer assigned to the link TAD
 *  @return STATUS OK or ERROR if the function worked or not
 */
STATUS link_set_link2(Link* link, Id id);
/**
 *  @brief It sets the State given prom parameters
 *
 *  link_set_state     It changes the state
 *
 *  @date 07/04/2019
 *  @author Alex Conache & Sara Erika Catana
 *
 *  @param state is the new state
 *  @param link is the pointer assigned to the link TAD
 *  @return STATUS OK or ERROR if the function worked or not
 *
 */
STATUS link_set_state(Link* link, STATE state);
/**
 *  @brief Prints the link
 *
 *  link_print     Prints the link struct
 *
 *  @date 07/04/2019
 *  @author Alex Conache && Sara Erika Catana
 *
 *  @param link is the pointer assigned to the link TAD
 *  @return STATUS OK or ERROR if the function worked or not
 *
 */
STATUS link_print(Link* link) ;

#endif /* LINK_H */
