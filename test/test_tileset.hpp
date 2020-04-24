#ifndef __NK_SPARROW_TEST_TILESET_HPP__
#define __NK_SPARROW_TEST_TILESET_HPP__

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

    tileset(void) = delete;
};

}

#endif
