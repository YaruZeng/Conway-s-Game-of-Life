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
#include <fstream>

namespace gol 
{
  
  Status::Status(const int& rows, const int& columns)
  {
    m_rows = rows;
    m_columns = columns;
    
    std::vector<int> grid_rows;
    
    for(int i=0; i<m_columns; i++)
    {
      grid_rows.push_back(0);
    }
    for(int j=0; j<m_rows; j++)
    {
      m_grid.push_back(grid_rows);
    }
  }


  Status::Status(const int& rows, const int& columns, const int& num_alive)
  {
    m_rows = rows;
    m_columns = columns;
    std::vector<int> grid_rows;
    
    for(int i=0; i<m_columns; i++)
    {
      grid_rows.push_back(0);
    }
    for(int j=0; j<m_rows; j++)
    {
      m_grid.push_back(grid_rows);
    }

    int tol = m_columns*m_rows;
    m_alive = num_alive > tol? tol : num_alive;
    srand((unsigned)time(NULL));
    int count = 0;
    int alive_row = 0;
    int alive_column = 0;

    while(count < m_alive)
    {
      alive_row = rand() % m_rows;
      alive_column = rand() % m_columns;

      if(m_grid[alive_row][alive_column] == 1) continue;
      m_grid[alive_row][alive_column] = 1;
      count++;

    }
  }


  Status::Status(const std::string& filepath)
  {
    std::ifstream infile(filepath);
    std::string s;
    
    if (!infile)
    {
      std::cout << "Failed to open the file." << std::endl;
    }
    else
    {
      while (getline(infile, s))
      {
        std::vector<int> grid_rows={};
        int col_count = 0;
        for(auto value:s)
        {
          switch (value)
          {
            case '-': 
            grid_rows.push_back(0);
            ++col_count;
            break;

            case 'o': 
            grid_rows.push_back(1);
            ++col_count;
            m_alive++;
            break;
          }
        }
        m_grid.push_back(grid_rows);
        m_columns = col_count;
        m_rows++;
      }
      infile.close();
    }

  }
  

  void Status::StatusSet(const int& rows, const int& columns, const std::string& status)
  {
    if(status=="alive"||"o")
    {
      m_grid[rows][columns] = 1;
    }
    else if (status=="dead"||"-")
    {
      m_grid[rows][columns] = 0;
    }
    
  }


  std::string Status::StatusGet(const int& rows, const int& columns)
  {
    return m_grid[rows][columns] == 0 ? "-" : "o";
  }


  void Status::StatusPrint()
  {
    for(int i=0; i<m_rows; i++)
    {
      for(int j=0; j<m_columns; j++)
      {
        std::string status = m_grid[i][j] == 0 ? "-" : "o";
        std::cout << status << ' ';
      }
      std::cout << '\n';
    }
    std::cout << std::endl;
  }

} // end namespace
