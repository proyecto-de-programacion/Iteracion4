/** 
 * @brief It declares the tests for the space module
 * 
 * @file test_space.h
 * @author Alexandra Conache
 * @version 1.0 
 * @date 08-04-2019
 * 
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

/**
 *      @test   Tests the create a space function
 *      @pre    Parameter:  an Id for the space
 *      @post   Returns: must be something that's different than NULL
 */
void test1_space_create();
/**
 *      @test   Tests the create a space function
 *      @pre    Parameter:  an id for the space
 *      @post   Returns: the id we assigned
 */
void test2_space_create();

/**
 *      @test   Tests the assign a name to the space function
 *      @pre    Parameter: an id for the space we created and a name for it
 *      @post   Returns: must return OK
 */
void test1_space_set_name();
/**
 *      @test   Tests the assign a name to the space function
 *      @pre    Parameter: a name for the space and a null space pointer
 *      @post   Returns: must return ERROR
 */
void test2_space_set_name();
/**
 *      @test   Tests the assign a name to the space function
 *      @pre    Parameter: an id for the space and a NULL name
 *      @post   Returns: must return ERROR
 */
void test3_space_set_name();
/**
 *      @test   Tests the assign a north link to the space function
 *      @pre    Parameter: an id for the space and the id of the space we want to link to
 *      @post   Returns: must return OK
 */
void test1_space_set_north_link();
/**
 *      @test   Tests the assign a north link to the space function
 *      @pre    Parameter: a NULL space pointer and the id of the space we want to link to
 *      @post   Returns: must return ERROR;
 */
void test2_space_set_north_link();
/**
 *      @test   Tests the assign a north link to the space function
 *      @pre    Parameter: an id for the space and a NO_ID for the space we want to link to
 *      @post   Returns:must return RRROR
 */
void test3_space_set_north_link();
/**
 *      @test   Tests the assign a south link to the space function
 *      @pre    Parameter: an id for the space and an id for the space we want to link to
 *      @post   Returns: must return OK
 */
void test1_space_set_south_link();
/**
 *      @test   Tests the assign a south link to the space function
 *      @pre    Parameter: a NULL space pointer and an id for the space we want to link to
 *      @post   Returns: must return ERROR
 */
void test2_space_set_south_link();
/**
 *      @test   Tests the assign a south link to the space function
 *      @pre    Parameter: an id for the space and a NO_ID for the space we want to link to
 *      @post   Returns: must return ERROR
 */
void test3_space_set_south_link();
/**
 *      @test   Tests the assign an east link to the space function
 *      @pre    Parameter: an id for the space and an id for the space we want to link to
 *      @post   Returns: must return OK
 */
void test1_space_set_east_link();
/**
 *      @test   Tests the assign an east link to the space function
 *      @pre    Parameter: a NULL space pointer and an id for the space we want to link to
 *      @post   Returns: must return ERROR
 */
void test2_space_set_east_link();
/**
 *      @test   Tests the assign an east link to the space function
 *      @pre    Parameter: an id for the space and a NO_ID for the space we want to link to
 *      @post   Returns: must return ERROR
 */
void test3_space_set_east_link();
/**
 *      @test   Tests the assign a west link to the space function
 *      @pre    Parameter: an id for the space and an id for the space we want to link to
 *      @post   Returns: must return OK
 */
void test1_space_set_west_link();
/**
 *      @test   Tests the assign a west link to the space function
 *      @pre    Parameter: a NULL space pointer and an id for the space we want to link to
 *      @post   Returns: must return ERROR
 */
void test2_space_set_west_link();
/**
 *      @test   Tests the assign a west link to the space function
 *      @pre    Parameter: an id for the space and a NO_ID for the space we want to link to
 *      @post   Returns: must return ERROR
 */
void test3_space_set_west_link();
/**
 *      @test   Tests the return the space's id function
 *      @pre    Parameter: a space id
 *      @post   Returns: the id we assigned
 */
void test1_space_get_id();
/**
 *      @test   Tests the return the space's id function
 *      @pre    Parameter: a null space pointer
 *      @post   Returns: must return NO_ID
 */
void test2_space_get_id();
/**
 *      @test   Tests the assign an object to the space function
 *      @pre    Parameter: an id for the space and an id for the object
 *      @post   Returns: must return OK
 */
void test1_space_set_object();
/**
 *      @test   Tests the assign an object to the space function
 *      @pre    Parameter: a null space pointer and an id for the object
 *      @post   Returns: must return ERRRO
 */
