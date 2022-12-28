# maps
This was a school project where I made a map of the university campus with the ability to find a route from one location to another.

# Install

## Install GCC/G++

### Linux
Install GCC/G++ with
```bash
sudo apt install gcc g++
```

### MacOS
Install brew with
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
Install GCC/G++ with
```bash
brew install gcc
```

### Windows
Download and install MSYS2 form the MSYS2 website

Install MinGW with
```bash
pacman -S mingw-w64-x86_64-toolchain
```
Add the binaries folder to the environment variables

## Install Make

### Linux
Install Make with
```bash
sudo apt install make
```

### MacOS
Install Make with
```bash
brew install make
```

### Windows
It should have already been installed with GCC/G++ in the 'Install GCC/G++' section

## Install OpenCV:

### Linux
Install OpenCV with
```bash
sudo apt install libopencv-dev
```

Install pkg-config with:
```bash
sudo apt install pkg-config
```

### MacOS
Install OpenCV with
```bash
brew install opencv
```
Install pkg-config with:
```bash
brew install pkg-config
```

### Windows
Download and install OpenCV from the OpenCV website

Copy and paste the following files from
```
C:\opencv-3.4.13\build\bin
```
to the project folder:
- libopencv_core3413.dll
- libopencv_highgui3413.dll
- libopencv_imgcodecs3413.dll
- libopencv_imgproc3413.dll 

# Build
Edit the appropriate makefile for your system
1. remove the file extension
2. add the appropriate paths for 'CC=' and 'CXX=' for your system if it is not already the case
3. set 'OPENCV=1' for compiling with OpenCV or 'OPENCV=0' to not compile with OpenCV

To run compile and run the Prim's algorithm, run this command:
```bash
make prim
```

To run compile and run the Kruskal's algorithm, run this command:
```bash
make kruskal
```

To run compile and run the Dijkstra algorithm, run this command:
```bash
make dijkstra
```

To find a route between different buildings for the the Dijkstra algorithm, edit the 'main.cpp' file and change the parameters of the line
```c++
searchOnCampus("SAEF", "GRAD");
```
to the names of your desired buildings.
