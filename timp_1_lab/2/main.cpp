#include "modAlphaCipher.h"
using namespace std;


int main(int argc, char **argv)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    int key;
    wstring text;
    int op;
    wcout<<"Cipher ready. Input key: ";
    wcin>>key;
    if (!wcin.good()) {
        wcerr<<"key not valid\n";
        return 1;
    }
    wcout<<"Key loaded\n";
    modAlphaCipher cipher(key);
    do {
        wcout<<"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
        wcin>>op;
        if (op > 2) {
            wcout<<"Illegal operation\n";
        } else if (op >0) {
            wcout<<"Cipher ready. Input text: ";
            wcin>>text;
            
        	if (op==1) {
            	wcout<<"Encrypted text: "<<cipher.encrypt(text)<<endl;
        	} else {
            	wcout<<"Decrypted text: "<<cipher.decrypt(text)<<endl;
        	}
    
        }
    } while (op!=0);
    return 0;
}
