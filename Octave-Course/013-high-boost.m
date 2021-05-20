clc; clear; close all;
pkg load image;

% Ler para níveis de cinza
img0 = imread('pics/lena.jpg');
if length(size(img0)) > 2
  img = rgb2gray(img0);
end

% Filtro da média
h = fspecial('average', 3);
imgFilt = conv2(img, h, 'same');

% Máscara de nitidez e filtragem high-boost
mask = img - uint8(imgFilt);

k = 2;
imgNew = img + k * (mask);

figure
subplot(2, 2, 1)
imshow(img), title('Original')
subplot(2, 2, 2)
imshow(uint8(imgFilt)), title('Suavizada')
subplot(2, 2, 3)
imshow(mask), title('Mask')
subplot(2, 2, 4)
imshow(imgNew), title('Nova Imagem')