#include <gtest/gtest.h>
#include <json/json.h>

#include <sstream>

#include "request_message.hpp"
#include "response_message.hpp"

// Helper: JSON 문자열 → Json::Value
Json::Value parseJsonString(const std::string& jsonStr) {
    Json::Value root;
    Json::CharReaderBuilder reader;
    std::string errs;
    std::istringstream iss(jsonStr);

    if (!Json::parseFromStream(reader, iss, &root, &errs)) {
        throw std::runtime_error("JSON parse error: " + errs);
    }

    return root;
}

// 1. RequestMessage serialize
TEST(RequestMessageTest, SerializeToJsonString) {
    RequestMessage req;
    req.command = "launch";
    req.id = 10;

    Json::Value json = req.toJson();
    std::string jsonStr = Json::writeString(Json::StreamWriterBuilder(), json);

    EXPECT_NE(jsonStr.find("\"command\" : \"launch\""), std::string::npos);
    EXPECT_NE(jsonStr.find("\"id\" : 10"), std::string::npos);
}

// 2. ResponseMessage deserialize
TEST(ResponseMessageTest, DeserializeFromJsonString) {
    std::string input = R"({
        "success": true,
        "message": "Operation done"
    })";

    Json::Value json = parseJsonString(input);
    ResponseMessage expected{true, "Operation done"};
    ResponseMessage actual = ResponseMessage::fromJson(json);

    EXPECT_EQ(actual, expected);
}

// 3. RequestMessage operator==
TEST(RequestMessageTest, EqualityOperatorWorks) {
    RequestMessage a{"run", 42};
    RequestMessage b{"run", 42};
    RequestMessage c{"stop", 42};

    EXPECT_EQ(a, b);
    EXPECT_NE(a, c);
}

// 4. 잘못된 JSON → 예외 발생 테스트
TEST(ResponseMessageTest, MalformedJsonThrows) {
    std::string badJson = R"({
        "success": tru,  // 오타 intentional
        "message": "oops"
    })";

    EXPECT_THROW(
        {
            try {
                Json::Value json = parseJsonString(badJson);
                ResponseMessage::fromJson(json);
            } catch (const std::exception& e) {
                std::cerr << "Caught exception: " << e.what() << std::endl;
                throw;
            }
        },
        std::exception);
}
