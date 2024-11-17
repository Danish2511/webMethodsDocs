#
#
#     Copyright (c) 1999 - 2011 my-Channels Ltd
#     Copyright (c) 2012 - 2022 Software AG, Darmstadt, Germany and/or Software AG USA Inc., Reston, VA, USA, and/or its subsidiaries and/or its affiliates and/or their licensors.
#
#     Use, reproduction, transfer, publication or disclosure is prohibited except as specifically provided for in your License Agreement with Software AG.
#
#

cmake_minimum_required (VERSION 2.6)
set(Project "deletequeuejoin")
set(Include_Path "../..")

project (${Project})
include_directories( "../nSampleApp/")
include_directories( "${Include_Path}/include")
include_directories( "${Include_Path}/include/nbase")
include_directories( "${Include_Path}/include/nbase/events")
include_directories( "${Include_Path}/include/foundation")
include_directories( "${Include_Path}/include/foundation/threads")
include_directories( "${Include_Path}/include/foundation/security")
include_directories( "${Include_Path}/include/foundation/drivers")
include_directories( "${Include_Path}/include/foundation/drivers/shm")
include_directories( "${Include_Path}/include/foundation/drivers/multicast")
include_directories( "${Include_Path}/include/foundation/drivers/configuration")
include_directories( "${Include_Path}/include/client")
include_directories( "${Include_Path}/include/client/p2p")
include_directories( "${Include_Path}/include/nAdmin")
include_directories( "${Include_Path}/include/nAdminAPI")
include_directories( "${Include_Path}/include/umTransport")
include_directories( "../exampleBase/")

#
# Add the library directive
#
include ("sourceList.txt")

#
# Detect and set the OS and build type
#
include (CheckTypeSize)
check_type_size("void *" SIZE_OF_VOID_P )
#
#
if( CMAKE_SYSTEM_PROCESSOR STREQUAL "armv7l")
     message(STATUS "Setting to ARM")
     link_directories("../../lib/Linux/armv7l" "../../../../common/security/openssl/lib" "../../../../common/security/openssl/bin" )
     set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "../../lib/Linux/armv7l" "../../../../common/security/openssl/lib" "../../../../common/security/openssl/bin")
else()
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(arch "x86_64")
         link_directories("../../lib/x86_64" "../../../../common/security/openssl/lib" "../../../../common/security/openssl/bin")
         set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "../../lib/x86_64" "../../../../common/security/openssl/lib" "../../../../common/security/openssl/bin")
    else()
         set(arch "x86")
         link_directories("../../lib/x86" "../../../../common/security/openssl32/lib" "../../../../common/security/openssl32/bin")
         set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "../../lib/x86" "../../../../common/security/openssl32/lib" "../../../../common/security/openssl32/bin")
    endif()
endif()

#
# With the use of advanced pointers we need to specify the standards level for Linux G++ to at least 10
#
if(UNIX)
    set(os "Linux")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")
    message(STATUS "Specified langauge level to gnu++0x")
endif()

if( WIN32)
    set(os "windows")
    message(STATUS "If you want 64bit Windows, please specify the 64bit VS environment on the command line")

    set (BUILD_SHARED_LIBS FALSE) # should force the libraries to be static
    message(STATUS "Setting shared libs to false")
endif()

if( APPLE)
    set(os "Darwin")
endif()

Message(STATUS "Discovered OS as ${os} and architecture as ${arch}" )


add_executable ( ${Project} ${SRC} )

target_link_libraries(${Project} debug PocoUtild)
target_link_libraries(${Project} debug PocoFoundationd)
target_link_libraries(${Project} debug PocoNetd)
target_link_libraries(${Project} debug PocoNetSSLd)
target_link_libraries(${Project} debug PocoCryptod)

target_link_libraries(${Project} optimized PocoUtil)
target_link_libraries(${Project} optimized PocoFoundation)
target_link_libraries(${Project} optimized PocoNet)
target_link_libraries(${Project} optimized PocoNetSSL)
target_link_libraries(${Project} optimized PocoCrypto)

target_link_libraries(${Project} Nirvana)

IF(WIN32)
    TARGET_LINK_LIBRARIES(${Project} ws2_32)
ENDIF(WIN32)


#
# Now Build it
#

target_link_libraries(${Project})

