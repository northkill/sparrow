path_before="${PWD}"
path_after="$(dirname "$(readlink -f "${BASH_SOURCE}")")"

set_path() {
    cd "${path_after}"
}

reset_path() {
    cd "${path_before}"
}
