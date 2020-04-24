#ifndef __NK_SPARROW_TEST_TILESET_H__
#define __NK_SPARROW_TEST_TILESET_H__

#include <variant>

namespace nk::sparrow::test {

class tileset {
public:
    enum class a {
        one, two, three, four, five
    };

    enum class b {
        one, two, three, four, five
    };

    enum class c {
        one, two, three, four, five
    };

    using value = std::variant< a, b, c >;

    enum class suit {
        a = value(a::one).index(),
        b = value(b::one).index(),
        c = value(c::one).index(),
    };

    tileset(void) = delete;
};

}

#endif
