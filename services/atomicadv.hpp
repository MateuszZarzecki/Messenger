#pragma once
#include <mutex>

template<typename T>
class AtomicAdv
{
public:
    AtomicAdv(T variable);
    AtomicAdv();
    void store(T variable);
    T load();
private:
    std::mutex mtx;
    T storedVariable;
};
