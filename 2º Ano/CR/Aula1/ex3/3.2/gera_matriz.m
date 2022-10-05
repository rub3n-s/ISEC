function mat = gera_matriz(a,b,x)
% Inputs:
% a - número de linhas da matriz a gerar 
% b - número de colunas da matriz a gerar 
% x - limite maximo dos numeros aleatorios
% Output:
% m - matriz a * b inicializada com numeros inteiros
mat = randi(x,a,b)
end