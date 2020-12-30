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
           {"--123", 0, PARSE_EMPTY},
           {"-", 0, PARSE_EMPTY},
           {"invalid", 0, PARSE_EMPTY},
           {"NULL", 0, PARSE_EMPTY},
           {"\0", 0, PARSE_EMPTY},
           {"\n", 0, PARSE_EMPTY},
       };

   for (int i = 0; i < sizeof dd / sizeof *dd; i++)
   {
      struct data d = dd[i];
      CU_ASSERT(d.err == parse_flag(d.input, &d.output));
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
   CU_cleanup_registry();
   return CU_get_error();
}