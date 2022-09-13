function [new_price] = reuse(retrieved_cases, new_case)

    x1 = retrieved_cases{:,4}; % Number of Persons
    x2 = retrieved_cases{:,7}; % Duration
    y = retrieved_cases{:,3}; % Prices
    
    % TREINO

    % Multiple Regression
    % Adapted from https://www.mathworks.com/examples/matlab/mw/matlab-ex88655142-multiple-regression
    
    % Dados utilizados para treinar
    X = [ones(size(x1)) x1 x2];
    
    b = X\y;
    
    % TESTE: Aplicar o modelo treinado (b) ao novo exemplo (new_case)

    % b) Implementa a formula que permite chegar ao novo valor estimado do
    % preço, sabendo que o modelo matematico se trata de uma regressao
    % linear multipla.
    new_price = b(1) + b(2) * new_case.number_persons + b(3) * new_case.duration;
        
    fprintf(['Based on the attributes Number of Persons and Duration of the retrieved cases,\n', ...
                'the estimated price for the new case is %.2f, instead of %.2f.'], new_price, new_case.price);

end

