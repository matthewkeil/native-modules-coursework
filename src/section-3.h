#include <napi.h>
#include "string"
#include "vector"
#include "algorithm"

void InitSection3(Napi::Env env, Napi::Object &exports)
{
    Napi::Object obj = Napi::Object::New(env);
    /**
     * 6 JavaScript primitive types
     */
    auto key = std::string("string");
    Napi::String jsKey = Napi::String::New(env, key);
    auto value = std::string("fancy string value");
    Napi::Value jsValue = Napi::String::New(env, value);
    obj.Set(jsKey, jsValue);
    obj.Set(Napi::String::New(env, "undefined"), env.Undefined());
    obj.Set(Napi::String::New(env, "null"), env.Null());
    obj.Set(Napi::String::New(env, "symbol"), Napi::Symbol::New(env));
    obj.Set(Napi::String::New(env, "boolean"), Napi::Boolean::New(env, bool{true}));
    obj.Set(Napi::String::New(env, "number"), Napi::Number::New(env, int{123}));
    // available in N-API 4
    // obj.Set(Napi::String::New(env, "bigInt"), Napi::BigInt::New(env, double{42}));
    // obj.Set(Napi::String::New(env, "date"), Napi::Date::New(env, double{0}));
    /**
     * Example for types that extend Object
     */
    auto vector = std::vector{std::string("first"), std::string("second"), std::string("third")};
    auto array = Napi::Array::New(env);
    for (int i = 0; vector.begin() + i != vector.end(); i++)
        array.Set(i, Napi::String::New(env, vector[i]));
    obj.Set(Napi::String::New(env, "array"), array);
    exports.Set(Napi::String::New(env, "section3"), obj);
}
