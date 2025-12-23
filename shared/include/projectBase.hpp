#pragma once
#include <string>
#include <variant>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using C = char;
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
class Triplet
{
public:
    Triplet(DataType1 data1, DataType2 data2, DataType3 data3)
        : first(data1), second(data2), third(data3) {}
    Triplet() {}

    DataType1 first;
    DataType2 second;
    DataType3 third;
};
template<typename DataType1, typename DataType2, typename DataType3>
using T = Triplet<DataType1,DataType2,DataType3>;

template<typename Outcome, typename DataType = std::monostate>
class [[nodiscard]] Return
{
public:
    Return(Outcome outcome = (Outcome)(-1), DataType data = DataType())
        : data(data), outcome(outcome) {}

    DataType data;
    Outcome outcome;
};




