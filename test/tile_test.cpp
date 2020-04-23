#include <boost/test/unit_test.hpp>
#include <sparrow/tile.h>

namespace spr = nk::sparrow;

BOOST_AUTO_TEST_SUITE (sparrow_tile_test_suite)

BOOST_AUTO_TEST_CASE (equal_type_equal_value_equal)
{
    spr::tile tile_1(1, 1);
    spr::tile tile_2(1, 1);
    BOOST_CHECK_EQUAL(tile_1 == tile_2, true);
}

BOOST_AUTO_TEST_CASE (equal_type_equal_value_not_equal)
{
    spr::tile tile_1(1, 1);
    spr::tile tile_2(1, 1);
    BOOST_CHECK_EQUAL(tile_1 != tile_2, false);
}

BOOST_AUTO_TEST_CASE (not_equal_type_equal_value_equal)
{
    spr::tile tile_1(1, 1);
    spr::tile tile_2(2, 1);
    BOOST_CHECK_EQUAL(tile_1 == tile_2, false);
}

BOOST_AUTO_TEST_CASE (not_equal_type_equal_value_not_equal)
{
    spr::tile tile_1(1, 1);
    spr::tile tile_2(2, 1);
    BOOST_CHECK_EQUAL(tile_1 != tile_2, true);
}

BOOST_AUTO_TEST_CASE (equal_type_not_equal_value_equal)
{
    spr::tile tile_1(1, 1);
    spr::tile tile_2(1, 2);
    BOOST_CHECK_EQUAL(tile_1 == tile_2, false);
}

BOOST_AUTO_TEST_CASE (equal_type_not_equal_value_not_equal)
{
    spr::tile tile_1(1, 1);
    spr::tile tile_2(1, 2);
    BOOST_CHECK_EQUAL(tile_1 != tile_2, true);
}

BOOST_AUTO_TEST_CASE (not_equal_type_not_equal_value_equal)
{
    spr::tile tile_1(1, 2);
    spr::tile tile_2(2, 4);
    BOOST_CHECK_EQUAL(tile_1 == tile_2, false);
}

BOOST_AUTO_TEST_CASE (not_equal_type_not_equal_value_not_equal)
{
    spr::tile tile_1(1, 2);
    spr::tile tile_2(2, 4);
    BOOST_CHECK_EQUAL(tile_1 != tile_2, true);
}

BOOST_AUTO_TEST_CASE (copy)
{
    spr::tile tile_1(3, 4);
    spr::tile tile_2(tile_1);
    BOOST_CHECK_EQUAL(tile_1 == tile_2, true);
}

BOOST_AUTO_TEST_CASE (assignment)
{
    spr::tile tile_1(1, 2);
    spr::tile tile_2(3, 4);
    tile_2 = tile_1;
    BOOST_CHECK_EQUAL(tile_1 == tile_2, true);
}

BOOST_AUTO_TEST_SUITE_END()
