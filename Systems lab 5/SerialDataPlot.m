veldat = zeros(length(WindowDat)-1,1);

for i = 1:length(WindowDat)-1
    veldat(i) = (WindowDat(i+1)-WindowDat(i))/Ts;
end

t = 0:Ts:Ts*(length(WindowDat)-1);

figure;plot(t,WindowDat,'-o')
title('Motor Position vs Input Voltage')
xlabel('time (secs)')
ylabel('Amplitude')
grid on

figure;plot(t(1:length(t)-1),veldat,'-o');
title('Motor Velocity vs Input Voltage')
xlabel('time (secs)')
ylabel('Amplitude')
grid on



