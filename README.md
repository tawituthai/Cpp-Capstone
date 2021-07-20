# CPPND: Capstone

TODO: Explain what we are going to do here.

## Cloning

When cloning this project, be sure to use the `--recurse-submodules` flag. Using HTTPS:
```
git clone https://github.com/tawituthai/Cpp-Capstone.git --recurse-submodules
```

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* IO2D
  * Installation instructions for all operating systems can be found [here](https://github.com/cpp-io2d/P0267_RefImpl/blob/master/BUILDING.md)
  * This library must be built in a place where CMake `find_package` will be able to find it

## Install IO2D
These installation steps assume APT package manager on Ubuntu Linux.
Installation steps:
1. Refresh apt: `sudo apt update`
2. Install GCC: `sudo apt install build-essential`
3. Install CMake: `sudo apt install cmake`
4. Install Cairo: `sudo apt install libcairo2-dev`
5. Install graphicsmagick: `sudo apt install libgraphicsmagick1-dev`
6. Install libpng: `sudo apt install libpng-dev`

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./capstone`.
