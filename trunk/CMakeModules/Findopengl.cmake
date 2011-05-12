# - Find OPENGL
# Componants can be :
#
# NoThing
#
#
#
#  REMEMBER : The order of the component is very important.
#
#  OPENGL_INCLUDE_DIRS - where to find digiplant/Utils/FromString.h, etc.
#  OPENGL_LIBRARIES    - List of libraries when using OPENGL.
#  OPENGL_FOUND        - True if OPENGL found.

# Look for the header file.
FIND_PATH(OPENGL_INCLUDE_DIR GL/gl.h
	/usr/local/include/libOPENGL
	/usr/local/include/OPENGL
	/usr/local/include
	/usr/include/libOPENGL
	/usr/include/OPENGL
	/usr/local/include
	/usr/include
	C:/Program Files (x86)/OPENGL/include
	C:/Program Files (x86)/OPENGL/include/OPENGL
	C:/Program Files (x86)/OPENGL
	C:/OPENGL/include
	C:/OPENGL/include/OPENGL
	C:/OPENGL
	"$ENV{OPENGL_ROOT}/include"
	"$ENV{OPENGL_ROOT}/include/libOPENGL"
	"$ENV{OPENGL_ROOT}/include/OPENGL"
	)
	
MARK_AS_ADVANCED(OPENGL_INCLUDE_DIR)

# Look for the library.
SET(SEARCH_PATH
 /usr/lib
  /usr/lib64
  /usr/local/lib64 
  /opt/local/lib64
  /usr/local/lib 
  /opt/local/lib
  C:/Program Files (x86)/OPENGL/lib
  C:/Program Files (x86)/OPENGL/
  C:/OPENGL/
  C:/OPENGL/lib
  "$ENV{OPENGL_ROOT}/lib")

SET(COMPONENT OPENGL)

    FIND_LIBRARY( OPENGL_LIBRARIES
		NAMES ${COMPONENT} 
		PATHS ${SEARCH_PATH})
		
		MARK_AS_ADVANCED(OPENGL_LIBRARIES)
  

	

# handle the QUIETLY and REQUIRED arguments and set OPENGL_FOUND to TRUE if 
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(OPENGL DEFAULT_MSG OPENGL_INCLUDE_DIR OPENGL_LIBRARIES)

IF(OPENGL_FOUND)
  SET(OPENGL_INCLUDE_DIRS ${OPENGL_INCLUDE_DIR})
  SET(OPENGL_LIBRARIES ${OPENGL_LIBRARY})
ELSE(OPENGL_FOUND)
  SET(OPENGL_INCLUDE_DIRS)
ENDIF(OPENGL_FOUND)
