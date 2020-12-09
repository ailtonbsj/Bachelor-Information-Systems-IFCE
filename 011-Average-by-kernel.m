clc; clear; close all;
pkg load image;

function imgAvg = filtroMedia (img, n)
  h = fspecial('average', [n n]);  % kernel media
  imgAvg = uint8(conv2(img, h, 'same'));
endfunction

% Ler para níveis de cinza
img0 = imread('pics/lena.jpg');
if length(size(img0)) > 2
  img = rgb2gray(img0);
end

figure;
subplot(1,3,1);
imshow(filtroMedia(img, 3)), title('Janela 3x3');
subplot(1,3,2);
imshow(filtroMedia(img, 7)), title('Janela 7x7');
subplot(1,3,3);
imshow(filtroMedia(img, 9)), title('Janela 9x9')