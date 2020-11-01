add_executable(T_Simple main.cpp)

target_link_libraries(T_Simple nlohmann_json_glm)

add_test(NAME Simple COMMAND T_Simple)
