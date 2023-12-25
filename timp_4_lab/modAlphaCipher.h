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
 * @warning Реализация только для русского языка
 */

class modAlphaCipher
{
private:
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
        ///алфавит по порядку
	std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
        ///ассоциативный массив "номер по символу"
	std::map <wchar_t,int> alphaNum;
        ///ключ 
	std::vector <int> key;
        ///Преобразование строка-вектор
	std::vector<int> convert(const std::wstring& ws);
        ///Преобразование вектор-строка
	std::wstring convert(const std::vector<int>& v);
        /**
        * @brief Проверка на хороший ключ
        * @throw cipher_error, если ключ пустой или в ключе находится символ не принадлежащий алфавиту 
        */
	std::wstring getValidKey(const std::wstring & ws);
        /**
        * @brief Метод для валидации открытого текста \n
        * Все символы не принадлежащие алфавиту игнорируются \n
        * Все строчные символы преобразуются к прописным
        * @throw cipher_error, если текст пустой 
        */
	std::wstring getValidOpenText(const std::wstring & ws);
         /**
        * @brief Метод для валидации текста зашифрования \n
        * @throw cipher_error, если текст пустой или в тексте содержатся строчные буквы 
        */
	std::wstring getValidCipherText(const std::wstring & ws);
public:
        ///запретим конструктор без параметров
	modAlphaCipher()=delete;
        ///конструктор для установки ключа
	modAlphaCipher(const std::wstring& wskey);
        /**
        * @brief Зашифровывание
        * Открытый текст не должен быть пустой строкой.
        * Строчные символы автоматически преобразуются к 
        прописным.
        * Все не-буквы удаляются
        * @throw cipher_error, если текст пустой
        */
	std::wstring encrypt(const std::wstring& open_text);
        /**
        * @brief Расшифровывание
        * @throw cipher_error, если текст пустой
        */
	std::wstring decrypt(const std::wstring& cipher_text);
};
/**
* @file modAlphaCipher.h
* @brief Класс-исключение
*/
class cipher_error: public std::invalid_argument
{
public:
        ///Принимает строку, поднимает исключение
	explicit cipher_error (const std::string& what_arg):
		std::invalid_argument(what_arg) {}
        ///Принимает строку, поднимает исключение
	explicit cipher_error (const char* what_arg):
		std::invalid_argument(what_arg) {}
};
