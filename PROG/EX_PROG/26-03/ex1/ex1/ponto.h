//
//  ponto.h
//  ex1
//
//  Created by rsantos on 26/03/2020.
//  Copyright © 2020 Rúben Mendes Santos. All rights reserved.
//

#ifndef ponto_h
#define ponto_h

    // alinea a)
    typedef struct ponto ponto2D;
        struct ponto{
            int x, y;
    };

    void printPonto(ponto2D a);

    void initPonto(ponto2D* p);

    void movePonto(ponto2D* p, int dx, int dy);

    int retaPonto(ponto2D p1, ponto2D p2, ponto2D p3);

#endif /* ponto_h */
