#include <iostream>
#include <vector>
#include "hangman.h"

int main() {
    std::vector<std::string> words = {"apple", "banana", "cherry"};
    Hangman hangman(words);

      std::vector<char> guessedLetters;
    try {
        std::string word = hangman.chooseWord();
        std::cout << "Загаданное слово (для отладки): " << word << std::endl; // Для отладки
	std::string hiddenWord = hangman.displayGuessedWord(word, guessedLetters);
        std::cout << "Зашифрованное слово: " << hiddenWord << std::endl;
	
	 // Пример: угадана буква 'a'
        guessedLetters.push_back('a');
        std::string partiallyGuessedWord = hangman.displayGuessedWord(word, guessedLetters);
        std::cout << "Слово с угаданными буквами (a): " << partiallyGuessedWord << std::endl;

        // Пример: угаданы буквы 'a' и 'e'
        guessedLetters.push_back('e');
        std::string moreGuessedWord = hangman.displayGuessedWord(word, guessedLetters);
        std::cout << "Слово с угаданными буквами (a, e): " << moreGuessedWord << std::endl;


    } catch (const std::runtime_error& error) {
        std::cerr << "Ошибка: " << error.what() << std::endl;
        return 1; // Код ошибки
    }

    return 0; // Код успешного завершения
}