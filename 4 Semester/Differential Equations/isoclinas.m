% Programa para generar isoclinas de Ecuaciones Diferenciales de primer orden
% @version: 2025.1
% @surso: ISC 4C Ecuaciones Diferenciales

clc; clear; close all;

% Definir la ecuación diferencial dy/dx = f(x, y)
f = @(x, y) x.^2 - y.^2;  % <-- CAMBIAR AQUÍ SI DESEAS MODIFICAR LA ECUACIÓN

% Definir el rango de valores para la malla
[x, y] = meshgrid(-3:0.5:3, -3:0.5:3);  % Rango de x e y

% Calcular el campo de dirección
dy = f(x, y);
dx = ones(size(dy));  % dx es 1 para visualizar la dirección del campo

% Normalizar los vectores
L = sqrt(dx.^2 + dy.^2);
dx = dx ./ L;
dy = dy ./ L;

% Graficar el campo de dirección
quiver(x, y, dx, dy, 0.5, "k");
hold on;

% Definir y resolver las ecuaciones diferenciales para diferentes condiciones iniciales
tspan = [-3 3];  % Intervalo de solución
sol_colors = ['r', 'b', 'g', 'm'];  % Colores para cada solución

% Condiciones iniciales
y0_values = [1, 0, 2, 0];  % <-- CAMBIAR AQUÍ SI QUIERES OTRAS CONDICIONES INICIALES
x0_values = [-2, 3, 0, 0]; % <-- CAMBIAR AQUÍ SI QUIERES OTRAS CONDICIONES INICIALES

for i = 1:length(y0_values)
    x0 = x0_values(i);
    y0 = y0_values(i);

    % Resolver la ecuación diferencial
    [t, y] = ode45(@(t, y) f(t, y), tspan, y0);

    % Graficar la solución
    plot(t, y, sol_colors(i), 'LineWidth', 1.5, 'DisplayName', sprintf('y(%d) = %d', x0, y0));
end

xlabel('x');
ylabel('y');
title('Campo de Dirección y Soluciones');
legend show;
grid on;
hold off;
