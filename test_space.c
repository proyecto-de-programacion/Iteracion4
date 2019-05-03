/**
 * @brief Tests the space module
 * 
 * @file   test_space.c
 * @author Alexandra Conache
 * @version 1.0
 * @date 08/04/2019
 *   
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#include "../include/space.h"
#include "../include/test_space.h"
#include "../include/test.h"

#define MAX_TESTS 69 /*!< Maximum number of tests */
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
        printf("Running all test for module Space:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 && test > MAX_TESTS) {
            printf("Error: unknown test %d\t", test);
            exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_space_create();
    if (all || test == 2) test2_space_create();
    if (all || test == 3) test1_space_set_name();
    if (all || test == 4) test2_space_set_name();
    if (all || test == 5) test3_space_set_name();
    if (all || test == 6) test1_space_set_north_link();
    if (all || test == 7) test2_space_set_north_link();
    if (all || test == 8) test3_space_set_north_link();
    if (all || test == 9) test1_space_set_south_link();
    if (all || test == 10) test2_space_set_south_link();
    if (all || test == 11) test3_space_set_south_link();
    if (all || test == 12) test1_space_set_east_link();
    if (all || test == 13) test2_space_set_east_link();
    if (all || test == 14) test3_space_set_east_link();
    if (all || test == 15) test1_space_set_west_link();
    if (all || test == 16) test2_space_set_west_link();
    if (all || test == 17) test3_space_set_west_link();
    if (all || test == 18) test1_space_get_id();
    if (all || test == 19) test2_space_get_id();
    if (all || test == 20) test1_space_set_object();
    if (all || test == 21) test2_space_set_object();
    if (all || test == 22) test1_space_get_name();
    if (all || test == 23) test2_space_get_name();
    if (all || test == 24) test1_space_get_north_link();
    if (all || test == 25) test2_space_get_north_link();
    if (all || test == 26) test1_space_get_south_link();
    if (all || test == 27) test2_space_get_south_link();
    if (all || test == 28) test1_space_get_east_link();
    if (all || test == 29) test2_space_get_east_link();
    if (all || test == 30) test1_space_get_west_link();
    if (all || test == 31) test2_space_get_west_link();
    if (all || test == 34) test1_space_set_description();
    if (all || test == 35) test2_space_set_description();
    if (all || test == 36) test3_space_set_description();
    if (all || test == 37) test1_space_del_object();
    if (all || test == 38) test2_space_del_object();
    if (all || test == 39) test3_space_del_object();
    if (all || test == 40) test4_space_del_object();
    if (all || test == 41) test1_space_set_gdesc();
    if (all || test == 42) test2_space_set_gdesc();
    if (all || test == 43) test3_space_set_gdesc();
    if (all || test == 44) test1_space_get_gdesc1();
    if (all || test == 45) test2_space_get_gdesc1();
    if (all || test == 46) test1_space_get_description();
    if (all || test == 47) test2_space_get_description();
    if (all || test == 48) test1_space_object_is_in();
    if (all || test == 49) test2_space_object_is_in();
    if (all || test == 50) test1_space_get_gdesc2();
    if (all || test == 51) test2_space_get_gdesc2();
    if (all || test == 52) test1_space_get_gdesc3();
    if (all || test == 53) test2_space_get_gdesc3();
    if (all || test == 54) test1_space_set_detail_description();
    if (all || test == 55) test2_space_set_detail_description();
    if (all || test == 56) test1_space_get_detail_description();
    if (all || test == 57) test2_space_get_detail_description();
    if (all || test == 58) test1_space_set_illuminated();
    if (all || test == 59) test1_space_set_illuminated();
    if (all || test == 60) test1_space_get_illuminated();
    if (all || test == 61) test2_space_get_illuminated();
    if (all || test == 62) test1_space_set_up_link();
    if (all || test == 63) test2_space_set_up_link();
    if (all || test == 64) test1_space_set_down_link();
    if (all || test == 65) test2_space_set_down_link();
    if (all || test == 66) test1_space_get_up_link();
    if (all || test == 67) test2_space_get_up_link();
    if (all || test == 68) test1_space_get_down_link();
    if (all || test == 69) test2_space_get_down_link();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}
