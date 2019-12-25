#include <napi.h>
#include "string"
#include "vector"

void InitSection3(Napi::Env env, Napi::Object &exports)
{
    /**
     * 6 JavaScript primitive types
     */
    Napi::Value undefined = env.Undefined();
    Napi::Value null = env.Null();
    Napi::Value jsSymbol = Napi::Symbol::New(env);
    bool boolean = true;
    Napi::Value jsBoolean = Napi::Boolean::New(env, boolean);
    auto str = std::string("string value");
    Napi::Value jsString = Napi::String::New(env, str);
    int num = 123;
    Napi::Value jsNumber = Napi::Number::New(env, num);
    /**
     * everything else is at its core a JavaScript Object
     */
    Napi::Object obj = Napi::Object::New(env);
    obj.Set(Napi::String::New(env, "string"), jsString);
    obj.Set(Napi::String::New(env, "number"), jsNumber);
    obj.Set(Napi::String::New(env, "boolean"), jsBoolean);
    obj.Set(Napi::String::New(env, "symbol"), jsSymbol);
    /**
     * Arrays is an Object optimized to work with a numerical index
     */
    std::vector<int> vector{1, 2, 3};
    Napi::Array stringArray = Napi::Array::New(env, vector.size());
    for (int index : vector)
        stringArray.Set(index, Napi::Number::New(env, vector[index]));
    stringArray.Set(Napi::String::New(env, "array"), stringArray);
    /**
     * Depending on the version of N-API you target you can also create
     */
    // double bigInt{1.123};
    // obj.Set(Napi::String::New(env, "bigInt"), Napi::BigInt::New(env, bigInt));
    // obj.Set(Napi::String::New(env, "symbol"), Napi::Date::(env, 0.0));
    exports.Set(Napi::String::New(env, "section3"), obj);
}
