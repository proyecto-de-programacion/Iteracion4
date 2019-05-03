/**
 * @brief Tests the object module
 * 
 * @file   test_object.c
 * @author Alexandra Conache
 * @version 1.0
 * @date 08/04/2019
 *   
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/object.h"
#include "../include/test_object.h"
#include "../include/test.h"

#define MAX_TESTS 32 /*!< Maximum number of tests */
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
        printf("Running all test for module Object:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 && test > MAX_TESTS) {
            printf("Error: unknown test %d\t", test);
            exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_object_create();
    if (all || test == 2) test2_object_create();
    if (all || test == 3) test1_object_get_id();
    if (all || test == 4) test2_object_get_id();
    if (all || test == 5) test1_object_set_name();
    if (all || test == 6) test2_object_set_name();
    if (all || test == 7) test1_object_set_description();
    if (all || test == 8) test2_object_set_description();
    if (all || test == 9) test1_object_get_name();
    if (all || test == 10) test2_object_get_name();
    if (all || test == 11) test1_object_get_description();
    if (all || test == 12) test2_object_get_description();
    if (all || test == 13) test1_object_set_movable();
    if (all || test == 14) test2_object_set_movable();
    if (all || test == 15) test1_object_get_movable();
    if (all || test == 16) test2_object_get_movable();
    if (all || test == 17) test1_object_set_moved(); 
    if (all || test == 18) test2_object_set_moved();
    if (all || test == 19) test1_object_get_moved();
    if (all || test == 20) test2_object_get_moved();
    if (all || test == 21) test1_object_set_original_location();
    if (all || test == 22) test2_object_set_original_location();
    if (all || test == 23) test1_object_get_original_location();
    if (all || test == 24) test2_object_get_original_location();
    if (all || test == 25) test1_object_set_hidden();
    if (all || test == 26) test2_object_set_hidden();
    if (all || test == 27) test1_object_get_hidden();
    if (all || test == 28) test2_object_get_hidden();
    if (all || test == 29) test1_object_set_moved_description();
    if (all || test == 30) test2_object_set_moved_description();
    if (all || test == 31) test1_object_get_moved_description();
    if (all || test == 32) test2_object_get_moved_description();
    if (all || test == 33) test1_object_set_open_link();
    if (all || test == 34) test2_object_set_open_link();
    if (all || test == 35) test1_object_get_open_link();
    if (all || test == 36) test2_object_get_open_link();
    if (all || test == 37) test1_object_get_illuminate();
    if (all || test == 38) test2_object_get_illuminate();
    if (all || test == 39) test1_object_set_illuminate();
    if (all || test == 40) test2_object_set_illuminate();
    if (all || test == 41) test1_object_get_turnedon();
    if (all || test == 42) test2_object_get_turnedon();
    if (all || test == 43) test1_object_set_turnedon();
    if (all || test == 44) test2_object_set_turnedon();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}
/*
 *      First object_create test
 */
void test1_object_create(){
    Object *o =NULL;

    o = object_create(3);

    PRINT_TEST_RESULT(o != NULL);
    object_destroy(o);
}

/*
 *      Second object_create test
 */
void test2_object_create(){
    Object *o = NULL;

    o = object_create(9);

    PRINT_TEST_RESULT(object_get_id(o) == 9);
    object_destroy(o);
} 

/*
 *      First object_get_id test
 */
void test1_object_get_id(){
    Object *o = NULL;

    o = object_create(27);

    PRINT_TEST_RESULT(object_get_id(o) == 27);
    object_destroy(o);
}

/*
 *      Second object_get_id test
 */
void test2_object_get_id(){
    Object *o = NULL;

    PRINT_TEST_RESULT(object_get_id(o) == NO_ID);
} 

/*
 *      First object_set_name test
 */
void test1_object_set_name(){
    Object *o = NULL;
    o = object_create(1);
    PRINT_TEST_RESULT(object_set_name(o,"DAB") == OK);
    object_destroy(o);
} 