/*
 * 
 */
void test1_space_create() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(s != NULL);
  space_destroy(s);
}
/*
 * 
 */
void test2_space_create() {
    Space *s;
    s = space_create(4);
    PRINT_TEST_RESULT(space_get_id(s) == 4);
    space_destroy(s);
}

/*
 * 
 */
void test1_space_set_name() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_name(s, "hola") == OK);
    space_destroy(s);
}
/*
 * 
 */
void test2_space_set_name() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_name(s, "hola") == ERROR);
}
/*
 * 
 */
void test3_space_set_name() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_name(s, NULL) == ERROR);
    space_destroy(s);
}
/*
 * 
 */
void test1_space_set_north_link() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_north_link(s, 4) == OK);
    space_destroy(s);
}
/*
 * 
 */
void test2_space_set_north_link() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_north_link(s, 4) == ERROR);
}
/*
 * 
 */
void test3_space_set_north_link() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_north_link(s, NO_ID) == ERROR);
    space_destroy(s);
}
/*
 * 
 */
void test1_space_set_south_link() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_south_link(s, 4) == OK);
    space_destroy(s);
}
/*
 * 
 */
void test2_space_set_south_link() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_south_link(s, 4) == ERROR);
}
/*
 * 
 */
void test3_space_set_south_link() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_south_link(s, NO_ID) == ERROR);
    space_destroy(s);
}
/*
 * 
 */
void test1_space_set_east_link() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_east_link(s, 4) == OK);
    space_destroy(s);
}
/*
 * 
 */
void test2_space_set_east_link() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_east_link(s, 4) == ERROR);
}
/*
 * 
 */
void test3_space_set_east_link() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_east_link(s, NO_ID) == ERROR);
    space_destroy(s);
}
/*
 * 
 */
void test1_space_set_west_link() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_west_link(s, 4) == OK);
    space_destroy(s);
}
/*
 * 
 */
void test2_space_set_west_link() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_west_link(s, 4) == ERROR);
}
/*
 * 
 */
void test3_space_set_west_link() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_west_link(s, NO_ID) == ERROR);
    space_destroy(s);
}
/*
 * 
 */
void test1_space_get_id() {
    Space *s;
    s = space_create(25);
    PRINT_TEST_RESULT(space_get_id(s) == 25);
    space_destroy(s);
}
/*
 * 
 */
void test2_space_get_id() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_id(s) == NO_ID);
}
/*
 * 
 */
void test1_space_set_object() {
    Space *s;
    s = space_create(1);
    PRINT_TEST_RESULT(space_set_object(s, 8) == OK);
    space_destroy(s);
}
/*
 * 
 */
void test2_space_set_object() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_object(s, 5) == ERROR);
}
/*
 * 
 */
void test1_space_get_name() {
    Space *s;
    s = space_create(1);
    space_set_name(s, "adios");
    PRINT_TEST_RESULT(strcmp(space_get_name(s), "adios") == 0);
    space_destroy(s);

}
/*
 * 
 */
void test2_space_get_name() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_name(s) == NULL);

}
/*
 * 
 */
void test1_space_get_north_link() {
    Space *s;
    s = space_create(5);
    space_set_north_link(s, 4);
    PRINT_TEST_RESULT(space_get_north_link(s) == 4);
    space_destroy(s);
}
/*
 * 
 */
void test2_space_get_north_link() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_north_link(s) == NO_ID);
}
/*
 * 
 */
void test1_space_get_south_link() {
    Space *s;
    s = space_create(5);
    space_set_south_link(s, 2);
    PRINT_TEST_RESULT(space_get_south_link(s) == 2);
    space_destroy(s);
}
/*
 * 
 */
void test2_space_get_south_link() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_south_link(s) == NO_ID);
}
/*
 * 
 */
void test1_space_get_east_link() {
    Space *s;
    s = space_create(5);
    space_set_east_link(s, 1);
    PRINT_TEST_RESULT(space_get_east_link(s) == 1);
    space_destroy(s);
}
/*
 * 
 */
void test2_space_get_east_link() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_east_link(s) == NO_ID);
}
/*
 * 
 */
