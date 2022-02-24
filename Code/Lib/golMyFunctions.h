/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef golMyFunctions_h
#define golMyFunctions_h
#include "golBasicTypes.h"
#include <iostream>
#include <string>
#include <vector>
/**
* \file golMyFunctions.h
* \brief Various Utilities.
* \ingroup utilities
*/
namespace gol
{
  class GameofLife: public gol::Status
  {
    public:
    GameofLife(const Status& s);
    ~GameofLife();
    void TakeStep();
    void PrintGrid();

    Status m_currstatus;

  };

} // end namespace

#endif
