t=0:0.01:3;
f = abs(sin(t)./realpow(2,((t.^t-pi/2)/pi)));
g = abs(cos(t)./realpow(2,((t.^t-pi/2)/pi)));
h = f+g;
figure
plot(t,f, 'LineWidth',1.2)
hold on
plot(t,g, 'LineWidth',1.2)
hold on
plot(t,h, 'LineWidth',1.2)
xlabel('time (s)')
ylabel('function value')
legend('f(t)', 'g(t)', 'h(t)')
set(gca, "linewidth", 1, "fontsize", 18);
grid on


y = (f+g)/2.*(f>=0.2).*(g>=0.2)+g.*(f>=0.2).*(g<0.2)+f.*(f<0.2).*(g>=0.2)+(f+g).*(f<0.2).*(g<0.2);
figure 
plot(t,f, 'LineWidth',1.2)
hold on
plot(t,g, 'LineWidth',1.2)
hold on
plot(t,y, 'LineWidth',1.2)
xlabel('time (s)')
ylabel('function value')
legend('f(t)', 'g(t)', 'y(t)')
set(gca, "linewidth", 1, "fontsize", 18);
grid on