void test1_space_get_west_link() {
    Space *s;
    s = space_create(5);
    space_set_west_link(s, 6);
    PRINT_TEST_RESULT(space_get_west_link(s) == 6);
    space_destroy(s);
}
/*
 * 
 */
void test2_space_get_west_link() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_west_link(s) == NO_ID);
}

/*
 * 
 */
void test1_space_set_description() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_description(s, "Estás en una oca") == ERROR);
}
/*
 * 
 */
void test2_space_set_description() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_description(s, NULL) == ERROR);
    space_destroy(s);
}
/*
 * 
 */
void test3_space_set_description() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_description(s, "Estás en el puente") == OK);
    space_destroy(s);
}
/*
 * 
 */
void test1_space_del_object() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_del_object(s, 4) == ERROR);
}
/*
 * 
 */
void test2_space_del_object() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_del_object(s, 4) == ERROR);
    space_destroy(s);
}
/*
 * 
 */
void test3_space_del_object() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_del_object(s, NO_ID) == ERROR);
    space_destroy(s);
}
/*
 * 
 */
void test4_space_del_object() {
    Space *s;
    s = space_create(5);
    space_set_object(s, 4);
    PRINT_TEST_RESULT(space_del_object(s, 4) == OK);
    space_destroy(s);
}
/*
 * 
 */
void test1_space_set_gdesc() {
    Space *s = NULL;
    char gdesc[ROWS][COLUMNS];

    strcpy(gdesc[0], "       ");
    strcpy(gdesc[1], "       ");
    strcpy(gdesc[2], "       ");
    PRINT_TEST_RESULT(space_set_gdesc(s, gdesc[2],3) == ERROR);
}
/*
 * 
 */
void test2_space_set_gdesc() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_gdesc(s, NULL,0) == ERROR);
    space_destroy(s);
}
/*
 * 
 */
void test3_space_set_gdesc() {
    Space *s;
    char gdesc[ROWS][COLUMNS];

    s = space_create(5);
    strcpy(gdesc[0], "       ");
    strcpy(gdesc[1], "       ");
    strcpy(gdesc[2], "       ");
    PRINT_TEST_RESULT(space_set_gdesc(s, gdesc[2],0) == OK);
    space_destroy(s);
}
/*
 * 
 */
void test1_space_get_gdesc1() {
    Space *s;
    char gdesc[ROWS][COLUMNS];
    int i = 0;

    for( i = 0; i < ROWS; i++){
        gdesc[i][0] = '\0';
    }

    s = space_create(5);
    strcpy(gdesc[0], "       ");
    strcpy(gdesc[1], "       ");
    strcpy(gdesc[2], "       ");
    space_set_gdesc(s, gdesc[0],0);
    PRINT_TEST_RESULT(strncmp(space_get_gdesc1(s), gdesc[0], 7) == 0);
    space_destroy(s);
}
/*
 * 
 */
void test2_space_get_gdesc1() {
    Space *s = NULL;
    char gdesc[ROWS][COLUMNS];

    strcpy(gdesc[0], "       ");
    strcpy(gdesc[1], "       ");
    strcpy(gdesc[2], "       ");
    space_set_gdesc(s, gdesc[0],0);
    PRINT_TEST_RESULT(space_get_gdesc1(s) == NULL);
}

/*
 * 
 */
void test1_space_get_description() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_description(s) == NULL);
}
/*
 * 
 */
void test2_space_get_description() {
    Space *s;
    s = space_create(5);
    space_set_description(s, "Has muerto");
    PRINT_TEST_RESULT(strcmp(space_get_description(s), "Has muerto") == 0);
    space_destroy(s);
}

/*
 * 
 */
void test1_space_object_is_in(){
    Space *s = NULL;
    s = space_create(2);

    PRINT_TEST_RESULT(space_object_is_in(s,1) != TRUE);
    space_destroy(s);
}
/*
 * 
 */
void test2_space_object_is_in(){
    Space *s = NULL;

    PRINT_TEST_RESULT(space_object_is_in(s,NO_ID) == FALSE);
}

/*
 * 
 */
