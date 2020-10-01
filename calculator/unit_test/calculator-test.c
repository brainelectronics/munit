/* Example file for using µnit with the calculator example.
 *
 * µnit is MIT-licensed, but for this file and this file alone:
 *
 * To the extent possible under law, the author(s) of this file have
 * waived all copyright and related or neighboring rights to this
 * work.  See <https://creativecommons.org/publicdomain/zero/1.0/> for
 * details.
 *********************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "../../munit.h"
#include "../src/calculator.h"

/* This is just to disable an MSVC warning about conditional
 * expressions being constant, which you shouldn't have to do for your
 * code.  It's only here because we want to be able to do silly things
 * like assert that 0 != 1 for our demo. */
#if defined(_MSC_VER)
#pragma warning(disable: 4127)
#endif

//--------------------------------------------------------------------------------------------------
static MunitResult
test_abolut_truth(const MunitParameter params[], void* data) {
  // These are just to silence compiler warnings about the parameters
  // being unused.
  (void) params;
  (void) data;

  const unsigned char val_uchar = 'b';
  const short val_short = 1729;
  double pi = 3.141592654;
  char* stewardesses = "stewardesses";
  char* most_fun_word_to_type;

  // Let's start with the basics
  munit_assert(0 != 1);
  munit_assert_false(0);
  munit_assert_true(true);

  // this will let the test fail
  // munit_error("FAIL");
  // munit_errorf("Goodbye, cruel %s", "world");

  // by default everything of INFO or higher will be printed
  // Info: ../calculator/unit_test/calculator-test.c:47: Some INFO message to log
  // munit_log(MUNIT_LOG_DEBUG, "Some DEBUG message to log");
  // munit_log(MUNIT_LOG_INFO, "Some INFO message to log");
  // munit_log(MUNIT_LOG_WARNING, "Some WARNING message to log");

  // if set as ERROR level, the test will be marked as failed
  // munit_log(MUNIT_LOG_ERROR, "Some ERROR message to log");

  // There are macros for comparing lots of types
  // Error: ../calculator/unit_test/calculator-test.c:60: assertion failed: val_uchar == 'c' ('\x62' == '\x63')
  munit_assert_char('a', ==, 'a');
  munit_assert_uchar(val_uchar, ==, 'c');
  munit_assert_short(42, <, val_short);           // -128...127
  munit_assert_ushort(242, >, 12);                // 0...255 (2^8 -1)
  munit_assert_int(65530, <, 65631);              // -32768...32767
  munit_assert_uint(0, <, 65535);                 // 0...65535 (2^16 -1)
  munit_assert_long(-2147483647, <, 2147483647);  // -2147483648...2147483647
  munit_assert_ulong(4294967295, >, 0);           // 0...4294967295 (2^32 -1)
  munit_assert_llong(-9223372036854775800, <, 9223372036854775807);   // -9223372036854775808...9223372036854775807
  // munit_assert_ullong(18446744073709551610, >, 0);// 0...18446744073709551615 (2^64 -1)

  munit_assert_int8(-128, <, 127);
  munit_assert_uint8(255, >, 0);
  munit_assert_int16(-32768, <, 32767);
  munit_assert_uint16(65535, >, 0);
  munit_assert_int32(-2147483648, <, 2147483647);
  munit_assert_uint32(4294967295, >, 0);
  munit_assert_int64(-9223372036854775808, <, 9223372036854775807);
  munit_assert_uint64(18446744073709551610, >, 0);

  munit_assert_double(pi, ==, 3.141592654);
  munit_assert_float(1.23456789, <, 9.87654321);

  // compare values up to the given precision (10e-9)
  munit_assert_double_equal(3.141592654, 3.141592653589793, 9);

  munit_assert_size(strlen("uncopyrightables"), >, strlen("dermatoglyphics"));

  // String operations
  munit_assert_string_equal(stewardesses, "stewardesses");
  munit_assert_string_not_equal(stewardesses, "pilot");

  // Memory operations
  munit_assert_memory_equal(7, stewardesses, "steward");
  munit_assert_memory_not_equal(8, stewardesses, "steward");

  // Pointer operations
  most_fun_word_to_type = stewardesses;
  char *a_null_pointer = NULL;
  munit_assert_ptr(stewardesses, ==, most_fun_word_to_type);               // must be a pointer
  munit_assert_ptr_null(a_null_pointer);        // must be the NULL pointer
  munit_assert_null(NULL);                      // must be NULL
  munit_assert_not_null(most_fun_word_to_type); // must not be null
  munit_assert_ptr_equal(most_fun_word_to_type, stewardesses);
  munit_assert_ptr_not_null(stewardesses);      // must not be NULL

  // use provided data via _setup function
  munit_assert_ptr_equal(data, (void*)(uintptr_t)0xdeadbeef);
  munit_assert_ptr_not_equal(data, stewardesses);

  return MUNIT_OK;
}