void test2_space_set_object();
/**
 *      @test   Tests the return the space's name function
 *      @pre    Parameter: a space id and a name for the space
 *      @post   Returns: must be 0 for the string comparison
 */
void test1_space_get_name();
/**
 *      @test   Tests the return the space's name function
 *      @pre    Parameter: a NULL space pointer
 *      @post   Returns: must be NULL
 */
void test2_space_get_name();
/**
 *      @test   Tests the return the id of the space linked to the north function
 *      @pre    Parameter: a space id and an id for the space linked
 *      @post   Returns: must return the linked id
 */
void test1_space_get_north_link();
/**
 *      @test   Tests the return the id of the space linked to the north function
 *      @pre    Parameter: a NULL space pointer
 *      @post   Returns: must return NO_ID
 */
void test2_space_get_north_link();
/**
 *      @test   Tests the return the id of the space linked to the south function
 *      @pre    Parameter: a space id and an id for the space linked
 *      @post   Returns: must return the linked id
 */
void test1_space_get_south_link();
/**
 *      @test   Tests the return the id of the space linked to the south function
 *      @pre    Parameter: a NULL space pointer
 *      @post   Returns: must return NO_ID
 */
void test2_space_get_south_link();
/**
 *      @test   Tests the return the id of the space linked to the east function
 *      @pre    Parameter: a space id and an id for the space linked
 *      @post   Returns: must return the linked id
 */
void test1_space_get_east_link();
/**
 *      @test   Tests the return the id of the space linked to the east function
 *      @pre    Parameter: a NULL space pointer
 *      @post   Returns: must return NO_ID
 */
void test2_space_get_east_link();
/**
 *      @test   Tests the return the id of the space linked to the west function
 *      @pre    Parameter: a space id and an id for the space linked
 *      @post   Returns: must return the linked id
 */
void test1_space_get_west_link();
/**
 *      @test   Tests the return the id of the space linked to the west function
 *      @pre    Parameter: a NULL space pointer
 *      @post   Returns: must return NO_ID
 */
void test2_space_get_west_link();
/**
 *      @test   Tests the assign a description to the space function
 *      @pre    Parameter: a NULL space pointer
 *      @post   Returns: must return ERROR
 */
void test1_space_set_description();
/**
 *      @test   Tests the assign a description to the space function
 *      @pre    Parameter: a space id and a NULL description
 *      @post   Returns: must return ERROR
 */
void test2_space_set_description();
/**
 *      @test   Tests the assign a description to the space function
 *      @pre    Parameter: an id for the space and a description 
 *      @post   Returns: must return OK
 */
void test3_space_set_description();
/**
 *      @test   Tests the delete an object from the space function
 *      @pre    Parameter: a NULL space pointer and an object id
 *      @post   Returns: must return ERROR
 */
void test1_space_del_object();
/**
 *      @test   Tests the delete an object from the space function
 *      @pre    Parameter: a space id and an object id
 *      @post   Returns: must return ERROR
 */
void test2_space_del_object();
/**
 *      @test   Tests the delete an object from the space function
 *      @pre    Parameter: a space id and a NO_ID for the object's id
 *      @post   Returns: must return ERROR
 */
void test3_space_del_object();
/**
 *      @test   Tests the delete an object from the space function
 *      @pre    Parameter: a space id and an object id
 *      @post   Returns: must return OK
 */
void test4_space_del_object();
/**
 *      @test   Tests the assign a gdesc to the space function
 *      @pre    Parameter: a NULL space pointer and a gdesc position
 *      @post   Returns: must return ERROR
 */
void test1_space_set_gdesc();
/**
 *      @test   Tests the assign a gdesc to the space function
 *      @pre    Parameter: a space id, a NULL gdesc, a gdesc position
 *      @post   Returns: must return ERROR
 */
void test2_space_set_gdesc();
/**
 *      @test   Tests the assign a gdesc to the space function
 *      @pre    Parameter: a space id, a valid gdesc and a gdesc position
 *      @post   Returns: must return OK
 */
void test3_space_set_gdesc();



/**
 *      @test   Tests the return the first row of gdesc function
 *      @pre    Parameter: a space id, a valid gdesc for each row
 *      @post   Returns: must return 0 for the string comparison
 */
void test1_space_get_gdesc1();
/**
 *      @test   Tests the return the second row of gdesc function
 *      @pre    Parameter: a space id, a valid gdesc for each row
 *      @post   Returns:must return 0 for the string comparison
 */
void test1_space_get_gdesc2();
/**
 *      @test   Tests the return the third row of gdesc function
 *      @pre    Parameter: a space id, a valid gdesc for each row
 *      @post   Returns:must return 0 for the string comparison
 */

