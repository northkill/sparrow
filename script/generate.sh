#!/bin/bash

path="$(dirname "${BASH_SOURCE}")"
source "${path}/common.sh"

set_path

cd ..

mkdir -p ./build
cd ./build

CC=clang CXX=clang++ \
cmake \
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=true \
    -DBOOST_ROOT=/home/asdf/lib/include \
    -DSPARROW_ENABLE_TEST=true \
    ..

reset_path
