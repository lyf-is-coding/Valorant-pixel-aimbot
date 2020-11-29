#pragma once

#include "pch.h"
#include "MyForm1.h"
//#include "interception.h"
//#include <stdio.h>
//#include <iostream>
//#include <thread>
//#include <chrono>


//extern int UIMain();

using namespace std;
using namespace Lavender;

int UIMain()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault;

    MyForm^ NewUi = gcnew MyForm();
    Application::Run(NewUi);

    return 1;
}


DWORD WINAPI Main_Thread(LPVOID lpParam)
{
    UIMain();
    return 1;
}

void DestroyBelowThing(InterceptionContext context) {
    interception_destroy_context(context);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(hModule);
            CreateThread(0, 0, Main_Thread, 0, 0, 0);
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            /*interception_destroy_context(context);*/
            DestroyBelowThing(context);
            if (screenData) {
                free(screenData);
            }
            
            break;
    }

    return TRUE;
}