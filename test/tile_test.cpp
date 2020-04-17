#include <boost/test/unit_test.hpp>
#include <sparrow/tile.h>

using nk::sparrow::tile_type_type;
using nk::sparrow::tile_value_type;
using nk::sparrow::tile;

BOOST_AUTO_TEST_SUITE (sparrow_tile_test_suite)

BOOST_AUTO_TEST_CASE (equal_type_equal_value_equal)
{
    tile tile_1(tile_type_type(1), tile_value_type(1));
    tile tile_2(tile_type_type(1), tile_value_type(1));
    BOOST_CHECK_EQUAL(tile_1 == tile_2, true);
}

BOOST_AUTO_TEST_CASE (equal_type_equal_value_not_equal)
{
    tile tile_1(tile_type_type(1), tile_value_type(1));
    tile tile_2(tile_type_type(1), tile_value_type(1));
    BOOST_CHECK_EQUAL(tile_1 != tile_2, false);
}

BOOST_AUTO_TEST_CASE (not_equal_type_equal_value_equal)
{
    tile tile_1(tile_type_type(1), tile_value_type(1));
    tile tile_2(tile_type_type(2), tile_value_type(1));
    BOOST_CHECK_EQUAL(tile_1 == tile_2, false);
}

BOOST_AUTO_TEST_CASE (not_equal_type_equal_value_not_equal)
{
    tile tile_1(tile_type_type(1), tile_value_type(1));
    tile tile_2(tile_type_type(2), tile_value_type(1));
    BOOST_CHECK_EQUAL(tile_1 != tile_2, true);
}

BOOST_AUTO_TEST_CASE (equal_type_not_equal_value_equal)
{
    tile tile_1(tile_type_type(1), tile_value_type(1));
    tile tile_2(tile_type_type(1), tile_value_type(2));
    BOOST_CHECK_EQUAL(tile_1 == tile_2, false);
}

BOOST_AUTO_TEST_CASE (equal_type_not_equal_value_not_equal)
{
    tile tile_1(tile_type_type(1), tile_value_type(1));
    tile tile_2(tile_type_type(1), tile_value_type(2));
    BOOST_CHECK_EQUAL(tile_1 != tile_2, true);
}

BOOST_AUTO_TEST_CASE (not_equal_type_not_equal_value_equal)
{
    tile tile_1(tile_type_type(1), tile_value_type(2));
    tile tile_2(tile_type_type(2), tile_value_type(4));
    BOOST_CHECK_EQUAL(tile_1 == tile_2, false);
}

BOOST_AUTO_TEST_CASE (not_equal_type_not_equal_value_not_equal)
{
    tile tile_1(tile_type_type(1), tile_value_type(2));
    tile tile_2(tile_type_type(2), tile_value_type(4));
    BOOST_CHECK_EQUAL(tile_1 != tile_2, true);
}

BOOST_AUTO_TEST_CASE (copy)
{
    tile tile_1(tile_type_type(3), tile_value_type(4));
    tile tile_2(tile_1);
    BOOST_CHECK_EQUAL(tile_1 == tile_2, true);
}

BOOST_AUTO_TEST_CASE (assignment)
{
    tile tile_1(tile_type_type(1), tile_value_type(2));
    tile tile_2(tile_type_type(3), tile_value_type(4));
    tile_2 = tile_1;
    BOOST_CHECK_EQUAL(tile_1 == tile_2, true);
}

BOOST_AUTO_TEST_SUITE_END()
