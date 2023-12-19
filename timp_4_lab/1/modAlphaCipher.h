/** @file modAlphaCipher.h
 * @author Калгудаева А.Е.
 * @version 1.0
 * @date 19.12.2023
 * @copyright ИБСТ ПГУ
 * @warning Это учебный пример
 */
#pragma once
#include <vector>
#include <string>
#include <map>
#include <codecvt>
#include <locale>
/** @brief Шифрование методом Гронсфельда
 * @details Ключ устанавливается в конструкторе.
 * Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
 * @warning Реализация только для английского языка
 */

class modAlphaCipher
{
private:
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
	std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	std::map <wchar_t,int> alphaNum;
	std::vector <int> key;
	std::vector<int> convert(const std::wstring& ws);
	std::wstring convert(const std::vector<int>& v);
	std::wstring getValidKey(const std::wstring & ws);
	std::wstring getValidOpenText(const std::wstring & ws);
	std::wstring getValidCipherText(const std::wstring & ws);
public:
	modAlphaCipher()=delete;
	modAlphaCipher(const std::wstring& wskey);
	std::wstring encrypt(const std::wstring& open_text);
	std::wstring decrypt(const std::wstring& cipher_text);
};
/**
* @file modAlphaCipher.h
* @brief Класс-исключение
*/
class cipher_error: public std::invalid_argument
{
public:
	explicit cipher_error (const std::string& what_arg):
		std::invalid_argument(what_arg) {}
		/**
	* @brief Принимает строку, поднимает исключение
	* @param what_arg
	*/
	explicit cipher_error (const char* what_arg):
		std::invalid_argument(what_arg) {}
		/**
* @brief Принимает си строку, поднимает исключение
* @param what_arg
*/
};
