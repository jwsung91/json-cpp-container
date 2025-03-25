#pragma once
#include <json/json.h>

#include <string>

class RequestMessage {
   public:
    std::string command;
    int id;

    static RequestMessage fromJson(const Json::Value& json) {
        RequestMessage msg;
        msg.command = json["command"].asString();
        msg.id = json["id"].asInt();
        return msg;
    }

    Json::Value toJson() const {
        Json::Value json;
        json["command"] = command;
        json["id"] = id;
        return json;
    }
};
