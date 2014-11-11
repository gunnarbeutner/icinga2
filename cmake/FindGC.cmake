# - Try to find libgc
# Once done this will define
#  GC_FOUND - System has GC
#  GC_INCLUDE_DIRS - The GC include directories
#  GC_LIBRARIES - The libraries needed to use GC
#  GC_DEFINITIONS - Compiler switches required for using GC

find_package(PkgConfig)
pkg_check_modules(PC_GC QUIET gc)
set(GC_DEFINITIONS ${PC_GC_CFLAGS_OTHER})

find_path(GC_INCLUDE_DIR gc/gc.h
          HINTS ${PC_GC_INCLUDEDIR} ${PC_GC_INCLUDE_DIRS}
          PATH_SUFFIXES libgc)

find_library(GC_LIBRARY NAMES gc libgc
             HINTS ${PC_GC_LIBDIR} ${PC_GC_LIBRARY_DIRS})

set(GC_LIBRARIES ${GC_LIBRARY} )
set(GC_INCLUDE_DIRS ${GC_INCLUDE_DIR})

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set GC_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(gc DEFAULT_MSG
                                  GC_LIBRARY GC_INCLUDE_DIR)

mark_as_advanced(GC_INCLUDE_DIR GC_LIBRARY)
