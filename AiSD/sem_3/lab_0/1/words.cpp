#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void generateWords(const std::string& alphabet, int n, std::string current, std::vector<std::string>& result) {
    if (n == 0) {
        result.push_back(current);
        return;
    }

    for (char letter : alphabet) {
        generateWords(alphabet, n - 1, current + letter, result);
    }
}

int main() {
    int n = 1; // Замените на нужное значение n
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz"; // Замените на свой алфавит

    std::vector<std::string> result;
    generateWords(alphabet, n, "", result);

    // Сортируем полученные слова в лексикографическом порядке
    std::sort(result.begin(), result.end());

    // Выводим все слова
    for (const std::string& word : result) {
        std::cout << word << std::endl;
    }

    return 0;
}