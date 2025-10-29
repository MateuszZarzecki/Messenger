#include "debug.hpp"

void Debug::terminationString(TerminationCode terminationCode)
{
    Console console;
    switch(terminationCode)
    {
        case TerminationCode::NONE:
            console << "NONE";
            break;
        case TerminationCode::COMPLETE:
            console << "COMPLETE";
            break;
        case TerminationCode::FAILURE:
            console << "FAILURE";
            break;
        case TerminationCode::FINISH:
            console << "FINISH";
            break;
        case TerminationCode::QUIT:
            console << "QUIT";
            break;
        case TerminationCode::SKIP:
            console << "SKIP";
            break;
    }
}
