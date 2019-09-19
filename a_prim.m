function t = a_prim (w)
mr = zeros (1,length(w));
[~,i] = min (w(1,:));
mr(i) = 1;
t{1} = i;
while length(find(mr)) ~= length(w)
    [t,mr] = add_min_edge (t, w, mr);
end
end

function [t,mr] = add_min_edge (t, w, mr)
m = inf;
for i = 1:length(t)
    for j = 1:length(mr)
        if mr(j) == 1
            continue
        end
        if m > w(i,j)
            m = w(i,j);
            im = i;
            jm = j;
        end
    end
end
mr(jm) = 1;
disp(t);
t{im}(end+1) = jm;
end
