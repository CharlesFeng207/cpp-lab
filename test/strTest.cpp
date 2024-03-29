// #include <float.h>
#include <assert.h>
#include <cstring>
#include <iostream>
#include <boost/format.hpp>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <boost/algorithm/string/join.hpp>

using namespace std;

std::string getFileName(const std::string& filePath) {
    size_t lastSlash = filePath.find_last_of('/');

    if (lastSlash != std::string::npos) {
        return filePath.substr(lastSlash + 1);
    } else {
        return filePath;
    }
}

std::string getDirectory(const std::string& filePath) {
    size_t lastSlash = filePath.find_last_of('/');

    if (lastSlash != std::string::npos) {
        return filePath.substr(0, lastSlash);
    } else {
        return "";
    }
}

char *strcopytest(char *des, const char *src)
{
    assert(des != nullptr && src != nullptr);

    char *r = des;
    while ((*des++ = *src++) != '\0')
        ;
    return r;
}

int strcmptest(const char *s1, const char *s2)
{
    assert(s1 != nullptr && s2 != nullptr);

    while (*s1++ == *s2++)
    {
        if (*s1 == '/0')
            break;
    }

    return *s1 == *s2 ? 1 : 0;
}

template <typename... Args>
static std::string str_format(const std::string &format, Args... args)
{
    auto size_buf = std::snprintf(nullptr, 0, format.c_str(), args...) + 1;
    std::unique_ptr<char[]> buf(new (std::nothrow) char[size_buf]);

    if (!buf)
        return std::string("");

    std::snprintf(buf.get(), size_buf, format.c_str(), args...);
    return std::string(buf.get(), buf.get() + size_buf - 1);
}

template <typename... Args>
static std::wstring wstr_format(const std::wstring &format, Args... args)
{
    auto size_buf = std::snprintf(nullptr, 0, format.c_str(), args...) + 1;
    std::unique_ptr<char[]> buf(new (std::nothrow) char[size_buf]);

    if (!buf)
        return std::wstring("");

    std::snprintf(buf.get(), size_buf, format.c_str(), args...);
    return std::wstring(buf.get(), buf.get() + size_buf - 1);
}

void formatArr()
{
    vector<string> arr = {"1", "2", "3"};
    string str = boost::algorithm::join(arr, ",");
    cout << str << endl;

    std::unordered_set<std::string> set = {"1", "2", "3"};
    string str2 = boost::algorithm::join(set, ",");
    cout << str2 << endl;
}

void formatString()
{
    cout << "formatString..." << endl;
    std::string str = "1234567890";
    str += "x";
    str += 2;

    cout << str << endl;

    char *package_name = "com.tencent.tmgp.pubgmhd";
    char file_name[260];
    snprintf(file_name, sizeof(file_name), "/sdcard/Android/data/%s/files/framerecord.txt", package_name);
    cout << file_name << endl;

    boost::format fmt("/sdcard/Android/data/%1%/files/%2%/framerecord.txt");
    fmt % package_name % 100;

    std::string filepath = fmt.str();
    cout << "filepath " << filepath << endl;
    cout << "getFileName " << getFileName(filepath) << endl;
    cout << "getDirectory " << getDirectory(filepath) << endl;

    std::string strtest = str_format("%d.%d.%d", 1, 0, 1);
    std::string wstrtest = str_format("%d.%d.%d", 2, 3, 2);

    cout << "str = " << strtest << "\n";
    cout << "wstr = " << wstrtest << "\n";

    std::string name = "Bob";
    int age = 30;

    std::stringstream ss;
    ss << "My name is " << name << " and I am " << age << " years old." << package_name;
    std::string formattedString = ss.str();
    std::cout << formattedString << std::endl;
}

int main()
{
    // char s2[] = "asdp32132";

    // cout << strcmptest("asdp32132", "3123123") << endl;
    char dest[] = "4321";
    char src[] = "123";

    // strcopytest(dest, src);

    cout << dest << endl;

    cout << strcmptest(dest, "4321") << endl;
    cout << dest << endl;
    // cout << strcmp("asd", "asd3xzx") << endl;
    // cout << strcmp("asd2xxx", "asd2xxx") << endl;
    formatString();

    formatArr();
}