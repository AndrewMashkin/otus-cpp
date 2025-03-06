file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test/*.h)

set(TEST_PRJ_NAME version_api)

add_executable(${TEST_PRJ_NAME}_t ${SRC})

target_link_libraries(${TEST_PRJ_NAME}_t gtest_main version_lib)
set_target_properties(${TEST_PRJ_NAME}_t PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${TEST_OUTPUT_PATH})
set_target_properties(${TEST_PRJ_NAME}_t PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${TEST_OUTPUT_PATH})
add_test(NAME ${TEST_PRJ_NAME}_t COMMAND ${TEST_PRJ_NAME}_t WORKING_DIRECTORY ${TEST_OUTPUT_PATH})

message("AAAA" ${TEST_OUTPUT_PATH})




