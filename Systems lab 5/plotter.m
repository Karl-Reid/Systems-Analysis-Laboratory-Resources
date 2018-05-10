a = find(FullDat<10e-3);
Ts = 0.010;
L = length(FullDat((a(end)+1):end));
T = Ts*(0:(L-1));

data = FullDat(a(end)+1:end);

figure;
plot(T(1:600),data(1:600),'b','Linewidth',1,'MarkerSize',5,'Marker','.')
grid
title('Experimental Open Loop Step Response');
legend('Experimental', 'Location', 'Best');     %Legend
xlabel('Time (seconds)')                             % x-axis label
ylabel('w (radians/second)')                         % y-axis label

Omega = data(1:600);
Time = T(1:600)';

A=ones(601,2);      %Sample 2-dimensional data
filename = 'excel_data.xlsx';

sheet = 1;
xlRange = 'A1';
xlswrite(filename,Time,sheet,xlRange)
xlRange = 'B1';
xlswrite(filename,Omega,sheet,xlRange)

