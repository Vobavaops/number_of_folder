#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int countFiles(const fs::path& directory) {
    int count = 0;

    for (const auto& entry : fs::recursive_directory_iterator(directory)) {
        if (fs::is_regular_file(entry)) {
            count++;
        }
    }

    return count;
}

int main() {
    std::cout << "Введите путь к директории: ";
    std::string directoryPath;
    std::getline(std::cin, directoryPath);

    int fileCount = countFiles(directoryPath);

    std::cout << "Количество файлов: " << fileCount << std::endl;

    return 0;
}