/*
 *      Second object_set_name test
 */
void test2_object_set_name(){
    Object *o = NULL;
    PRINT_TEST_RESULT(object_set_name(o,"DAB") == ERROR);

}
/*
 *      First object_set_description test
 */
void test1_object_set_description(){
    Object *o =NULL;
    o = object_create(1);
    PRINT_TEST_RESULT(object_set_description(o,"Objeto fabuloso") == OK);
    object_destroy(o);
}

/*
 *      Second object_set_description test
 */
void test2_object_set_description(){
    Object *o =NULL;
    PRINT_TEST_RESULT(object_set_description(o,"Objeto roto") != OK);

}

/* 
 *      First object_get_name test
 */
void test1_object_get_name(){
    Object *o = NULL;
    o = object_create(1);
    object_set_name(o,"DAB");
    PRINT_TEST_RESULT(strcmp(object_get_name(o),"DAB") == 0);
    object_destroy(o);
}
/*
 *      Second object_get_name test
 */
void test2_object_get_name(){
    Object *o = NULL;
    PRINT_TEST_RESULT(object_get_name(o)==NULL);
}

/*
 *      First object_get_description test
 */

void test1_object_get_description(){
    Object *o = NULL;
    o = object_create(1);
    object_set_description(o,"Objeto Fabuloso");
    PRINT_TEST_RESULT(strcmp(object_get_description(o),"Objeto Fabuloso")==0);
    object_destroy(o);
}

/*
 *      Second object_get_description test
 */
