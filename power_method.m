% define matrix A and initial guess vector x
A = [3 0 0;
    -4 6 2;
     16 -15 -5];

x = [1; 0.5; 0.25];  % initial guess


epsilon = 1e-3;      % convergence tolerance
max_iter = 100;      % maximum number of iterations

% Initialize
lambda = -1;
v = x;

for i = 1:max_iter
    v = A * x;                      % multiply matrix by vector
    lambda = max(abs(v));           % approximate dominant eigenvalue
    v = v / lambda;                 % normalize vector

    if norm(x - v) < epsilon        % check for convergence
        break;
    end
    
    x = v;                          % update x for next iteration
end

% normalize eigenvector
x = x / norm(x);


fprintf('Dominant Eigenvalue ≈ %.4f\n', lambda);
fprintf('Corresponding Eigenvector (normalized):\n');
disp(x);
