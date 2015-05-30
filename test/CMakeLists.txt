# Create the test binary
if(WIN32)
  string(REPLACE "/" "\\\\" CMAKE_CURRENT_BINARY_DIR_NATIVE ${CMAKE_CURRENT_BINARY_DIR})
  string(REPLACE "/" "\\\\" CMAKE_RUNTIME_OUTPUT_DIRECTORY_NATIVE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
else()
  set(CMAKE_CURRENT_BINARY_DIR_NATIVE ${CMAKE_CURRENT_BINARY_DIR})
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_NATIVE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/TestConfig.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/TestConfig.h)

# add custom target so that the test executable is rebuilt when the config header is regenerated
add_custom_target(TestConfigTarget DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/TestConfig.h)
add_dependencies(${BII_test_main_TARGET} TestConfigTarget)

target_include_directories(${BII_test_main_TARGET} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

# Run the test
enable_testing()

add_test(NAME ${BII_test_main_TARGET}
         COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BII_test_main_TARGET})
