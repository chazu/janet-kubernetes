#include <janet/janet.h>

static Janet myfun(int32_t argc, Janet *argv) {
    janet_fixarity(argc, 0);
    printf("hello from a module!\n");
    return janet_wrap_nil();
}

static const JanetReg cfuns[] = {
    {"myfun", myfun, "(mymod/myfun)\n\nPrints a hello message."},
    {NULL, NULL, NULL}
};

JANET_MODULE_ENTRY(JanetTable *env) {
    janet_cfuns(env, "mymod", cfuns);
}
