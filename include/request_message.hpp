#pragma once

#include <json/json.h>

#include <string>

class RequestMessage {
   public:
    std::string command;
    int id;

    static RequestMessage fromJson(const Json::Value& json);
    Json::Value toJson() const;
};