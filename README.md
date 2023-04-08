# Fiduccia–Mattheyses algorithm
## Shcherbakov Alexey, B01-908
# Build
## Windows
    cmake .
    cmake --build .
## Unix
    cmake .
    make
# Run
## Windows
    ./build/Debug/fm.exe <path_to_graph>
    ./build/Debug/fm.exe -m <path_to_graph>
## Unix
    ./build/fm <path_to_graph>
    ./build/fm -m <path_to_graph>
## Run all tests Windows
    python scr.py > res.txt