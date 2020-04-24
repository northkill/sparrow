#include <boost/test/unit_test.hpp>

#include <array>
#include <vector>

#include "./test_game.hpp"

namespace sparrow = nk::sparrow;
namespace test = nk::sparrow::test;

using tile_type = test::game::tile_type;
using tiles_type = std::vector< test::game::tile_type >;

namespace {

auto count_tiles(tiles_type const& tiles, test::tileset::value const value)
{
    return std::count(begin(tiles), end(tiles), tile_type(value));
}

}

BOOST_AUTO_TEST_SUITE (sparrow_game_test_suite)

BOOST_AUTO_TEST_CASE (wall_composure)
{
    auto const tiles = test::game::compose_wall();
    BOOST_CHECK_EQUAL(tiles.size(), test::rule::wall_size());
    BOOST_CHECK_EQUAL(count_tiles(tiles, test::tileset::a::one), 1);
    BOOST_CHECK_EQUAL(count_tiles(tiles, test::tileset::b::one), 2);
    BOOST_CHECK_EQUAL(count_tiles(tiles, test::tileset::b::two), 2);
    BOOST_CHECK_EQUAL(count_tiles(tiles, test::tileset::c::one), 3);
    BOOST_CHECK_EQUAL(count_tiles(tiles, test::tileset::c::two), 3);
    BOOST_CHECK_EQUAL(count_tiles(tiles, test::tileset::c::three), 3);
}

BOOST_AUTO_TEST_SUITE_END()
