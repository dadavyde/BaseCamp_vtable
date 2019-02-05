#include "base.h"

#include <iostream>

using basecamp::Base;

typedef int (*EvalType)(Base*, int, int);
typedef void (*PrintMsgType)(Base*, const std::string&);

int Base::eval_virtual(Base *base, int a, int b) {

    return (a + b);
}

void Base::printMsg_virtual(Base *base, const std::string& msg) {
    std::cout << "[Base]: " << msg << std::endl;
}

static void* vtable[2] = {reinterpret_cast<void*>(&Base::eval_virtual), reinterpret_cast<void*>(&Base::printMsg_virtual)};

Base::Base()
{
	vtbl = vtable;
}

Base::~Base()
{
    
}

int Base::eval(int a, int b) {
    EvalType eval_cpy = (EvalType)vtbl[0];

    return (eval_cpy(a, b));
}

void Base::printMsg(const std::string& msg) {
    PrintMsgType printMsg_cpy = (PrintMsgType)vtbl[1];
    printMsg_cpy(msg);
}
