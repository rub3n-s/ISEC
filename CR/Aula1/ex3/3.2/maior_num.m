function m = maior_num(x)
% Input
% t - tipo de implementação
%       (1) para implementação sem utilização de vetor/matrizes
%       (2) para implementação com a função max
switch x
    case 1
        maior = -inf;
        n = 1;
        while (n~=0)
            n = input('Digite um numero: ');
            if (n > maior)
                maior = n
            end
        end
    case 2
        v = [];
        n = 1;
        while (n~=0)
            n = input('Digite um numero: ');
            v = [v n]
        end
        maior = max(v);
end