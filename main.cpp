#include <iostream>
#include <vector>
#include "hangman.h"

int main() {
    std::vector<std::string> words = {"apple", "banana", "cherry"};
    Hangman hangman(words);

    try {
        std::string word = hangman.chooseWord();
        std::cout << "Загаданное слово (для отладки): " << word << std::endl; // Для отладки
        std::string hiddenWord = hangman.getHiddenWord(word);
        std::cout << "Зашифрованное слово: " << hiddenWord << std::endl;

    } catch (const std::runtime_error& error) {
        std::cerr << "Ошибка: " << error.what() << std::endl;
        return 1; // Код ошибки
    }

    return 0; // Код успешного завершения
}