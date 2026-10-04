#include <windows.h>
#include <fstream>

// Estrutura obrigatória que o SKSE 32-bits (LE) exige para reconhecer o mod
struct PluginInfo {
    unsigned int infoVersion;
    const char* name;
    unsigned int version;
};

extern "C" {
    // Função que o SKSE chama para verificar a compatibilidade
    __declspec(dllexport) bool SKSEPlugin_Query(const void* skse, PluginInfo* info) {
        info->infoVersion = 1;
        info->name = "MCO_LE_Targeting_Fix";
        info->version = 1;
        return true;
    }

    // Função executada quando o jogo abre
    __declspec(dllexport) bool SKSEPlugin_Load(const void* skse) {
        // Cria um arquivo de log para provarmos que a DLL funcionou no seu PC
        std::ofstream log("Data\\SKSE\\Plugins\\MCO_LE_Targeting_Fix_Log.txt");
        log << "Motor de mira base carregado no Skyrim LE com sucesso!" << std::endl;
        return true;
    }
}

// Ponto de entrada padrão do Windows para a DLL
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    return TRUE;
}
