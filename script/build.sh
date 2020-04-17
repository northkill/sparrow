#!/bin/bash

path="$(dirname "${BASH_SOURCE}")"
source "${path}/common.sh"

set_path

cd ../build

cmake --build . --target sparrow

reset_path
