#include "IntrebareManager.h"
#include <iostream>

IntrebareManager::IntrebareManager() {
    intrebari = {
        {"Care este capitala Frantei?", {"Paris", "Londra", "Berlin", "Madrid"}, 0},
        {"Care este cel mai mare ocean?", {"Pacific", "Atlantic", "Indian", "Arctic"}, 0},
        {"Cine a scris 'Micul Print'?", {"Victor Hugo", "Mark Twain", "Antoine de Saint-Exupery", "Jules Verne"}, 2},
        {"Care este cel mai mare continent?", {"Asia", "Africa", "America", "Europa"}, 0},
        {"Cine a fost primul om pe luna?", {"Yuri Gagarin", "Neil Armstrong", "Buzz Aldrin", "John Glenn"}, 1},
        {"Ce este un computer?", {"Un animal", "O masina", "Un dispozitiv electronic", "Un vehicul"}, 2},
        {"Cum se numește capitala Italiei?", {"Roma", "Paris", "Berlin", "Madrid"}, 0},
        {"Cine a compus 'Simfonia 5'?", {"Mozart", "Beethoven", "Bach", "Chopin"}, 1},
        {"Care este cel mai mare animal terestru?", {"Elefantul", "Girafa", "Leul", "Hipopotamul"}, 0},
        {"Ce planetă este cunoscută ca 'Planeta Roșie'?", {"Venus", "Pământ", "Marte", "Jupiter"}, 2},
        {"Cine a inventat becul?", {"Thomas Edison", "Nikola Tesla", "Alexander Graham Bell", "James Watt"}, 0},
        {"Care este cel mai adânc ocean?", {"Pacific", "Atlantic", "Indian", "Arctic"}, 0},
        {"Ce limba vorbesc majoritatea oamenilor în China?", {"Mandarina", "Cantonă", "Engleza", "Francesa"}, 0},
        {"Ce fruct este cunoscut pentru conținutul său de vitamina C?", {"Mar", "Portocala", "Banana", "Strugure"}, 1},
        {"Care este cel mai lung fluviu din lume?", {"Amazon", "Nil", "Yangtze", "Mississippi"}, 0}
    };
}

Intrebare IntrebareManager::obtineIntrebare(int index) {
    return intrebari[index];
}

void IntrebareManager::afiseazaToateIntrebarile(const std::vector<Intrebare>& intrebari) {
    for (size_t i = 0; i < intrebari.size(); ++i) {
        std::cout << "\nIntrebare " << (i + 1) << ": " << intrebari[i].intrebare << std::endl;
        for (size_t j = 0; j < intrebari[i].raspunsuri.size(); ++j) {
            std::cout << j + 1 << ". " << intrebari[i].raspunsuri[j] << std::endl;
        }
    }
}
