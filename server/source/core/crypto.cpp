#include "crypto.hpp"

std::string Crypto::key = "";

void Crypto::changeKey(std::string key) {
    this->key = key;
}
std::string Crypto::hash(std::string input) {
    // unsigned char hash[SHA256_DIGEST_LENGTH];
    // const unsigned char* data = (const unsigned char*)input.c_str();
    // SHA256(data, input.size(), hash);
    // std::stringstream ss;
    // for(int i =0; i < SHA256_DIGEST_LENGTH; i++ ) {
    //     ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    // }
    // return ss.str();
    return "";
}
std::string Crypto::encode(std::string input) {
    return "";
}
std::string Crypto::decode(std::string input) {
    return "";
}
