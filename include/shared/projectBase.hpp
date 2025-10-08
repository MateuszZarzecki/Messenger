#pragma once
#include <iostream>

enum class TerminationCode { NONE=-1,COMPLETE,SKIP,FINISH,QUIT,FAILURE };

namespace ApplicationData {
    extern std::string projectName;
}

