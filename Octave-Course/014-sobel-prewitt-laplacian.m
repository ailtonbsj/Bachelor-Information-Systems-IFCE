clc; clear; close all;
pkg load image;

% Ler para níveis de cinza
img0 = imread('pics/lena.jpg');
if length(size(img0)) > 2
  img = rgb2gray(img0);
end

hSobel = fspecial('sobel');
hPrewitt = fspecial('prewitt');
hLap = fspecial('laplacian');

imSobelX = imfilter(img, hSobel, 'same');
imSobelY = imfilter(img, hSobel', 'same');
imPrewittX = imfilter(img, hPrewitt, 'same');
imPrewittY = imfilter(img, hPrewitt', 'same');
imLapX = imfilter(img, hLap, 'same');
imLapY = imfilter(img, hLap', 'same');

figure
subplot(2, 3, 1)
imshow(uint8(imSobelX)), title('Sobel Horizontal')
subplot(2, 3, 2)
imshow(uint8(imPrewittX)), title('Prewitt Horizontal')
subplot(2, 3, 3)
imshow(uint8(imLapX)), title('Laplaciano Horizontal')
subplot(2, 3, 4)
imshow(uint8(imSobelY)), title('Sobel Vertical')
subplot(2, 3, 5)
imshow(uint8(imPrewittY)), title('Prewitt Vertical')
subplot(2, 3, 6)
imshow(uint8(imLapY)), title('Laplaciano Vertical')