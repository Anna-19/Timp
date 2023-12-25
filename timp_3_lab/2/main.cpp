#include <UnitTest++/UnitTest++.h>
#include <Cipher.h>
#include <iostream>
#include <locale>
#include <codecvt>
using namespace std;
struct KeyB_fixture {
    Cipher * p;
    KeyB_fixture()
    {
        p = new Cipher(L"3");
    }
    ~KeyB_fixture()
    {
        delete p;
    }
};
wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
SUITE(KeyTest)
{
    TEST(ValidKey) {
        CHECK_EQUAL("РА-ЕПАЧЕХ", codec.to_bytes(Cipher(L"3").encrypt(L"ЧЕРЕПАХА")));
    }
    TEST(LongKey) {
        CHECK_EQUAL("Х-А-П-Е-Р-Е-ЧА",codec.to_bytes(Cipher(L"7").encrypt(L"ЧЕРЕПАХА")));
    }
    TEST(ShortKey) {
        CHECK_EQUAL("ЕЕААЧРПХ",codec.to_bytes(Cipher(L"2").encrypt(L"ЧЕРЕПАХА")));
    }
    TEST(NegativeKey) {
        CHECK_THROW(Cipher cp(L"-1"),cipher_error);
    }
    TEST(WhitespaceInKey) {
        CHECK_THROW(Cipher cp(L"0 0 7"),cipher_error);
    }
    TEST(EmptyKey) {
        CHECK_THROW(Cipher cp(L""),cipher_error);
    }
    TEST(AlphaAndPunctuationInKey) {
        CHECK_THROW(Cipher cp(L"Привет!"),cipher_error);
    }
    TEST(LongKeyTextLength) {
    Cipher cp(L"10"); 
    CHECK_THROW(cp.encrypt(L"Черепаха"), cipher_error); 
}

}
SUITE(EncryptTest)
{
    TEST_FIXTURE(KeyB_fixture, UpCaseString) {
        CHECK_EQUAL("РА-ЕПАЧЕХ",
                    codec.to_bytes(p->encrypt(L"ЧЕРЕПАХА")));
    }
    TEST_FIXTURE(KeyB_fixture, LowCaseString) {
        CHECK_EQUAL("РА-ЕПАЧЕХ",
                    codec.to_bytes(p->encrypt(L"черепаха")));
    }
    TEST_FIXTURE(KeyB_fixture, StringWithWhitspaceAndPunct) {
        CHECK_EQUAL("РА-ЕПАЧЕХ",
                    codec.to_bytes(p->encrypt(L"Че ре паха!")));
    }
    TEST_FIXTURE(KeyB_fixture, StringWithNumbers) {
        CHECK_EQUAL("РА-ЕПАЧЕХ", codec.to_bytes(p->encrypt(L"1черепаха")));
    }
    TEST_FIXTURE(KeyB_fixture, EmptyString) {
        CHECK_THROW(p->encrypt(L""),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, NoAlphaString) {
        CHECK_THROW(p->encrypt(L"1"),cipher_error);
    }
}
SUITE(DecryptText)
{
    TEST_FIXTURE(KeyB_fixture, UpCaseString) {
        CHECK_EQUAL("ЧЕРЕПАХА",
                    codec.to_bytes(p->decrypt(L"РА-ЕПАЧЕХ")));
    }
    TEST_FIXTURE(KeyB_fixture, LowCaseString) {
        CHECK_THROW(p->decrypt(L"РА-ЕпАЧЕХ"),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, WhitespaceString) {
        CHECK_THROW(p->decrypt(L"РА-ЕП АЧЕХ"),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, DigitsString) {
        CHECK_THROW(p->decrypt(L"РА-ЕП4АЧЕХ"),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, PunctString) {
        CHECK_THROW(p->decrypt(L"РА-ЕП.АЧЕХ"),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, EmptyString) {
        CHECK_THROW(p->decrypt(L""),cipher_error);
    }
}
int main(int argc, char **argv)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    return UnitTest::RunAllTests();
}