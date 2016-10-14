%showLabel
path = 'E:\data\MNIST\trainlabel';
imgPath = 'E:\data\MNIST\train';
labelPath = '.\result';
imgName = '1.png';
im = imread([path,'\',imgName]);
figure(1)
imagesc(im);
[xx,yy,zz] = fileparts(imgName);
label = textread([labelPath,'\',yy,'.txt']);
figure(2)
imagesc(label)
img = imread([imgPath,'\',imgName]);
figure(3);
imagesc(img)