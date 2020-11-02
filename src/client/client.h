#pragma once

#include <string>

#include <Poco/JSON/Object.h>

#include "../model.h"
#include "../fwd.h"

namespace NOctoshell {

class IClient {
public:
    IClient(TContext& ctx) : Ctx_{ctx} {}
    virtual ~IClient() = default;

    virtual std::string Name() const = 0;
    virtual TUpdate ParseUpdate(const Poco::JSON::Object& data) const = 0;
    virtual void SendReaction(const TUpdate& update, const TReaction& reaction) const = 0;

protected:
    TContext& Ctx_;
};

} // namespace NOctoshell
