# xBerry-Exercise

## Table of contents
1. [ Quick Start ](#quick)
2. [ Description ](#des)
3. [ Architecture ](#archi)
4. [ To-Dos ](#todo)
5. [ Results ](#res)

<a name="quick">.</a>
## Quick Build

```sh
    git clone https://github.com/GHRik/xBerry-Exercise.git 
    cd xBerry-Exercise
    mkdir build
    cd build
    cmake .. && cmake --build .
```
Aplication will work automatic if you open a executable file.
If you want to close this console aplication write "0" and then press enter.

<a name="des">.</a>
## Description

This aplication is simulation for a small sensor network.
All of sensors have own thread. 
All of sensors write data to buffor which is a component of MainNetworkNode.
This sensors write thise data to buffor using interface: MainNetworkListener.
Using MainNetworkListener , MainNetworkNode can read buffor date.

<a name="archi">.</a>
## Architecture

Architecture was created to be easy expandable. For example if you would like to add
new sensor , you should registry this sensor in SensorMenager and and write class support for this sensor.

Above you will see a some examples of use cases in this architecture.

Architecture
[img]

Start program
[img]

Wrtie to buffor
[img]

<a name="todo">.</a>
## To-Dos

Considering that the application works to increase security and stability, a few more things like:
1. Write unit tests - cmake and aplication is prepared so if unit tests would appear, just add them in the "tests" directory
2. ErrorCodes - Most of the time the program used ErrorCode when the value was returned by the function. However, due to insufficient time, many snippets of code do not use ErrorCode at all.
3. Sensors should not write to the buffer directly through one interface. This causes the problem that if, for example, the data type changed, there would be a need to change the sensor code.
4. The logger should write to the file and not to the standard output.
5. Not supported in several places of nullpointer occurrence

<a name="res">.</a>
## Results

[video]

