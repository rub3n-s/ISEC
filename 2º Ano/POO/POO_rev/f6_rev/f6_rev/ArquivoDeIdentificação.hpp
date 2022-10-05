//
//  ArquivoDeIdentificação.hpp
//  f6_rev
//
//  Created by rsantos on 11/02/2021.
//  Copyright © 2021 Rúben Santos. All rights reserved.
//

#ifndef ArquivoDeIdentificac_a_o_hpp
#define ArquivoDeIdentificac_a_o_hpp

#include "Cidadao.hpp"
#include <vector>

class ArquivoDeIdentificação : public Cidadao {
    vector<Cidadao *> cidadaos;
    
public:
    ArquivoDeIdentificação(string n, int b);
    virtual ~ArquivoDeIdentificação();
};

#endif /* ArquivoDeIdentificac_a_o_hpp */
