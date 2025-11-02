#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

enum class TerminationCode { NONE=-1,COMPLETE,SKIP,PARTIAL,FINISH,QUIT,FAILURE };
enum class TerminationGroupCode { CORRECT=-1,PARTIAL,EXIT};

class TerminationGroup {
public:
    TerminationGroup();
    TerminationGroup(TerminationCode terminationCode);

    void operator=(TerminationCode terminationCode);
    TerminationGroupCode getTerminationGroupCode();

    TerminationCode tCode;
private:
    const std::unordered_map<TerminationCode,TerminationGroupCode> terminationGroups =
    {
        {TerminationCode::NONE, TerminationGroupCode::CORRECT},
        {TerminationCode::COMPLETE, TerminationGroupCode::CORRECT},
        {TerminationCode::SKIP, TerminationGroupCode::PARTIAL},
        {TerminationCode::PARTIAL, TerminationGroupCode::PARTIAL},
        {TerminationCode::FINISH, TerminationGroupCode::PARTIAL},
        {TerminationCode::QUIT, TerminationGroupCode::EXIT},
        {TerminationCode::FAILURE, TerminationGroupCode::EXIT},
    };
};

using I = int;
using F = float;
using D = double;
using L = long long;
using S = std::string;

template<typename DataType>
using V = std::vector<DataType>;

template<typename DataType1, typename DataType2>
using UM = std::unordered_map<DataType1,DataType2>;

template <typename DataType1, typename DataType2>
using M = std::map<DataType1,DataType2>;

template<typename DataType1, typename DataType2>
using P = std::pair<DataType1,DataType2>;

template<typename DataType1, typename DataType2, typename DataType3>
struct Triplet
{
    Triplet(DataType1 data1, DataType2 data2, DataType3 data3)
    {
        first = data1;
        second = data2;
        third = data3;
    }
    Triplet()
    {
        first = DataType1();
        second = DataType2();
        third = DataType3();
    }

    DataType1 first;
    DataType2 second;
    DataType3 third;
};
template<typename DataType1, typename DataType2, typename DataType3>
using T = Triplet<DataType1,DataType2,DataType3>;

struct NoneData {};

template<typename DataType = NoneData>
struct ReturnData
{
public:
    static ReturnData blend();
    ReturnData(DataType data, TerminationCode terminationCode)
        : data(data), tGroup(terminationCode) {}

    ReturnData(DataType data)
        : data(data) {}

    ReturnData(TerminationCode terminationCode)
        : tGroup(terminationCode) {}

    ReturnData() {}

    DataType data;
    TerminationGroup tGroup;
};

namespace ApplicationData
{
    extern std::string projectName;
}
