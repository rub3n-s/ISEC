//
//  main.cpp
//  f6_rev
//
//  Created by rsantos on 10/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include <random>
#include <ctime>
#include "Peixe.hpp"
#include "Aquario.hpp"
#include "Cidadao.hpp"
#include "Passeio.hpp"
#include "ArquivoDeIdentificação.hpp"
#include "FichaDeInscricao.hpp"

double getRealUniform() {
    static default_random_engine e(time(0));
    static uniform_real_distribution<double> d(0.0, 1.0);
    
    return d(e);
}

int main(int argc, const char * argv[]) {
    /* Aquario a;
    Peixe *p1 = new Peixe("Nemo", "Laranja");
    Peixe *p2 = new Peixe("Dori", "Azul");
    Peixe *p3 = new Peixe("Bolhas", "Amarelo");
    
    a.addPeixe(p1);
    a.addPeixe(p2);
    a.addPeixe(p3);
    
    cout << a;
    
    cout << "------------------------------------------------\n";
    a.alimentarPeixes(50);
    cout << a;
    
    cout << "------------------------------------------------\n";
    a.alimentarPeixes(50);
    cout << a;
    
    */
    Cidadao lider("Joao", 123456789);
    Passeio p(lider,"Mira","Segunda-Feira");
    
    /*Cidadao *p1 = new Cidadao("Manuel", 1);
    Cidadao *p2 = new Cidadao("Pedro", 2);
    Cidadao *p3 = new Cidadao("Ze", 3);
    Cidadao *p4 = new Cidadao("Ruben", 4); */
    
    Cidadao *c1 = new ArquivoDeIdentificação("Manuel", 1);
    Cidadao *c2 = new ArquivoDeIdentificação("Pedro", 2);
    Cidadao *c3 = new ArquivoDeIdentificação("Ze", 3);
    Cidadao *c4 = new ArquivoDeIdentificação("Ruben", 4);
    
    p.associarParticipante(c1);
    p.associarParticipante(c2);
    p.associarParticipante(c3);
    p.associarParticipante(c4);
    
    cout << p;
    
    FichaDeInscricao f1(c1, 0);
    FichaDeInscricao f2(c2,2);
    FichaDeInscricao f3(c3,1);
    FichaDeInscricao f4(c4,0);
    
    cout << f1 << f2 << f3 << f4;
    
    return 0;
}
