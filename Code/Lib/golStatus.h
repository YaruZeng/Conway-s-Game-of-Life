#ifndef golStatus_h
#define golStatus_h
#include <iostream>
#include <string>
#include <vector>

namespace gol
{
  class Status //Create the class to store the status of the 2D grid of cells
  {
  public:
    Status();
    ~Status();
    Status(const int &rows, const int &columns);
    Status(const int &rows, const int &columns, const int &num_alive); //initialise the grid with random cell's status
    Status(const std::string &filename);

    void StatusSet(const int &row, const int &column, const std::string &status);
    std::string StatusGet(const int &row, const int &column);
    void StatusPrint();
    int NeighAlive(const int &row, const int &column);

    int m_columns = 0;
    int m_rows = 0;
    int m_alive = 0;
    std::vector<std::vector<int>> m_grid = {};
  };

} // end namespace

#endif
