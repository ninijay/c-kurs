#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "test_utils.h"
#ifndef TARGET
#error missing TARGET define
#endif

#define OUTFILE "stdout.txt"
#define ERRFILE "stderr.txt"

#define INPUT "normal.input"

// setup & cleanup
static int setup(void){
	remove_file_if_exists(OUTFILE);
	remove_file_if_exists(ERRFILE);
	return 0;
}

static int teardown(void){
	// do nothing
	return 0;
}

static void test_main(void){
	const char *out_txt[] = {
		"Bitte geben Sie die eine Liste von Worten ein.\nEinzelne wörter durch Return terminiert, Ende der Sequenz mit \"ZZZ\":\n",
		"a\nb\nc\nd\n"
	};

	//act
	int exit_code = system(XSTR(TARGET) " 1> " OUTFILE " 2> " ERRFILE " < " INPUT);
	//assert
	CU_ASSERT_EQUAL(exit_code, EXIT_SUCCESS);
	assert_lines(OUTFILE, out_txt, sizeof(out_txt)/sizeof(*out_txt));
}

/**
 * @brief run tests
 */
int main(void){
	TestMainBasic(
	"main",
	setup,
	teardown,
	test_main
	);
}
