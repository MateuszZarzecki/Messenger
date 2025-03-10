#pragma once
#include <mutex>

template<typename T>
class AtomicAdv
{
public:
    AtomicAdv(T& variable) {store(variable);}
    AtomicAdv(T&& variable) {store(std::move(variable));}
    AtomicAdv() = default;

    void store(T& variable) {
        mtx.lock();
        storedVariable = variable;
        mtx.unlock();
    }
    void store(T&& variable) {
        mtx.lock();
        storedVariable = std::move(variable);
        mtx.unlock();
    }
    T load() {
        mtx.lock();
        return storedVariable;
        mtx.unlock();
    }
    void operator= (T& variable) {
        store(variable);
    }
    void operator= (T&& variable) {
        store(std::move(variable));
    }
private:
    std::mutex mtx;
    T storedVariable;
};
