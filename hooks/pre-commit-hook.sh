#!/usr/bin/env sh

cd "$(git rev-parse --show-toplevel)"
make check
