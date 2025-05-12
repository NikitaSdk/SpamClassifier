cmake_minimum_required(VERSION 3.30)
project(Test2)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_TOOLCHAIN_FILE "C:/Users/user/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

add_definitions(-D_ITERATOR_DEBUG_LEVEL=2)
add_definitions(-DDLIB_USE_CBLAS)

include_directories("C:/Users/user/vcpkg/installed/x64-windows/include")
link_directories("C:/Users/user/vcpkg/installed/x64-windows/debug/lib")
link_directories("C:/Users/user/vcpkg/installed/x64-windows/lib")

add_executable(DlibTest main.cpp)

target_link_libraries(DlibTest PRIVATE
        debug C:/Users/user/vcpkg/installed/x64-windows/debug/lib/dlib.lib
        optimized C:/Users/user/vcpkg/installed/x64-windows/lib/dlib.lib
        debug C:/Users/user/vcpkg/installed/x64-windows/debug/lib/openblas.lib
        optimized C:/Users/user/vcpkg/installed/x64-windows/lib/openblas.lib
)

cmake_minimum_required(VERSION 3.30)
project(CodeForTest1withC)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_TOOLCHAIN_FILE "C:/Users/user/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

if(MSVC)
    add_definitions(-D_ITERATOR_DEBUG_LEVEL=2)
    add_definitions(-DDLIB_USE_CBLAS)
    add_definitions(-D_DEBUG)
endif()

include_directories("C:/Users/user/vcpkg/installed/x64-windows/include")

set(SOURCES
    main.cpp
    SpamClassifier.cpp
    DataLoader.cpp
)

add_executable(CodeForTest1withC ${SOURCES})

target_link_libraries(CodeForTest1withC PRIVATE
    $<$<CONFIG:Debug>:C:/Users/user/vcpkg/installed/x64-windows/debug/lib/dlib.lib>
    $<$<CONFIG:Release>:C:/Users/user/vcpkg/installed/x64-windows/lib/dlib.lib>
    $<$<CONFIG:Debug>:C:/Users/user/vcpkg/installed/x64-windows/debug/lib/openblas.lib>
    $<$<CONFIG:Release>:C:/Users/user/vcpkg/installed/x64-windows/lib/openblas.lib>
)


