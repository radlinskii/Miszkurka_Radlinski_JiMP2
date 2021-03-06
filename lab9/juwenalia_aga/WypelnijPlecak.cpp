//
// Created by miszk on 5/11/2017.
//

#include "WypelnijPlecak.h"

WypelnijPlecak::WypelnijPlecak(Student *imprezowicz) {
    srand((unsigned int)(time(NULL)));
    int wylosowana;
    int numer_polki=0;
    while (numer_polki <20 ) {
        numer_polki++;
        wylosowana = rand()%5;

        if (wylosowana == 0) {
            Wodka * vodka = new Wodka;
            if (ebac(imprezowicz->plecak_studenta, *imprezowicz, (*vodka).gram_alkoholu))
            {
                //std::cout << "dodaje wodke" << std::endl;
                imprezowicz->plecak_studenta.prowianty_.emplace_back(*vodka);
                imprezowicz->plecak_studenta.gram_alkoholu += (*vodka).gram_alkoholu;
                imprezowicz->plecak_studenta.pojemnosc --;
            }
            else{
                delete(vodka);
            }
        }
        else if (wylosowana == 1) {
            Winko * kadarka = new Winko;
            if (ebac(imprezowicz->plecak_studenta, *imprezowicz, (*kadarka).gram_alkoholu))
            {
               // std::cout << "dodaje piwo" << std::endl;
                imprezowicz->plecak_studenta.prowianty_.emplace_back(*kadarka);
                imprezowicz->plecak_studenta.gram_alkoholu += (*kadarka).gram_alkoholu;
                imprezowicz->plecak_studenta.pojemnosc --;
            }
            else{
                delete(kadarka);
            }
        }
        else if (wylosowana == 2) {
            Piwko * piwo = new Piwko;
            if (ebac(imprezowicz->plecak_studenta, *imprezowicz, (*piwo).gram_alkoholu))
            {
                // std::cout << "dodaje piwo" << std::endl;
                imprezowicz->plecak_studenta.prowianty_.emplace_back(*piwo);
                imprezowicz->plecak_studenta.gram_alkoholu += (*piwo).gram_alkoholu;
                imprezowicz->plecak_studenta.pojemnosc --;
            }
            else{
                delete(piwo);
            }
        }
        else if (wylosowana == 3) {
            //std::cout << "dodaje sok" << std::endl;
            Sok *soczek = new Sok;
            imprezowicz->plecak_studenta.prowianty_.emplace_back(*soczek);
            imprezowicz->plecak_studenta.pojemnosc --;
        }
        else if (wylosowana == 4) {
            //std::cout << "dodaje drozdzowke" << std::endl;
            Drozdzowka *buleczka = new Drozdzowka;
            imprezowicz->plecak_studenta.prowianty_.emplace_back(*buleczka);
            imprezowicz->plecak_studenta.pojemnosc --;
        }

    }
}

bool WypelnijPlecak::ebac(Plecak pl, Student st, int dodatkowe_gramy_alkoholu) {
    double ebac=0;
    double SD;
    SD = (pl.gram_alkoholu + dodatkowe_gramy_alkoholu) / 10;
    ebac = ((0.806 * SD * 1.2)/(st.BW*st.Wt) - st.MR*st.DP);
    //std::cout << "SD" << SD <<std::endl;
    return ebac < 0.2;
}
