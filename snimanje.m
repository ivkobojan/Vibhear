clear all
close all
clc

% ucitavanje
[signal,frek] = wavread('zvukAlarma.wav');

dt = 1/frek;
t = 0:dt:(length(signal)*dt)-dt;

% reprezentacija signala u vremenskom domenu
figure
subplot(2,2,1)
plot(t,signal(:,1))
xlabel('t[s]')
title('Time representation of sonud from chanel 1')

subplot(2,2,2)
plot(t,signal(:,2))
xlabel('t[s]')
title('Time representation of sonud from chanel 2')



N = length(signal);

amplitude = abs(fftshift(fft(signal(:,1))));
binVrednosti = [0 : N-1];
N2 = ceil(N/2);
ucestanost = (binVrednosti-N2)*frek/N;

% reprezentacija u frekvencijskom domenu
subplot(2,2,[3 4])
plot(ucestanost, amplitude)
xlabel('f[Hz]')
ylabel('Magnitude');
title('Double-sided Magnitude spectrum of smoke alarm sound');
axis tight