#include <napi.h>

class NativeClass : Napi::ObjectWrap<NativeClass>
{
public:
    static void Init(Napi::Env env, Napi::Object &exports);
    NativeClass(const Napi::CallbackInfo &info);

private:
    static Napi::FunctionReference constructor;
    std::string opaque_token;
    Napi::Value DoSomthing(const Napi::CallbackInfo &info);
};

void NativeClass::Init(Napi::Env env, Napi::Object &exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "NativeClass",
        {InstanceMethod("instanceMethod", &NativeClass::DoSomthing)});
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set(Napi::String::New(env, "section5"), func);
}