/* The setup function, if you provide one, for a test will be run
 * before the test, and the return value will be passed as the sole
 * parameter to the test function. */
static void*
test_abolut_truth_setup(const MunitParameter params[], void* user_data) {
  (void) params;

  // munit_assert_string_equal(user_data, "µnit");
  return (void*) (uintptr_t) 0xdeadbeef;
}

/* To clean up after a test, you can use a tear down function.
 * The fixture argument is the value returned by the setup function above. */
static void
test_abolut_truth_tear_down(void* fixture) {
  munit_assert_ptr_equal(fixture, (void*)(uintptr_t)0xdeadbeef);
}

//--------------------------------------------------------------------------------------------------
static MunitResult
test_sum(const MunitParameter params[], void* data) {
  // These are just to silence compiler warnings about the parameters
  // being unused.
  (void) params;
  (void) data;

  int result = 0;

  // no number, only zero
  result = calc_sum(0, 0);
  munit_assert_int(result, ==, 0);

  // only one number and zero
  result = calc_sum(0, 1);
  munit_assert_int(result, ==, 1);

  result = calc_sum(4, 0);
  munit_assert_int(result, ==, 4);

  // two positive numbers
  result = calc_sum(3, 4);
  munit_assert_int(result, ==, 7);

  result = calc_sum(9, 7);
  munit_assert_int(result, ==, 16);

  // positive and negative number
  result = calc_sum(-3, 1);
  munit_assert_int(result, ==, -2);

  result = calc_sum(-9, 24);
  munit_assert_int(result, ==, 15);

  result = calc_sum(5, -10);
  munit_assert_int(result, ==, -5);

  result = calc_sum(60, -12);
  munit_assert_int(result, ==, 48);

  // two negative numbers
  result = calc_sum(-5, -8);
  munit_assert_int(result, ==, -13);

  result = calc_sum(-15, -2);
  munit_assert_int(result, ==, -17);

  // Let this test explicitly fail by uncommenting the next line
  // munit_assert_int(0, ==, 1);

  return MUNIT_OK;
}

//--------------------------------------------------------------------------------------------------
static MunitResult
test_difference(const MunitParameter params[], void* data) {
  // These are just to silence compiler warnings about the parameters
  // being unused.
  (void) params;
  (void) data;

  int result = 0;

  // no number, only zero
  result = calc_difference(0, 0);
  munit_assert_int(result, ==, 0);

  // only one number and zero
  result = calc_difference(0, 1);
  munit_assert_int(result, ==, -1);

  result = calc_difference(4, 0);
  munit_assert_int(result, ==, 4);

  // two positive numbers
  result = calc_difference(3, 4);
  munit_assert_int(result, ==, -1);

  result = calc_difference(9, 7);
  munit_assert_int(result, ==, 2);

  // positive and negative number
  result = calc_difference(-3, 1);
  munit_assert_int(result, ==, -4);

  result = calc_difference(5, -10);
  munit_assert_int(result, ==, 15);

  // two negative numbers
  result = calc_difference(-5, -8);
  munit_assert_int(result, ==, 3);

  result = calc_difference(-15, -2);
  munit_assert_int(result, ==, -13);

  return MUNIT_OK;
}

//--------------------------------------------------------------------------------------------------
static MunitResult
test_multiplication(const MunitParameter params[], void* data) {
  // These are just to silence compiler warnings about the parameters
  // being unused.
  (void) params;
  (void) data;

  int result = 0;

  // no number, only zero
  result = multiplication(0, 0);
  munit_assert_int(result, ==, 0);

  // only one number and zero
  result = multiplication(0, 1);
  munit_assert_int(result, ==, 0);

  result = multiplication(4, 0);
  munit_assert_int(result, ==, 0);

  // two positive numbers
  result = multiplication(3, 4);
  munit_assert_int(result, ==, 12);

  result = multiplication(9, 7);
  munit_assert_int(result, ==, 63);

  // positive and negative number
  result = multiplication(-3, 1);
  munit_assert_int(result, ==, -3);

  result = multiplication(5, -10);
  munit_assert_int(result, ==, -50);

  // two negative numbers
  result = multiplication(-5, -8);
  munit_assert_int(result, ==, 40);

  return MUNIT_OK;
}

