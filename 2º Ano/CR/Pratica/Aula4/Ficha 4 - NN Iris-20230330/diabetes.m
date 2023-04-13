function diabetes 
    clear all; close all;
    
    % Carrega os dados
    S = readmatrix("diabetes.csv","Delimiter",",","DecimalSeparator",".");

    size(S)

    inputs = S(:, 1:end-1)';    % ir buscar as colunas e aplicar a transposta
    targets = S(:,end)';

    %% Configuração
    % 10 camadas escondidas
    net = feedforwardnet(10);
    %net = feedforwardnet([10 10 10]);
    
    % Função de Ativação
    net.layers{1}.transferFcn = 'tansig';
    net.layers{2}.transferFcn = 'purelin';
    
    %net.layers{1}.transferFcn = 'tansig';
    %net.layers{2}.transferFcn = 'tansig';
    %net.layers{3}.transferFcn = 'purelin';
    
    % OU
    % Da primeira camada até a penultima
    % net.layers{1:end-1}.transferFcn = 'logsig';
    %
    % Ultima camada
    % net.layers{1:end-1}.transferFcn = 'purelin';
    
    % Função de Treino
    net.trainFcn = 'trainlm';
    
    % Divisao de treino
    net.divideFcn = 'dividerand';
    net.divideParam.trainRatio = 0.70;
    net.divideParam.valRatio = 0.15;
    net.divideParam.testRatio = 0.15;
    
    %% Treino
    [net,tr] = train(net, inputs, targets);

    %% Teste
    out = net(inputs);

    % Calcula e mostra a percentagem de classificacoes corretas no conjunto
    TTargets = targets(tr.testInd);
    out_test = (out(tr.testInd) > 0.5);
    accuracy = 100*sum(out_test==TTargets)/length(tr.testInd);
    fprintf('Accuracy test: %f',accuracy);

    %% Desempenho
    disp(tr.performFcn);
    disp(['Train Performance: ' num2str(tr.best_perf)])
    disp(['Validation Performance: ' num2str(tr.best_vperf)]);
    disp(['Test Performance: ' num2str(tr.best_tperf)]);
end