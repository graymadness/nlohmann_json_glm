add_executable(T_Write main.cpp)

target_link_libraries(T_Write nlohmann_json_glm)

add_test(NAME Write COMMAND T_Write)
