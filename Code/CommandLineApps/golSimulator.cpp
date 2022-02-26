#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "golStatus.h"
#include "golGameofLife.h"

static void show_usage(std::string name) //Define a global function to print help message
{
    std::cerr << "Usage: " << name << " <arguments(s)> SOURCES" << "\n"
              << "Get usage (optional):\n"
              << "\t-h,--help\t\tShow this help message\n"
              << "Run by specifying an input file:\n"
              << "\tf,filepath FILEPATH\tSpecify the path of input txt file\n"
              << "\titer,iteration ITERATION_NUM\tSpecify the iteration number of Game of Life\n"
              << "Run by starting with random cell contents:\n"
              << "\tr,row ROW\tSpecify the row number of the grid\n"
              << "\tc,column COLUMN\tSpecify the column number of the grid\n"
              << "\ta,alive ALIVE_NUM\tSpecify the number of initial alive cells\n"
              << "\titer,iteration ITERATION_NUM\tSpecify the iteration number of Game of Life\n"
              << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc < 5)
    {
        show_usage(argv[0]);
        return 1;
    }
    else if (argc == 5) //Run by specifying an input file
    {
        std::string filepath = "";
        int iter = 0;
        for (int i = 1; i < argc; ++i) //Check every arguments and store data input
        {
            std::string arg = argv[i];
            if ((arg == "-h") || (arg == "--help"))
            {
                show_usage(argv[0]);
                return 0;
            }
            else if ((arg == "f") || (arg == "filepath"))
            {
                if (i + 1 < argc) //Make sure this is not the last argument
                {
                    filepath = argv[++i];
                }
                else
                {
                    show_usage(argv[0]);
                    return 0;
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
        //Run Game of Life
        gol::Status s(filepath);
        gol::GameofLife gof(s);
        gof.PrintGrid();
        for (int i = 0; i < iter; i++)
        {
            gof.TakeStep();
            gof.PrintGrid();
        }

        return 1;
    }
    else if (argc == 9) //Run by starting with random cell contents
    {
        int row = 0;
        int col = 0;
        int alive = 0;
        int iter_ran = 0;
        for (int i = 1; i < argc; ++i) //Check every arguments and store data input
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
            else if ((arg == "c") || (arg == "column"))
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
            else if ((arg == "a") || (arg == "alive"))
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
                    iter_ran = atoi(argv[++i]);
                }
                else
                {
                    std::cerr << "iter requires one iteration number." << std::endl;
                    return 1;
                }
            }
        }
        //Run Game of Life
        gol::Status s(row, col, alive);
        gol::GameofLife gof(s);
        gof.PrintGrid();
        for (int i = 0; i < iter_ran; i++)
        {
            gof.TakeStep();
            gof.PrintGrid();
        }
    }
    else
    {
        show_usage(argv[0]);
        return 1;
    }
    return 0;
}