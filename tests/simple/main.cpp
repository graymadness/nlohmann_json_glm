#include <nlohmann/json/glm.hpp>

template<typename TVec>
void TestVector(TVec result, const std::vector<std::string>& inputs)
{
    using json = nlohmann::json;

    for(auto& in : inputs)
    {
        json j = json::parse(in);

        TVec value = j;
        if(value != result)
            throw std::runtime_error("Did not get expected result");
    }
}

template<typename TVec>
void TestVector_Fail(TVec result, const std::vector<std::string>& inputs)
{
    bool failed = false;

    try
    {
        TestVector(result, inputs);
    }
    catch (std::exception& ex)
    {
        failed = true;
    }

    if(!failed)
        throw std::runtime_error("Test did not fail");
}

int main(int argc, const char** argv)
{
    // vec2 - multiple values
    {
        std::vector<std::string> inputs = {
                "[1, 2]",
                R"({ "x":1, "y":2 })"
        };
        TestVector<glm::vec2>(glm::vec2(1,2), inputs);
        TestVector<glm::dvec2>(glm::dvec2(1,2), inputs);

        TestVector<glm::i8vec2>(glm::i8vec2(1,2), inputs);
        TestVector<glm::i16vec2>(glm::i16vec2(1,2), inputs);
        TestVector<glm::i32vec2>(glm::i32vec2(1,2), inputs);
        TestVector<glm::i64vec2>(glm::i64vec2(1,2), inputs);

        TestVector<glm::u8vec2>(glm::u8vec2(1,2), inputs);
        TestVector<glm::u16vec2>(glm::u16vec2(1,2), inputs);
        TestVector<glm::u32vec2>(glm::u32vec2(1,2), inputs);
        TestVector<glm::u64vec2>(glm::u64vec2(1,2), inputs);
    }

    // vec2 - single value
    {
        std::vector<std::string> inputs = {
                "9",
                "9.0"
        };
        TestVector<glm::vec2>(glm::vec2(9), inputs);
        TestVector<glm::dvec2>(glm::dvec2(9), inputs);

        TestVector<glm::i8vec2>(glm::i8vec2(9), inputs);
        TestVector<glm::i16vec2>(glm::i16vec2(9), inputs);
        TestVector<glm::i32vec2>(glm::i32vec2(9), inputs);
        TestVector<glm::i64vec2>(glm::i64vec2(9), inputs);

        TestVector<glm::u8vec2>(glm::u8vec2(9), inputs);
        TestVector<glm::u16vec2>(glm::u16vec2(9), inputs);
        TestVector<glm::u32vec2>(glm::u32vec2(9), inputs);
        TestVector<glm::u64vec2>(glm::u64vec2(9), inputs);
    }

    // vec3 - multiple values
    {
        std::vector<std::string> inputs = {
                "[1, 2, 3]",
                R"({ "x":1, "y":2, "z":3 })"
        };
        TestVector<glm::vec3>(glm::vec3(1,2,3), inputs);
        TestVector<glm::dvec3>(glm::dvec3(1,2,3), inputs);

        TestVector<glm::i8vec3>(glm::i8vec3(1,2,3), inputs);
        TestVector<glm::i16vec3>(glm::i16vec3(1,2,3), inputs);
        TestVector<glm::i32vec3>(glm::i32vec3(1,2,3), inputs);
        TestVector<glm::i64vec3>(glm::i64vec3(1,2,3), inputs);

        TestVector<glm::u8vec3>(glm::u8vec3(1,2,3), inputs);
        TestVector<glm::u16vec3>(glm::u16vec3(1,2,3), inputs);
        TestVector<glm::u32vec3>(glm::u32vec3(1,2,3), inputs);
        TestVector<glm::u64vec3>(glm::u64vec3(1,2,3), inputs);
    }

    // vec3 - single value
    {
        std::vector<std::string> inputs = {
                "9",
                "9.0"
        };
        TestVector<glm::vec3>(glm::vec3(9), inputs);
        TestVector<glm::dvec3>(glm::dvec3(9), inputs);

        TestVector<glm::i8vec3>(glm::i8vec3(9), inputs);
        TestVector<glm::i16vec3>(glm::i16vec3(9), inputs);
        TestVector<glm::i32vec3>(glm::i32vec3(9), inputs);
        TestVector<glm::i64vec3>(glm::i64vec3(9), inputs);

        TestVector<glm::u8vec3>(glm::u8vec3(9), inputs);
        TestVector<glm::u16vec3>(glm::u16vec3(9), inputs);
        TestVector<glm::u32vec3>(glm::u32vec3(9), inputs);
        TestVector<glm::u64vec3>(glm::u64vec3(9), inputs);
    }

    // vec4 - multiple values
    {
        std::vector<std::string> inputs = {
                "[1, 2, 3, 4]",
                R"({ "x":1, "y":2, "z":3, "w":4 })"
        };
        TestVector<glm::vec4>(glm::vec4(1,2,3, 4), inputs);
        TestVector<glm::dvec4>(glm::dvec4(1,2,3, 4), inputs);

        TestVector<glm::i8vec4>(glm::i8vec4(1,2,3, 4), inputs);
        TestVector<glm::i16vec4>(glm::i16vec4(1,2,3, 4), inputs);
        TestVector<glm::i32vec4>(glm::i32vec4(1,2,3, 4), inputs);
        TestVector<glm::i64vec4>(glm::i64vec4(1,2,3, 4), inputs);

        TestVector<glm::u8vec4>(glm::u8vec4(1,2,3, 4), inputs);
        TestVector<glm::u16vec4>(glm::u16vec4(1,2,3, 4), inputs);
        TestVector<glm::u32vec4>(glm::u32vec4(1,2,3, 4), inputs);
        TestVector<glm::u64vec4>(glm::u64vec4(1,2,3, 4), inputs);
    }

    // vec4 - single value
    {
        std::vector<std::string> inputs = {
                "9",
                "9.0"
        };
        TestVector<glm::vec4>(glm::vec4(9), inputs);
        TestVector<glm::dvec4>(glm::dvec4(9), inputs);

        TestVector<glm::i8vec4>(glm::i8vec4(9), inputs);
        TestVector<glm::i16vec4>(glm::i16vec4(9), inputs);
        TestVector<glm::i32vec4>(glm::i32vec4(9), inputs);
        TestVector<glm::i64vec4>(glm::i64vec4(9), inputs);

        TestVector<glm::u8vec4>(glm::u8vec4(9), inputs);
        TestVector<glm::u16vec4>(glm::u16vec4(9), inputs);
        TestVector<glm::u32vec4>(glm::u32vec4(9), inputs);
        TestVector<glm::u64vec4>(glm::u64vec4(9), inputs);
    }

    // Special cases
    {
        TestVector<glm::vec4>(
                glm::vec4(1,2,3,0),
                {
                        "[ 1, 2, 3 ]",
                        R"({ "x":1, "y":2, "z":3 })"
                }
        );
        TestVector<glm::vec4>(
                glm::vec4(1,2,0,0),
                {
                        "[ 1, 2 ]",
                        R"({ "x":1, "y":2 })"
                }
        );
        TestVector<glm::vec4>(
                glm::vec4(1,0,0,0),
                {
                        "[ 1 ]",
                        R"({ "x":1 })"
                }
        );
        TestVector<glm::vec4>(
                glm::vec4(0,0,0,0),
                {
                        "[ ]",
                        "{ }"
                }
        );
    }

    // Failing tests
    {
        TestVector_Fail<glm::vec4>(glm::vec4(), { "['abc']" });
        TestVector_Fail<glm::vec4>(glm::vec4(), { "{ 'x':'abc' }" });
        TestVector_Fail<glm::vec4>(glm::vec4(), { "{ 'x':[] }" });
        TestVector_Fail<glm::vec4>(glm::vec4(), { "{ 'x':{} }" });
    }
}
