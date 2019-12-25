#include <napi.h>

void InitSection2(Napi::Env env, Napi::Object &exports)
{
    exports.Set(Napi::String::New(env, "section2"),
                Napi::String::New(env, "world"));
}
