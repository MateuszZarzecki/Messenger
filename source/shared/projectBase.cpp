#include "projectBase.hpp"

std::string ApplicationData::projectName = "Messenger";

TerminationGroup::TerminationGroup()
{
    tCode = TerminationCode::NONE;
}
TerminationGroup::TerminationGroup(TerminationCode terminationCode)
{
    this->tCode = terminationCode;
}
TerminationGroupCode TerminationGroup::getTerminationGroupCode()
{
    if(terminationGroups.count(tCode)) {
        return terminationGroups.at(tCode);
    }
    return TerminationGroupCode::CORRECT;
}
void TerminationGroup::operator=(TerminationCode terminationCode)
{
    tCode = terminationCode;
}
