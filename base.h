#ifndef _BASE_H_
#define _BASE_H_

#include <string>

namespace basecamp {

typedef int (*EvalType)(int, int);
typedef void (*PrintMsgType)(const std::string&);

class Base {
public:
	Base();
	~Base();

    //virtual 
    int eval(int a, int b);
    
    //virtual 
    void printMsg(const std::string& msg);

    static int eval_virtual(Base *base, int a, int b);
    static void printMsg_virtual(Base *base, const std::string& msg);
private:
    void  **vtbl;
};

}

#endif
