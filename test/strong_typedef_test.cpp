#include <boost/test/unit_test.hpp>
#include <sparrow/tile.h>

using nk::sparrow::tile_value_type;

BOOST_AUTO_TEST_SUITE (sparrow_strong_typedef_test_suite)

BOOST_AUTO_TEST_CASE (equal_values_equal)
{
    tile_value_type value_1(1);
    tile_value_type value_2(1);
    BOOST_CHECK_EQUAL(value_1 == value_2, true);
}

BOOST_AUTO_TEST_CASE (equal_values_not_equal)
{
    tile_value_type value_1(1);
    tile_value_type value_2(1);
    BOOST_CHECK_EQUAL(value_1 != value_2, false);
}

BOOST_AUTO_TEST_CASE (not_equal_values_equal)
{
    tile_value_type value_1(1);
    tile_value_type value_2(2);
    BOOST_CHECK_EQUAL(value_1 == value_2, false);
}

BOOST_AUTO_TEST_CASE (not_equal_values_not_equal)
{
    tile_value_type value_1(1);
    tile_value_type value_2(2);
    BOOST_CHECK_EQUAL(value_1 != value_2, true);
}

BOOST_AUTO_TEST_CASE (assignment)
{
    tile_value_type value_1(1);
    tile_value_type value_2(2);
    BOOST_REQUIRE_EQUAL(value_1 != value_2, true);

    value_1 = value_2;
    BOOST_CHECK_EQUAL(value_1 == value_2, true);
}

BOOST_AUTO_TEST_SUITE_END()