void test2_object_get_description(){
    Object *o = NULL;
    PRINT_TEST_RESULT(object_get_description(o) == NULL);
}
/*
 *      NEW TESTS I4
 *
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
void test1_object_set_movable(){
    Object *o = NULL;
    o = object_create(1);
    PRINT_TEST_RESULT(object_set_movable(o,TRUE) == OK);
    object_destroy(o);
}
void test2_object_set_movable(){
    Object *o = NULL;

    PRINT_TEST_RESULT(object_set_movable(o,TRUE) == ERROR);
}
void test1_object_get_movable(){
    Object *o = NULL;
    o = object_create(2);
    object_set_movable(o,TRUE);
    PRINT_TEST_RESULT(object_get_movable(o)==TRUE);
    object_destroy(o);
}
void test2_object_get_movable(){
    Object *o = NULL;
    PRINT_TEST_RESULT(object_get_movable(o)==FALSE);
}
void test1_object_set_moved(){
    Object *o = NULL;
    o = object_create(1);
    PRINT_TEST_RESULT(object_set_moved(o,4) == OK);
    object_destroy(o);
} 
void test2_object_set_moved(){
    Object *o = NULL;
    PRINT_TEST_RESULT(object_set_moved(o,2) == ERROR);
}
void test1_object_get_moved(){
    Object *o = NULL;
    o = object_create(2);
    object_set_original_location(o,2);
    object_set_moved(o,2);
    PRINT_TEST_RESULT(object_get_moved(o) == TRUE);
    object_destroy(o);
}
void test2_object_get_moved(){
    Object *o = NULL;
    PRINT_TEST_RESULT(object_get_moved(o)==FALSE);

}
void test1_object_set_original_location(){
    Object *o = NULL;
    o = object_create(1);
    PRINT_TEST_RESULT(object_set_original_location(o,2) == OK);
    object_destroy(o);
}
void test2_object_set_original_location(){
    Object *o = NULL;
    PRINT_TEST_RESULT(object_set_original_location(o,1) == ERROR);
}
void test1_object_get_original_location(){
    Object *o = NULL;
    o = object_create(1);
    object_set_original_location(o,2);
    PRINT_TEST_RESULT(object_get_original_location(o) == 2);
    object_destroy(o);
}
void test2_object_get_original_location(){
    Object *o = NULL;
    PRINT_TEST_RESULT(object_get_original_location(o) == NO_ID);
}
void test1_object_set_hidden(){
    Object *o = NULL;
    o = object_create(1);
    PRINT_TEST_RESULT(object_set_hidden(o,TRUE) == OK);
    object_destroy(o);
}
void test2_object_set_hidden(){
    Object *o = NULL;
    PRINT_TEST_RESULT(object_set_hidden(o,FALSE)==ERROR);
}
void test1_object_get_hidden(){
    Object *o = NULL;
    o = object_create(1);
    object_set_hidden(o,TRUE);
    PRINT_TEST_RESULT(object_get_hidden(o)==TRUE);
    object_destroy(o);

}
void test2_object_get_hidden(){
    Object *o = NULL;
    PRINT_TEST_RESULT(object_get_hidden(o) == FALSE);
}
void test1_object_set_moved_description(){
    Object *o = NULL;
    o = object_create(1);
    PRINT_TEST_RESULT(object_set_moved_description(o,"Not today") == OK);
    object_destroy(o);
}
void test2_object_set_moved_description(){
    Object *o = NULL;
    PRINT_TEST_RESULT(object_set_moved_description(o,"Oh no") == ERROR);
}
void test1_object_get_moved_description(){
    Object *o = NULL;
    o = object_create(2);
    object_set_moved_description(o,"Not today");
    PRINT_TEST_RESULT(strcmp(object_get_moved_description(o),"Not today") == 0);
    object_destroy(o);

}
void test2_object_get_moved_description(){
    Object *o = NULL;
    PRINT_TEST_RESULT(strcmp(object_get_moved_description(o),"Not today") != 0);
}

void test1_object_set_open_link(){
    Object *o = NULL;
    o = object_create(2);
    PRINT_TEST_RESULT(object_set_open_link(o, 4) == OK);
    object_destroy(o);
}

void test2_object_set_open_link(){
    Object *o = NULL;
    PRINT_TEST_RESULT(object_set_open_link(o, 4) == ERROR);
}

void test1_object_get_open_link(){
    Object *o = NULL;
    o = object_create(2);
    object_set_open_link(o, 4);
    PRINT_TEST_RESULT(object_get_open_link(o, 14) == 14);
    object_destroy(o);
}

void test2_object_get_open_link(){
    Object *o = NULL;
    PRINT_TEST_RESULT(object_get_open_link(o, 4) == NO_ID);
}

void test1_object_get_illuminate(){
    Object *o = NULL;
    o = object_create(2);
    object_set_illuminate(o, TRUE);
    PRINT_TEST_RESULT(object_get_illuminate(o) == TRUE);
    object_destroy(o);
}

void test2_object_get_illuminate(){
    Object *o = NULL;
    PRINT_TEST_RESULT(object_get_illuminate(o) == FALSE);
}

void test1_object_set_illuminate(){
    Object *o = NULL;
    o = object_create(2);
    PRINT_TEST_RESULT(object_set_illuminate(o, FALSE) == OK);
    object_destroy(o);
}

void test2_object_set_illuminate(){
    Object *o = NULL;
    PRINT_TEST_RESULT(object_set_illuminate(o, TRUE) == ERROR);
}

void test1_object_get_turnedon(){
    Object *o = NULL;
    o = object_create(2);
    object_set_illuminate(o, TRUE);
    object_set_turnedon(o, TRUE);
    PRINT_TEST_RESULT(object_get_turnedon(o) == TRUE);
    object_destroy(o);
}

void test2_object_get_turnedon(){
    Object *o = NULL;
    PRINT_TEST_RESULT(object_get_turnedon(o) == FALSE);
}

void test1_object_set_turnedon(){
    Object *o = NULL;
    o = object_create(2);
    object_set_illuminate(o, TRUE);
    PRINT_TEST_RESULT(object_set_turnedon(o, TRUE) == OK);
    object_destroy(o);
}

void test2_object_set_turnedon(){
    Object *o = NULL;
    PRINT_TEST_RESULT(object_set_turnedon(o, TRUE) == ERROR);
}
/*
 *      THE END 
 */
