function maior = maior_num()
    op = 1;
    maior=-inf;
    arr = []
    while op ~= 0
        op = input('Introduza um numero: ');
        %if op > maior
        %    maior = op;            
        %end
        arr = [arr op];
    end
    maior = max(arr);
end