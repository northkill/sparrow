#ifndef __NK_SPARROW_HAND_HPP__
#define __NK_SPARROW_HAND_HPP__

#include "./tile.hpp"

namespace nk::sparrow {

template < typename Tileset, template < typename ... Args > typename Container >
class hand {
public:
    using tiles_type = Container< tile_cref< Tileset >>;
    using tile_type = tile< Tileset >;
    using iterator = typename tiles_type::iterator;
    using const_iterator = typename tiles_type::const_iterator;

    hand(void) :
        m_tiles()
    { }

    auto push(tile_type const& tile)
    {
        auto const lb = std::lower_bound(m_tiles.cbegin(), m_tiles.cend(), tile);
        m_tiles.emplace(lb, tile);
    }

    auto pop(const_iterator const iterator)
    {
        m_tiles.erase(iterator);
    }

    auto pop(tile_type const& tile)
    {
        auto const lb = std::lower_bound(m_tiles.cbegin(), m_tiles.cend(), tile);
        if (lb != m_tiles.cend() and *lb == tile)
            m_tiles.erase(lb);
    }

    auto begin(void) noexcept
    {
        return m_tiles.begin();
    }

    auto begin(void) const noexcept
    {
        return cbegin();
    }

    auto cbegin(void) const noexcept
    {
        return m_tiles.cbegin();
    }

    auto end(void) noexcept
    {
        return m_tiles.end();
    }

    auto end(void) const noexcept
    {
        return cend();
    }

    auto cend(void) const noexcept
    {
        return m_tiles.cend();
    }

    auto size(void) const noexcept
    {
        return m_tiles.size();
    }

private:
    tiles_type m_tiles;
};

}

#endif
