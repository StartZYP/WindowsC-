#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <set>

using namespace std;

BOOL CALLBACK EnumChildProc(_In_ HWND hwnd, _In_ LPARAM lParam)
{
    char szTitle[MAX_PATH] = {0};
    char szClass[MAX_PATH] = {0};
    int nMaxCount = MAX_PATH;

    LPSTR lpClassName = szClass;
    LPSTR lpWindowName = szTitle;

    GetWindowTextA(hwnd, lpWindowName, nMaxCount);
    GetClassNameA(hwnd, lpClassName, nMaxCount);

    return TRUE;
}

BOOL CALLBACK EnumWindowProc(HWND hwnd, LPARAM lParam)
{

    char szTitle[MAX_PATH] = {0};
    char szClass[MAX_PATH] = {0};
    int nMaxCount = MAX_PATH;
    LPSTR lpClassName = szClass;
    LPSTR lpWindowName = szTitle;

    //cout << "[Parent window] window handle: " << hwnd << endl;
    GetWindowTextA(hwnd, lpWindowName, nMaxCount);
    GetClassNameA(hwnd, lpClassName, nMaxCount);
    // cout << "[Parent window] window handle: " << hwnd << " window name: "
    //      << lpWindowName << " class name " << lpClassName << endl;
    set<string> msg{"Hello", "÷Ì÷Ìœ¿", "—ßœ∞", " C++ extension!", "and the Cfe++ extension!", "and the C++ extefension!"};
    for (const string &word : msg)
    {

        if (strstr(lpWindowName, word.c_str()))
        {
            cout << "[Child window] window handle: " << hwnd << " window name: "
                 << lpWindowName << " class name " << lpClassName << endl;
        }
    }

    //EnumChildWindows(hwnd, EnumChildProc, lParam);
    return TRUE;
}

VOID GetProcessHandle(const set<string> &set)
{
    EnumWindows(EnumWindowProc, 0);
}

int main()
{

    vector<string> msg{"Hello", "66666", "shellcode", " C++ extension!", "and the Cfe++ extension!", "and the C++ extefension!"};
    EnumWindows(EnumWindowProc, 0);
    // for (const string &word : msg)
    // {
    //     //MessageBox(NULL, word.c_str(), "hahah?", MB_OK);
    //     HWND window = FindWindowA(NULL, word.c_str());
    //     cout << window << "1\n";
    //     cout << word << "2\n";
    //     if (window != NULL)
    //     {
    //         MessageBox(NULL, word.c_str(), "hahah?", MB_OK);
    //     }
    // }
    // cout << endl;
    return 0;
}
