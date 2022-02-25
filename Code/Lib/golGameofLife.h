#ifndef golGameofLife_h
#define golGameofLife_h
#include "golStatus.h"
#include <iostream>
#include <string>
#include <vector>

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
