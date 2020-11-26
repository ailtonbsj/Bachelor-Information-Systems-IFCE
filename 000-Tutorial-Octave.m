% Tutorial de Octave
% As linhas começadas por porcentagem é um comentário 

% Remove as variaveis do escopo atual
clear;

% Cria Matriz 2x2 nomeada como A e NÃO exibe no terminal
A = [ 1 2; 3 4 ];

% Cria Matriz 2x2 nomeada como B e exibe no terminal
B = [ 5 6; 7 8 ]

% Produto termo a termo
C = A .* B

% Divisão termo a termo
D = A ./ B

% Produto Matricial
E = A * B

% Divisão Matricial. Equivalente => A * inv(B)
F = A / B

% Matriz inversa. Equivalente => A * G = I, onde I = [1 0; 0 1]
G = inv(A)

% Cria Matriz 3x2 nomeada como H
H = [1 2 3; 4 5 6];

% Tamanho da Matriz, Linhas e Colunas
size(H)
size(H,1)
size(H,2)

% Cria vetor de range com intervalo [5,10]
V = 5:10

% Comprimento do vetor V
length(V)