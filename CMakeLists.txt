project(${BII_BLOCK_NAME})

include(azriel/sl_cmake/slBlockFunctions)
include(biicode/cmake/tools)

# Bii variables
set(BII_LIB_DEPS ${BII_LIB_DEPS} azriel_cppmicroservices)
set(BII_LIB_SRC Activity.cpp
                Application.cpp
                impl/SlCoreApplicationActivator.cpp)
set(BII_test_main_SRC test/main.cpp)

usFunctionGenerateModuleInit(BII_LIB_SRC MODULE_NAME ${BII_BLOCK_NAME})

# Actually create targets: executables and libraries.
ADD_BII_TARGETS()

ACTIVATE_CPP11(${BII_LIB_TARGET})
ADAPT_TARGETS_FOR_CPPMICROSERVICES()

SL_INCLUDE_TESTS(${BII_test_main_TARGET})