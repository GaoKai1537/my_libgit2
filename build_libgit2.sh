if [ -d "build" ]; then
    rm -rf build
fi
mkdir build && cd build
cmake ..
cmake --build .
cmake .. -DCMAKE_INSTALL_PREFIX=/install/prefix
echo "GK990702" | sudo cmake --build . --target install
cd ..
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/install/prefix/lib
export LD_LIBRARY_PATH
