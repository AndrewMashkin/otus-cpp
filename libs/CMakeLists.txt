project(libs)

if(UNITTEST)
    set(BUILD_GMOCK OFF)
    add_subdirectory(gtest_framework)
    include(CTest)
endif()

