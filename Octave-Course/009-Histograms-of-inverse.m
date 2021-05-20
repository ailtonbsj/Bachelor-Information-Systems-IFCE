% Obter o histograma de uma imagem qualquer. Em seguida obter o negativo
% desta imagem e o histograma correspondente. Compare e mostre os
% histogramas obtidos em janelas diferentes.
clc; clear; close all;

pkg load image;

img = rgb2gray(imread('pics/lena.jpg'));
invImg = imcomplement(img);

figure;
subplot(2,2,1), imshow(img);
subplot(2,2,2), imshow(invImg);
subplot(2,2,3), imhist(img);
subplot(2,2,4), imhist(invImg);
