/* Test narrowing divide.
   Copyright (C) 2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#include "libm-test-driver.c"

static const struct test_aa_f_data div_test_data[] =
  {
    TEST_aa_f (div, arg_qnan_value, arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_qnan_value, -arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_qnan_value, arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_qnan_value, -arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_qnan_value, arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_qnan_value, -arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_qnan_value, arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_qnan_value, -arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_snan_value, arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_snan_value, -arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_snan_value, arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_snan_value, -arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_snan_value, arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_snan_value, -arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_snan_value, arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_snan_value, -arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),

    TEST_aa_f (div, arg_qnan_value, arg_plus_zero, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_qnan_value, arg_minus_zero, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_qnan_value, arg_plus_infty, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_qnan_value, arg_minus_infty, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_qnan_value, arg_min_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_qnan_value, -arg_min_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_qnan_value, arg_min_subnorm_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_qnan_value, -arg_min_subnorm_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_qnan_value, arg_max_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_qnan_value, -arg_max_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_plus_zero, arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_minus_zero, arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_plus_infty, arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_minus_infty, arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_min_value, arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_min_value, arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_min_subnorm_value, arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_min_subnorm_value, arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_max_value, arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_max_value, arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_qnan_value, arg_plus_zero, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_qnan_value, arg_minus_zero, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_qnan_value, arg_plus_infty, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_qnan_value, arg_minus_infty, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_qnan_value, arg_min_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_qnan_value, -arg_min_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_qnan_value, arg_min_subnorm_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_qnan_value, -arg_min_subnorm_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_qnan_value, arg_max_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_qnan_value, -arg_max_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_plus_zero, -arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_minus_zero, -arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_plus_infty, -arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_minus_infty, -arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_min_value, -arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_min_value, -arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_min_subnorm_value, -arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_min_subnorm_value, -arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_max_value, -arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_max_value, -arg_qnan_value, qnan_value, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),

    TEST_aa_f (div, arg_snan_value, arg_plus_zero, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_snan_value, arg_minus_zero, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_snan_value, arg_plus_infty, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_snan_value, arg_minus_infty, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_snan_value, arg_min_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_snan_value, -arg_min_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_snan_value, arg_min_subnorm_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_snan_value, -arg_min_subnorm_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_snan_value, arg_max_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_snan_value, -arg_max_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_plus_zero, arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_minus_zero, arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_plus_infty, arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_minus_infty, arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_min_value, arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_min_value, arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_min_subnorm_value, arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_min_subnorm_value, arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_max_value, arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_max_value, arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_snan_value, arg_plus_zero, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_snan_value, arg_minus_zero, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_snan_value, arg_plus_infty, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_snan_value, arg_minus_infty, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_snan_value, arg_min_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_snan_value, -arg_min_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_snan_value, arg_min_subnorm_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_snan_value, -arg_min_subnorm_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_snan_value, arg_max_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_snan_value, -arg_max_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_plus_zero, -arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_minus_zero, -arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_plus_infty, -arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_minus_infty, -arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_min_value, -arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_min_value, -arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_min_subnorm_value, -arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_min_subnorm_value, -arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, arg_max_value, -arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),
    TEST_aa_f (div, -arg_max_value, -arg_snan_value, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION),

    TEST_aa_f (div, arg_plus_infty, arg_plus_infty, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM),
    TEST_aa_f (div, arg_plus_infty, arg_minus_infty, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM),
    TEST_aa_f (div, arg_minus_infty, arg_plus_infty, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM),
    TEST_aa_f (div, arg_minus_infty, arg_minus_infty, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM),

    TEST_aa_f (div, arg_plus_zero, arg_plus_zero, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM),
    TEST_aa_f (div, arg_plus_zero, arg_minus_zero, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM),
    TEST_aa_f (div, arg_minus_zero, arg_plus_zero, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM),
    TEST_aa_f (div, arg_minus_zero, arg_minus_zero, qnan_value, NO_INEXACT_EXCEPTION|INVALID_EXCEPTION|ERRNO_EDOM),

    TEST_aa_f (div, arg_plus_infty, arg_plus_zero, plus_infty, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_plus_infty, arg_minus_zero, minus_infty, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_plus_infty, arg_min_value, plus_infty, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_plus_infty, -arg_min_value, minus_infty, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_plus_infty, arg_min_subnorm_value, plus_infty, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_plus_infty, -arg_min_subnorm_value, minus_infty, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_plus_infty, arg_max_value, plus_infty, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_plus_infty, -arg_max_value, minus_infty, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_plus_zero, arg_plus_infty, plus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_minus_zero, arg_plus_infty, minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_min_value, arg_plus_infty, plus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_min_value, arg_plus_infty, minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_min_subnorm_value, arg_plus_infty, plus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_min_subnorm_value, arg_plus_infty, minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_max_value, arg_plus_infty, plus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_max_value, arg_plus_infty, minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_minus_infty, arg_plus_zero, minus_infty, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_minus_infty, arg_minus_zero, plus_infty, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_minus_infty, arg_min_value, minus_infty, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_minus_infty, -arg_min_value, plus_infty, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_minus_infty, arg_min_subnorm_value, minus_infty, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_minus_infty, -arg_min_subnorm_value, plus_infty, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_minus_infty, arg_max_value, minus_infty, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_minus_infty, -arg_max_value, plus_infty, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_plus_zero, arg_minus_infty, minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_minus_zero, arg_minus_infty, plus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_min_value, arg_minus_infty, minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_min_value, arg_minus_infty, plus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_min_subnorm_value, arg_minus_infty, minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_min_subnorm_value, arg_minus_infty, plus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, arg_max_value, arg_minus_infty, minus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),
    TEST_aa_f (div, -arg_max_value, arg_minus_infty, plus_zero, NO_INEXACT_EXCEPTION|ERRNO_UNCHANGED),

    TEST_aa_f (div, arg_min_value, arg_plus_zero, plus_infty, NO_INEXACT_EXCEPTION|DIVIDE_BY_ZERO_EXCEPTION|ERRNO_ERANGE),
    TEST_aa_f (div, -arg_min_value, arg_plus_zero, minus_infty, NO_INEXACT_EXCEPTION|DIVIDE_BY_ZERO_EXCEPTION|ERRNO_ERANGE),
    TEST_aa_f (div, arg_min_subnorm_value, arg_plus_zero, plus_infty, NO_INEXACT_EXCEPTION|DIVIDE_BY_ZERO_EXCEPTION|ERRNO_ERANGE),
    TEST_aa_f (div, -arg_min_subnorm_value, arg_plus_zero, minus_infty, NO_INEXACT_EXCEPTION|DIVIDE_BY_ZERO_EXCEPTION|ERRNO_ERANGE),
    TEST_aa_f (div, arg_max_value, arg_plus_zero, plus_infty, NO_INEXACT_EXCEPTION|DIVIDE_BY_ZERO_EXCEPTION|ERRNO_ERANGE),
    TEST_aa_f (div, -arg_max_value, arg_plus_zero, minus_infty, NO_INEXACT_EXCEPTION|DIVIDE_BY_ZERO_EXCEPTION|ERRNO_ERANGE),
    TEST_aa_f (div, arg_min_value, arg_minus_zero, minus_infty, NO_INEXACT_EXCEPTION|DIVIDE_BY_ZERO_EXCEPTION|ERRNO_ERANGE),
    TEST_aa_f (div, -arg_min_value, arg_minus_zero, plus_infty, NO_INEXACT_EXCEPTION|DIVIDE_BY_ZERO_EXCEPTION|ERRNO_ERANGE),
    TEST_aa_f (div, arg_min_subnorm_value, arg_minus_zero, minus_infty, NO_INEXACT_EXCEPTION|DIVIDE_BY_ZERO_EXCEPTION|ERRNO_ERANGE),
    TEST_aa_f (div, -arg_min_subnorm_value, arg_minus_zero, plus_infty, NO_INEXACT_EXCEPTION|DIVIDE_BY_ZERO_EXCEPTION|ERRNO_ERANGE),
    TEST_aa_f (div, arg_max_value, arg_minus_zero, minus_infty, NO_INEXACT_EXCEPTION|DIVIDE_BY_ZERO_EXCEPTION|ERRNO_ERANGE),
    TEST_aa_f (div, -arg_max_value, arg_minus_zero, plus_infty, NO_INEXACT_EXCEPTION|DIVIDE_BY_ZERO_EXCEPTION|ERRNO_ERANGE),

    AUTO_TESTS_aa_f (div),
  };

static void
div_test (void)
{
  ALL_RM_TEST (div, 1, div_test_data, RUN_TEST_LOOP_aa_f, END);
}

static void
do_test (void)
{
  div_test ();
}

/*
 * Local Variables:
 * mode:c
 * End:
 */