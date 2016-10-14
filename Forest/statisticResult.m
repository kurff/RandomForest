% statisticResult
path = './result';
labelpath = 'E:\data\MNIST\testlabel';
n = 0;
a = 0;
c = 0;
for i = 1:10000
    if mod(i,100) ==0
        disp(i)
    end
   label = imread([path,'\',int2str(i),'.png']);
   im = imread([labelpath,'\',int2str(i),'.png']);
   im = double(im);
   label = label(:,1:28);
   n = n + length(find(label~=0));
   index = find(label~=0);
   a = a + length(find(label(index)== im(index)));
   val = hist(label(:),0:11);
   valim = hist(im(:),0:11);
   [~, lval] = max(val(2:end-1));
   [~, lvalim] = max(valim(2:end-1));
   if  lval == lvalim
       c = c+ 1;
   else
       imagesc(label);
   end
end
a/n
c/10000