#ifndef __NK_SPARROW_GAME_HPP__
#define __NK_SPARROW_GAME_HPP__

#include <vector>

namespace nk::sparrow {

template <typename Rule >
class game {
public:
    using rule_type = Rule;
    using tile_type = typename rule_type::tile_type;

    static auto compose_wall(void) -> std::vector< tile_type >
    {
        std::vector< tile_type > tiles;
        tiles.reserve(rule_type::wall_size());

        for (auto const& component : rule_type::wall_components) {
            auto const tile_value = std::get< 0 >(component);
            auto const tile_number = std::get< 1 >(component);
            for (std::decay_t< decltype(tile_number) > i = 0; i < tile_number; i += 1)
                tiles.emplace_back(tile_value);
        }

        return tiles;
    }

    game(void) = delete;
};

}

#endif
