cmake_minimum_required(VERSION 2.6)
		
#Déclaration du projet
project(RobienEngine)

IF(MINGW)
FIND_PACKAGE(libSDL REQUIRED)
ELSE(MINGW)
FIND_PACKAGE(SDL REQUIRED)
ENDIF(MINGW)

FIND_PACKAGE(opengl REQUIRED)

INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})


#Génération de la liste des fichiers sources
file(
	GLOB_RECURSE
	source_files
	src/*
	include/*
)

#Déclaration de l'exécutable
add_executable(
	robien
	${source_files}
)


IF(MINGW)
  SET(MINGWLIB "mingw32")
ELSE(MINGW)
  SET(MINGWLIB )
ENDIF(MINGW)


target_link_libraries(
	robien
	${MINGWLIB}
	${SDL_LIBRARY}
	${OPENGL_gl_LIBRARY}
	${OPENGL_glu_LIBRARY}
	${SDL_LIBRARIES}
	${SDL_LIBRARIES2}
)



