#include <json/json.h>

#include <iostream>
#include <sstream>

#include "request_message.hpp"

int main() {
    try {
        // 입력 JSON 문자열
        std::string inputJsonStr = R"({
            "command": "run",
            "id": 7
        })";

        // 문자열을 Json::Value로 파싱
        Json::Value root;
        Json::CharReaderBuilder reader;
        std::string errs;
        std::istringstream s(inputJsonStr);

        if (!Json::parseFromStream(reader, s, &root, &errs)) {
            std::cerr << "Failed to parse JSON: " << errs << std::endl;
            return 1;
        }

        // JSON → RequestMessage 객체 (deserialize)
        RequestMessage req = RequestMessage::fromJson(root);

        std::cout << "[Deserialize Result]" << std::endl;
        std::cout << "Command: " << req.command << ", ID: " << req.id
                  << std::endl;

        // RequestMessage 객체 → JSON (serialize)
        Json::Value outJson = req.toJson();
        Json::StreamWriterBuilder writer;
        std::string outputJsonStr = Json::writeString(writer, outJson);

        std::cout << "\n[Serialized JSON Output]\n"
                  << outputJsonStr << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
