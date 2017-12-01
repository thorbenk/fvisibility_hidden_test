#!/bin/bash
cmake -GNinja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -Bbuild-gcc-dbg -H$PWD
cmake -GNinja -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -Bbuild-gcc-rel -H$PWD
CXX=/usr/bin/clang++-5.0 cmake -GNinja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -Bbuild-clang-dbg -H$PWD
CXX=/usr/bin/clang++-5.0 cmake -GNinja -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -Bbuild-clang-rel -H$PWD

CTEST_OUPUT_ON_FAILURE=1
for d in build-gcc-dbg build-gcc-rel build-clang-dbg build-clang-rel; do
    echo $d
    cd $d
    cmake --build . || exit
    ctest -V -j1 . || exit
    cd ..
done;
