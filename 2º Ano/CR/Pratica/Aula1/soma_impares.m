function impares = maior_num(matriz)
    impares = [];
    soma = 0;
    for i=0;size(matriz)
        if mod(i,matriz(i)) ~= 0
            %impares = [impares matriz(i)];
            soma = soma+ matriz(i);
        end
    end
end