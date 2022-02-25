#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <stdlib.h>
#include <unistd.h>
#include "golBasicTypes.h"
#include "golMyFunctions.h"

static void show_usage(std::string name)
{
    std::cerr << "Usage: " << name << " <arguments(s)> SOURCES" << "\n"
              << "Get usage (optional):\n"
              << "\t-h,--help\t\tShow this help message\n"
              << "Find Sill Lifes by starting with random cell contents:\n"
              << "\tr,row ROW\tSpecify the row number of the grid\n"
              << "\tc,column COLUMN\tSpecify the column number of the grid\n"
              << "\ta,alive ALIVE_NUM\tSpecify the number of initial alive cells\n"
              << "\titer,iteration ITERATION_NUM\tSpecify the iteration number of Game of Life\n"
              << std::endl;
}


int main(int argc, char* argv[])
{
    if (argc < 8) 
    {
        show_usage(argv[0]);
        return 1;
    }
    else if ((argc == 8)||(argc == 9))
    {   
        int row = 0;
        int col = 0;
        int alive = 0;
        int iter = 0;
        for (int i = 1; i < argc; ++i)
        {
            std::string arg = argv[i];
            if ((arg == "r") || (arg == "row")) 
            {   
                if (i + 1 < argc) 
                { 
                    row = atoi(argv[++i]);
                } 
                else 
                { 
                    show_usage(argv[0]);
                    return 1;
                }  
            }
            else if((arg == "c") || (arg == "column")) 
            {   
                if (i + 1 < argc) 
                {
                    col = atoi(argv[++i]); 
                } 
                else 
                { 
                    show_usage(argv[0]);
                    return 1;
                } 
            } 
            else if((arg == "a") || (arg == "alive"))
            {   
                if (i + 1 < argc) 
                { 
                    alive = atoi(argv[++i]);
                } 
                else 
                { 
                    show_usage(argv[0]);
                    return 1;
                } 
            }
            else if ((arg == "iter") || (arg == "iteration")) 
            {
                if (i + 1 < argc) 
                {   
                    iter = atoi(argv[++i]);
                } 
                else 
                { 
                    std::cerr << "iter requires one iteration number." << std::endl;
                    return 1;
                }
            }

        }
        
        int rand_cnt = 0;
        int rand_num = 500;
        std::vector<gol::Status> rand_grid = {};
        std::cout << "I'm finding..." << "\n";
        while(rand_cnt < rand_num)
        {   
            gol::Status status(row,col,alive);

            if(rand_grid.size() == 0)
            {
                rand_grid.push_back(status);
            }
            else
            {
                if(status.m_grid != rand_grid[rand_grid.size()-1].m_grid)
                {
                    rand_grid.push_back(status);
                }
            }
            ++rand_cnt;
            sleep(1);
        }

        std::cout << "Number of searched random grids: " << rand_grid.size() << "\n";
        std::vector<gol::Status> still_life = {};
        for (auto status:rand_grid)
        {   
            int still_iter = 0;
            std::vector<std::vector<int>> curr_status = {};
            std::vector<std::vector<int>> next_status = {};
            gol::GameofLife gof(status);
            
            for(int i=0; i<iter; i++)
            {
                curr_status = gof.m_currstatus.m_grid;
                gof.TakeStep();
                next_status = gof.m_currstatus.m_grid;
                if(curr_status == next_status)
                {
                    ++still_iter;
                }
            }

            if (still_iter == iter)
            {
                still_life.push_back(status);
            }
        }

        std::cout << "Number of found Still lifes: " <<  still_life.size() << "\n";

        if(still_life.size() == 0)
        {
            std::cout << "Cannot find still lifes. " << std::endl;
        }
        else
        {
            std::cout << "Found Still lifes: " << "\n";
            for (auto status:still_life)
            {
                status.StatusPrint();
            }
        }
    }
    else
    {
        show_usage(argv[0]);
        return 1;
    }
    return 0;
}