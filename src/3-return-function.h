#include <napi.h>

Napi::String ReturnFunction(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::String::New(env, "world");
};

void InitExample3(Napi::Env env, Napi::Object &exports)
{
    exports.Set(Napi::String::New(env, "example3"),
                Napi::Function::New(env, ReturnFunction));
}
