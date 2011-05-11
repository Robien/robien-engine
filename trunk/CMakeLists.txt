cmake_minimum_required(VERSION 2.6)
		
#Déclaration du projet
project(RobienEngine)

#Génération de la liste des fichiers sources
file(
	GLOB
	source_files
	*.cpp
	*.h
)

#Déclaration de l'exécutable
add_executable(
	robien
	${source_files}
)