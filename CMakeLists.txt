CMAKE_MINIMUM_REQUIRED (VERSION 3.17)

PROJECT (Sparrow)

FIND_PACKAGE (Boost 1.72 REQUIRED COMPONENTS serialization)

ADD_LIBRARY (
    sparrow
    "./src/tile.cpp"
    "./src/hand.cpp"
)

TARGET_LINK_LIBRARIES (
    sparrow
    Boost::serialization
)

TARGET_INCLUDE_DIRECTORIES (
    sparrow
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

SET_TARGET_PROPERTIES (
    sparrow
    PROPERTIES CXX_STANDARD 17
)

IF (SPARROW_ENABLE_TEST)
    FIND_PACKAGE (Boost 1.72 REQUIRED COMPONENTS unit_test_framework)
    ADD_EXECUTABLE (
        sparrow-test
        "./test/hand_test.cpp"
        "./test/strong_typedef_test.cpp"
        "./test/test.cpp"
        "./test/tile_test.cpp"
    )
    SET_TARGET_PROPERTIES (
        sparrow-test
        PROPERTIES CXX_STANDARD 17
    )
    TARGET_COMPILE_OPTIONS (
        sparrow
        PRIVATE -fprofile-instr-generate
        PRIVATE -fcoverage-mapping
    )
    TARGET_COMPILE_OPTIONS (
        sparrow-test
        PRIVATE -fprofile-instr-generate
        PRIVATE -fcoverage-mapping
    )
    TARGET_LINK_OPTIONS (
        sparrow
        PRIVATE -fprofile-instr-generate
    )
    TARGET_LINK_OPTIONS (
        sparrow-test
        PRIVATE -fprofile-instr-generate
    )
    TARGET_COMPILE_DEFINITIONS (
        sparrow-test
        PRIVATE BOOST_TEST_DYN_LINK)
    TARGET_LINK_LIBRARIES (
        sparrow-test
        Boost::unit_test_framework
        sparrow
    )
    ADD_CUSTOM_TARGET (
        sparrow-coverage
        COMMAND
            ${CMAKE_COMMAND} -E
                env LLVM_PROFILE_FILE=$<TARGET_FILE_DIR:sparrow-test>/$<TARGET_FILE_BASE_NAME:sparrow-test>.profraw
                $<TARGET_FILE:sparrow-test>
        COMMAND
            llvm-profdata merge
                --sparse
                --output $<TARGET_FILE_DIR:sparrow-test>/$<TARGET_FILE_BASE_NAME:sparrow-test>.profdata
                $<TARGET_FILE_DIR:sparrow-test>/$<TARGET_FILE_BASE_NAME:sparrow-test>.profraw
        COMMAND
            llvm-cov show
                --format html
                --instr-profile $<TARGET_FILE_DIR:sparrow-test>/$<TARGET_FILE_BASE_NAME:sparrow-test>.profdata
                --output-dir "${PROJECT_SOURCE_DIR}/coverage"
                $<TARGET_FILE:sparrow-test>
        DEPENDS sparrow-test
        WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")
ENDIF (SPARROW_ENABLE_TEST)
