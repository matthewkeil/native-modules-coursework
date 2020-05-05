#include <napi.h>
#include <openssl/sha.h>

class NativeClass : Napi::ObjectWrap<NativeClass>
{
public:
    static void Init(Napi::Env env, Napi::Object &exports);
    NativeClass(const Napi::CallbackInfo &info);
    ~NativeClass();

private:
    static Napi::FunctionReference constructor;
    static unsigned char *opaque_token;
    Napi::Value DoSomthing(const Napi::CallbackInfo &info);
};

Napi::FunctionReference NativeClass::constructor;

void NativeClass::Init(Napi::Env env, Napi::Object &exports)
{
    Napi::HandleScope scope(env);
    const unsigned char *id_input = "sha1 unique object id";
    SHA1(id_input, strlen(reinterpret_cast<const char *>(id_input)), opaque_token);

    Napi::Function func = DefineClass(
        env,
        "NativeClass",
        {InstanceMethod("instanceMethod", &NativeClass::DoSomthing)});

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set(Napi::String::New(env, "section5"), func);
}

NativeClass::NativeClass(const Napi::CallbackInfo &info) : Napi::ObjectWrap<NativeClass>(info)
{
    Napi::Env env = info.Env();
}

NativeClass::~NativeClass()
{
}