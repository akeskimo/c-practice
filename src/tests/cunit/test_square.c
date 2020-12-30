#include "CUnit/Basic.h"
#include "../../square.h"

/* Test function parse_flag.
* Tries to convert different values and checks that
* function output matches that of the expected value.
*/
void test_parse_flag(void)
{
   struct data
   {
      char *input;
      double output;
      int err;
   };

   struct data dd[] =
       {
           {"0", 0, PARSE_OK},
           {"1", 1, PARSE_OK},
           {"-5", -5, PARSE_OK},
           {"0.1111882", 0.1111882, PARSE_OK},
           {"2.3E-308", 2.3E-308, PARSE_OK},
           // odd cases
           {"--123", 0, PARSE_EMPTY_RESULT},
           {"-", 0, PARSE_EMPTY_RESULT},
           {"invalid", 0, PARSE_EMPTY_RESULT},
           {"NULL", 0, PARSE_EMPTY_RESULT},
           {"\0", 0, PARSE_EMPTY_RESULT},
           {"\n", 0, PARSE_EMPTY_RESULT},
       };

   for (int i = 0; i < sizeof dd / sizeof *dd; i++)
   {
      struct data d = dd[i];
      int result = parse_flag(d.input, &d.output);
      CU_ASSERT(d.err == result);
      if (d.err != result)
      {
         printf("Parsing %d failed, input: %s, value: %f, result: %d\n", i, d.input, d.output, result);
      }
   }
}

int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_1", NULL, NULL);
   if (NULL == pSuite)
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if ((NULL == CU_add_test(pSuite, "test parse_flag()", test_parse_flag)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();

   /* After running tests - strangely enough - CUnit reports only framework
   function errors so we need to ask the registry if has any failed tests and
   exit with non-zero status in such cases. */
   if (CU_get_number_of_tests_failed() != 0)
   {
      CU_cleanup_registry();
      return 1;
   }

   CU_cleanup_registry();
   return CU_get_error();
}
