function iris_ex()
%IRIS_DATASET Summary of this function goes here
%   Detailed explanation goes here

clear all;
close all;

% Carrega o dataset
load iris_dataset;

% CRIAR E CONFIGURAR A REDE NEURONAL
% INDICAR: N? camadas escondidas e nos por camada escondida
% INDICAR: Funcao de treino: {'trainlm', 'trainbfg', traingd'}
% INDICAR: Funcoes de ativacao das camadas escondidas e de saida: {'purelin', 'logsig', 'tansig'}
% INDICAR: Divisao dos exemplos pelos conjuntos de treino, validacao e teste

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
net.trainFcn = 'trainoss';

% Divisao de treino
net.divideFcn = 'dividerand';
net.divideParam.trainRatio = 0.70;
net.divideParam.valRatio = 0.15;
net.divideParam.testRatio = 0.15;

somaGlobal = 0;
somaTeste = 0;

% Ciclo para realizar 10 iterações
for i = 1:10
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
    
    somaGlobal = somaGlobal + accuracy;

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

    
    somaTeste= somaTeste + accuracy;
end

% Apresentar as medias
fprintf('Apos 10 Iterações:\n')
fprintf('\tMedia Precisao Total = %f\n', somaGlobal/10);
fprintf('\tMedia Precisao Teste = %f\n', somaTeste/10);
end

