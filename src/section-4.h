#include <napi.h>

Napi::String ReturnsAValue(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::String::New(env, "hello world");
};

Napi::String TakesAParameter(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, "first parameter must be a string")
            .ThrowAsJavaScriptException();
        return;
    }
    return info[0].ToString();
};

Napi::Value TakesACallback(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::String incoming = TakesAParameter(info);
    if (!info[1].IsFunction())
    {
        Napi::TypeError::New(env, "second parameter must be a function")
            .ThrowAsJavaScriptException();
        return;
    }
    auto callback = info[1].As<Napi::Function>();
    callback.Call(env.Global(), {incoming});
    return;
};

void InitSection4(Napi::Env env, Napi::Object &exports)
{
    Napi::Object obj = Napi::Object::New(env);
    obj.Set(Napi::String::New(env, "returnsAValue"),
            Napi::Function::New(env, TakesAParameter));
    obj.Set(Napi::String::New(env, "takesAParameter"),
            Napi::Function::New(env, ReturnsAValue));
    obj.Set(Napi::String::New(env, "takesACallback"),
            Napi::Function::New(env, TakesACallback));
    exports.Set(Napi::String::New(env, "section4"), obj);
}
