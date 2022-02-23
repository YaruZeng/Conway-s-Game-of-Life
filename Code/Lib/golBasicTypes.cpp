/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "golBasicTypes.h"
#include <random>
#include <stdlib.h> 
#include <time.h>  

namespace gol 
{
  Status::Status(const int& rows, const int& columns)
  {
    m_rows = rows;
    m_columns = columns;
    
    std::vector<std::string> grid_rows;
    
    for(int i=0; i<m_columns; i++)
    {
      grid_rows.push_back("-");
    }
    for(int j=0; j<m_rows; j++)
    {
      m_grid.push_back(grid_rows);
    }
  }

  void Status::StatusSet(const int& columns, const int& rows, const std::string& status)
  {
    m_grid[columns][rows] = status;
  }

  std::string Status::StatusGet(const int& columns, const int& rows)
  {
    return m_grid[columns][rows];
  }

  void Status::StatusPrint()
  {
    for(int i=0; i<m_rows; i++)
    {
      for(int j=0; j<m_columns; j++)
      {
        std::cout << m_grid[i][j] << ' ';
      }
      std::cout << '\n';
    }
    std::cout << std::endl;
  }

} // end namespace
