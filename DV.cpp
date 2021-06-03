#include <windows.h>
#include <iostream>
#include <string>
#include <VersionHelpers.h>
using namespace std;

#pragma warning(disable : 4996)


string GetOsVersionName()
{
    if (IsWindows10OrGreater())
    {
        return "10";
    }
    if (IsWindows8Point1OrGreater())
    {
        return "8.1";
    }
    if (IsWindows8OrGreater())
    {
        return "8";
    }
    if (IsWindows7SP1OrGreater())
    {
        return "7 Service Pack 1";
    }
    if (IsWindows7OrGreater())
    {
        return "7";
    }
    if (IsWindowsVistaOrGreater())
    {
        return "Vista";
    }
    if (IsWindowsXPOrGreater())
    {
        return "XP";
    }
    return "Unknown";
}

string GetBitWindows()
{
#if defined(_WIN64)
    return "x64";
#elif defined(_WIN32)
    return "x32";
#else
    return "can not defined bit size"
#endif
}

string GetOsBuild()
{
    DWORD dwVersion;
    DWORD dwBuild = 0;
    dwVersion = GetVersion();

    if (dwVersion < 0x80000000)
        dwBuild = (DWORD)(HIWORD(dwVersion));
    return to_string(dwBuild);
}

int main()
{
    string osVersionName = GetOsVersionName();//определение имени ос
    string osBitSize = GetBitWindows();//битность системы
    string osBuild = GetOsBuild();//номер билда


    cout << "Operating system: Windows " + osVersionName + " " + osBitSize + "( Build " + osBuild + ")";

    return 0;
}