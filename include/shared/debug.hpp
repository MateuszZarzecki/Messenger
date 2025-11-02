#pragma once
#include "consoleUtils.hpp"
#include "projectBase.hpp"

class Debug
{
public:
    static void terminationString(TerminationCode terminationCode);
private:
    inline static Console console;
};

// namespace ABC {
//     class A {
//     public:
//         A() {
//             for (int nazwa = 0; nazwa < 10; ++nazwa) {

//             }
//         }
//     };
//     A a();
// }
