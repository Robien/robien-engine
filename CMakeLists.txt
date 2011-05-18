cmake_minimum_required(VERSION 2.6)
		
#Déclaration du projet
project(RobienEngine)

set(EXECUTABLE_OUTPUT_PATH bin)

include(FindBoost)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREAD ON)


find_package(
	Boost 
	1.36.0
	REQUIRED filesystem thread
)


IF(MINGW)
FIND_PACKAGE(libSDL REQUIRED)
ELSE(MINGW)
FIND_PACKAGE(SDL REQUIRED)
ENDIF(MINGW)

IF(MINGW)
  SET(MINGWLIB "mingw32")
ELSE(MINGW)
  SET(MINGWLIB )
ENDIF(MINGW)


FIND_PACKAGE(OpenGL REQUIRED)

link_directories(${Boost_LIBRARY_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})

INCLUDE_DIRECTORIES(sources)
ADD_SUBDIRECTORY(sources)

#Génération de la liste des fichiers sources
file(
	GLOB
	include_files
	sources/
)

INCLUDE_DIRECTORIES(${include_files})



