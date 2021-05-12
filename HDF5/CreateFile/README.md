# HDF5Write

摘自[HDF5 1.12 CPP Reference Manual](https://portal.hdfgroup.org/pages/viewpage.action?pageId=50073884)

## 测试结果

- [x] WSL2 Ubuntu20.04. HDF5安装自libhdf5-dev
- [x] Visual Studio 2019. HDF5安装自vcpkg
- [x] mingw64. HDF5安装自msys2

## 引用参考

- `The HDF5 1.12.x product requires a minimum CMake version of 3.12.` 来自HDF5源文件中的`USING_HDF5_CMake.txt`

- CMakeLists文件内容并未采用`USING_HDF5_CMake.txt`，而是启发自[CMake 官方文档 FindHDF5 result-variables](https://cmake.org/cmake/help/latest/module/FindHDF5.html#result-variables)
