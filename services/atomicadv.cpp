// template<typename T>
// AtomicAdv<T>::AtomicAdv(T variable)
//     : storedVariable(variable) {}

// template<typename T>
// AtomicAdv<T>::AtomicAdv()
//     : storedVariable("") {}

// template<typename T>
// void AtomicAdv<T>::store(T variable) {
//     std::lock_guard<std::mutex> lock(mtx);
//     storedVariable = variable;
// }

// template<typename T>
// T AtomicAdv<T>::load() {
//     std::lock_guard<std::mutex> lock(mtx);
//     return storedVariable;
// }
