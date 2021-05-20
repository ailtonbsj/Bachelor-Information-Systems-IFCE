clc; clear; close all;

C = imread('pics/lena.jpg');
G = rgb2gray(C);

E = histeq(G);

figure;
subplot(2,2,1);
imshow(G);
subplot(2,2,2);
imshow(E);
subplot(2,2,3);
imhist(G);
subplot(2,2,4);
imhist(E);