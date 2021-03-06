#pragma once

#include <glm/mat2x2.hpp>
#include <nlohmann/json.hpp>

namespace nlohmann
{
    template<typename T>
    struct adl_serializer<glm::mat<3, 3, T, glm::defaultp>>
    {
        typedef glm::mat<3, 3, T, glm::defaultp> mat;

        static_assert(
                std::is_same<T, float>::value ||
                std::is_same<T, double>::value,
                "Invalid type for matrix"
        );

        static void to_json(json& j, const mat& value)
        {
            j = json::array({
                    value[0][0], value[0][1], value[0][2],
                    value[1][0], value[1][1], value[1][2],
                    value[2][0], value[2][1], value[2][2]
            });
        }

        static void from_json(const json& j, mat& value)
        {
            switch(j.type())
            {
                default:
                    throw std::runtime_error("Invalid value type");
                case json::value_t::number_float:
                case json::value_t::number_integer:
                case json::value_t::number_unsigned:
                {
                    T v = j;
                    value = mat(
                            v, v, v,
                            v, v, v,
                            v, v, v
                    );
                    return;
                }
                case json::value_t::array:
                {
                    std::array<T, 9> arr = {};
                    for(std::size_t i = 0; i < arr.size(); i++)
                        arr[i] = j.size() > i && !j[i].empty() ? j[i].get<T>() : T();

                    value = mat(
                            arr[0], arr[1], arr[2],
                            arr[3], arr[4], arr[5],
                            arr[6], arr[7], arr[8]
                    );
                    return;
                }
            }
        }
    };

}
