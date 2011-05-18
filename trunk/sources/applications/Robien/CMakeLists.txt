cmake_minimum_required(VERSION 2.6)
		

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include(FindBoost)

#Génération de la liste des fichiers sources
file(
	GLOB
	include_files
	include/
)

INCLUDE_DIRECTORIES(${include_files})

#Génération de la liste des fichiers sources
file(
	GLOB
	source_files
	src/*.cpp
)

#Déclaration de l'exécutable
add_executable(
	robien
	${source_files}
)



target_link_libraries(
	robien
	${MINGWLIB}
	${SDL_LIBRARY}
	${OPENGL_gl_LIBRARY}
	${OPENGL_glu_LIBRARY}
	${SDL_LIBRARIES}
	${SDL_LIBRARIES2}
	${Boost_LIBRARIES}
	utils
	video
)



