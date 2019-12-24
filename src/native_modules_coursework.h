#pragma once

#include <napi.h>

class NativeModulesCoursework : public Napi::ObjectWrap<NativeModulesCoursework>
{
public:
    NativeModulesCoursework(const Napi::CallbackInfo&);
    Napi::Value Greet(const Napi::CallbackInfo&);

    static Napi::Function GetClass(Napi::Env);

private:
    std::string _greeterName;
};
