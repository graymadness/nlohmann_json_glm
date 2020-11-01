#pragma once

#include <glm/vec3.hpp>
#include <nlohmann/json.hpp>

namespace nlohmann
{
    template<typename T>
    struct adl_serializer<glm::vec<3, T, glm::defaultp>>
    {
        typedef glm::vec<3, T, glm::defaultp> vec;

        static_assert(
                std::is_same<T, float>::value ||
                std::is_same<T, double>::value ||
                std::is_same<T, int8_t>::value ||
                std::is_same<T, int16_t>::value ||
                std::is_same<T, int32_t>::value ||
                std::is_same<T, int64_t>::value ||
                std::is_same<T, uint8_t>::value ||
                std::is_same<T, uint16_t>::value ||
                std::is_same<T, uint32_t>::value ||
                std::is_same<T, uint64_t>::value,
                "Invalid type for vector"
        );

        static void to_json(json& j, const vec& value)
        {
            j = { value.x, value.y, value.z };
        }

        static void from_json(const json& j, vec& value)
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
                    value = vec(v, v, v);
                    return;
                }
                case json::value_t::array:
                {
                    float x = j.size() >= 1 && !j[0].empty() ? j[0].get<T>() : 0.0f;
                    float y = j.size() >= 2 && !j[1].empty() ? j[1].get<T>() : 0.0f;
                    float z = j.size() >= 3 && !j[2].empty() ? j[2].get<T>() : 0.0f;

                    value = vec(x, y, z);
                    return;
                }
                case json::value_t::object:
                {
                    if(j.empty())
                    {
                        value = vec(0, 0, 0);
                    }
                    else
                    {
                        float x = j.contains("x") && !j["x"].empty() ? j["x"].get<T>() : 0.0f;
                        float y = j.contains("y") && !j["y"].empty() ? j["y"].get<T>() : 0.0f;
                        float z = j.contains("z") && !j["z"].empty() ? j["z"].get<T>() : 0.0f;

                        value = vec(x, y, z);
                    }
                    return;
                }
            }
        }
    };

}
