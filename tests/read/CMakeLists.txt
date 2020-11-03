add_executable(T_Read main.cpp)

target_link_libraries(T_Read nlohmann_json_glm)

add_test(NAME Read COMMAND T_Read)
