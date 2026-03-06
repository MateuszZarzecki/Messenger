#pragma once
#include <string>
#include <variant>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using String = std::string;

template<typename DataType>
using Vector = std::vector<DataType>;

template<typename DataType1, typename DataType2>
using UnorderedMap = std::unordered_map<DataType1,DataType2>;

template <typename DataType1, typename DataType2>
using Map = std::map<DataType1,DataType2>;

template<typename DataType1, typename DataType2>
using Pair = std::pair<DataType1,DataType2>;

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

template<typename DataType>
class Scope
{
public:
    Scope(DataType left, DataType right)
        : left(left),right(right) {}

    bool in(DataType value)
    {
        return (left <= value && value <= right);
    }
private:
    DataType left,right;
};

template<typename Outcome, typename DataType = std::monostate>
class [[nodiscard]] Return
{
public:
    Return(Outcome outcome = (Outcome)(-1), DataType data = DataType())
        : data(data), outcome(outcome) {}

    DataType data;
    Outcome outcome;
};




