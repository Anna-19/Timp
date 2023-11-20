#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cctype>

class modAlphaCipher
{
private:
    int key1;
public:
    modAlphaCipher()=delete;
    modAlphaCipher(const int& key) :key1(key) {};
    std::wstring encrypt(const std::wstring& text);
    std::wstring decrypt(const std::wstring& cipher_text);
};
