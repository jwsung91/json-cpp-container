#include "response_message.hpp"

ResponseMessage ResponseMessage::fromJson(const Json::Value& json) {
    ResponseMessage msg;
    msg.success = json["success"].asBool();
    msg.message = json["message"].asString();
    return msg;
}

Json::Value ResponseMessage::toJson() const {
    Json::Value json;
    json["success"] = success;
    json["message"] = message;
    return json;
}