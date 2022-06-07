clc; clear; close all;

% Question (a)
u = 10;
v = 20;
w = [30 40 50];
p = 100;

z = p - (w/(u+v)) + (p+(w/(u+v)))./(p+(w/(u-v)))


% Question (b)
u = [10 10 10];
v = 20;
w = 30;
p = 100;

z = p - (w./(u+v)) + (p+(w./(u+v)))./(p+(w./(u-v)))



% Question (c)
u = 10;
v = 20;
w = 30;
p = [100 200 300];

z = p - (w/(u+v)) + (p+(w/(u+v)))./(p+(w/(u-v)))