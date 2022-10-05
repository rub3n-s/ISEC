function v = filtra_matriz(m,x)
% Input: 
% m - matriz
% x - tipo de implementação
%       (1) com intruções for e if
%       (2) com find
% Output:
% v - vetor unidimensional com os numeros pares

switch x
    case 1
        v = [];
        for coluna = 1 : size(m,2) % ,2 -> quantas colunas
            for linha = 1 : size(m,1) % ,1 -> quantas linhas
                value = m(linha,coluna);
                if mod(value,2)==0
                    v = [v value];
                end
            end
        end
    case 2
        posicoes = find(mod(m,2)==0)
        v = m(posicoes)';
        
end