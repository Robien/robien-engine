cmake_minimum_required(VERSION 2.6)
		
#Déclaration du projet
project(RobienEngine)

FIND_PACKAGE(SDL REQUIRED)
INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIR})



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

target_link_libraries(
	robien
	${SDL_LIBRARY}
)



