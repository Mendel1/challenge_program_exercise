
t=0:0.1:20;
w=pi/10;
r=1;
sita=pi-w.*t;
figure;
%s-sita
S1=r.*cos(sita)+r;
plot(sita,S1,'r');
xlabel('sita');
ylabel('S')
title('S-sita');
%s-t
figure;
S2=r.*(1-cos(w.*t));
plot(t,S2,'g');
xlabel('t');
ylabel('S');
title('S-t');
%v-sita
figure;
v1=-r.*sin(sita);
plot(sita,v1,'r');
xlabel('sita');
ylabel('v');
title('v-sita');
%v-t
figure;
v2=w*r.*sin(w.*t);
plot(t,v2,'b');
xlabel('t');
ylabel('v');
title('v-t');
%a-sita
figure;
a1=-r.*cos(sita);
plot(sita,a1);
xlabel('sita');
ylabel('a');
title('a-sita');
%a-t
figure;
a2=w^2*r.*cos(w.*t);
plot(t,a2,'r');
xlabel('t');
ylabel('a');
title('a-t');