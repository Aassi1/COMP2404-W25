#!/bin/bash

clang -E layout.cc > myfile.cpp
clang -cc1 -fdump-record-layouts myfile.cpp > output.txt