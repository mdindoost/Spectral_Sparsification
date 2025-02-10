#!/usr/bin/env bash
set -e

echo "Initializing gSparse submodule..."
git submodule update --init --recursive

echo "Done. You can now run 'make' to build the library."

