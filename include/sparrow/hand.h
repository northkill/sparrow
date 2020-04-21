#ifndef __NK_SPARROW_HAND_H__
#define __NK_SPARROW_HAND_H__

#include <list>
#include <memory>
#include <optional>

#include "./tile.h"

namespace nk::sparrow {

template < typename T >
struct pool_allocator {
public:
    using value_type = T;
};

class hand {
public:
    using tiles_type = std::list< tile >;
    using size_type = tiles_type::size_type;
    using iterator = tiles_type::iterator;
    using const_iterator = tiles_type::const_iterator;

    hand(void);

    auto push_tile(tile const tile) -> void;
    auto pop_tile(const_iterator const iterator) -> void;
    auto pop_tile(tile const tile) -> void;

    auto begin(void) noexcept -> iterator;
    auto begin(void) const noexcept -> const_iterator;
    auto cbegin(void) const noexcept -> const_iterator;
    auto end(void) noexcept -> iterator;
    auto end(void) const noexcept -> const_iterator;
    auto cend(void) const noexcept -> const_iterator;
    auto size(void) const noexcept -> size_type;

private:
    tiles_type m_tiles;
};

}

#endif