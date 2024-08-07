#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#ifndef __MINIUNIT_H__
#define __MINIUNIT_H__

#define MU_SUCCESS 0

#define mu_start() int __mu_first_failure_line_number_or_0 = MU_SUCCESS

#define mu_check(condition) \
        do{ \
                if (__mu_first_failure_line_number_or_0 != MU_SUCCESS) {} \
                else if((condition) == MU_SUCCESS) { \
                        __mu_first_failure_line_number_or_0 = __LINE__;} \
        }while(false)

#define mu_end() return __mu_first_failure_line_number_or_0

#define mu_run(n) n() == MU_SUCCESS ? printf("Test Passed: %s\n", #n) : printf("Test failed: %s at line %d\n", #n, n())

#define mu_check_strings_equal(s1, s2) mu_check(((strcmp((s1), (s2))) == MU_SUCCESS))

#endif /* end of include guard: __MINIUNIT_H__ */
