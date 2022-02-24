/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "catch.hpp"
#include "golCatchMain.h"
#include "golMyFunctions.h"
#include "golBasicTypes.h"
#include <unistd.h>
#include <iostream>
#include <vector>
#include <fstream>

TEST_CASE( "Test1 for instantiation of class Status", "[Defualt]" ) {

  gol::Status s1(6,5);
  REQUIRE(s1.m_rows==6);
  REQUIRE(s1.m_columns==5);
  s1.StatusSet(2,1,"o");
  s1.StatusSet(4,2,"o");
  REQUIRE(s1.StatusGet(2,1)=="o");
  REQUIRE(s1.StatusGet(4,2)=="o");

  gol::Status s2(4,4);
  REQUIRE(s2.m_rows==4);
  REQUIRE(s2.m_columns==4);
  s2.StatusSet(0,0,"o");
  s2.StatusSet(3,3,"o");
  REQUIRE(s2.StatusGet(0,0)=="o");
  REQUIRE(s2.StatusGet(3,3)=="o");

}

TEST_CASE( "Test2 for instantiation of class Status", "[Random]" ) {

  gol::Status s1(5,5,5);
  REQUIRE(s1.m_rows==5);
  REQUIRE(s1.m_columns==5);
  REQUIRE(s1.m_alive==5);

  sleep(2);

  gol::Status s2(5,5,5);
  REQUIRE(s2.m_rows==5);
  REQUIRE(s2.m_columns==5);
  REQUIRE(s2.m_alive==5);

  REQUIRE(s1.m_grid != s2.m_grid);

  gol::Status s3(6,7,5);
  REQUIRE(s3.m_rows==6);
  REQUIRE(s3.m_columns==7);
  REQUIRE(s3.m_alive==5);
  
}

TEST_CASE( "Test3 for instantiation of class Status", "[File Input]" ){

  std::string filepath1 = "../testing/data/glider.txt";
  std::ifstream infile1(filepath1);
  std::string str1; 

  gol::Status grid1(filepath1);

  int row_cnt1=0;
  
  while (getline(infile1, str1))
  {
    std::string grid_row = "";
    for(auto value:grid1.m_grid[row_cnt1])
    {
      grid_row += value == 0 ? "-" : "o";
      grid_row += " ";
    }
    grid_row.pop_back();
    ++row_cnt1;

    REQUIRE(str1==grid_row);
    
  }

  std::string filepath2 = "../testing/data/still_lifes.txt";
  std::ifstream infile2(filepath2);
  std::string str2; 

  gol::Status grid2(filepath2);
  
  int row_cnt2=0;
  
  while (getline(infile2, str2))
  {
    std::string grid_row = "";
    for(auto value:grid2.m_grid[row_cnt2])
    {
      grid_row += value == 0 ? "-" : "o";
      grid_row += " ";
    }
    grid_row.pop_back();
    ++row_cnt2;

    REQUIRE(str2==grid_row);
    
  }
  
  std::string filepath3 = "../testing/data/oscillators.txt";
  std::ifstream infile3(filepath3);
  std::string str3; 

  gol::Status grid3(filepath3);
  
  int row_cnt3=0;
  
  while (getline(infile3, str3))
  {
    std::string grid_row = "";
    for(auto value:grid3.m_grid[row_cnt3])
    {
      grid_row += value == 0 ? "-" : "o";
      grid_row += " ";
    }
    grid_row.pop_back();
    ++row_cnt3;

    REQUIRE(str3==grid_row);
    
  }

}

