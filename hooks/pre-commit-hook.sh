#!/usr/bin/env sh

set -o errexit

cd "$(git rev-parse --show-toplevel)"
make check
