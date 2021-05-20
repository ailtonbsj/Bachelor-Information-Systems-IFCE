% Ler uma imagem e obter os histogramas de duas regiões (R1 e R2) dessa
% imagem, em que a união (R1 ∪ R2) das duas regiões consiste na imagem
% inteira. Em seguida, obter um histograma resultante somando os histogramas
% de R1 e R2 e compará-lo com o histograma obtido a partir da imagem completa.
clc; clear; close all;

pkg load image;

img = rgb2gray(imread('pics/lena.jpg'));
[m, n] = size(img);

R1 = img(1:m/2,:);
R2 = img(m/2+1:m,:);
histR1 = imhist(R1);
histR2 = imhist(R2);

figure;
subplot(3,2,1);
imshow(R1), title('R1');
subplot(3,2,2);
imshow(R2), title('R2');
subplot(3,2,3);
plot(histR1), xlim([0 255]), title('Histograma R1');
subplot(3,2,4);
plot(histR2), xlim([0 255]), title('Histograma R2');
subplot(3,2,5:6);
plot(histR1+histR2), xlim([0 255]), title('Hist. R1 + R2 | Hist. da Imagem original (offset de 20)');
hold on;
histIm = imhist(img);
plot(histIm+20);