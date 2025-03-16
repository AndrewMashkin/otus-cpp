project(libs)

if(UNITTEST)
    add_subdirectory(gtest_framework)
    include(CTest)
endif()

add_subdirectory(ip)
add_subdirectory(ip_loader)
