% EXERCICIO: Criar uma função que receba duas imagens binárias e
% o tipo de operação ('AND', 'OR', XOR, div, prod, soma, dif)
% a ser executada entre essas duas imagens.
% Retornar o resultado e mostrar utilizando a função imshow.
clear;
pkg load image;

function ret = imageOperating (im1, im2, operating)
  if ( strcmp(operating,'AND') ) ret = and(im1,im2);
  elseif ( strcmp(operating,'OR') ) ret = or(im1,im2);
  elseif ( strcmp(operating,'XOR') ) ret = xor(im1,im2);
  elseif ( strcmp(operating,'DIV') )
    ret = im1 ./ ( ((im2 == 0) .* 0.1) + im2 ) > 0;
  elseif ( strcmp(operating,'PROD') ) ret = im1 .* im2;
  elseif ( strcmp(operating,'SOMA') ) ret = (im1 + im2) > 0;
  elseif ( strcmp(operating,'DIF') ) ret = (im1 - im2) > 0;
  endif
endfunction

ball = im2bw(imread('pics/ball.png'));
triangle = im2bw(imread('pics/triangle.png'));

figure;

subplot(2,5,1);
subimage(ball);
title('ball'); hold on;
subplot(2,5,2);
subimage(triangle);
title('triangle'); hold on;
subplot(2,5,3);
subimage( imageOperating(ball, triangle, "AND") ); 
title('AND'); hold on;
subplot(2,5,4);
subimage( imageOperating(ball, triangle, "OR") ); 
title('OR'); hold on;
subplot(2,5,5);
subimage( imageOperating(ball, triangle, "XOR") ); 
title('XOR'); hold on;
subplot(2,5,6);
subimage( imageOperating(ball, triangle, 'DIV') ); 
title('DIV'); hold on;
subplot(2,5,7);
subimage( imageOperating(ball, triangle, "PROD") ); 
title('PROD'); hold on;
subplot(2,5,8);
subimage( imageOperating(ball, triangle, "SOMA") ); 
title('SOMA'); hold on;
subplot(2,5,9);
subimage( imageOperating(ball, triangle, "DIF") ); 
title('DIF'); hold on;