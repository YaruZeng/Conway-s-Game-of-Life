#include "golStatus.h"
#include <random>
#include <stdlib.h> 
#include <time.h>  
#include <fstream>
#include <algorithm>
#include <stdexcept>

namespace gol 
{
  Status::Status(){}
  Status::~Status(){}
  Status::Status(const int& rows, const int& columns)
  {
    if((rows <= 1)||(columns <= 1)) 
    {
      throw std::logic_error("Rows and Columns should be ints larger than 1.");
    }

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
    if((rows <= 0)||(columns <= 0)) 
    {
      throw std::logic_error("Rows and Columns should be ints larger than 0.");
    }

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
  

  void Status::StatusSet(const int& row, const int& column, const std::string& status)
  {
    if((row < 0)||(column < 0)) 
    {
      throw std::logic_error("Row and Column should be ints larger than or equal to 0.");
    }

    if(status=="alive"||"o")
    {
      m_grid[row][column] = 1;
    }
    else if (status=="dead"||"-")
    {
      m_grid[row][column] = 0;
    }
    
  }


  std::string Status::StatusGet(const int& row, const int& column)
  {
    if((row < 0)||(column < 0)) 
    {
      throw std::logic_error("Row and Column should be ints larger than or equal to 0.");
    }

    return m_grid[row][column] == 0 ? "-" : "o";
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


  int Status::NeighAlive(const int& row, const int& column)
  {
    if((row < 0)||(column < 0)) 
    {
      throw std::logic_error("Row and Column should be ints larger than or equal to 0.");
    }

    int up = 0;
    int down = 0;
    int left = 0;
    int right = 0;
    int upleft = 0;
    int upright = 0;
    int downleft = 0;
    int downright = 0;

    int NeighAlive = 0;

    if((row-1<0)&&(column-1<0))
    {
      down = m_grid[row+1][column] == 1? 1: 0;
      right = m_grid[row][column+1] == 1? 1: 0;
      downright = m_grid[row+1][column+1] ==1? 1: 0;
    }
    else if((row-1<0)&&(column+1>=m_columns))
    {
      down = m_grid[row+1][column] == 1? 1: 0;
      left = m_grid[row][column-1] == 1? 1: 0;
      downleft = m_grid[row+1][column-1] == 1? 1: 0;
    }
    else if(row-1<0)
    {
      down = m_grid[row+1][column] == 1? 1: 0;
      left = m_grid[row][column-1] == 1? 1: 0;
      right = m_grid[row][column+1] == 1? 1: 0;
      downleft = m_grid[row+1][column-1] == 1? 1: 0;
      downright = m_grid[row+1][column+1] == 1? 1: 0;
    }
    else if((column-1<0)&&(row+1>=m_rows))
    {
      up = m_grid[row-1][column] == 1? 1: 0;
      right = m_grid[row][column+1] == 1? 1: 0;
      upright = m_grid[row-1][column+1] == 1? 1: 0;
    }
    else if(column-1<0)
    {
      up = m_grid[row-1][column] == 1? 1: 0;
      down = m_grid[row+1][column] == 1? 1: 0;
      right = m_grid[row][column+1] == 1? 1: 0;
      upright = m_grid[row-1][column+1] == 1? 1: 0;
      downright = m_grid[row+1][column+1] == 1? 1: 0;
    }
    else if((row+1>=m_rows)&&(column+1>=m_columns))
    {
      up = m_grid[row-1][column] == 1? 1: 0;
      left = m_grid[row][column-1] == 1? 1: 0;
      upleft = m_grid[row-1][column-1] == 1? 1: 0;
    }
    else if(row+1>=m_rows)
    {
      up = m_grid[row-1][column] == 1? 1: 0;
      left = m_grid[row][column-1] == 1? 1: 0;
      right = m_grid[row][column+1] == 1? 1: 0;
      upleft = m_grid[row-1][column-1] == 1? 1: 0;
      upright = m_grid[row-1][column+1] == 1? 1: 0;
    }
    else if(column+1>=m_columns)
    {
      up = m_grid[row-1][column] == 1? 1: 0;
      down = m_grid[row+1][column] == 1? 1: 0;
      left = m_grid[row][column-1] == 1? 1: 0;
      upleft = m_grid[row-1][column-1] == 1? 1: 0;
      downleft = m_grid[row+1][column-1] == 1? 1: 0;
    }
    else
    {
      up = m_grid[row-1][column] == 1? 1: 0;
      down = m_grid[row+1][column] == 1? 1: 0;
      left = m_grid[row][column-1] == 1? 1: 0;
      right = m_grid[row][column+1] == 1? 1: 0;
      upleft = m_grid[row-1][column-1] == 1? 1: 0;
      upright = m_grid[row-1][column+1] == 1? 1: 0;
      downleft = m_grid[row+1][column-1] == 1? 1: 0;
      downright = m_grid[row+1][column+1] == 1? 1: 0;
    }
    NeighAlive = up+down+left+right+upleft+upright+downleft+downright;
    return NeighAlive;
  }

} // end namespace
