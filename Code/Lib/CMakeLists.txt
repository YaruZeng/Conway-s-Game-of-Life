#/*============================================================================
#
#  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.
#
#  Copyright (c) University College London (UCL). All rights reserved.
#
#  This software is distributed WITHOUT ANY WARRANTY; without even
#  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
#  PURPOSE.
#
#  See LICENSE.txt in the top level directory for details.
#
#============================================================================*/

set(PHAS0100ASSIGNMENT1_LIBRARY_NAME PHAS0100ASSIGNMENT1)

set(PHAS0100ASSIGNMENT1_LIBRARY_SRCS
  golStatus.cpp
  golGameofLife.cpp
  golException.cpp
)

set(PHAS0100ASSIGNMENT1_LIBRARY_HDRS
  golExceptionMacro.h
)

add_library(${PHAS0100ASSIGNMENT1_LIBRARY_NAME} ${PHAS0100ASSIGNMENT1_LIBRARY_HDRS} ${PHAS0100ASSIGNMENT1_LIBRARY_SRCS})

target_link_libraries(${PHAS0100ASSIGNMENT1_LIBRARY_NAME} PRIVATE ${ALL_THIRD_PARTY_LIBRARIES})

