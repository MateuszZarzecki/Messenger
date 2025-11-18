#pragma once
#include <string>
#include <variant>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

//ZASTAPIC NONE - DONE

enum class TerminationCode { NONE=-1,DONE,COMPLETE,SKIP,PARTIAL,FINISH,QUIT,FAILURE };
enum class TerminationGroupCode { CORRECT=-1,PARTIAL,EXIT};

using B = bool;
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
        : first(data1), second(data2), third(data3) {}
    Triplet() {}

    DataType1 first;
    DataType2 second;
    DataType3 third;
};
template<typename DataType1, typename DataType2, typename DataType3>
using T = Triplet<DataType1,DataType2,DataType3>;

template<typename DataType = std::monostate>
struct [[nodiscard]] Return
{
    Return(TerminationCode terminationCode = TerminationCode::NONE, DataType data = DataType())
        : data(data), tCode(terminationCode) {}

    TerminationGroupCode groupOf(TerminationCode tCodeArg)
    {
        switch(tCodeArg)
        {
            case TerminationCode::NONE:
            case TerminationCode::DONE:
            case TerminationCode::COMPLETE: return TerminationGroupCode::CORRECT;

            case TerminationCode::SKIP:
            case TerminationCode::PARTIAL:
            case TerminationCode::FINISH: return TerminationGroupCode::PARTIAL;

            case TerminationCode::QUIT:
            case TerminationCode::FAILURE: return TerminationGroupCode::EXIT;

            default: return TerminationGroupCode::EXIT;
        }
    }
    Return merge(V<Return> returns)
    {
        TerminationCode combined = TerminationCode::NONE;
        for(Return ret : returns)
        {
            if((int)combined < (int)ret.tCode)
            {
                combined = ret.tCode;
            }
        }
        return Return<DataType>(combined,data);
    }
    bool ok() { return groupOf(tCode) == TerminationGroupCode::CORRECT; }
    bool partial() { return groupOf(tCode) == TerminationGroupCode::PARTIAL; }
    bool exit() { return groupOf(tCode) == TerminationGroupCode::EXIT; }

    DataType data;
    TerminationCode tCode;
};

namespace ApplicationData
{
    extern std::string projectName;
}







