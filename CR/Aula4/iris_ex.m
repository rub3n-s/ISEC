function iris_ex()
%IRIS_DATASET Summary of this function goes here
%   Detailed explanation goes here

clear all;
close all;

% Carrega o dataset
load iris_dataset;

nrEpochs = 10;
accuracy_overall_stack = [];
accuracy_teste_stack = [];

for epoch = 1 : nrEpochs
    % CRIAR E CONFIGURAR A REDE NEURONAL
    % INDICAR: N? camadas escondidas e nos por camada escondida
    % INDICAR: Funcao de treino: {'trainlm', 'trainbfg', traingd'}
    % INDICAR: Funcoes de ativacao das camadas escondidas e de saida: {'purelin', 'logsig', 'tansig'}
    % INDICAR: Divisao dos exemplos pelos conjuntos de treino, validacao e teste
    
    net = feedforwardnet();
    %net = feedforwardnet([5 5]); % 2 camadas de 5 neuronios cada uma
    %net = feedforwardnet([10 10]); % 2 camadas de 10 neuronios cada uma
    
    % exemplo 1 - tansig/purelin
    net.layers{1:end-1}.transferFcn = 'tansig';
    net.layers{end}.transferFcn = 'purelin';
    
    % exemplo 2 - logsig/purelin
    %net.layers{1:end-1}.transferFcn = 'logsig'; 
    %net.layers{end}.transferFcn = 'purelin';
      
    % exemplo 3 - tansig/logsig
    %net.layers{1:end-1}.transferFcn = 'tansig'; 
    %net.layers{end}.transferFcn = 'logsig';

    net.trainFcn = 'trainlm';
    %net.trainFcn = 'traingd';
    %net.trainFcn = 'trainbfg';
    
    net.divideFcn = 'dividerand';
    net.divideParam.trainRatio = 0.9;
    net.divideParam.valRatio = 0.05;
    net.divideParam.testRatio = 0.05;
    
    % TREINAR
    [net,tr] = train(net, irisInputs, irisTargets);
    %view(net);
    %disp(tr);
    
    % SIMULAR
    out = sim(net, irisInputs);
    
    %VISUALIZAR DESEMPENHO
    
    %plotconfusion(irisTargets, out) % Matriz de confusao
    
    %plotperf(tr)         % Grafico com o desempenho da rede nos 3 conjuntos           
    
    %erro = perform(net, out,irisTargets);
    %fprintf('Erro na classificação dos 150 exemplos %f\n', erro)
    %Calcula e mostra a percentagem de classificacoes corretas no total dos exemplos
    r=0;
    for i=1:size(out,2)               % Para cada classificacao  
      [a b] = max(out(:,i));          %b guarda a linha onde encontrou valor mais alto da saida obtida
      [c d] = max(irisTargets(:,i));  %d guarda a linha onde encontrou valor mais alto da saida desejada
      if b == d                       % se estao na mesma linha, a classificacao foi correta (incrementa 1)
          r = r+1;
      end
    end
    
    accuracy = r/size(out,2)*100;
    fprintf('Precisao total (nos 150 exemplos) %f\n', accuracy)
    
    accuracy_overall_stack = [accuracy_overall_stack accuracy];
    
    % SIMULAR A REDE APENAS NO CONJUNTO DE TESTE
    TInput = irisInputs(:, tr.testInd);
    TTargets = irisTargets(:, tr.testInd);
    
    out = sim(net, TInput);
    
    %erro = perform(net, out,TTargets);
    %fprintf('Erro na classificação do conjunto de teste %f\n', erro)
    
    %Calcula e mostra a percentagem de classificacoes corretas no conjunto de teste
    r=0;
    for i=1:size(tr.testInd,2)               % Para cada classificacao  
      [a b] = max(out(:,i));          %b guarda a linha onde encontrou valor mais alto da saida obtida
      [c d] = max(TTargets(:,i));  %d guarda a linha onde encontrou valor mais alto da saida desejada
      if b == d                       % se estao na mesma linha, a classificacao foi correta (incrementa 1)
          r = r+1;
      end
    end
    accuracy = r/size(tr.testInd,2)*100;
    fprintf('Precisao teste %f\n', accuracy)
    
    accuracy_teste_stack = [accuracy_teste_stack accuracy];
end

round(mean(accuracy_overall_stack))
round(mean(accuracy_teste_stack))

end

