project(sl_core_application)

include(biicode/cmake/tools)

# Bii variables
set(BII_LIB_SRC Activity.cpp
                Application.cpp
                impl/SlCoreApplicationActivator.cpp)
SET(BII_LIB_DEPS ${BII_LIB_DEPS} azriel_cppmicroservices)
set(BII_test_main_SRC test/main.cpp)

usFunctionGenerateModuleInit(BII_LIB_SRC MODULE_NAME ${PROJECT_NAME})

# Actually create targets: executables and libraries.
ADD_BII_TARGETS()

ACTIVATE_CPP11(${BII_LIB_TARGET})
set_property(TARGET ${BII_LIB_TARGET} APPEND PROPERTY COMPILE_DEFINITIONS US_MODULE_NAME=${PROJECT_NAME})

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(${BII_LIB_TARGET} PRIVATE US_STATIC_MODULE)
endif()

# Tests
if(NOT ${BII_IS_DEP})
  # Need to tell GTest not to use std::tuple because CppMicroServices uses its own definition, and it causes a redefinition error
  target_compile_definitions(${BII_test_main_TARGET} PRIVATE GTEST_HAS_TR1_TUPLE=1 GTEST_USE_OWN_TR1_TUPLE=0)

  add_subdirectory(test)
endif()
