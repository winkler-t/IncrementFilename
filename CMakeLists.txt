cmake_minimum_required(VERSION 3.11.0)
project("IncrementFilenames" VERSION 1.0.0.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CPP_STANDARD 17)

cmake_policy(SET CMP0041 NEW)

set(ProjectDir ${PROJECT_SOURCE_DIR})

set(PROJECT_SYS_ARCH ${CMAKE_SYSTEM_PROCESSOR})
set(PROJECT_SYS_OS ${CMAKE_SYSTEM_NAME})

set(IncrementFilenamesDir ${PROJECT_SOURCE_DIR})
set(IncrementFilenamesSrcDir ${IncrementFilenamesDir}/src)
set(IncrementFilenamesOutDir ${IncrementFilenamesDir}/bin)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${IncrementFilenamesOutDir})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${IncrementFilenamesOutDir})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${IncrementFilenamesOutDir})

message(STATUS "---------------------------------------------------------")
message(STATUS "| + IncrementFilenamesDir: ${IncrementFilenamesDir}")
message(STATUS "| + IncrementFilenamesSrcDir: ${IncrementFilenamesSrcDir}")
message(STATUS "| + IncrementFilenamesOutDir: ${IncrementFilenamesOutDir}")
message(STATUS "---------------------------------------------------------")

set(IncrementFilenamesHeaderList

)

set(IncrementFilenamesSourceList
    "${IncrementFilenamesSrcDir}/main.cpp"
)

add_executable(IncrementFilenames ${IncrementFilenamesSourceList} ${IncrementFilenamesHeaderList})
target_include_directories(IncrementFilenames PRIVATE "${IncrementFilenamesSrcDir}")

target_compile_features(IncrementFilenames PUBLIC cxx_std_17 c_std_17)

message(STATUS "--------------------------------------------")
message(STATUS "| + System architecture: ${PROJECT_SYS_ARCH}")
message(STATUS "| + Operating system: ${PROJECT_SYS_OS}")
message(STATUS "--------------------------------------------")