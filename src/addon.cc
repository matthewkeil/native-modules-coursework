#include <napi.h>
#include "section-2.h"
#include "section-3.h"

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    InitSection2(env, exports);
    InitSection3(env, exports);
    return exports;
}

NODE_API_MODULE(addon, Init)