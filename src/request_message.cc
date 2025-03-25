#include "request_message.hpp"

RequestMessage RequestMessage::fromJson(const Json::Value& json) {
    RequestMessage msg;
    msg.command = json["command"].asString();
    msg.id = json["id"].asInt();
    return msg;
}

Json::Value RequestMessage::toJson() const {
    Json::Value json;
    json["command"] = command;
    json["id"] = id;
    return json;
}