#include <gtest/gtest.h>
#include <json/json.h>

#include <sstream>

#include "request_message.hpp"
#include "response_message.hpp"

TEST(RequestMessageTest, SerializeToJsonString) {
    RequestMessage req;
    req.command = "start";
    req.id = 123;

    Json::Value json = req.toJson();

    Json::StreamWriterBuilder writer;
    std::string jsonStr = Json::writeString(writer, json);

    // 예상되는 JSON 문자열 일부 포함 여부 확인
    EXPECT_NE(jsonStr.find("\"command\" : \"start\""), std::string::npos);
    EXPECT_NE(jsonStr.find("\"id\" : 123"), std::string::npos);
}

TEST(ResponseMessageTest, DeserializeFromJsonString) {
    std::string inputStr = R"({
        "success": true,
        "message": "Task completed"
    })";

    Json::CharReaderBuilder reader;
    Json::Value json;
    std::string errs;
    std::istringstream iss(inputStr);

    ASSERT_TRUE(Json::parseFromStream(reader, iss, &json, &errs));

    ResponseMessage res = ResponseMessage::fromJson(json);

    EXPECT_TRUE(res.success);
    EXPECT_EQ(res.message, "Task completed");
}
