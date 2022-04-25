#ifndef _FINAM_FUNCTIONS
#define _FINAM_FUNCTIONS
#include <windows.h>

typedef bool (WINAPI *tcallback)(BYTE* pData);
typedef BYTE* (WINAPI *typeSendCommand)(BYTE* pData);
typedef bool (WINAPI  *typeFreeMemory)(BYTE* pData);
typedef bool (WINAPI *typeSetCallback)(tcallback pCallback);

// BYTE* Initialize(const BYTE* logPath, int logLevel);
typedef BYTE* (WINAPI *initialize)(const BYTE*, int);
#endif