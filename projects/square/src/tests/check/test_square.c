#include <stdlib.h>
#include "../../square.h"
#include "check.h"

START_TEST(test_parse_flag)
{
    struct data
    {
        char *input;
        double output;
        int err;
    };

    struct data dd[] = {
        {"0.1", 0.1, PARSE_OK},
        {"0", 0, PARSE_OK},
        {"-1.2", -1.2, PARSE_OK},
        {"-1e12", -1e12, PARSE_OK},
        {"12212.34556", 12212.34556, PARSE_OK},
        {"-326239237.129128", -326239237.129128, PARSE_OK},
        {"     124", 124, PARSE_OK},
        // odd cases
        {"\0", 0, PARSE_EMPTY_RESULT},
        {"\n", 0, PARSE_EMPTY_RESULT},
        {"duh", 0, PARSE_EMPTY_RESULT},
        {"abcd1244", 0, PARSE_EMPTY_RESULT}};

    for (int i = 0; i < sizeof dd / sizeof dd[0]; i++)
    {
        struct data d = dd[i];
        double v = 0;
        int err = 0;

        err = parse_flag(d.input, &v);
        ck_assert_int_eq(err, err);
        ck_assert_double_eq(d.output, v);
    }
}
END_TEST

Suite *test_square(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Test Square");

    /* Core Test Case */
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_parse_flag);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    Suite *s;
    SRunner *sr;
    int n_failed;

    s = test_square();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    n_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return n_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}