# Safaga
Light Game Engine

## Building SDK
### Get the Prerequisites
* CMake (tested with 3.7.2)
* Visual Studio (tested with 2015 in 64 bit mode)
* Git

Make sure CMake, Git and MSBuild are in your path.

### Clone this repository:
    git bash> git clone git@github.com:WissamElkadi/Safaga.git

### Building the SDK
Execute the following command to build the SDK

git bash> cd build

use -t to select one of the supported platforms {windows }, is a mandatory argument.

#### Windows Build

    git bash> ./build.sh -t windows

default is building both debug and release for "win64"

use -a to select specific android architecture either { all, win64}, default {all}

use -b to select one of build type or both {all, debug, release}, default {all}

use -o  to choose the output directory name, default {safaga_build}

Example:
build Windows win64 debug

    git bash> ./build.sh -t windows -a win64 -b debug


### Output
the output libraries is in Safaga/bin
