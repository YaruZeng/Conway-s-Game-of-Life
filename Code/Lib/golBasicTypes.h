/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef golBasicTypes_h
#define golBasicTypes_h
#include <iostream>
#include <string>
#include <vector>
/**
* \defgroup internal internal
* \brief Internal stuff, not for end-users.
*/

/**
* \defgroup types types
* \brief Package-wide data types.
*/

/**
* \defgroup utilities utilities
* \brief Groups of c-style functions.
*/

/**
* \defgroup applications applications
* \brief Small, end-user applications, most likely command line.
*/

/**
* \file golBasicTypes.h
* \brief Defines types and typedefs used in this library.
* \ingroup types
*/

//! Single namespace for all code in this package
namespace gol
{
  class Status
  {
    public:
    Status(const int& columns, const int& rows);
    void StatusSet(const int& columns, const int& rows, const std::string& status);
    std::string StatusGet(const int& columns, const int& rows);
    void StatusPrint();

    int m_columns;
    int m_rows;
    int m_alive;
    std::vector<std::vector<std::string>> m_grid;

  };

} // end namespace

#endif
