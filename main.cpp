#include <Windows.h>

int main() {
    HWND hWnd = FindWindow(0, "ManipuleMe"); //Name of target process
    if(hWnd == 0){ //If window doesn't exist
        MessageBox(0, "Pencere bulunamadi", "Hata", MB_OK|MB_ICONERROR); //Error window
    } else {
        DWORD proccess_ID;
        GetWindowThreadProcessId(hWnd, &proccess_ID); //Get process id
        HANDLE islem = OpenProcess(PROCESS_ALL_ACCESS, FALSE, proccess_ID); //Handle the process
        if(!islem){ //Failed to open process
            MessageBox(0, "Program acilamiyor!", "Hata!", MB_OK|MB_ICONERROR);
        } else {
            int veri = 500; //Our new data
            DWORD veriboyutu = sizeof(veri); //Data size
            if(WriteProcessMemory(islem, (LPVOID)0x61ff08, &veri, veriboyutu, NULL)){ //Write data to data address
                MessageBox(NULL, "Fonksiyon Calisti", "Basarili", MB_OK + MB_ICONINFORMATION); //Succes
            } else {
                MessageBox(NULL, "Fonksiyon calistirilamadi!", "Hata", MB_OK + MB_ICONERROR); //Error
            }
            CloseHandle(islem); //Close the handle
        }
    }
    return 0;

}