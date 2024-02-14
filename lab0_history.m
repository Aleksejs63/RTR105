%-- 02/14/2024 04:38:03 PM --%
% mkdir lesson1
% cd lesson1/
A = [1 2 3 4; 5 6 7 8; 9 10 11 12; 13 14 15 16]
%% Task 1
x = -6:1:6
%% Task 2.1
x = -6:1:6;
%% Task 2.2
C = [4 3 2];
C(1)
format compact
C(2)
C(3)

y = C(1)*x.^2 + C(2)*x + C(3)
%% Task 2.3
plot(x,y)
x2 = -6:.01:6;
y2 = C(1)*x2.^2 + C(2)*x2 + C(3);
plot(x2,y2)
%% Task 2.4
plot(x,y,'o')
plot(x,y,'g')
plot(x,y,'--')
plot(x,y,'o--g')
help plot
plot(x,y,'x:b')
plot(x,y,x2,y2)
stairs(x,y)
bar(x,y)
stem(x,y)
t = 0:0.01:1;
y1 = sin(2*pi*t);
y2 = cos(2*pi*t);
stairs(t,y1)
hold on
stairs(t,y2)
hold off
legend('sin function', 'cos function')
xlabel('t,s')
ylabel('signal')
title('my first graph')
gtext('\leftarrow This is sinusoid')
gtext('\leftarrow This is cosinusoid')
grid
%%
grid minor
%%
grid minor
%%
grid
%%
grid on
%%
grid off
% edite
lissajous
lisazu_fun(1,3)
lisazu_fun2(1,3)
lisazu_fun2(2,3)
lisazu_fun2(2,4)