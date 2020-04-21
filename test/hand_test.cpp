#include <algorithm>

#include <boost/test/unit_test.hpp>
#include <sparrow/hand.h>

namespace spr = nk::sparrow;

BOOST_AUTO_TEST_SUITE (sparrow_hand_test_suite)

BOOST_AUTO_TEST_CASE (sparrow_hand_default_construct)
{
    spr::hand hand;
    BOOST_CHECK_EQUAL(hand.size(), 0);
}

BOOST_AUTO_TEST_CASE (sparrow_hand_add_tiles)
{
    std::vector< spr::tile > const tiles {
        spr::tile(spr::tile_type_type(0), spr::tile_value_type(1)),
        spr::tile(spr::tile_type_type(0), spr::tile_value_type(2)), };

    spr::hand hand;
    for (auto const& tile : tiles)
        hand.push_tile(tile);

    BOOST_CHECK_EQUAL(hand.size(), 2);

    auto i = hand.cbegin();
    for (std::size_t j = 0; j < tiles.size(); j += 1, ++i) {
        BOOST_CHECK_EQUAL(*i == tiles[j], true);
    }
}

BOOST_AUTO_TEST_CASE (sparrow_hand_sorted_add_tiles)
{
    std::vector< spr::tile > const input_tiles {
        spr::tile(spr::tile_type_type(3), spr::tile_value_type(1)),
        spr::tile(spr::tile_type_type(0), spr::tile_value_type(5)),
        spr::tile(spr::tile_type_type(1), spr::tile_value_type(0)),
        spr::tile(spr::tile_type_type(0), spr::tile_value_type(2)),
        spr::tile(spr::tile_type_type(1), spr::tile_value_type(0)),
    };

    std::vector< spr::tile > const expected_tiles {
        spr::tile(spr::tile_type_type(0), spr::tile_value_type(2)),
        spr::tile(spr::tile_type_type(0), spr::tile_value_type(5)),
        spr::tile(spr::tile_type_type(1), spr::tile_value_type(0)),
        spr::tile(spr::tile_type_type(1), spr::tile_value_type(0)),
        spr::tile(spr::tile_type_type(3), spr::tile_value_type(1)),
    };

    BOOST_REQUIRE_EQUAL(input_tiles.size(), expected_tiles.size());

    spr::hand hand;
    for (auto const& tile : input_tiles)
        hand.push_tile(tile);

    auto i = hand.begin();
    for (std::size_t j = 0; j < expected_tiles.size(); j += 1, ++i)
        BOOST_CHECK_EQUAL(*i == expected_tiles[j], true);
}

BOOST_AUTO_TEST_CASE (sparrow_pop_tile_by_value)
{
    std::vector< spr::tile > const input_tiles {
        spr::tile(spr::tile_type_type(0), spr::tile_value_type(1)),
        spr::tile(spr::tile_type_type(0), spr::tile_value_type(2)),
        spr::tile(spr::tile_type_type(0), spr::tile_value_type(3)),
    };

    std::vector< spr::tile > const expected_tiles {
        spr::tile(spr::tile_type_type(0), spr::tile_value_type(1)),
        spr::tile(spr::tile_type_type(0), spr::tile_value_type(3)),
    };

    BOOST_REQUIRE_EQUAL(input_tiles.size() - 1, expected_tiles.size());

    spr::tile const target_tile(spr::tile_type_type(0), spr::tile_value_type(2));
    spr::hand hand;
    for (auto const& tile : input_tiles)
        hand.push_tile(tile);

    hand.pop_tile(target_tile);

    auto i = hand.cbegin();
    for (std::size_t j = 0; j < expected_tiles.size(); j += 1, ++i)
        BOOST_CHECK_EQUAL(*i == expected_tiles[j], true);
}

BOOST_AUTO_TEST_CASE (sparrow_pop_tile_by_iterator)
{
    std::vector< spr::tile > const input_tiles {
        spr::tile(spr::tile_type_type(0), spr::tile_value_type(1)),
        spr::tile(spr::tile_type_type(0), spr::tile_value_type(2)),
        spr::tile(spr::tile_type_type(0), spr::tile_value_type(3)),
    };

    std::vector< spr::tile > const expected_tiles {
        spr::tile(spr::tile_type_type(0), spr::tile_value_type(1)),
        spr::tile(spr::tile_type_type(0), spr::tile_value_type(3)),
    };

    BOOST_REQUIRE_EQUAL(input_tiles.size() - 1, expected_tiles.size());

    spr::tile const target_tile(spr::tile_type_type(0), spr::tile_value_type(2));
    spr::hand hand;
    for (auto const& tile : input_tiles)
        hand.push_tile(tile);

    auto const lb = std::lower_bound(hand.cbegin(), hand.cend(), target_tile);
    BOOST_REQUIRE_EQUAL(lb != hand.cend(), true);
    BOOST_REQUIRE_EQUAL(*lb == target_tile, true);
    hand.pop_tile(lb);

    auto i = hand.cbegin();
    for (std::size_t j = 0; j < expected_tiles.size(); j += 1, ++i)
        BOOST_CHECK_EQUAL(*i == expected_tiles[j], true);
}

BOOST_AUTO_TEST_SUITE_END()