void test1_space_get_gdesc3();





/**
 *      @test   Tests the return the first row of gdesc function
 *      @pre    Parameter: a NULL space pointer, a gdesc row and a position
 *      @post   Returns: must return NULL
 */
void test2_space_get_gdesc1();
/**
 *      @test   Tests the return the second row of gdesc function
 *      @pre    Parameter: a NULL space pointer, a gdesc row and a position
 *      @post   Returns: must return NULL
 */
void test2_space_get_gdesc2();
/**
 *      @test   Tests the return the first row of gdesc function
 *      @pre    Parameter: a NULL space pointer, a gdesc row and a position
 *      @post   Returns: must return NULL
 */
void test2_space_get_gdesc3();



/**
 *      @test   Tests the return the space's description function
 *      @pre    Parameter: a NULL space pointer
 *      @post   Returns: must return NULL
 */
void test1_space_get_description();
/**
 *      @test   Tests the return the space's description function
 *      @pre    Parameter: a space id and a space description
 *      @post   Returns: must return 0 as the result of the string comparison 
 */
void test2_space_get_description();

/**
 *      @test   Tests the inquiry if there's an object in space
 *      @pre    Parameter: a space id and an object id
 *      @post   Returns: must return something that's not TRUE
 */
void test1_space_object_is_in();
/**
 *      @test   Tests the inquiry if there's an object in space
 *      @pre    Parameter: a NULL space pointer and NO_ID as the object's id
 *      @post   Returns: must return FALSE
 */
void test2_space_object_is_in();

/**
 *      @test   Tests the assign a detail description to the space function
 *      @pre    Parameter: a NULL space pointer
 *      @post   Returns: must return ERROR
 */
void test1_space_set_detail_description();

/**
 *      @test   Tests the assign a detail description to the space function
 *      @pre    Parameter: a space id and a NULL description
 *      @post   Returns: must return ERROR
 */
void test2_space_set_detail_description();

/**
 *      @test   Tests the return the space's detail description function
 *      @pre    Parameter: a NULL space pointer
 *      @post   Returns: must return NULL
 */
void test1_space_get_detail_description();

/**
 *      @test   Tests the return the space's detail description function
 *      @pre    Parameter: a space id and a space description
 *      @post   Returns: must return 0 as the result of the string comparison 
 */
void test2_space_get_detail_description();

/**
 *      @test   Tests the assign an illumination to the space function
 *      @pre    Parameter: a null space pointer
 *      @post   Returns: must return NULL
 */
void test1_space_set_illuminated();

/**
 *      @test   Tests the assign an illumination to the space function
 *      @pre    Parameter: 
 *      @post   Returns: must return OK
 */
void test2_space_set_illuminated();

/**
 *      @test   Tests the return the space's illumination function
 *      @pre    Parameter: a null space pointer
 *      @post   Returns: must return NULL
 */
void test1_space_get_illuminated();

/**
 *      @test   Tests the return the space's illumination function
 *      @pre    Parameter: 
 *      @post   Returns: must return 0 as the result of the string comparison 
 */
void test2_space_get_illuminated();

/**
 *      @test   Tests the assign an up link to the space function
 *      @pre    Parameter: a null space pointer
 *      @post   Returns: must return ERROR
 */
void test1_space_set_up_link();

/**
 *      @test   Tests the assign an up link to the space function
 *      @pre    Parameter: 
 *      @post   Returns: must return OK
 */
void test2_space_set_up_link();

/**
 *      @test   Tests the assign an down link to the space function
 *      @pre    Parameter: a null space pointer
 *      @post   Returns: must return NULL
 */
void test1_space_set_down_link();

/**
 *      @test   Tests the assign the down link to the space function
 *      @pre    Parameter: 
 *      @post   Returns: must return ERROR
 */
void test2_space_set_down_link();

/**
 *      @test   Tests the return the up space's link function
 *      @pre    Parameter: a null space pointer
 *      @post   Returns: must return NULL
 */
void test1_space_get_up_link();

/**
 *      @test   Tests the return the up space's link function
 *      @pre    Parameter: 
 *      @post   Returns: must return OK
 */
void test2_space_get_up_link();

/**
 *      @test   Tests the return the down space's link function
 *      @pre    Parameter: a null space pointer
 *      @post   Returns: must return NULL
 */
void test1_space_get_down_link();

/**
 *      @test   Tests the return the down space's link function
 *      @pre    Parameter: 
 *      @post   Returns: must return the Id 
 */
void test2_space_get_down_link();

#endif