void test1_space_get_gdesc2() {
    Space *s;
    char gdesc[ROWS][COLUMNS];

    s = space_create(5);
    strcpy(gdesc[0], "       ");
    strcpy(gdesc[1], "       ");
    strcpy(gdesc[2], "       ");
    space_set_gdesc(s, gdesc[1],1);
    PRINT_TEST_RESULT(strncmp(space_get_gdesc2(s), gdesc[1],7) == 0);
    space_destroy(s);
}
/*
 * 
 */
void test2_space_get_gdesc2() {
    Space *s = NULL;
    char gdesc[ROWS][COLUMNS];

    strcpy(gdesc[0], "       ");
    strcpy(gdesc[1], "       ");
    strcpy(gdesc[2], "       ");
    space_set_gdesc(s, gdesc[1],1);
    PRINT_TEST_RESULT(space_get_gdesc2(s) == NULL);
}

/*
 * 
 */
void test1_space_get_gdesc3() {
    Space *s;
    char gdesc[ROWS][COLUMNS];

    s = space_create(5);
    strcpy(gdesc[0], "       ");
    strcpy(gdesc[1], "       ");
    strcpy(gdesc[2], "       ");
    space_set_gdesc(s, gdesc[2],2);
    PRINT_TEST_RESULT(strncmp(space_get_gdesc3(s), gdesc[2],7) == 0);
    space_destroy(s);
}
/*
 * 
 */
void test2_space_get_gdesc3() {
    Space *s = NULL;
    char gdesc[ROWS][COLUMNS];

    strcpy(gdesc[0], "       ");
    strcpy(gdesc[1], "       ");
    strcpy(gdesc[2], "       ");
    space_set_gdesc(s, gdesc[2],2);
    PRINT_TEST_RESULT(space_get_gdesc3(s) == NULL);
}

/*
 * 
 */
void test1_space_set_detail_description(){
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_detail_description(s, ------) == ERROR);
    
}

/*
 * 
 */
void test2_space_set_detail_description(){
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_detail_description(s,--------) == OK);
    space_destroy(s);
    
}

/*
 * 
 */
void test1_space_get_detail_description(){
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_detail_description(s) == NULL);
}

/*
 * 
 */
void test2_space_get_detail_description(){
    Space *s;
    s = space_create(5);
    space_set_description(s, -------);
    PRINT_TEST_RESULT(strcmp(space_get_detail_description(s), -----) == 0);
    space_destroy(s);
}

/*
 * 
 */
void test1_space_set_illuminated(){
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_illuminated(s, ---) == ERROR);   
}

/*
 * 
 */
void test2_space_set_illuminated(){
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_illuminated(s, NULL) == ERROR);
    space_destroy(s);
}

/*
 * 
 */
void test1_space_get_illuminated(){
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_illuminated(s) == NULL);
}

/*
 * 
 */
void test2_space_get_illuminated(){
    Space *s;
    s = space_create(5);
    space_set_description(s, ---);
    PRINT_TEST_RESULT(strcmp(space_get_illuminated(s), ---) == 0);
    space_destroy(s);
}

/*
 * 
 */
void test1_space_set_up_link(){
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_up_link(s, 4) == ERROR);
}

/*
 * 
 */
void test2_space_set_up_link(){
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_up_link(s, 4) == ERROR);
    space_destroy(s);
}

/*
 * 
 */
void test1_space_set_down_link(){
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_down_link(s, ---) == OK);
    space_destroy(s);
}

/*
 * 
 */
void test2_space_set_down_link(){
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_down_link(s, -----) == ERROR);
}

/*
 * 
 */
void test1_space_get_up_link(){
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_up_link(s, ---) == ERROR);
}

/*
 * 
 */
void test2_space_get_up_link(){
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_get_up_link(s, ---) == ERROR);
    space_destroy(s);
}

/*
 * 
 */
void test1_space_get_down_link(){
    Space *s;
    s = space_create(5);
    space_set_down_link(s, 6);
    PRINT_TEST_RESULT(space_get_down_link(s) == 6);
    space_destroy(s);
}

/*
 * 
 */
void test2_space_get_down_link(){
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_down_link(s) == NO_ID);
}


/*
*       THE END... for now
*/