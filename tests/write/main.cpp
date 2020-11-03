#include <nlohmann/json/glm.hpp>

template<typename TVec>
void TestVector(TVec value)
{
    using json = nlohmann::json;

    // To JSON
    json j = value;

    std::string jsonText = j.dump(2);

    // From JSON
    json j2 = json::parse(jsonText);

    TVec result = j2;

    if(value != result)
        throw std::runtime_error("Result does not match");
}

void Test_Vectors()
{
    // vec2
    {
        TestVector<glm::vec2>(glm::vec2(1,2));
        TestVector<glm::dvec2>(glm::dvec2(1,2));

        TestVector<glm::i8vec2>(glm::i8vec2(1,2));
        TestVector<glm::i16vec2>(glm::i16vec2(1,2));
        TestVector<glm::i32vec2>(glm::i32vec2(1,2));
        TestVector<glm::i64vec2>(glm::i64vec2(1,2));

        TestVector<glm::u8vec2>(glm::u8vec2(1,2));
        TestVector<glm::u16vec2>(glm::u16vec2(1,2));
        TestVector<glm::u32vec2>(glm::u32vec2(1,2));
        TestVector<glm::u64vec2>(glm::u64vec2(1,2));
    }

    // vec3
    {
        TestVector<glm::vec3>(glm::vec3(1,2,3));
        TestVector<glm::dvec3>(glm::dvec3(1,2,3));

        TestVector<glm::i8vec3>(glm::i8vec3(1,2,3));
        TestVector<glm::i16vec3>(glm::i16vec3(1,2,3));
        TestVector<glm::i32vec3>(glm::i32vec3(1,2,3));
        TestVector<glm::i64vec3>(glm::i64vec3(1,2,3));

        TestVector<glm::u8vec3>(glm::u8vec3(1,2,3));
        TestVector<glm::u16vec3>(glm::u16vec3(1,2,3));
        TestVector<glm::u32vec3>(glm::u32vec3(1,2,3));
        TestVector<glm::u64vec3>(glm::u64vec3(1,2,3));
    }

    // vec4
    {
        TestVector<glm::vec4>(glm::vec4(1,2,3, 4));
        TestVector<glm::dvec4>(glm::dvec4(1,2,3, 4));

        TestVector<glm::i8vec4>(glm::i8vec4(1,2,3, 4));
        TestVector<glm::i16vec4>(glm::i16vec4(1,2,3, 4));
        TestVector<glm::i32vec4>(glm::i32vec4(1,2,3, 4));
        TestVector<glm::i64vec4>(glm::i64vec4(1,2,3, 4));

        TestVector<glm::u8vec4>(glm::u8vec4(1,2,3, 4));
        TestVector<glm::u16vec4>(glm::u16vec4(1,2,3, 4));
        TestVector<glm::u32vec4>(glm::u32vec4(1,2,3, 4));
        TestVector<glm::u64vec4>(glm::u64vec4(1,2,3, 4));
    }
}

void Test_Matrices()
{
    // mat2x2
    {
        TestVector<glm::mat2>(
                glm::mat2(
                        9, 9,
                        9, 9
                )
        );
        TestVector<glm::dmat2>(
                glm::dmat2(
                        9, 9,
                        9, 9
                )
        );
    }

    // mat3x3
    {
        TestVector<glm::mat3>(
                glm::mat3(
                        9, 9, 9,
                        9, 9, 9,
                        9, 9, 9
                )
        );
        TestVector<glm::dmat3>(
                glm::dmat3(
                        9, 9, 9,
                        9, 9, 9,
                        9, 9, 9
                )
        );
    }

    // mat4x4
    {
        TestVector<glm::mat4>(
                glm::mat4(
                        9, 9, 9, 9,
                        9, 9, 9, 9,
                        9, 9, 9, 9,
                        9, 9, 9, 9
                )
        );
        TestVector<glm::dmat4>(
                glm::dmat4(
                        9, 9, 9, 9,
                        9, 9, 9, 9,
                        9, 9, 9, 9,
                        9, 9, 9, 9
                )
        );
    }
}

int main(int argc, const char** argv)
{
    Test_Vectors();
    Test_Matrices();
}