//--------------------------------------------------------------------------------------------------
static MunitResult
test_division(const MunitParameter params[], void* data) {
  // These are just to silence compiler warnings about the parameters
  // being unused.
  (void) params;
  (void) data;
  char debugMessage[80];

  double result = 0;
  int divisor = 0;
  int dividend = 0;

  double *pdResult = &result;
  // int *pDivisor = &divisor;
  // int *pDividend = &dividend;

  // positive, not zero divisor and dividend
  divisor = 8;
  dividend = 4;
  result = division(divisor, dividend);
  munit_assert_double_equal(result, 2.0, 10);

  divisor = 4;
  dividend = 8;
  result = division(divisor, dividend);
  munit_assert_double_equal(result, 0.5, 10);

  // negative, not zero divisor and dividend
  divisor = -6;
  dividend = 2;
  result = division(divisor, dividend);
  munit_assert_double_equal(result, -3.0, 10);

  divisor = 4;
  dividend = -9;
  result = division(divisor, dividend);
  munit_assert_double_equal(result, -0.44444, 5);

  divisor = -33;
  dividend = -10;
  result = division(divisor, dividend);
  munit_assert_double_equal(result, 3.30, 5);

  // zero dividend
  divisor = 12;
  dividend = 0;
  result = division(divisor, dividend);
  sprintf(debugMessage, "Result of division by zero: %1.2f", result);
  munit_log(MUNIT_LOG_INFO, debugMessage);
  munit_assert_true(isinf(result)); // check returned values is infinite

  // zero divisor
  divisor = 0;
  dividend = 10;
  result = division(divisor, dividend);
  sprintf(debugMessage, "Result of division of zero: %1.2f", result);
  munit_log(MUNIT_LOG_INFO, debugMessage);
  munit_assert_double(result, ==, 0);

  // zero dividend
  divisor = 7;
  dividend = 0;
  division_ptr(&divisor, &dividend, pdResult);
  sprintf(debugMessage, "Result of division by zero: %1.2f", *pdResult);
  munit_log(MUNIT_LOG_INFO, debugMessage);
  munit_assert_true(isinf(*pdResult)); // check returned values is infinite

  return MUNIT_OK;
}

/* This test case shows how to accept parameters.  We'll see how to
 * specify them soon.
 *
 * By default, every possible variation of a parameterized test is
 * run, but you can specify parameters manually if you want to only
 * run specific test(s), or you can pass the --single argument to the
 * CLI to have the harness simply choose one variation at random
 * instead of running them all. */
// static MunitResult
// test_parameters(const MunitParameter params[], void* user_data) {
//   const char* asdf;
//   const char* foo;
//   const char* bar;
//   const int* someNumber;

//   union UnionContent myUnion;

//   (void) user_data;

//   /* The "foo" parameter is specified as one of the following values:
//    * "one", "two", or "three". */
//   foo = munit_parameters_get(params, "foo");
//   /* Similarly, "bar" is one of "four", "five", or "six". */
//   bar = munit_parameters_get(params, "bar");

//   // "asdf" is one of "nice", "name"
//   asdf = munit_parameters_get(params, "asdf");

//   // "numbers" is one of 3, 7, 4
//   // munit_parameters_get_union(params, "numbers", TYPE_INT8, &myUnion);

//   /* "baz" is a bit more complicated.  We don't actually specify a
//    * list of valid values, so by default NULL is passed.  However, the
//    * CLI will accept any value.  This is a good way to have a value
//    * that is usually selected randomly by the test, but can be
//    * overridden on the command line if desired. */
//   /* const char* baz = munit_parameters_get(params, "baz"); */

//   /* Notice that we're returning MUNIT_FAIL instead of writing an
//    * error message.  Error messages are generally preferable, since
//    * they make it easier to diagnose the issue, but this is an
//    * option.
//    *
//    * Possible values are:
//    *  - MUNIT_OK: Sucess
//    *  - MUNIT_FAIL: Failure
//    *  - MUNIT_SKIP: The test was skipped; usually this happens when a
//    *    particular feature isn't in use.  For example, if you're
//    *    writing a test which uses a Wayland-only feature, but your
//    *    application is running on X11.
//    *  - MUNIT_ERROR: The test failed, but not because of anything you
//    *    wanted to test.  For example, maybe your test downloads a
//    *    remote resource and tries to parse it, but the network was
//    *    down.
//    */

//   if (strcmp(foo, "one") != 0 &&
//       strcmp(foo, "two") != 0 &&
//       strcmp(foo, "three") != 0)
//     return MUNIT_FAIL;

//   if (strcmp(bar, "red") != 0 &&
//       strcmp(bar, "green") != 0 &&
//       strcmp(bar, "blue") != 0)
//     return MUNIT_FAIL;

//   if (strcmp(asdf, "nice") != 0 &&
//       strcmp(asdf, "name") != 0)
//     return MUNIT_FAIL;

//   /*
//   if (someNumber != 3 &&
//       someNumber != 4 &&
//       someNumber != 7)
//     return MUNIT_FAIL;
//   */

//   return MUNIT_OK;
// }

