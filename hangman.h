#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>

class Hangman {
public:
    // Конструктор класса Hangman.
    // Принимает вектор строк (словарь слов) для игры.
    Hangman(const std::vector<std::string>& wordList);

    // Метод для выбора случайного слова из словаря.
    std::string chooseWord();

    // Метод для получения зашифрованного слова (изначально все символы скрыты).
    std::string getHiddenWord(const std::string& word);

    // Метод для отображения зашифрованного слова с учетом угаданных букв.
    std::string displayGuessedWord(const std::string& word, const std::vector<char>& guessedLetters);

    // Метод для получения корректного ввода от пользователя.
    char getUserInput(const std::vector<char>& guessedLetters); // ИЗМЕНЕНО

    // (Новый) Метод для проверки, есть ли буква в слове.
    bool isLetterInWord(char letter, const std::string& word);

private:
    // Вектор строк, содержащий словарь слов.
    std::vector<std::string> wordList;
};

#endif