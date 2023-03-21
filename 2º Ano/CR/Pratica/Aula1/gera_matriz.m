function matriz = gera_matriz(a,b,x)
    % Inputs
    %   a - número de linhas da matriz a gerar
    %   b - número de linhas da matriz a gerar
    %   x - limite máximo dos números aleatórios a colocar na matriz a
    %   gerar
    % Output
    %   matriz - matriz a*b inicializada com números aleatórios entre 0 e x
    % Função para gerar uma matriz a*b
    %a = input('Insert lines:')
    %b = input('Insert columns: ')
    %x = input('Insert interval: ')
    matriz = randi(x,a,b);
end