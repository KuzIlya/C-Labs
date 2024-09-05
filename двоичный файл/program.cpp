#include <iostream>
#include <fstream>
#include <cstdint>

struct TMRecord {
    uint16_t parameterNumber;
    uint32_t timestamp;
    uint8_t dimension;
    uint8_t attribute;
    uint8_t valueType;
    uint8_t value[8];
};

bool readTMRecord(std::ifstream& file, TMRecord& record) {
    file.read(reinterpret_cast<char*>(&record), sizeof(TMRecord));
    return file.gcount() == sizeof(TMRecord);
}

int main() {
    const char* fileName = "190829_v29854.KNP"; 
    std::ifstream inputFile(fileName, std::ios::binary);

    if (!inputFile) {
        std::cerr << "Не удалось открыть файл: " << fileName << std::endl;
        return 1;
    }

    int usefulRecordsCount = 0;
    TMRecord record;

    if (!readTMRecord(inputFile, record)) {
        std::cerr << "Ошибка чтения первой записи начала сеанса." << std::endl;
        return 1;
    }

    while (record.parameterNumber == 0xFFFF) {
        inputFile.seekg(sizeof(TMRecord), std::ios::cur);
        if (!readTMRecord(inputFile, record)) {
            std::cerr << "Ошибка чтения следующей записи." << std::endl;
            return 1;
        }
    }

    do {

        if (record.parameterNumber != 0xFFFF) {
            usefulRecordsCount++;
        }

        if (!readTMRecord(inputFile, record)) {
            break; 
        }

    } while (true);

    std::cout << usefulRecordsCount << std::endl;

    inputFile.close();
    return 0;
}
