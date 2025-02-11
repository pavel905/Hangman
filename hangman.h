#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>
#include <map>

class Hangman {
public:
    // Конструктор класса Hangman.
    // Принимает словарь тем (ключ - название темы, значение - имя файла).
    Hangman(const std::map<std::string, std::string>& themeFiles);

    // Метод для выбора случайного слова из словаря.
    std::string chooseWord();

    // Метод для получения зашифрованного слова (изначально все символы скрыты).
    std::string getHiddenWord(const std::string& word);

    // Метод для отображения зашифрованного слова с учетом угаданных букв.
    std::string displayGuessedWord(const std::string& word, const std::vector<char>& guessedLetters);

    // Метод для получения корректного ввода от пользователя.
    char getUserInput(const std::vector<char>& guessedLetters);

    // Метод для проверки, есть ли буква в слове.
    bool isLetterInWord(char letter, const std::string& word);

    // Метод для отрисовки виселицы.
    void drawHangman(int incorrectAttempts);

    // Метод для выбора сложности.
    int chooseDifficulty();

    // Метод для выбора темы слов.
    std::string chooseTheme();

private:
    // Словарь тем (ключ - название темы, значение - имя файла).
    std::map<std::string, std::string> themeFiles;

    // Текущий список слов для игры.
    std::vector<std::string> wordList;

    // (Новый) Метод для чтения слов из файла.
    std::vector<std::string> readWordsFromFile(const std::string& filename);
};

#endif