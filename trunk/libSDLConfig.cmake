# - Find SDL
# Componants can be :
#
# NoThing
#
#
#
#  REMEMBER : The order of the component is very important.
#
#  SDL_INCLUDE_DIRS - where to find digiplant/Utils/FromString.h, etc.
#  SDL_LIBRARIES    - List of libraries when using SDL.
#  SDL_FOUND        - True if SDL found.

# Look for the header file.
FIND_PATH(SDL_INCLUDE_DIR SDL/SDL.h
	/usr/local/include/libSDL
	/usr/local/include/SDL
	/usr/local/include
	/usr/include/libSDL
	/usr/include/SDL
	/usr/local/include
	/usr/include
	C:/Program Files (x86)/SDL/include
	C:/Program Files (x86)/SDL
	C:/SDL/include
	C:/SDL
	"$ENV{SDL_ROOT}/include"
	"$ENV{SDL_ROOT}/include/libSDL"
	"$ENV{SDL_ROOT}/include/SDL"
	)
	
MARK_AS_ADVANCED(SDL_INCLUDE_DIR)

# Look for the library.
SET(SEARCH_PATH
 /usr/lib
  /usr/lib64
  /usr/local/lib64 
  /opt/local/lib64
  /usr/local/lib 
  /opt/local/lib
  C:/Program Files (x86)/SDL/lib
  C:/SDL/lib/
  "$ENV{SDL_ROOT}/lib")

SET(COMPONENT SDLmain)

    FIND_LIBRARY( SDL_LIBRARIES
		NAMES ${COMPONENT}
		PATHS ${SEARCH_PATH})
		

  
SET(COMPONENT SDL)

    FIND_LIBRARY( SDL_LIBRARIES2
		NAMES ${COMPONENT}
		PATHS ${SEARCH_PATH})
		
	

		MARK_AS_ADVANCED(SDL_LIBRARIES)
# handle the QUIETLY and REQUIRED arguments and set SDL_FOUND to TRUE if 
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL DEFAULT_MSG SDL_INCLUDE_DIR SDL_LIBRARIES)

IF(SDL_FOUND)
  SET(SDL_INCLUDE_DIRS ${SDL_INCLUDE_DIR})
ELSE(SDL_FOUND)
  SET(SDL_INCLUDE_DIRS)
ENDIF(SDL_FOUND)
