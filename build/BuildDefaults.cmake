#common build settings across all modules

#Append custom CMake modules.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

#Setup default build options,like compiler flags and build type.
include(BuildOptions)

# Setup platform dependant variables.
include(Platforms)

#add caffe
include(Caffe)


