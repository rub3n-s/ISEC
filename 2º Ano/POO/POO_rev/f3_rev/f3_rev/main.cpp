//
//  main.cpp
//  f3_rev
//
//  Created by rsantos on 08/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#include <iostream>
#include "Ponto.hpp"
#include "Triangulo.hpp"
#include "Retangulo.hpp"
#include "Desenho.hpp"
#include "Prego.hpp"
#include "Aviso.hpp"
#include "Clube.hpp"
#include "Pessoa.hpp"
#include "Banco.hpp"
#include "Conta.hpp"
#include "Turma.hpp"

int main(int argc, const char * argv[]) {
    //Ponto a(1,2);
    //Ponto b(3,4);
    //const Ponto c(5,6);
    //Ponto c(5,6);
    
    /*
    cout << a.getAsString();
    cout << b.getAsString();
    cout << c.getAsString();
        
    c.setX(7);
    c.setY(1);
    cout << c.getAsString();
    
    cout << "distancia entre 'a' e 'b': " << a.distancia(b) << endl;
    
    Ponto d[] = { {1,3},{2,4},{5,7} };
    for (auto p : d)
        cout << p.getAsString(); */
    
    //Triangulo q("A",a,b,c);
    //cout << q.getAsString();
    
    /*Ponto p1(1,2);
    Retangulo r1(1,2,p1);
    Retangulo r2(2,4,p1);
    
    Ponto p2(4,5);
    r2.setCSE(p2);
    cout << r2.getAsString(); */
    
    /*Ponto p1(1,2);
    Retangulo r1(1,2,p1);
    Desenho d("A");
    
    d.addFigura(r1);
    
    cout << d.getAsString(); */
    
    /*Aviso a("Um dia asdasf...");
    Prego p(1,2);
    
    a.penduraEm(p);
    
    cout << a.getAsString();
    
    p.mudaDeSitio(4, 6);
    cout << a.getAsString(); */
    
    //Clube c("C", "Pesca");
    Pessoa p1("Ruben", 123456789, 111241241);
    Pessoa p2("Joao", 123456789, 111241241);
    Pessoa p3("Maria", 123456789, 111241241);
    
    /*cout << c.getAsString();
    
    c.addPessoa(p1);
    c.addPessoa(p2);
    c.addPessoa(p3);
    cout << c.getAsString();*/
    
    /*Banco b("CGD");
    Conta c1(150, p1);
    Conta c2(400, p2);
    Conta c3(650, p3);
    
    b.addConta(c1);
    b.addConta(c2);
    b.addConta(c3);
    
    cout << b.getAsString();*/
    
    Pessoa prof("Prof. ABC", 123456789, 111241241);
    Turma t(prof);
    
    t.addAluno(p1);
    t.addAluno(p2);
    t.addAluno(p3);
    
    cout << t.getAsString();
    
    return 0;
}
