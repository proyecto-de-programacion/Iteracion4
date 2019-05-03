/** 
 * @test It declares the tests for the command module
 * 
 * @file test_command.h
 * @author Alexandra Conache
 * @version 2.0 
 * @date 09/04/2019
 * @copyright GNU Public License
 */

#ifndef TEST_DIE_H
#define TEST_DIE_H
/**
 *  @test Tests the create a command function
 *  @pre Parameters: a non-NULL command pointer
 *  @post Return: something that's not NULL
 */
void test1_command_create();
/**
 *  @test Tests the create a command function
 *  @pre Parameters: a NULL command pointer
 *  @post Return: must return NULL
 */
void test2_command_create();

/**
 *  @test Tests the set a name to the command function
 *  @pre Parameters: the command created and a name for it
 *  @post Return: must return something other than NULL
 */
void test1_command_set_name();
/**
 *  @test Tests the set a name to the command function
 *  @pre Parameters: a NULL command pointer and a name for it
 *  @post Return: must return NULL
 */
void test2_command_set_name();



/**
 *  @test Tests the return the command's name function
 *  @pre Parameters: a non-NULL command pointer and a name for it
 *  @post Return: the string comparison must return 0
 */
void test1_command_get_name();
/**
 *  @test Tests the return the command's name function
 *  @pre Parameters: a non_NULL command pointer and a NULL name for it
 *  @post Return: must return something other than 0 for the string comparison
 */
void test2_command_get_name();

/**
 *  @test Tests the set a link_name to the command function
 *  @pre Parameters: the command created and a name for it
 *  @post Return: must return something other than NULL
 */
void test1_command_set_link_name();
/**
 *  @test Tests the set a link_name to the command function
 *  @pre Parameters: a NULL command pointer and a name for it
 *  @post Return: must return NULL
 */
void test2_command_set_link_name();

/**
 *  @test Tests the return the command's name link function
 *  @pre Parameters: a non-NULL command pointer and a name for it
 *  @post Return: the string comparison must return 0
 */
void test1_command_get_link_name();
/**
 *  @test Tests the return the command's name link function
 *  @pre Parameters: a non_NULL command pointer and a NULL name for it
 *  @post Return: must return something other than 0 for the string comparison
 */
void test2_command_get_link_name();
#endif