cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(MVC VERSION ${PROJECT_VESRION})

configure_file(lib/version_lib/version_define.h.in version_define.h)

set(HEADERS src/view.h
  src/model.h
  src/model_facade.h
  src/controller.h
)

set(SOURCES src/view.cpp
  src/model.cpp
  src/model_facade.cpp
  src/controller.cpp
)

add_library(version lib/version_lib/version.cpp lib/version_lib/version.h)
add_executable(MVC ${SOURCES} ${HEADERS})

target_include_directories(version
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(MVC PRIVATE
    version
)

install(TARGETS MVC RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
