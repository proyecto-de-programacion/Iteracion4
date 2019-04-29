/**
 *      @brief Declares the tests for the object module
 * 
 *      @file test_object.h
 *      @author Alexandra Conache
 *      @version 1.0
 *      @date 08-04-2019
 * 
 * 
 */

#ifndef TEST_OBJECT_H
#define TEST_OBJECT_H


/**
 *      @test   Tests the object creation function
 *      @pre    Parameter: an Id
 *      @post   Return: a non NULL pointer to the object created
 */
void test1_object_create();
/**
 *      @test   Tests the object creation function
 *      @pre    Parameter: an Id
 *      @post   Return: the object's Id is the one we inputed
 */
void test2_object_create();
/**
 *      @test   Tests the return the object's id function
 *      @pre    Parameter: an Id
 *      @post   Return: the object's id is the one we inputed
 */
void test1_object_get_id();
/**
 *      @test   Tests the return the object's id function
 *      @pre    Parameter: NULL object
 *      @post   Return: the object has NO_ID assigned
 */
void test2_object_get_id();
/**
 *      @test   Tests the assign an object's name function
 *      @pre    Parameter: the name we want to assign
 *      @post   Return: has to be OK
 */
void test1_object_set_name();
/**
 *      @test   Tests the assign an object's name function
 *      @pre    Parameter: the name we want to assign
 *      @post   Return: has to be ERROR
 */
void test2_object_set_name();
/**
 *      @test   Tests the assign an object's description function
 *      @pre    Parameter: the description we want to assign
 *      @post   Return: has to be OK
 */
void test1_object_set_description();
/**
 *      @test   Tests the assign an object's description function
 *      @pre    Parameter: the description we want to assign
 *      @post   Return: has to be different than OK
 */
void test2_object_set_description();
/**
 *      @test   Tests the return an object's name function
 *      @pre    Parameter: the name we assigned to the object
 *      @post   Return: has to be 0 for the string comparison we did
 */
void test1_object_get_name();
/**
 *      @test   Tests the return an object's name function
 *      @pre    Parameter: a NULL object
 *      @post   Return: has to be NULL
 */
void test2_object_get_name();
/**
 *      @test   Tests the return an object's description function
 *      @pre    Parameter: the description we assigned to the object
 *      @post   Return: has to be 0 for the string comparison we did
 */
void test1_object_get_description();
/**
 *      @test   Tests the return an object's description function
 *      @pre    Parameter: a NULL object
 *      @post   Return: has to be NULL
 */
void test2_object_get_description();

/**
 *      @test Tests the assign an object the movable status true or false
 *      @pre  Parameter: an id for the object and a TRUE value for the function
 *      @post Return: must be OK
 */
void test1_object_set_movable();
/**
 *      @test Tests the assign an object the movable status true or false
 *      @pre  Parameter: TRUE as an argument for the function 
 *      @post Return: must be ERROR
 */
void test2_object_set_movable();
/**
 *      @test Tests the return whether the object is movable or not function
 *      @pre  Parameter: an Id for the object, TRUE as the set function argument
 *      @post Return: must be TRUE
 */
void test1_object_get_movable();
/**
 *      @test Tests the return whether the object is movable or not function
 *      @pre  Parameter: a NULL object
 *      @post Return: must be FALSE
 */
void test2_object_get_movable();
/**
 *      @test Tests the check if an object has been moved or not function
 *      @pre  Parameter: an Id for the object and an Id for the space it's from
 *      @post Return: must return OK
 */
void test1_object_set_moved(); 
/**
 *      @test Tests the check if an object has been moved or not function
 *      @pre  Parameter: 
 *      @post Return: must return ERROR
 */
void test2_object_set_moved();
/**
 *      @test
 *      @pre  Parameter: 
 *      @post Return:
 */
void test1_object_get_moved();
/**
 *      @test
 *      @pre  Parameter: 
 *      @post Return:
 */
void test2_object_get_moved();
/**
 *      @test
 *      @pre  Parameter: 
 *      @post Return:
 */
void test1_object_set_original_location();
/**
 *      @test
 *      @pre  Parameter: 
 *      @post Return:
 */
void test2_object_set_original_location();
/**
 *      @test
 *      @pre  Parameter: 
 *      @post Return:
 */
void test1_object_get_original_location();
/**
 *      @test
 *      @pre  Parameter: 
 *      @post Return:
 */
void test2_object_get_original_location();
/**
 *      @test
 *      @pre  Parameter: 
 *      @post Return:
 */
void test1_object_set_hidden();
/**
 *      @test
 *      @pre  Parameter: 
 *      @post Return:
 */
void test2_object_set_hidden();
/**
 *      @test
 *      @pre  Parameter: 
 *      @post Return:
 */
void test1_object_get_hidden();
/**
 *      @test
 *      @pre  Parameter: 
 *      @post Return:
 */
void test2_object_get_hidden();
/**
 *      @test
 *      @pre  Parameter: 
 *      @post Return:
 */
void test1_object_set_moved_description();
/**
 *      @test
 *      @pre  Parameter: 
 *      @post Return:
 */
void test2_object_set_moved_description();
/**
 *      @test
 *      @pre  Parameter: 
 *      @post Return:
 */
void test1_object_get_moved_description();
/**
 *      @test
 *      @pre  Parameter: 
 *      @post Return:
 */
void test2_object_get_moved_description();
#endif
