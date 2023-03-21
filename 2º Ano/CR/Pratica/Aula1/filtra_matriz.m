function [m] = filtra_matriz(m,t)
    % Input
    %   m - matriz inicializada pela função gera_matriz
    %   t - tipo de implementação:
    %       (1) - instruções for e if
    %       (2) - função find 
    % Output
    %   v - vetor unidimensional com os elementos pares da matriz m
    
    switch t
        case 1
            v = [];
            for i=1:size(m,2)   % size(m,2) = colunas
                for j=1:size(m,1)   % size(m,1) = linhas
                    if mod(m(i,j),2)==0
                        v = [v m(i,j)]
                    end
                end
            end
        case 2
            v = m(find(mod(m,2)==0))'
    end
end