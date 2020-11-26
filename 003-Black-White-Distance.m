% Criar uma imagem de tamanho M x N (pode ser uma matriz de zeros com apenas
% um pixel com valor igual a 1 e calcular a distância (Euclidiana, city block
% ou chessboard) do pixel de valor 1 em relação a todos os pixels da imagem.
% Mostrar a matriz de distância obtida com imshow e surf.

pkg load image;
clear;

bw = zeros(200,200);
bw(100,100) = 1;

D1 = bwdist(bw, 'euclidean');
D2 = bwdist(bw, 'cityblock');
D3 = bwdist(bw, 'chessboard');

figure;

subplot(2,4,1);
subimage(bw), title('Original');
hold on;

subplot(2,4,2);
subimage(mat2gray(D1)), title('Euclidian');
hold on; contour(D1);

subplot(2,4,3);
subimage(mat2gray(D2)), title('City Block');
hold on; contour(D2);

subplot(2,4,4);
subimage(mat2gray(D3)), title('Chessboard');
hold on; contour(D3);

subplot(2,4,5);
surf(bw);
colormap summer;
shading interp;

subplot(2,4,6);
surf(D1);
colormap summer;
shading interp;

subplot(2,4,7);
surf(D2);
colormap summer;
shading interp;

subplot(2,4,8);
surf(D3);
colormap summer;
shading interp;
