cmake_minimum_required(VERSION 2.6)

INCLUDE_DIRECTORIES(
../utils/include/*.h
include/*.h
)


set(LIBRARY_OUTPUT_PATH ${RobienEngine_BINARY_DIR}/bin)
SET(LIB_NAME video)
FILE(GLOB_RECURSE SRC src/*.cpp include/*.h)
ADD_LIBRARY(${LIB_NAME} SHARED ${SRC})

target_link_libraries(
	${LIB_NAME}
	utils
	${MINGWLIB}
	${SDL_LIBRARY}
	${OPENGL_gl_LIBRARY}
	${OPENGL_glu_LIBRARY}
	${SDL_LIBRARIES}
	${SDL_LIBRARIES2}
	${Boost_LIBRARIES}
	)