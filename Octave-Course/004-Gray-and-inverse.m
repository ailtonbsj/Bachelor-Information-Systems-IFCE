% Ler uma imagem qualquer (com imread) e caso a imagem lida seja colorida,
% transformar para níveis de cinza (com rgb2gray). Por fim, obtenha o negativo
% da imagem em nível de cinza.
clc; clear; close all;

img0 = imread('pics/lena.jpg');

% Colorida para níveis de cinza
if length(size(img0)) > 2
  img = rgb2gray(img0);
end

max_value = max(img(:));
neg_img = max_value - img;

figure
subplot(1,3,1), imshow(img0);
subplot(1,3,2), imshow(img);
subplot(1,3,3), imshow(neg_img);
