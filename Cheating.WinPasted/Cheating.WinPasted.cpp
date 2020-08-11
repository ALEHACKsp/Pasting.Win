#include <Windows.h>
#include <iostream>
#include <time.h>
#include <random>
#include "kdmapper.hpp"
#include "xorstr.h"

std::string random(int len)
{
    std::string str = xorstr_("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    std::string newstr;
    int pos;
    srand(time(0));
    while (newstr.size() != len) {
        pos = ((rand() % (str.size() - 2)));
        newstr += str.substr(pos, 1);
    }
    std::mt19937 rand_func(std::random_device{}());
    std::shuffle(newstr.begin(), newstr.end(), rand_func);
    return newstr.c_str();
}

//Cheating.Win does a lot of rebrands, and one of them is strawberry (please do not give hate to disrupt, he did not know this untill i dumped it.)
//then i got my hands on strawberrys loader, and decided to give it a shot since level is a huge dickhead paster cunt, after a few hours, i was doing it
//all wrong, as bitch had disabled every loader, so i decided look into the memory trick, little did i know that after 10 minutes i had the driver in my 
//debugger, i dumped it to a file, fixed a few issues like (relocation and shit), then it was like a driver from levels pc  but more like driver from btbd's 
//hwid spoofer repo lmfao. in conclusion level / nexlevel is the same retarded kevin paster which i raped a few months ago, who just knows slightly more so
//he can paste and be not that obvious. oh and btw kevin if ur reading this, can u please not lie to me next time? cuz this is the only driver which is
//referenced in ur kdmapper, so ur driver is obviously not streamed so yeah lol GG.

int main()
{
    SetConsoleTitleA(xorstr_("Cheating.Win Spoofer Crack By Bucciarati#1337 + ZeraX"));

    remove(xorstr_("C:\\Windows\\Cheating.win-pasta loll"));

    DWORD crap = 0;

    std::cout << xorstr_("Cheating.win Paste Cracked By Bucciarati#1337 + ZeraX!\nDo not buy his paste, hes a full on retard skid who lies a shit ton!") << std::endl;

    std::cout << xorstr_("\nCreating File For Paste lol!") << std::endl;

    //Creating file in C:\Windows so the driver sees the file and reads it (btw i hex editted the driver slightly so it doesnt screw my friend's brand)
    HANDLE file = CreateFileA(xorstr_("C:\\Windows\\Cheating.win-pasta loll"), GENERIC_READ | GENERIC_WRITE, 0, 0, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);

    //file failed to be created, so an basic exception handler
    if (file == INVALID_HANDLE_VALUE)
    {
        std::cout << xorstr_("\nFailed To Make File In C:\\Windows For Cheating.lose Paste Driver!") << std::endl;
        Sleep(5000);
        exit(1);
    }

    std::cout << xorstr_("Created File Successfully!\nGenerating A Random Serial!\nWriting Random Serial For Paste ROFL!") << std::endl;

    //generates a random serial which is size of 11 
    std::string kek = random(11);   
    //a bit of a watermark cuz why not ;)
    std::string shit = xorstr_("pasting.win_crkbyzerax_") + kek;

    //write serial to file
    BOOL write = WriteFile(file, shit.c_str(), strlen(shit.c_str()), &crap, 0);

    //exception handling
    if (write == FALSE)
    {
        std::cout << xorstr_("\nFailed To Write File In SystemRoot For Cheating.lose Paste Driver!") << std::endl;
        Sleep(5000);
        exit(1);
    }

    //close the handle so other shit, can open an handle and read the file.
    CloseHandle(file);

    std::cout << xorstr_("Successfully Writen File\nLoading Cheating.lose Paste Driver!\n") << std::endl;


    //loading shit intel vulner driver for kdmapper
    HANDLE iqvw64e_device_handle = intel_driver::Load();

    //driver failed to load rip
    if (!iqvw64e_device_handle || iqvw64e_device_handle == INVALID_HANDLE_VALUE)
    {
        std::cout << xorstr_("[-] Failed to load driver iqvw64e.sys") << std::endl;
        return -1;
    }

    //maps section for kd
    if (!kdmapper::MapDriver(iqvw64e_device_handle))
    {
        //failed to map them sections RIP
        intel_driver::Unload(iqvw64e_device_handle);
        return -1;
    }

    //unload the driver cuz its work is done
    intel_driver::Unload(iqvw64e_device_handle);

    std::cout << xorstr_("\nLoaded Driver Successfully!\n") << std::endl;

    //stops windows management instrumenation service because it has smbios cache and we want it to be cleared
    system(xorstr_("net stop winmgmt /y"));
    //starts windows management instrumenation service as the cache has been cleared, and we can turn it on
    system(xorstr_("net start winmgmt"));

    //deletes the serial file
    remove(xorstr_("C:\\Windows\\Cheating.win-pasta loll"));
    std::cout << xorstr_("\n\nSpoofed With Pasted Shit! Exiting In 5 Seconds!") << std::endl;
    remove(xorstr_("C:\\Windows\\Cheating.win-pasta loll"));

    Sleep(5000);

    exit(0);
}
