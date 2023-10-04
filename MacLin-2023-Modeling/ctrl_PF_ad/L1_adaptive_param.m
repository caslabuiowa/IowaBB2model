s = tf('s');

%% Depth
% Desired System
%Msz.tf = .1/(s+.1);%1/(s+1);
wn = 0.08; zeta = 1;
Msz.tf = wn^2/(s^2+2*zeta*wn*s+wn^2);%1/(s+1);
Msz.ss=ss(Msz.tf);
Amz = Msz.ss.a;
Bmz = Msz.ss.b;
Cmz = Msz.ss.c;
Dmz = Msz.ss.d;


% Filter
s=tf('s');
Csz.tf= 0.1^1*0.01/((s+0.1)^1*(s+0.01));%1^2*.3/((s+1)^2*(s+.3));
Cszb = Csz.tf.Numerator{1}; Csza = Csz.tf.Denominator{1};

Osz.tf=minreal(Csz.tf*(Msz.tf)^-1*Cmz*(s*eye(size(Amz,1))-Amz)^-1);
Osz.ss   =   ss(Osz.tf,'min');
Aoz      =   Osz.ss.a;
Boz      =   Osz.ss.b;
Coz      =   Osz.ss.c;
Doz      =   Osz.ss.d;


% Compute Lambda, Phi
% Calculating of \Lambda
Qz       =   eye(size(Amz,1));
Pz       =   lyap(Amz',Qz);
sqrtPz   =   sqrtm(Pz);
Dz       =   null(Cmz*inv(sqrtPz));
Dz       =   Dz';
Lambdaz  =   [Cmz ; Dz*sqrtPz];
% Calculating of \Phi matrics
Phiz     =   -inv(Lambdaz*Amz/Lambdaz)*(eye(size(Amz,1))-expm(Lambdaz*(Amz/Lambdaz)*Ts))*Lambdaz;
Phiinvz  =   inv(Phiz);

L1.Amz = Amz; L1.Bmz = Bmz; L1.Cmz = Cmz; L1.Dmz = Dmz;
L1.Aoz = Aoz; L1.Boz = Boz; L1.Coz = Coz; L1.Doz = Doz;
L1.Lambdaz = Lambdaz;
L1.Phiinvz = Phiinvz;




%% Yaw
%Msz.tf = .1/(s+.1);%1/(s+1);
wn = 0.08; zeta = 1;
Mspsi.tf = wn^2/(s^2+2*zeta*wn*s+wn^2);%1/(s+1);
Mspsi.ss=ss(Msz.tf);
Ampsi = Mspsi.ss.a;
Bmpsi = Mspsi.ss.b;
Cmpsi = Mspsi.ss.c;
Dmpsi = Mspsi.ss.d;


% Filter
s=tf('s');
Cspsi.tf= 0.01^1*0.01/((s+0.01)^1*(s+0.01));%1^2*.3/((s+1)^2*(s+.3));
Cspsib = Cspsi.tf.Numerator{1}; Cspsia = Cspsi.tf.Denominator{1};

Ospsi.tf=minreal(Cspsi.tf*(Mspsi.tf)^-1*Cmpsi*(s*eye(size(Ampsi,1))-Ampsi)^-1);
Ospsi.ss   =   ss(Ospsi.tf,'min');
Aopsi      =   Ospsi.ss.a;
Bopsi      =   Ospsi.ss.b;
Copsi      =   Ospsi.ss.c;
Dopsi      =   Ospsi.ss.d;


% Compute Lambda, Phi
% Calculating of \Lambda
Qpsi       =   eye(size(Ampsi,1));
Ppsi       =   lyap(Ampsi',Qpsi);
sqrtPpsi   =   sqrtm(Ppsi);
Dpsi       =   null(Cmpsi*inv(sqrtPpsi));
Dpsi       =   Dpsi';
Lambdapsi  =   [Cmpsi ; Dpsi*sqrtPpsi];
% Calculating of \Phi matrics
Phipsi     =   -inv(Lambdapsi*Ampsi/Lambdapsi)*(eye(size(Ampsi,1))-expm(Lambdapsi*(Ampsi/Lambdapsi)*Ts))*Lambdapsi;
Phiinvpsi  =   inv(Phipsi);

L1.Ampsi = Ampsi; L1.Bmpsi = Bmpsi; L1.Cmpsi = Cmpsi; L1.Dmpsi = Dmpsi;
L1.Aopsi = Aopsi; L1.Bopsi = Bopsi; L1.Copsi = Copsi; L1.Dopsi = Dopsi;
L1.Lambdapsi = Lambdapsi;
L1.Phiinvpsi = Phiinvpsi;