function out = paridade_par(x)
    % Verifica se o numero de entradas é diferente de 4
    %if (length(x) ~= 4)
    %    error("O numero de entradas deve ser 4");
    %end

    % Verifica se o numero de entradas é par
    if (mod(length(x),2) ~= 0)
        error("O numero de entradas de ser par");
    end

    % Calcula a soma do parametro de entrada
    s = sum(x);

    % Verifica se a soma é > 1
    if (s >= 1)
        out = 1;
    else
        out = 0;
    end
end