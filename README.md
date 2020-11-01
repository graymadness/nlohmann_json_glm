# GLM parser for nlohmann's JSON

Extends [nlohmann's JSON library](https://nlohmann.github.io/json/) with [GLM](https://glm.g-truc.net) types.

## Libraries

| Name | License | Version |
|------|---------|---------|
| [GLM](https://glm.g-truc.net) | [`MIT`](https://github.com/g-truc/glm/blob/master/copying.txt) | branch: [`master`](https://github.com/g-truc/glm/tree/master) |
| [nlohmann JSON](https://nlohmann.github.io/json/) | [`MIT`](https://github.com/nlohmann/json/blob/master/LICENSE.MIT) | branch: [`master`](https://github.com/nlohmann/json/tree/master) |

All libraries are used as `static library` to maximize optimization and limit problems with deployment and versions.

## Testing

Run `ctest` in build directory.

Executable of tests have prefix `t_` (test `abc` would be executable `t_abc`).
After creating new test, add it to [`tests/CMakeLists.txt`](tests/CMakeLists.txt) as `add_subdirectory(abc)` (where `abc` is name of your test).

To setup tests in CLion IDE, create new Run Configuration with Name=`CTest`, Working Directory=`$CMakeCurrentBuildDir$` and Executable pointing to your `ctest` executable.
On Linux it will be `/bin/ctest`, on Windows probably `C:\CMake\bin\ctest.exe` 
