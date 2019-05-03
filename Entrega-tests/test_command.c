/**
 * @brief Tests the command module
 *
 * @file   test_command.c
 * @author Alexandra Conache
 * @version 1.0
 * @date 09/04/2019
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "../include/command.h"
#include "../include/test_command.h"
#include "../include/test.h"

#define MAX_TESTS 10 /*!< Maximum number of tests */
/**
 * @brief Runs the test
 * @param argc first argument
 * @param *argv[] second argument
 * 
 */
int main(int argc, char** argv) {

    int test = 0;
    int all = 1;

    if (argc < 2) {
        printf("Running all test for module Command:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 && test > MAX_TESTS) {
            printf("Error: unknown test %d\t", test);
            exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_command_create();
    if (all || test == 2) test2_command_create();
    if (all || test == 3) test1_command_set_name();
    if (all || test == 4) test2_command_set_name();
    if (all || test == 5) test1_command_get_name();
    if (all || test == 6) test2_command_get_name();
    if (all || test == 7) test1_command_set_link_name();
    if (all || test == 8) test2_command_set_link_name();
    if (all || test == 9) test1_command_get_link_name();
    if (all || test == 10) test2_command_get_link_name();
    /*!< We can't do a functional test of command_get_command and coomand_set_command */

    PRINT_PASSED_PERCENTAGE;

    return 1;
}
/*
 *
 */
void test1_command_create(){
    Command *c = NULL;
    c = command_create();
    PRINT_TEST_RESULT(c != NULL);
    command_destroy(c);
}
/*
 *
 */
void test2_command_create(){
    Command *c = NULL;

    PRINT_TEST_RESULT(c == NULL);
}
/*
 *
 */
void test1_command_set_name(){
    Command *c = NULL;
    c = command_create();
    PRINT_TEST_RESULT(command_set_name(c,"uwu") != NULL);
    command_destroy(c);
}
/*
 *
 */
void test2_command_set_name(){
    Command *c = NULL;
    PRINT_TEST_RESULT(command_set_name(c,"NULL") == NULL);
}
/*
 *
 */
void test1_command_get_name(){
    Command *c = NULL;
    c = command_create();
    command_set_name(c,"Dabs");
    PRINT_TEST_RESULT(strcmp(command_get_name(c), "Dabs") == 0);
    command_destroy(c);
}
/*
 *
 */
void test2_command_get_name(){
    Command *c = NULL;
    c = command_create();
    command_set_name(c,NULL);
    PRINT_TEST_RESULT(strcmp(command_get_name(c), "NULL") != 0);
    command_destroy(c);
}

/*
 *
 */
void test1_command_set_link_name(){
    Command *c = NULL;
    c = command_create();
    PRINT_TEST_RESULT(command_set_name(c,"uwu") != NULL);
    command_destroy(c);
}
/*
 *
 */
void test2_command_set_link_name(){
    Command *c = NULL;
    PRINT_TEST_RESULT(command_set_name(c,"NULL") == NULL);
}
/*
 *
 */
void test1_command_get_link_name(){
    Command *c = NULL;
    c = command_create();
    command_set_link_name(c,"Dabs");
    PRINT_TEST_RESULT(strcmp(command_get_link_name(c), "Dabs") == 0);
    command_destroy(c);
}
/*
 *
 */
void test2_command_get_link_name(){
    Command *c = NULL;
    c = command_create();
    command_set_link_name(c,NULL);
    PRINT_TEST_RESULT(strcmp(command_get_link_name(c), "NULL") != 0);
    command_destroy(c);
}
