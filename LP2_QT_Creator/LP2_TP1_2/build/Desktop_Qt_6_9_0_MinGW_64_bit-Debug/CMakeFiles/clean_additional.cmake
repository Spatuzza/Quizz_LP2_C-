# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\LP2_TP1_2_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\LP2_TP1_2_autogen.dir\\ParseCache.txt"
  "LP2_TP1_2_autogen"
  )
endif()
