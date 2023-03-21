function out = calcFunction(w2,w1,w0,b,in,j)
	S = w2 * in(2,j) + w1 * in(1,j) + w0 * b;   % in(1,j) = x1; in(2,j) = x2;
    if S >= 0
        out = 1;
    else 
	    out = 0;
    end
end