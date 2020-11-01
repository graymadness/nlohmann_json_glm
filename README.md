# Template

This is template project to allow fast and simple C++ project creation.

## Libraries

| Name | License | Version |
|------|---------|---------|
| ... | `MIT` / `GPLv3` | branch: `master` |

All libraries are used as `static library` to maximize optimization and limit problems with deployment and versions.

## Testing

Run `ctest` in build directory.

Executable of tests have prefix `t_` (test `abc` would be executable `t_abc`).
After creating new test, add it to [`tests/CMakeLists.txt`](tests/CMakeLists.txt) as `add_subdirectory(abc)` (where `abc` is name of your test).

To setup tests in CLion IDE, create new Run Configuration with Name=`CTest`, Working Directory=`$CMakeCurrentBuildDir$` and Executable pointing to your `ctest` executable.
On Linux it will be `/bin/ctest`, on Windows probably `C:\CMake\bin\ctest.exe` 
