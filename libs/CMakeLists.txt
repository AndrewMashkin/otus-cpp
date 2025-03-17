project(libs)

if(UNITTEST)
    add_subdirectory(gtest_framework)
    include(CTest)
endif()

add_subdirectory(ip_filter)
add_subdirectory(ip_loader)
