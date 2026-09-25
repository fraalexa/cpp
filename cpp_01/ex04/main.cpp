#include <iostream>
#include <fstream>
#include <string>

static void replaceInFile(std::ifstream& inFile,
                          std::ofstream& outFile,
                          const std::string& toFind,
                          const std::string& toReplace) {
    std::string line;

    if (toFind == toReplace) {
        std::cerr << "error: s1 and s2 are equal \n";
        return ;
    }
    while (std::getline(inFile, line)) {
        size_t pos = 0;

        while ((pos = line.find(toFind, pos)) != std::string::npos) {
            line.replace(pos, toFind.length(), toReplace);
            pos += toReplace.length();
        }

        outFile << line;

        if (!inFile.eof()) {
            outFile << std::endl;
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Error: Invalid argument count. Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: Target string (s1) cannot be empty." << std::endl;
        return 1;
    }

    std::ifstream inFile(filename.c_str());
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open input file '" << filename << "'" << std::endl;
        return 1;
    }

    const std::string outFilename = filename + ".replace";
    std::ofstream outFile(outFilename.c_str());
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not create output file '" << outFilename << "'" << std::endl;
        inFile.close();
        return 1;
    }

    replaceInFile(inFile, outFile, s1, s2);

    inFile.close();
    outFile.close();

    return 0;
}