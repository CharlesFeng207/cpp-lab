#include <iostream>
#include <stdio.h>
#include <cstring>
#include <fstream>
#include <sstream>

FILE *file = nullptr;
void fileTestC()
{
    // Write 
    file = fopen("fileTestC.txt", "wb");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    char* testStr = "xxxxx2";
    fwrite(testStr, 1, strlen(testStr), file);
    fflush(file);
    fclose(file);

    // Read
    file = fopen("fileTestC.txt", "rb");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    char buffer[10];
    size_t nread = fread(buffer, 1, sizeof(buffer), file);
    printf("nread: %d\n", nread);
    printf("buffer: %s\n", buffer);
    fclose(file);
}

void fileTestCpp()
{
    std::ofstream output("fileTestCpp.txt");
    output << "xxxxxxxxxxx" << std::endl;
    output << "xxxxxxxxxxx2" << std::endl;
    output << "xxxxxxxxxxx3" << std::endl;
    output.close();

    std::ifstream input("fileTestCpp.txt");    // 打开文件
    if (!input) {
        std::cout << "Failed to open file." << std::endl;
        return;
    }

    // std::string line;
    // while (std::getline(input, line)) {    // 逐行读取文件内容
    //     std::cout << line << std::endl;    // 输出文件内容
    // }

    std::stringstream buffer;
    buffer << input.rdbuf();  // 一次性将文件内容读入到字符串流中
    std::string contents = buffer.str();
    std::cout << contents << std::endl;
    
    input.close();    // 关闭文件
}

int main()
{
    fileTestC();
    fileTestCpp();   
    return 0;
}