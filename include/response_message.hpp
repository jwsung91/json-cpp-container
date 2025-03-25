#pragma once

#include <json/json.h>

#include <string>

class ResponseMessage {
   public:
    bool success;
    std::string message;

    static ResponseMessage fromJson(const Json::Value& json) {
        ResponseMessage msg;
        msg.success = json["success"].asBool();
        msg.message = json["message"].asString();
        return msg;
    }

    Json::Value toJson() const {
        Json::Value json;
        json["success"] = success;
        json["message"] = message;
        return json;
    }
};