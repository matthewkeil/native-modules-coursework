#include "native_modules_coursework.h"

using namespace Napi;

NativeModulesCoursework::NativeModulesCoursework(const Napi::CallbackInfo& info) : ObjectWrap(info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments")
          .ThrowAsJavaScriptException();
        return;
    }

    if (!info[0].IsString()) {
        Napi::TypeError::New(env, "You need to name yourself")
          .ThrowAsJavaScriptException();
        return;
    }

    this->_greeterName = info[0].As<Napi::String>().Utf8Value();
}

Napi::Value NativeModulesCoursework::Greet(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments")
          .ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsString()) {
        Napi::TypeError::New(env, "You need to introduce yourself to greet")
          .ThrowAsJavaScriptException();
        return env.Null();
    }

    Napi::String name = info[0].As<Napi::String>();

    printf("Hello %s\n", name.Utf8Value().c_str());
    printf("I am %s\n", this->_greeterName.c_str());

    return Napi::String::New(env, this->_greeterName);
}

Napi::Function NativeModulesCoursework::GetClass(Napi::Env env) {
    return DefineClass(env, "NativeModulesCoursework", {
        NativeModulesCoursework::InstanceMethod("greet", &NativeModulesCoursework::Greet),
    });
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    Napi::String name = Napi::String::New(env, "NativeModulesCoursework");
    exports.Set(name, NativeModulesCoursework::GetClass(env));
    return exports;
}

NODE_API_MODULE(addon, Init)
