% Ler uma imagem e obter outra imagem com a metade do número de linhas
% e colunas da imagem original (utilize imresize). Obter os histogramas
% normalizados dessas duas imagens e mostrar em janelas diferentes.
clc; clear; close all;
pkg load image;

img = rgb2gray(imread('pics/lena.jpg'));
[m, n] = size(img);

img_2 = imresize(img, [m/2, n/2]);
[m_2, n_2] = size(img_2);

% Histogramas
hist_1 = imhist(img);
hist_2 = imhist(img_2);

% Histogramas normalizados
hist_1_norm = hist_1 / (m*n);
hist_2_norm = hist_2 / (m_2*n_2);

figure;
subplot(2,3,1);
imshow(img), title('Original');
subplot(2,3,2);
bar(hist_1), title('Histograma (original)');
subplot(2,3,3);
bar(hist_1_norm), title('Original (normalizada)');

subplot(2,3,4);
imshow(img_2), title('Redimensionada');
subplot(2,3,5);
bar(hist_2), title('Histograma (redimensionada)');
subplot(2,3,6);
bar(hist_2_norm), title('Redimensionada (normalizada)');

% Somas iguais a 1 pois equivale a uma estimativa de probabilidade
sum(hist_1_norm)
sum(hist_2_norm)
