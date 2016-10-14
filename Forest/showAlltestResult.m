%showAlltestResult
for i = 1:601
   im = imread(['./result/',int2str(i),'.png']);
   imagesc(im)
   pause(1);
end