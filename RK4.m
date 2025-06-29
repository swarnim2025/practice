
clc, clearvars;
function [t, y] = runge_kutta4(f, t0, y0, h, tf)
    % f  - function handle: f(t, y)
    % t0 - initial time
    % y0 - initial value (scalar or vector)
    % h  - step size
    % tf - final time

    t = t0:h:tf;
    n = length(t);
    y = zeros(length(y0), n);  % supports vector y0
    y(:,1) = y0(:);  % ensure column vector

    for i = 1:n-1
        k1 = f(t(i), y(:,i));
        k2 = f(t(i) + h/2, y(:,i) + h/2 * k1);
        k3 = f(t(i) + h/2, y(:,i) + h/2 * k2);
        k4 = f(t(i) + h,   y(:,i) + h * k3);

        y(:,i+1) = y(:,i) + (h/6)*(k1 + 2*k2 + 2*k3 + k4);
    end

    y = y.'; %  transpose to match row-wise output
    t = t.';
end






f = @(t, y) y^2 *t+2*y;
t0 = 0;
y0 = -5;
h = 0.1;
tf = 5;

[t, y] = runge_kutta4(f, t0, y0, h, tf);

plot(t, y, '-o');
xlabel('t'); ylabel('y');
title('RK4 Approximation');
grid on;
shg;
