#include "Application.hpp"

// bool CALLBACK acceptor2(BYTE *pData)
// {
//     // xmlfile<<pData<<std::endl;

//     // FreeMemory(pData);
//     return true;
// }


int main(int argc, char* argv[]) {

    Application& myapp = Application::getApplication();
    myapp.run("r", "q");
    myapp.getConnector()->sendCommand();
    // myapp->close();
    // myapp.getConnector().getUser().print();

    return 0;
}

// #include <windows.h>
// #include <iostream>
// #include <fstream>

//

// typedef bool (WINAPI *tcallback)(BYTE* pData);
// typedef BYTE* (WINAPI *typeSendCommand)(BYTE* pData);
// typedef bool (WINAPI  *typeFreeMemory)(BYTE* pData);
// typedef bool (WINAPI *typeSetCallback)(tcallback pCallback);


// std::ofstream xmlfile;
// typeFreeMemory FreeMemory;


// bool CALLBACK acceptor(BYTE *pData)
// {
//     xmlfile<<pData<<std::endl;
//     FreeMemory(pData);
//     return true;
// }

// int main(int argc, char* argv[]) {

//     setlocale(LC_CTYPE, "");

//     std::cout<<"Statring!"<<std::endl;
//     xmlfile.open("test.xml");
//     xmlfile<<"<?xml version='1.0' encoding='UTF-8'?>";
//     xmlfile<<"<root>";

//     HMODULE hm = LoadLibrary("D:\\repo\\ScalpAssistant\\src\\lib\\finam\\txmlconnector64.dll");
//     if (hm) {
//         typeSetCallback SetCallback =
//             reinterpret_cast<typeSetCallback>(GetProcAddress(hm, "SetCallback"));

//         FreeMemory =
//             reinterpret_cast<typeFreeMemory>(GetProcAddress(hm, "FreeMemory"));

//         SetCallback(acceptor);
    

//         typeSendCommand SendCommand =
//             reinterpret_cast<typeSendCommand>(GetProcAddress(hm,"SendCommand"));
//         if (!SendCommand)    {
//             printf("\"SendCommand\" not found (0x%X)\n", GetLastError());
//             return -1;
//         }
//         else {
//             BYTE* ss = SendCommand(const_cast<BYTE*> (reinterpret_cast<const BYTE*>(
//                 "<command id='connect'>"
//                 "<login>KOKS</login><password>koks</password>"
//                 "<host>192.168.15.15</host><port>3901</port>"
//                 "<logsdir>.\\LOGS\\</logsdir><loglevel>0</loglevel></command>")));
//             std::cout<<reinterpret_cast<const char*>(ss);
//             FreeMemory(ss);

//             Sleep(10000);

//             ss = SendCommand(const_cast<BYTE*> (reinterpret_cast<const BYTE*>("<command id='subscribe'>"
//                 "<alltrades><secid>304</secid></alltrades>"  //???????????????????????????? ???????? ???????????? ?????? ??????????????
//                 "<quotations><secid>304</secid></quotations>" //?? ?????????????? ???????? ???????? ?????????????????????????? ???? ????,
//                 "<quotes><secid>304</secid></quotes>" //?????? ???????????????????? ????????????
//                 "</command>")));
//             std::cout<<reinterpret_cast<const char*>(ss);
//             FreeMemory(ss);

//             // Sleep(1000);

//             // ss = SendCommand(reinterpret_cast<BYTE*>(
//             //         "<command id='disconnect'/>"));
//             //     std::cout<<reinterpret_cast<char*>(ss);
//             // FreeMemory(ss);
//         }
    
//         try {
//             FreeLibrary(hm);
//         }
//         catch (...) {
//             std::cout<<"Fail in FreeLibrary";
//         }
//     } else {
//         int err = GetLastError();

//         std::cout << "LoadLibrary(\"lib\\txmlconnector.dll\") - error\nError: " << err << "\n";
//     }
//     xmlfile<<"</root>";

//     std::cout<<"\nEnded...\n";
//     char c;
//     std::cin>>c;
//     return 0;
// }