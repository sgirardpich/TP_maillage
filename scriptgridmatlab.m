clear all;
close all;

grid;

for i=1:length(treegrid)
    n = length(treegrid{i});
    lengthbox = 1./2^n;
    originbox = [0 0];
    for j=1:n
        if ((treegrid{i}(j) == 1) || (treegrid{i}(j) == 2))
            originbox(1) = originbox(1) + 1./(2^j);
        end
        if ((treegrid{i}(j) == 2) || (treegrid{i}(j) == 3))
            originbox(2) = originbox(2) + 1./(2^j);
        end
    end
    rectangle('Position',[originbox lengthbox lengthbox]);
    text(originbox(1)+lengthbox/4.,originbox(2)+lengthbox/4.,int2str(i))
    hold on;
end

hold on; 
plot(points(:,1),points(:,2),'-o');