#include <napi.h>

void InitSection2(Napi::Env env, Napi::Object &exports)
{
    Napi::String key = Napi::String::New(env, "section2");
    Napi::String value = Napi::String::New(env, "hello world");
    exports.Set(key, value);
}
