#pragma once

#include <json/json.h>

#include <string>

class ResponseMessage {
   public:
    bool success;
    std::string message;

    static ResponseMessage fromJson(const Json::Value& json);
    Json::Value toJson() const;
};