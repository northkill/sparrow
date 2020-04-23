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
        spr::tile(0, 1),
        spr::tile(0, 2),
    };

    spr::hand hand;
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
    std::vector< spr::tile > const input_tiles {
        spr::tile(3, 1),
        spr::tile(0, 5),
        spr::tile(1, 0),
        spr::tile(0, 2),
        spr::tile(1, 0),
    };

    std::vector< spr::tile > const expected_tiles {
        spr::tile(0, 2),
        spr::tile(0, 5),
        spr::tile(1, 0),
        spr::tile(1, 0),
        spr::tile(3, 1),
    };

    BOOST_REQUIRE_EQUAL(input_tiles.size(), expected_tiles.size());

    spr::hand hand;
    for (auto const& tile : input_tiles)
        hand.push(tile);

    auto i = hand.begin();
    for (std::size_t j = 0; j < expected_tiles.size(); j += 1, ++i)
        BOOST_CHECK_EQUAL(*i == expected_tiles[j], true);
}

BOOST_AUTO_TEST_CASE (sparrow_pop_tile_by_value)
{
    std::vector< spr::tile > const input_tiles {
        spr::tile(0, 1),
        spr::tile(0, 2),
        spr::tile(0, 3),
    };

    std::vector< spr::tile > const expected_tiles {
        spr::tile(0, 1),
        spr::tile(0, 3),
    };

    BOOST_REQUIRE_EQUAL(input_tiles.size() - 1, expected_tiles.size());

    spr::tile const target_tile(0, 2);
    spr::hand hand;
    for (auto const& tile : input_tiles)
        hand.push(tile);

    hand.pop(target_tile);

    auto i = hand.cbegin();
    for (std::size_t j = 0; j < expected_tiles.size(); j += 1, ++i)
        BOOST_CHECK_EQUAL(*i == expected_tiles[j], true);
}

BOOST_AUTO_TEST_CASE (sparrow_pop_tile_by_iterator)
{
    std::vector< spr::tile > const input_tiles {
        spr::tile(0, 1),
        spr::tile(0, 2),
        spr::tile(0, 3),
    };

    std::vector< spr::tile > const expected_tiles {
        spr::tile(0, 1),
        spr::tile(0, 3),
    };

    BOOST_REQUIRE_EQUAL(input_tiles.size() - 1, expected_tiles.size());

    spr::tile const target_tile(0, 2);
    spr::hand hand;
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