TEST_CASE( "Test for Method of class Status", "[Neighbouring Alive Count]" )
{
  gol::Status s1(5,5);
  s1.StatusSet(2,4,"o");
  s1.StatusSet(0,2,"o");
  s1.StatusSet(4,4,"o");
  s1.StatusSet(1,3,"o");

  REQUIRE(s1.NeighAlive(0,0) == 0);
  REQUIRE(s1.NeighAlive(0,4) == 1);
  REQUIRE(s1.NeighAlive(4,0) == 0);
  REQUIRE(s1.NeighAlive(4,4) == 0);
  REQUIRE(s1.NeighAlive(0,1) == 1);
  REQUIRE(s1.NeighAlive(3,0) == 0);
  REQUIRE(s1.NeighAlive(4,1) == 0);
  REQUIRE(s1.NeighAlive(1,4) == 2);
  REQUIRE(s1.NeighAlive(2,3) == 2);

  std::string filepath = "../testing/data/still_lifes.txt";
  gol::Status s2(filepath);

  REQUIRE(s2.NeighAlive(0,0) == 1);
  REQUIRE(s2.NeighAlive(0,9) == 0);
  REQUIRE(s2.NeighAlive(9,0) == 2);
  REQUIRE(s2.NeighAlive(9,9) == 0);
  REQUIRE(s2.NeighAlive(0,5) == 0);
  REQUIRE(s2.NeighAlive(3,0) == 2);
  REQUIRE(s2.NeighAlive(9,1) == 2);
  REQUIRE(s2.NeighAlive(3,9) == 1);
  REQUIRE(s2.NeighAlive(8,1) == 4);

}


TEST_CASE( "Test1 for Game of Life", "[TakeStep]" ) {

  gol::Status s1(5,5);
  s1.StatusSet(2,4,"o");
  s1.StatusSet(0,2,"o");
  s1.StatusSet(4,4,"o");
  s1.StatusSet(1,3,"o");
  s1.StatusSet(0,0,"o");
  s1.StatusSet(3,3,"o");

  std::vector<std::vector<int>> s1_result={}; 
  s1_result.push_back(std::vector<int>{1,0,1,0,0});
  s1_result.push_back(std::vector<int>{0,0,0,1,0});
  s1_result.push_back(std::vector<int>{0,0,0,0,1});
  s1_result.push_back(std::vector<int>{0,0,0,1,0});
  s1_result.push_back(std::vector<int>{0,0,0,0,1});

  gol::GameofLife g1(s1);
  REQUIRE(g1.m_currstatus.m_grid == s1_result);

  std::vector<std::vector<int>> s1_result_iter1={};
  s1_result_iter1.push_back(std::vector<int>{0,0,0,0,0});
  s1_result_iter1.push_back(std::vector<int>{0,0,0,1,0});
  s1_result_iter1.push_back(std::vector<int>{0,0,0,1,1});
  s1_result_iter1.push_back(std::vector<int>{0,0,0,1,1});
  s1_result_iter1.push_back(std::vector<int>{0,0,0,0,0});

  g1.TakeStep();
  REQUIRE(g1.m_currstatus.m_grid == s1_result_iter1);

  std::vector<std::vector<int>> s1_result_iter2 = {};
  s1_result_iter2.push_back(std::vector<int>{0,0,0,0,0});
  s1_result_iter2.push_back(std::vector<int>{0,0,0,1,1});
  s1_result_iter2.push_back(std::vector<int>{0,0,1,0,0});
  s1_result_iter2.push_back(std::vector<int>{0,0,0,1,1});
  s1_result_iter2.push_back(std::vector<int>{0,0,0,0,0});

  g1.TakeStep();
  REQUIRE(g1.m_currstatus.m_grid == s1_result_iter2);

  std::vector<std::vector<int>> s1_result_iter3 = {};
  s1_result_iter3.push_back(std::vector<int>{0,0,0,0,0});
  s1_result_iter3.push_back(std::vector<int>{0,0,0,1,0});
  s1_result_iter3.push_back(std::vector<int>{0,0,1,0,0});
  s1_result_iter3.push_back(std::vector<int>{0,0,0,1,0});
  s1_result_iter3.push_back(std::vector<int>{0,0,0,0,0});

  g1.TakeStep();
  REQUIRE(g1.m_currstatus.m_grid == s1_result_iter3);


}