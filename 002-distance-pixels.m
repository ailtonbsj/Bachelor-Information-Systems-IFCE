% Criar uma função que receba as coordenadas (x,y) e (s,t) de dois pixels
% de uma imagem e que calcule a distância entre eles. A função também deve
% receber o nome da distância (euclidiana, city block ou chessboard) e
% retornar o valor calculado.
clear;

function ret = dist (xy, st, name)
  if (strcmp(name,'euclidiana'))
    ret = ( (xy(1) - st(1))^2 + (xy(2) - st(2))^2 )^(1/2)
  elseif (strcmp(name,'cityblock'))
    ret = abs(xy(1) - st(1)) + abs(xy(2) - st(2))
  elseif (strcmp(name,'chessboard'))
    ret = max(abs(xy(1)-st(1)),abs(xy(2)-st(2)))
  endif
endfunction

euclidiana = dist([3 3],[4 4],'euclidiana')
cityblock = dist([3 3],[4 4],'cityblock')
chessboard = dist([3 3],[4 4],'chessboard')