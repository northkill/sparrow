#define BOOST_TEST_MODULE sparrow test
#include <boost/test/unit_test.hpp>
#include <sparrow/sparrow.h>

BOOST_AUTO_TEST_SUITE (sparrow_test_suit_0)

BOOST_AUTO_TEST_CASE (sparrow_test_case_0)
{
    BOOST_TEST(nk::add(1, 2) == 4);
}

BOOST_AUTO_TEST_SUITE_END()