/*
static char* foo_params[] = {
  (char*) "one", (char*) "two", (char*) "three", NULL
};

static char* bar_params[] = {
  (char*) "red", (char*) "green", (char*) "blue", NULL
};

// define all values for some parameter
static char* asdf_params[] = {
  (char*) "nice", (char*) "name", NULL
};

static int8_t* number_params[] = {
  3, 7, 4, NULL
};

static char* char_params[] = {
  (char*) "testing", NULL
};

static MunitParameterEnum test_params[] = {
  // define a set of parameters with a set of values
  // name of parameter, content of parameter
  { (char*) "asdf", asdf_params },
  { (char*) "foo", foo_params },
  { (char*) "bar", bar_params },
  // { (char*) "numbers", char_params, TYPE_INT8, (union_content_t){.ppCharData=asdf_params}},
  { (char*) "baz", NULL },
  { NULL, NULL },
};
*/

/* Creating a test suite is pretty simple.  First, you'll need an
 * array of tests: */
static MunitTest test_suite_tests[] = {
  // {
  //   /* The name is just a unique human-readable way to identify the
  //    * test. You can use it to run a specific test if you want, but
  //    * usually it's mostly decorative. */
  //   (char*) "/example/compare",
  //   /* You probably won't be surprised to learn that the tests are
  //    * functions. */
  //   test_compare,
  //   /* If you want, you can supply a function to set up a fixture.  If
  //    * you supply NULL, the user_data parameter from munit_suite_main
  //    * will be used directly.  If, however, you provide a callback
  //    * here the user_data parameter will be passed to this callback,
  //    * and the return value from this callback will be passed to the
  //    * test function.
  //    *
  //    * For our example we don't really need a fixture, but lets
  //    * provide one anyways. */
  //   test_compare_setup,
  //   /* If you passed a callback for the fixture setup function, you
  //    * may want to pass a corresponding callback here to reverse the
  //    * operation. */
  //   test_compare_tear_down,
  //   /* Finally, there is a bitmask for options you can pass here.  You
  //    * can provide either MUNIT_TEST_OPTION_NONE or 0 here to use the
  //    * defaults. */
  //   MUNIT_TEST_OPTION_NONE,
  //   NULL
  // },
  // { (char*) "/example/compare", test_compare, test_compare_setup, test_compare_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
  // { (char*) "/example/compare", test_compare, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { (char*) "abolut_truth", test_abolut_truth, test_abolut_truth_setup, test_abolut_truth_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "sum", test_sum, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "difference", test_difference, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "product", test_multiplication, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { (char*) "quotient", test_division, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  // { (char*) "/example/parameters", test_parameters, NULL, NULL, MUNIT_TEST_OPTION_NONE, test_params },

  /* To tell the test runner when the array is over, just add a NULL
   * entry at the end. */
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

/* If you wanted to have your test suite run other test suites you
 * could declare an array of them.  Of course each sub-suite can
 * contain more suites, etc. */
/* static const MunitSuite other_suites[] = { */
/*   { "/second", test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE }, */
/*   { NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE } */
/* }; */

/* Now we'll actually declare the test suite.  You could do this in
 * the main function, or on the heap, or whatever you want. */
static const MunitSuite test_suite = {
  /* This string will be prepended to all test names in this suite;
   * for example, "/example/rand" will become "/µnit/example/rand".
   * Note that, while it doesn't really matter for the top-level
   * suite, NULL signal the end of an array of tests; you should use
   * an empty string ("") instead. */
  (char*) "calculator",
  /* The first parameter is the array of test suites. */
  test_suite_tests,
  /* In addition to containing test cases, suites can contain other
   * test suites.  This isn't necessary in this example, but it can be
   * a great help to projects with lots of tests by making it easier
   * to spread the tests across many files.  This is where you would
   * put "other_suites" (which is commented out above). */
  NULL,
  /* An interesting feature of µnit is that it supports automatically
   * running multiple iterations of the tests.  This is usually only
   * interesting if you make use of the PRNG to randomize your tests
   * cases a bit, or if you are doing performance testing and want to
   * average multiple runs.  0 is an alias for 1. */
  1,
  /* Just like MUNIT_TEST_OPTION_NONE, you can provide
   * MUNIT_SUITE_OPTION_NONE or 0 to use the default settings. */
  MUNIT_SUITE_OPTION_NONE
};

/* This is only necessary for EXIT_SUCCESS and EXIT_FAILURE, which you
 * *should* be using but probably aren't (no, zero and non-zero don't
 * always mean success and failure).  I guess my point is that nothing
 * about µnit requires it. */
#include <stdlib.h>

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  /* Finally, we'll actually run our test suite!  That second argument
   * is the user_data parameter which will be passed either to the
   * test or (if provided) the fixture setup function. */
  return munit_suite_main(&test_suite, (void*) "µnit", argc, argv);
}
