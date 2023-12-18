#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
#include <locale>
#include <codecvt>
#include <typeinfo>
using namespace std;
void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{
    try {
        wstring cipherText;
        wstring decryptedText;
        modAlphaCipher cipher(key);
        cipherText = cipher.encrypt(Text);
        if (destructCipherText)
            cipherText.front() = towlower(cipherText.front());
        decryptedText = cipher.decrypt(cipherText);
        wcout<<L"Ключ:"<<key<<endl;
        wcout<<L"Исходный текст:"<<Text<<endl;
        wcout<<L"Зашифрованный текст:"<<cipherText<<endl;
        wcout<<L"Расшифрованный текст:"<<decryptedText<<endl;
    } catch (const cipher_error & e) {
        wcerr<<"Error: "<<e.what()<<endl;
    }
}

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    check(L"ШАУРМА",L"ПИЦЦА");
    check(L"ПИЦ ЦА",L"ШАУРМА");
    check(L"22222",L"ШАУРМА");
    check(L"ПИЦЦА",L"");
    check(L"ПИЦЦА",L"ШАУРМА19");
 
}
