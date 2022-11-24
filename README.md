PHAS0100ASSIGNMENT1
------------------

[![Build Status](https://travis-ci.com/[USERNAME]/PHAS0100Assignment1.svg?branch=master)](https://travis-ci.com/[USERNAME]/PHAS0100Assignment1)
[![Build Status](https://ci.appveyor.com/api/projects/status/[APPVEYOR_ID]/branch/master)](https://ci.appveyor.com/project/[USERNAME]/PHAS0100Assignment1)


Purpose
-------

This project serves as a starting point for the PHAS0100 2021/22 Assignment 1 Game of Life Simulation coursework. It has a reasonable folder structure for [CMake](https://cmake.org/) based projects,
that use [CTest](https://cmake.org/) to run unit tests via [Catch](https://github.com/catchorg/Catch2). 

Further information on the specific project is left as an exercise for the student.


Credits
-------

This project is maintained by [Dr. Jim Dobson](https://www.ucl.ac.uk/physics-astronomy/people/dr-jim-dobson). It is based on [CMakeCatch2](https://github.com/UCL/CMakeCatch2.git) that was originally developed as a teaching aid for UCL's ["Research Computing with C++"](http://rits.github-pages.ucl.ac.uk/research-computing-with-cpp/)
course developed by [Dr. James Hetherington](http://www.ucl.ac.uk/research-it-services/people/james)
and [Dr. Matt Clarkson](https://iris.ucl.ac.uk/iris/browse/profile?upi=MJCLA42).


Build Instructions
------------------

If you want to test or use this project, it can be built by the following instructions. In Linux terms: 

```
mkdir PHAS0100Assignment1-build
cd PHAS0100Assignment1-build
cmake ..
make
```


Use instructions
----------------

After building, if you could find programs 'golBasicTest', 'golSimulation', 'golFindStillLife' under the directory of build/bin, you can now test the project or run the Game of Life as instructions following.

Run Tests:
```
cd PHAS0100Assignment1/build
./bin/golBasicTest
```

Run Game of Life Simulation:

-Check help messages:

```
cd PHAS0100Assignment1/build
./bin/golSimulation -h
```

-Run Game of Life simulation by specifying an input txt file:

```
cd PHAS0100Assignment1/build
./bin/golSimulation f FILENAME iter ITERATION_NUM
```

-Run Game of Life simulation by specifying conditions:

```
cd PHAS0100Assignment1/build
./bin/golSimulation r ROW c COLMUN a ALIVE_NUM iter ITERATION_NUM
```

Find Still Life's:

-Check help message:

```
cd PHAS0100Assignment1/build
./bin/golFindStillLife -h
```

-Find Still Life's based on provided conditions:
```
cd PHAS0100Assignment1/build
./bin/golFindStillLife r ROM c COLUMN a ALIVE_NUM iter ITERATION_NUM
```

Writeup on my PartC 9.d Result
------------------------------ 

I can find 10 Still Life's in total by running the golFindStillLife program for a 4 by 4 grid of cells with the number of initial alive cells being 4, 7, 8 and 9. 

It is a small number but takes some time to get. The initial conditions of a grid is setted randomly. Finding a Still Life requires sufficient grids with different initial conditions searched. Therefore, if increase the number of different random grids searched by the program I will probably find more Still Life's. But subject to the limitation of system performance, it will cost more time.
