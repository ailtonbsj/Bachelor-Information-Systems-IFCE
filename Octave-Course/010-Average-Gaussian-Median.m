clc; clear; close all;
pkg load image;

% Ler para níveis de cinza
img0 = imread('pics/lena.jpg');
if length(size(img0)) > 2
  img = rgb2gray(img0);
end

% Adiciona ruido
imgNoise = imnoise(img, 'salt & pepper', 0.05);

%Tamanho da janela
n = 3

% > Filtro passa-baixa linear por convolução <

h = fspecial('average', [n n]);  % kernel media
imgAvg = uint8(conv2(imgNoise, h, 'same'));
% Alternativo
% imgAvg = uint8(filter2(h, imgNoise, 'same'));

h = fspecial('gaussian', [n n], 0.5); % desvio padrao 0.5
imgGau = uint8(conv2(imgNoise, h, 'same'));

% > Filtro não linear (mediana) <
imgMed = medfilt2(imgNoise, [n n]);

figure;
subplot(2,3,1);
imshow(img), title('Original');
subplot(2,3,2);
imshow(imgNoise), title('Ruido Sal e pimenta');
subplot(2,3,3);
imshow(imgAvg), title('Média');
subplot(2,3,4);
imshow(imgGau), title('Gaussiana');
subplot(2,3,5);
imshow(imgMed), title('Mediana');