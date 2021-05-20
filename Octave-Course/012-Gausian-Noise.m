clc; clear; close all;
pkg load image;

% Ler para níveis de cinza
img0 = imread('pics/lena.jpg');
if length(size(img0)) > 2
  img = rgb2gray(img0);
end

% Adiciona ruido
imgNoise = imnoise(img, 'gaussian', 0.05);

function [imgAvg, imgGau, imgMed] = filtros(imgNoise, n)
  h = fspecial('average', [n n]);  % kernel media
  imgAvg = uint8(conv2(imgNoise, h, 'same'));
  h = fspecial('gaussian', [n n], 0.05); % desvio padrao 0.06
  imgGau = uint8(conv2(imgNoise, h, 'same'));
  imgMed = medfilt2(imgNoise, [n n]);
endfunction

[imgAvg, imgGau, imgMed] = filtros(imgNoise, 3);

figure;
subplot(2, 4, 1);
imshow(img), title('Original');
subplot(2, 4, 2);
imshow(imgAvg), title('Filtro Media 3x3');
subplot(2, 4, 3);
imshow(imgGau), title('Filtro Gaussiano 3x3');
subplot(2, 4, 4);
imshow(imgMed), title('Filtro mediana 3x3');
subplot(2, 4, 5);
imshow(imgNoise), title('Ruido gausiano');

[imgAvg, imgGau, imgMed] = filtros(imgNoise, 5);

subplot(2, 4, 6);
imshow(imgAvg), title('Filtro Media 5x5');
subplot(2, 4, 7);
imshow(imgGau), title('Filtro Gaussiano 5x5');
subplot(2, 4, 8);
imshow(imgMed), title('Filtro mediana 5x5');