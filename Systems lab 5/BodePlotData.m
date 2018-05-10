% This file should be used to generate the bode plots for the Open Loop 
% Frequency Response Experimental results

clear all;close all;clc;

GpdB = [61.0058 54.9455 40.8525 18.1603 11.64 -1.1386];  % Position vs Input magnitude data in dB  
                                                         % Replace these values with your measured values in dB
                                                         


GvdB = [32.4598 32.3975 31.7514 30.4260 21.3191 16.1355];% Velocity vs Input magnitude data in dB 
                                                         % Replace these values with your measured values in dB
                                                         


f = [0.01, 0.05, 0.1, 0.5, 1, 1.5];                       % Frequency range used in Hz
                                                          % Replace these values with your measured values

w = 2*pi*f;   

figure(1); semilogx(w,GpdB)
xlabel('w (rad/sec)');
ylabel('Mag (dB)');
hold on

figure(2);semilogx(w,GvdB)
xlabel('w (rad/sec)');
ylabel('Mag (dB)');
hold on

f = 0.01:0.01:1;
w = 2*pi*f;  

syms s

Km =115/3;                                             % Supply your value 
tm =1.31;                                              % Supply your value 
Gv = tf([Km],[tm 1])

Gp = tf([Km],[tm 1 0])

figure(1);bodemag(Gp,w,'--r');grid on
legend('Experimental','Simulated')
figure(2);bodemag(Gv,w,'--r');grid on
legend('Experimental','Simulated')
