#ifndef __NK_SPARROW_HAND_H__
#define __NK_SPARROW_HAND_H__

#include <list>

#include "./tile.hpp"

namespace nk::sparrow {

template < typename Tileset >
class hand {
public:
    using tile_type = tile< Tileset >;
    using tiles_type = std::list< tile_cref< Tileset >>;
    using size_type = typename tiles_type::size_type;
    using iterator = typename tiles_type::iterator;
    using const_iterator = typename tiles_type::const_iterator;

    hand(void) :
        m_tiles()
    { }

    auto push(tile_type const& tile) -> void
    {
        auto const lb = std::lower_bound(m_tiles.cbegin(), m_tiles.cend(), tile);
        m_tiles.emplace(lb, tile);
    }

    auto pop(const_iterator const iterator) -> void
    {
        m_tiles.erase(iterator);
    }

    auto pop(tile_type const& tile) -> void
    {
        auto const lb = std::lower_bound(m_tiles.cbegin(), m_tiles.cend(), tile);
        if (lb != m_tiles.cend() and *lb == tile)
            m_tiles.erase(lb);
    }

    auto begin(void) noexcept -> iterator
    {
        return m_tiles.begin();
    }

    auto begin(void) const noexcept -> const_iterator
    {
        return cbegin();
    }

    auto cbegin(void) const noexcept -> const_iterator
    {
        return m_tiles.cbegin();
    }

    auto end(void) noexcept -> iterator
    {
        return m_tiles.end();
    }

    auto end(void) const noexcept -> const_iterator
    {
        return cend();
    }

    auto cend(void) const noexcept -> const_iterator
    {
        return m_tiles.cend();
    }

    auto size(void) const noexcept -> size_type
    {
        return m_tiles.size();
    }

private:
    tiles_type m_tiles;
};

}

#endif
