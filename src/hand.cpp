#include <algorithm>

#include <sparrow/hand.h>

namespace nk::sparrow {

hand::hand(void)
    : m_tiles()
{ }

auto hand::push(tile const tile) -> void
{
    auto const lb = std::lower_bound(m_tiles.cbegin(), m_tiles.cend(), tile);
    m_tiles.emplace(lb, tile);
}

auto hand::pop(const_iterator const iterator) -> void
{
    m_tiles.erase(iterator);
}

auto hand::pop(tile const tile) -> void
{
    auto const lb = std::lower_bound(m_tiles.cbegin(), m_tiles.cend(), tile);
    if (lb != m_tiles.cend() and *lb == tile)
        m_tiles.erase(lb);
}

auto hand::begin(void) noexcept -> iterator
{
    return m_tiles.begin();
}

auto hand::begin(void) const noexcept -> const_iterator
{
    return cbegin();
}

auto hand::cbegin(void) const noexcept -> const_iterator
{
    return m_tiles.cbegin();
}

auto hand::end(void) noexcept -> iterator
{
    return m_tiles.end();
}

auto hand::end(void) const noexcept -> const_iterator
{
    return cend();
}

auto hand::cend(void) const noexcept -> const_iterator
{
    return m_tiles.cend();
}

auto hand::size(void) const noexcept -> size_type
{
    return m_tiles.size();
}


}
