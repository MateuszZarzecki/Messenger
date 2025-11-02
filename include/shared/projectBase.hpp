#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

enum class TerminationCode { NONE=-1,COMPLETE,SKIP,FINISH,PARTIAL,QUIT,FAILURE };

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
struct Triplet {
    Triplet(DataType1 data1, DataType2 data2, DataType3 data3) {
        first = data1;
        second = data2;
        third = data3;
    }
    Triplet() {
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

template<typename DataType>
struct ReturnData {
public:
    ReturnData(DataType data, TerminationCode terminationCode) {
        this->data = data;
        tCode = terminationCode;
    }
    ReturnData(DataType data) {
        this->data = data;
        tCode = TerminationCode::NONE;
    }
    ReturnData(TerminationCode terminationCode) {
        this->data = DataType();
        tCode = terminationCode;
    }
    ReturnData() {
        this->data = DataType();
        tCode = TerminationCode::NONE;
    }
    DataType data;
    TerminationCode tCode;
};

namespace ApplicationData {
    extern std::string projectName;
}
