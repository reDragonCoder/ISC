% Script en Octave para graficar un campo direccional de y' = f(x,y)

% Definir la función f(x, y) (se puede cambiar según el problema)
f=@(x, y)  x.^2 - y.^2;
;
% Pedir al usuario los valores mínimo y máximo de la malla
x_min = input('Ingrese el valor mínimo de x: ');
x_max = input('Ingrese el valor máximo de x: ');
y_min = input('Ingrese el valor mínimo de y: ');
y_max = input('Ingrese el valor máximo de y: ');

% Definir la malla de puntos
delta = 0.5; % Tamaño de paso entre puntos en la malla
[x, y] = meshgrid(x_min:delta:x_max, y_min:delta:y_max);

% Calcular las direcciones del campo direccional
u = ones(size(x));
v = f(x, y);
norm_factor = sqrt(1 + v.^2);
u = u ./ norm_factor;
v = v ./ norm_factor;

% Graficar el campo direccional
quiver(x, y, u, v, 'b');
xlabel('x'); ylabel('y');
title('Campo Direccional de y'' = f(x,y)');
grid on;
