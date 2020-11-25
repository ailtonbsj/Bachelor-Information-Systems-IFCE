pkg load image;

bw = zeros(200,200);
bw(100,100) = 1;

D1 = bwdist(bw, 'euclidean');
D2 = bwdist(bw, 'cityblock');
D3 = bwdist(bw, 'chessboard');

figure;

subplot(1,3,1);
subimage(mat2gray(D1)), title('Euclidian');
hold on;
contour(D1);

subplot(1,3,2);
subimage(mat2gray(D2)), title('City Block');
hold on;
contour(D2);

subplot(1,3,3);
subimage(mat2gray(D3)), title('Chessboard');
hold on;
contour(D3);
