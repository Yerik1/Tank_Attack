# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/TuProyecto_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/TuProyecto_autogen.dir/ParseCache.txt"
  "TuProyecto_autogen"
  )
endif()
