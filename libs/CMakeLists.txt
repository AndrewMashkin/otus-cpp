project(libs)

if(UNITTEST)
    set(BUILD_GMOCK OFF)
    add_subdirectory(test)
    include(CTest)
endif()

