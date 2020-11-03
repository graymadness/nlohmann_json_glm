#pragma once

#include <glm/mat2x2.hpp>
#include <nlohmann/json.hpp>

namespace nlohmann
{
    template<typename T>
    struct adl_serializer<glm::mat<4, 4, T, glm::defaultp>>
    {
        typedef glm::mat<4, 4, T, glm::defaultp> mat;

        static_assert(
                std::is_same<T, float>::value ||
                std::is_same<T, double>::value,
                "Invalid type for matrix"
        );

        static void to_json(json& j, const mat& value)
        {
            j = {
                    value[ 0], value[ 1], value[ 2], value[ 3],
                    value[ 4], value[ 5], value[ 6], value[ 7],
                    value[ 8], value[ 9], value[10], value[11],
                    value[12], value[13], value[14], value[15]
            };
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
                            v, v, v, v,
                            v, v, v, v,
                            v, v, v, v,
                            v, v, v, v
                    );
                    return;
                }
                case json::value_t::array:
                {
                    std::array<T, 16> arr = {};
                    for(std::size_t i = 0; i < arr.size(); i++)
                        arr[i] = j.size() > i && !j[i].empty() ? j[i].get<T>() : T();

                    value = mat(
                            arr[ 0], arr[ 1], arr[ 2], arr[ 3],
                            arr[ 4], arr[ 5], arr[ 6], arr[ 7],
                            arr[ 8], arr[ 9], arr[10], arr[11],
                            arr[12], arr[13], arr[14], arr[15]
                    );
                    return;
                }
            }
        }
    };

}
