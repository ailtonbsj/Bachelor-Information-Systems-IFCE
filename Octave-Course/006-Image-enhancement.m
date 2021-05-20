clc; clear; close all;

img = rgb2gray(imread('pics/lena.jpg'));

figure;
subplot(1,3,1);
imshow(uint8(img-80));
subplot(1,3,2);
imshow(uint8(img));
subplot(1,3,3);
imshow(uint8(img+80));