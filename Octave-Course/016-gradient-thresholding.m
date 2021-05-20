clc; clear; close all;
pkg load image;

% Ler para níveis de cinza
img0 = imread('pics/lena.jpg');
if length(size(img0)) > 2
  img = rgb2gray(img0);
end

hSobel = fspecial('sobel');
hPrewitt = fspecial('prewitt');

delX = imfilter(img, hSobel, 'same');
delY = imfilter(img, hPrewitt', 'same');

M = sqrt(delX.^2 + delY.^2);

figure;
subplot(2,3,1)
imshow(uint8(delX)), title('Delta X')
subplot(2,3,2)
imshow(uint8(delY)), title('Delta Y')
subplot(2,3,3)
imshow(mat2gray(M)), title('Magnitude')
subplot(2,3,4)
imshow(mat2gray(M) > 0.1), title('Limiar 0.1')
subplot(2,3,5)
imshow(mat2gray(M) > 0.2), title('Limiar 0.5')
subplot(2,3,6)
imshow(mat2gray(M) > 0.5), title('Limiar 0.7')