#ifndef __NK_SPARROW_TEST_GAME_HPP__
#define __NK_SPARROW_TEST_GAME_HPP__

#include <sparrow/game.hpp>

#include "./test_rule.hpp"

namespace nk::sparrow::test {

using game = sparrow::game< test::rule >;

}

#endif
