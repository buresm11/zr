cmake_minimum_required(VERSION 3.5)

project(zr)

LIST( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

set(ANTLR4CPP_JAR_LOCATION ${PROJECT_SOURCE_DIR}/thirdparty/antlr/antlr-4.7.1-complete.jar)
include( ExternalAntlr4Cpp )
include_directories( ${ANTLR4CPP_INCLUDE_DIRS} )
link_directories( ${ANTLR4CPP_LIBS} )
message(STATUS "Found antlr4cpp libs: ${ANTLR4CPP_LIBS} and includes: ${ANTLR4CPP_INCLUDE_DIRS} ")

set(antlr4cpp_include_dirs_${antlr4cpp_project_namespace} ${ANTLR4CPP_GENERATED_SRC_DIR}/${antlr4cpp_project_namespace})
message(STATUS "Antlr4Cpp ${antlr4cpp_project_namespace} include: ${ANTLR4CPP_GENERATED_SRC_DIR}/${antlr4cpp_project_namespace}")

message(STATUS "Local configuration:")
include_directories("/opt/llvm/llvm-src-370/include")
include_directories("${CMAKE_SOURCE_DIR}/src")

set(LLVM_DIR "/opt/llvm/llvm-release-370/cmake/modules/CMakeFiles")

add_definitions(--std=c++11 -g)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

FILE(GLOB parser_files ${PROJECT_SOURCE_DIR}/grammar/*.cpp)

foreach(generated_file ${parser_files})
   list(APPEND gsrc ${generated_file})
   set_source_files_properties(
    ${generated_file}
    PROPERTIES
    COMPILE_FLAGS -Wno-overloaded-virtual
    )
endforeach(generated_file)


FILE(GLOB src_files ${PROJECT_SOURCE_DIR}/src/*.cpp)

 foreach(src_file ${src_files})
   list(APPEND ssrc ${src_file})
   set_source_files_properties(
    ${src_file}
    PROPERTIES
    COMPILE_FLAGS -Wno-overloaded-virtual
    )
endforeach(src_file)

FILE(GLOB opt_files ${PROJECT_SOURCE_DIR}/src/opt/*.cpp)

 foreach(opt_file ${opt_files})
   list(APPEND osrc ${opt_file})
   set_source_files_properties(
    ${opt_file}
    PROPERTIES
    COMPILE_FLAGS -Wno-overloaded-virtual
    )
endforeach(opt_file)


# add sources
#file(GLOB_RECURSE SRC "src/*.cpp" "src/*.h"  )
#message(STATUS "Found LLVxM ${SRC}")

include_directories(${PROJECT_SOURCE_DIR}/grammar)
include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(zr ${gsrc} ${ssrc} ${osrc})
add_dependencies(zr antlr4cpp)

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(LLVM_LIBS support core mcjit native irreader linker ipo bitwriter)
target_link_libraries(zr antlr4-runtime ${LLVM_LIBS})