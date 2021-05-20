clc; clear; close all;
pkg load image;

% Ler para níveis de cinza
img0 = imread('pics/ball.png');
if length(size(img0)) > 2
  img = rgb2gray(img0);
end

hSobel = fspecial('sobel');
delX = imfilter(img, hSobel, 'same');
delY = imfilter(img, hSobel', 'same');
M = sqrt(delX.^2 + delY.^2);
bw = mat2gray(M) > 0.5;

SE = strel('disk', 1, 0);
imgEroded = imerode(bw, SE);
imgDil = imdilate(bw, SE);

figure;
subplot(1,3,1);
imshow(bw), title('Original')
subplot(1,3,2);
imshow(imgEroded), title('Erodido')
subplot(1,3,3);
imshow(imgDil), title('Dilatado')