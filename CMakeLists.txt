cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 11)
project(Exercise)

#设置版本信息
set (Exercise_VERSION_MAJOR 1)
set (Exercise_VERSION_MINOR 0)


#auto 变量
#信息提示 CMakeModules设置
MESSAGE(STATUS "PROJECT_SOURCE_DIR" ${PROJECT_SOURCE_DIR})
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/CMakeModules)

MESSAGE(STATUS "PROJECT_BINARY_DIR" ${PROJECT_BINARY_DIR})
#在第一节我们提到了<projectname>_BINARY_DIR和PROJECT_BINARY_DIR变量，他们指的编译发生的当前目录，如果是内部编译，
#就相当于PROJECT_SOURCE_DIR也就是工程代码所在目录，如果是外部编译，指的是外部编译所在目录，也就是本例中的build目录


# 包含这个模块FindPackageHandleStandardArgs.cmake 
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE(EnvConfig)

#选项
#OPTION(UNIT_TEST "test option" OFF)
OPTION(UNIT_TEST "test option" ON)
IF(UNIT_TEST)
    MESSAGE("-- enable test option.")
ENDIF(UNIT_TEST)


# set up install directories. INCLUDE_INSTALL_DIR and LIB_INSTALL_DIR must not be absolute paths
set(LIB_INSTALL_DIR_SUFFIX "" CACHE STRING "The directories where to install libraries to")
set(LIB_INSTALL_DIR lib${LIB_INSTALL_DIR_SUFFIX})
set(CMAKECONFIG_INSTALL_DIR ${LIB_INSTALL_DIR}/cmake/techlib)
# Use a versioned install directory for the headers so multiple versions can be installed in parallel
set(INCLUDE_INSTALL_DIR include)
# not changable, but we set a variable anyway for consistency
set(BIN_INSTALL_DIR bin)

MESSAGE(STATUS "LIB_INSTALL_DIR_SUFFIX " ${LIB_INSTALL_DIR_SUFFIX})
MESSAGE(STATUS "LIB_INSTALL_DIR " ${LIB_INSTALL_DIR})
MESSAGE(STATUS "BIN_INSTALL_DIR " ${BIN_INSTALL_DIR})
MESSAGE(STATUS "INCLUDE_INSTALL_DIR " ${INCLUDE_INSTALL_DIR})

#包含子文件夹
ADD_SUBDIRECTORY(./ForkJoin)
ADD_SUBDIRECTORY(./FutureModel)
ADD_SUBDIRECTORY(./MasterWorker)
ADD_SUBDIRECTORY(./ProducerConsumer)
ADD_SUBDIRECTORY(./threadPool)



#设置提示信息
MESSAGE(STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${PROJECT_SOURCE_DIR})





