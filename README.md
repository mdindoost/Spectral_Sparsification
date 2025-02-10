# Spectral_Sparsification

Spectral_Sparsification is a C++ library that provides a function to perform spectral sparsification of directed, unweighted graphs using the [gSparse](https://github.com/hwang595/gSparse) library. The main function, `run_gSparse`, takes a graph defined by source and destination arrays and produces an output flag array indicating which nodes remain in the sparsified graph.

> **Note:** Although gSparse is originally designed for undirected graphs (spectral sparsification via effective resistance), this project adapts the interface to work with directed graphs for demonstration purposes.

## Features

- **Function:** `run_gSparse`  
  Takes:
  - Number of nodes and edges.
  - Two arrays (`src` and `dst`) representing the directed edges.
  - An output array (`node_flags`) that will contain a `1` for nodes that are part of the sparsified graph, and `0` otherwise.
  
- **Submodules:**  
  - [gSparse](https://github.com/hwang595/gSparse) (embedded as a submodule under `external/gSparse`)
  - [Eigen](https://gitlab.com/libeigen/eigen) (if you choose to add it as a submodule; otherwise, see system installation instructions)

- **Build System:**  
  - Uses a Makefile for building the library and a demo executable.

## Repository Structure

Spectral_Sparsification/ ├── external/ │ ├── gSparse/ # gSparse submodule │ └── eigen/ # Optional: Eigen submodule (if used) ├── include/ │ └── run_gSparse.h # Header declaring run_gSparse function ├── src/ │ ├── run_gSparse.cpp # Implementation of run_gSparse │ └── main.cpp # Example main function to test the library ├── .gitignore # Ignore build artifacts and temporary files ├── Makefile # Build instructions ├── setup.sh # Setup script to initialize submodules └── README.md # This file

markdown
Copy

## Prerequisites

- **C++ Compiler:** A modern C++ compiler with C++17 support.
- **Git:** For cloning the repository and its submodules.
- **Eigen:**  
  - **Option 1:** Use the Eigen submodule provided in `external/eigen`.  
  - **Option 2:** Install Eigen system-wide (e.g., via your package manager).  
    - On Ubuntu/Debian:  
      ```bash
      sudo apt-get install libeigen3-dev
      ```
- **gSparse:** Included as a submodule. No additional installation is required.

## Setup

After cloning the repository, initialize the submodules by running:

```bash
chmod +x setup.sh
./setup.sh
This script updates the submodules (gSparse and optionally Eigen) so that all necessary dependencies are in place.

Building the Project
To build the project (both the library and the demo executable), simply run:

bash
Copy
make
The build process will compile:

src/run_gSparse.cpp into an object file.
src/main.cpp into a demo executable (e.g., spectral_sparsification_demo).
To clean build artifacts, run:

bash
Copy
make clean
Running the Demo
After a successful build, you can test the functionality by running the demo executable:

bash
Copy
./spectral_sparsification_demo
The demo creates a small directed graph, calls run_gSparse, and prints the node flags to indicate which nodes are included in the sparsified graph.

Integration into Other Projects
To use Spectral_Sparsification in another project:

Add Spectral_Sparsification as a submodule in your repository:
bash
Copy
git submodule add https://github.com/yourusername/Spectral_Sparsification.git external/Spectral_Sparsification
git submodule update --init --recursive
Include the header in your code:
cpp
Copy
#include "external/Spectral_Sparsification/include/run_gSparse.h"
Link against the static library (libSpectralSparsification.a) produced by the Makefile.
Contributing
Contributions, issues, and feature requests are welcome!
Feel free to check the issues page if you want to contribute.

License
This project is licensed under the MIT License. See the LICENSE file for details.


