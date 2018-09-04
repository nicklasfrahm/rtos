# RTOS _(real-time operating systems)_

This repository consists of the source code for the exercises during the RTOS course. The code can easily be compiled by use of `x86_64-w64-mingw32-g++`.

## Introduction

To compile the code, make sure to have the latest `mingw-w64` compiler installed. On Windows this can be accomplished by using the Linux subsystem for Windows (WSL). Compile it by running:

On Windows with WSL for a 64bit system:

```bash
x86_64-w64-mingw32-g++ ./src/classes/counter.cpp -o counter.exe
```

## Tools

This repo comes with small helper scripts for the WSL. To compile the code, run it and remove the executable, run:

```bash
./run.sh counter
```

To remove all `.exe`-files, run:

```bash
./clean.sh
```
