#include "modAlphaCipher.h"
using namespace std;
std::wstring modAlphaCipher::encrypt(const std::wstring& text) 
{
    wstring tabl = text;
    int dl, nstrok, index, x;
    dl = text.length(); 
    nstrok = (dl - 1) / key1 + 1; 
    x = 0;
    for (int i = key1; i > 0; i--) { 
        for (int j = 0; j < nstrok; j++) { 
            index = i+key1*j;
            if (index-1 < dl) {
                tabl[x] = text[index-1];
                x++;
            }
        }
    }
    return tabl;
}

std::wstring modAlphaCipher::decrypt(const std::wstring& cipher_text) 
{
    wstring tabl = cipher_text;
    int dl, nstrok, index, x;
    dl = cipher_text.length();
    nstrok = (dl - 1) / key1 + 1; 
    x = 0;
    for (int i = key1; i > 0; i--) { 
        for (int j = 0; j < nstrok; j++) { 
            index = i+key1*j;
            if (index-1 < dl) {
                tabl[index-1] = cipher_text[x];
                x++;
            }
        }
    }
    return tabl;
}
