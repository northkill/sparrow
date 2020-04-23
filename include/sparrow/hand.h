#ifndef __NK_SPARROW_HAND_H__
#define __NK_SPARROW_HAND_H__

#include <list>

#include "./tile.h"

namespace nk::sparrow {

class hand {
public:
    using tiles_type = std::list< tile >;
    using size_type = tiles_type::size_type;
    using iterator = tiles_type::iterator;
    using const_iterator = tiles_type::const_iterator;

    hand(void);

    auto push(tile const tile) -> void;
    auto pop(const_iterator const iterator) -> void;
    auto pop(tile const tile) -> void;

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
