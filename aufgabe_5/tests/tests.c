/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Test suite for the given package.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "test_utils.h"

#include "person.h"
#include "list.h"
#include "person.c"
#include "list.c"

#ifndef TARGET // must be given by the make file --> see test target
#error missing TARGET define
#endif

/// @brief The name of the STDOUT text file.
#define OUTFILE "stdout.txt"
/// @brief The name of the STDERR text file.
#define ERRFILE "stderr.txt"

// Test input files
#define INFILE_NORMAL_USECASE "normal.input"

// setup & cleanup
static int setup(void)
{
    initList();
	remove_file_if_exists(OUTFILE);
	remove_file_if_exists(ERRFILE);
	return 0; // success
}

static int teardown(void)
{
	// Do nothing.
	// Especially: do not remove result files - they are removed in int setup(void) *before* running a test.
	return 0; // success
}

static void test_clearList(){
    // setup
    Person person = {"Meier","Robert",50};
    // act
    clearList();
    // assert
    CU_ASSERT_TRUE(isListEmpty());
}

static void test_addToList(){
    // setup
    Person person = {"Meier","Robert",50};
    // act
    addToList(person);
    // assert
    CU_ASSERT_FALSE(isListEmpty());
}

static void test_main(void)
{

    // arrange
    	const char *out_txt[] = {
    		"I(nsert), R(emove), S(how), C(lear), E(nd):\n",
    		"----------------------------------------------------\n",
    		"Enter Input:\n",
    		"----------------------------------------------------\n",
    		"Insert\n",
    		"----------------------------------------------------\n",
    		"First Name:Name:Age:\n",
    		"Add      Meier     Robert 30\n",
    		"----------------------------------------------------\n",
    		"Enter Input:\n",
    		"----------------------------------------------------\n",
                "Show\n",
    		"----------------------------------------------------\n",
                "1:      Meier     Robert	30\n",
    		"----------------------------------------------------\n",
    		"Enter Input:\n",
    	};

    	// act
    	int exit_code = system(XSTR(TARGET) " 1>" OUTFILE " 2>" ERRFILE " <" INFILE_NORMAL_USECASE);
    	// assert
    	CU_ASSERT_EQUAL(exit_code, 0);
    	assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}


/**
 * @brief Registers and runs the tests.
 */
int main(void)
{
	// setup, run, teardown
	// setup, run, teardown
    	TestMainBasic(
    	"Struct",
    	setup,
    	teardown,
    	test_addToList,
    	test_clearList,
    	test_main
    	);
}
