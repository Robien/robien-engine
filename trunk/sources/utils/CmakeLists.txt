cmake_minimum_required(VERSION 2.6)

INCLUDE_DIRECTORIES(
include/*.h
)


set(LIBRARY_OUTPUT_PATH ${RobienEngine_BINARY_DIR}/bin)
SET(LIB_NAME utils)
FILE(GLOB_RECURSE SRC src/*.cpp include/*.h)
ADD_LIBRARY(${LIB_NAME} SHARED ${SRC})

