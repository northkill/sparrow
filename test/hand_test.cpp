#include <algorithm>

#include <boost/test/unit_test.hpp>
#include <sparrow/hand.hpp>

#include "./test_tileset.h"

namespace spr = nk::sparrow;
using tileset = spr::test::tileset;
using tile = spr::tile< tileset >;
using hand = spr::hand< tileset >;

BOOST_AUTO_TEST_SUITE (sparrow_hand_test_suite)

BOOST_AUTO_TEST_CASE (sparrow_hand_default_construct)
{
    hand hand;
    BOOST_CHECK_EQUAL(hand.size(), 0);
}

BOOST_AUTO_TEST_CASE (sparrow_hand_add_tiles)
{
    std::vector< tile > const tiles {
        tile(tileset::a::one),
        tile(tileset::a::two),
    };

    hand hand;
    for (auto const& tile : tiles)
        hand.push(tile);

    BOOST_CHECK_EQUAL(hand.size(), 2);

    auto i = hand.cbegin();
    for (std::size_t j = 0; j < tiles.size(); j += 1, ++i) {
        BOOST_CHECK_EQUAL(*i == tiles[j], true);
    }
}

BOOST_AUTO_TEST_CASE (sparrow_hand_sorted_add_tiles)
{
    std::vector< tile > const input_tiles {
        tile(tileset::c::two),
        tile(tileset::a::five),
        tile(tileset::b::one),
        tile(tileset::a::three),
        tile(tileset::b::one),
    };

    std::vector< tile > const expected_tiles {
        tile(tileset::a::three),
        tile(tileset::a::five),
        tile(tileset::b::one),
        tile(tileset::b::one),
        tile(tileset::c::two),
    };

    BOOST_REQUIRE_EQUAL(input_tiles.size(), expected_tiles.size());

    hand hand;
    for (auto const& tile : input_tiles)
        hand.push(tile);

    auto i = hand.begin();
    for (std::size_t j = 0; j < expected_tiles.size(); j += 1, ++i)
        BOOST_CHECK_EQUAL(*i == expected_tiles[j], true);
}

BOOST_AUTO_TEST_CASE (sparrow_pop_tile_by_value)
{
    std::vector< tile > const input_tiles {
        tile(tileset::a::one),
        tile(tileset::a::two),
        tile(tileset::a::three),
    };

    std::vector< tile > const expected_tiles {
        tile(tileset::a::one),
        tile(tileset::a::three),
    };

    BOOST_REQUIRE_EQUAL(input_tiles.size() - 1, expected_tiles.size());

    tile const target_tile(tileset::a::two);
    hand hand;
    for (auto const& tile : input_tiles)
        hand.push(tile);

    hand.pop(target_tile);

    auto i = hand.cbegin();
    for (std::size_t j = 0; j < expected_tiles.size(); j += 1, ++i)
        BOOST_CHECK_EQUAL(*i == expected_tiles[j], true);
}

BOOST_AUTO_TEST_CASE (sparrow_pop_tile_by_iterator)
{
    std::vector< tile > const input_tiles {
        tile(tileset::a::one),
        tile(tileset::a::two),
        tile(tileset::a::three),
    };

    std::vector< tile > const expected_tiles {
        tile(tileset::a::one),
        tile(tileset::a::three),
    };

    BOOST_REQUIRE_EQUAL(input_tiles.size() - 1, expected_tiles.size());

    tile const target_tile(tileset::a::two);
    hand hand;
    for (auto const& tile : input_tiles)
        hand.push(tile);

    auto const lb = std::lower_bound(hand.cbegin(), hand.cend(), target_tile);
    BOOST_REQUIRE_EQUAL(lb != hand.cend(), true);
    BOOST_REQUIRE_EQUAL(*lb == target_tile, true);
    hand.pop(lb);

    auto i = hand.cbegin();
    for (std::size_t j = 0; j < expected_tiles.size(); j += 1, ++i)
        BOOST_CHECK_EQUAL(*i == expected_tiles[j], true);
}

BOOST_AUTO_TEST_SUITE_END()
