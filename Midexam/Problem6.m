clc
clear all

city=input("Enter the name of city:",'s')

switch (city)
case 'Yuma'
T_mean=23.1;
T_peak=33.6;
omega=2*pi/365;
t_start=input("Enter the start time:");
t_end=input("Enter the end time:");
t=t_start:1:t_end;
t_peak=205;
T=0;
for i=1:length(t)
T=T+T_mean+(T_peak-T_mean)*cos(omega*(t(i)-t_peak));
end
T_avg=T/(t_end-t_start)
  
case 'Seattle'
T_mean=10.6;
T_peak=17.6;
omega=2*pi/365;
t_start=input("Enter the start time:");
t_end=input("Enter the end time:");
t=t_start:1:t_end;
t_peak=205;
T=0;
for i=1:length(t)
T=T+T_mean+(T_peak-T_mean)*cos(omega*(t(i)-t_peak));
end
T_avg=T/(t_end-t_start)
end