#include <boost/test/unit_test.hpp>
#include <sparrow/tile.hpp>

#include "./test_tileset.h"

namespace spr = nk::sparrow;
using tileset = spr::test::tileset;
using tile = spr::tile< tileset >;

BOOST_AUTO_TEST_SUITE (sparrow_tile_test_suite)

BOOST_AUTO_TEST_CASE (equal_suit_equal_value_equal)
{
    tile tile_1(tileset::a::one);
    tile tile_2(tileset::a::one);
    BOOST_CHECK_EQUAL(tile_1 == tile_2, true);
}

BOOST_AUTO_TEST_CASE (equal_suit_equal_value_not_equal)
{
    tile tile_1(tileset::a::one);
    tile tile_2(tileset::a::one);
    BOOST_CHECK_EQUAL(tile_1 != tile_2, false);
}

BOOST_AUTO_TEST_CASE (not_equal_suit_equal_value_equal)
{
    tile tile_1(tileset::a::one);
    tile tile_2(tileset::b::one);
    BOOST_CHECK_EQUAL(tile_1 == tile_2, false);
}

BOOST_AUTO_TEST_CASE (not_equal_suit_equal_value_not_equal)
{
    tile tile_1(tileset::a::one);
    tile tile_2(tileset::b::one);
    BOOST_CHECK_EQUAL(tile_1 != tile_2, true);
}

BOOST_AUTO_TEST_CASE (equal_suit_not_equal_value_equal)
{
    tile tile_1(tileset::a::one);
    tile tile_2(tileset::a::two);
    BOOST_CHECK_EQUAL(tile_1 == tile_2, false);
}

BOOST_AUTO_TEST_CASE (equal_suit_not_equal_value_not_equal)
{
    tile tile_1(tileset::a::one);
    tile tile_2(tileset::a::two);
    BOOST_CHECK_EQUAL(tile_1 != tile_2, true);
}

BOOST_AUTO_TEST_CASE (not_equal_suit_not_equal_value_equal)
{
    tile tile_1(tileset::a::one);
    tile tile_2(tileset::b::two);
    BOOST_CHECK_EQUAL(tile_1 == tile_2, false);
}

BOOST_AUTO_TEST_CASE (not_equal_suit_not_equal_value_not_equal)
{
    tile tile_1(tileset::a::one);
    tile tile_2(tileset::b::two);
    BOOST_CHECK_EQUAL(tile_1 != tile_2, true);
}

BOOST_AUTO_TEST_CASE (copy)
{
    tile tile_1(tileset::b::two);
    tile tile_2(tileset::b::two);
    BOOST_CHECK_EQUAL(tile_1 == tile_2, true);
}

BOOST_AUTO_TEST_CASE (assignment)
{
    tile tile_1(tileset::a::one);
    tile tile_2(tileset::b::two);
    tile_2 = tile_1;
    BOOST_CHECK_EQUAL(tile_1 == tile_2, true);
}

BOOST_AUTO_TEST_SUITE_END()
