%% Load surfaces
L0=1;
Xcg=[0; 0; 0;];

L0=70.2;
Xcg=[32.3114*1.0005364451; 0; 0;];

[nt_Hull,vt1_Hull,vt2_Hull,vt3_Hull,dA_Hull,n_Hull] = import_stl('surface/Hull.stl',L0,Xcg);
[nt_Sail,vt1_Sail,vt2_Sail,vt3_Sail,dA_Sail,n_Sail] = import_stl('./surface/Sail.stl',L0,Xcg);
[nt_PH,vt1_PH,vt2_PH,vt3_PH,dA_PH,n_PH] = import_stl('./surface/PropHub.stl',L0,Xcg);

[nt_SProot,vt1_SProot,vt2_SProot,vt3_SProot,dA_SProot,n_SProot] = import_stl('./surface/TailPlaneRoots.stl',L0,Xcg);
[nt_BP1,vt1_BP1,vt2_BP1,vt3_BP1,dA_BP1,n_BP1] = import_stl('./surface/SailPlanes1.stl',L0,Xcg);
[nt_BP2,vt1_BP2,vt2_BP2,vt3_BP2,dA_BP2,n_BP2] = import_stl('./surface/SailPlanes1-mirrored.stl',L0,Xcg);
[nt_X1a,vt1_X1a,vt2_X1a,vt3_X1a,dA_X1a,n_X1a] = import_stl('./surface/TailPlaneLowerSt1.stl',L0,Xcg);
[nt_X1b,vt1_X1b,vt2_X1b,vt3_X1b,dA_X1b,n_X1b] = import_stl('./surface/TailPlaneLowerSt2.stl',L0,Xcg);
[nt_X2a,vt1_X2a,vt2_X2a,vt3_X2a,dA_X2a,n_X2a] = import_stl('./surface/TailPlaneUpperSt1-mirrored.stl',L0,Xcg);
[nt_X2b,vt1_X2b,vt2_X2b,vt3_X2b,dA_X2b,n_X2b] = import_stl('./surface/TailPlaneUpperSt2-mirrored.stl',L0,Xcg);
[nt_X3a,vt1_X3a,vt2_X3a,vt3_X3a,dA_X3a,n_X3a] = import_stl('./surface/TailPlaneUpperPt1.stl',L0,Xcg);
[nt_X3b,vt1_X3b,vt2_X3b,vt3_X3b,dA_X3b,n_X3b] = import_stl('./surface/TailPlaneUpperPt2.stl',L0,Xcg);
[nt_X4a,vt1_X4a,vt2_X4a,vt3_X4a,dA_X4a,n_X4a] = import_stl('./surface/TailPlaneLowerPt1.stl',L0,Xcg);
[nt_X4b,vt1_X4b,vt2_X4b,vt3_X4b,dA_X4b,n_X4b] = import_stl('./surface/TailPlaneLowerPt2.stl',L0,Xcg);


%% Kinematic Properties
Bb   = 4418825.3321; %mass of submarine in kg
Mb   = 4418825.3321; %buoyancy of submarine. usually identical to Mb

Ixx  = 5.23e7;       %mass moment of inertia about x-axis. in kg*m^2
Iyy  = 1.375e9;      %mass moment of inertia about y-axis. in kg*m^2
Izz  = 1.367e9;      %mass moment of inertia about z-axis. in kg*m^2
Ixy  = 0;            %cross terms of inertia tensor
Ixz  = 0;
Iyz  = 0;

Xb   = 0;            %CB coordinates in m in ship system
Yb   = 0;
Zb   = 0.4406;       
Xg   = 0;            %Pivot point for imposed/captive calculations
Yg   = 0;            %Set to zero for free runs.
Zg   = 0;   




















function [ntri,vert1,vert2,vert3,dA,normal] = import_stl(filename,L0,Xcg)

%Reading STL information
f = fopen(filename,'r');
c = textscan(f,'%s','delimiter','\n');
fclose(f);
c = c{:};
[~,~,~,z] = regexp(c,'-*\d+\.\d+(E-*\d+)*\d+(e-*\d+)*');
z1 = z(~cellfun(@isempty,z));
raw = str2double(reshape([z1{:}],3,[])');

%Assigning variable Space.
ndat=length(raw);         %3 Vertices + 1 Normal
ntri=round(ndat/4);       % Number of Triangles

normal=zeros(ntri,3);
vert1=zeros(ntri,3);
vert2=zeros(ntri,3);
vert3=zeros(ntri,3);
dA=zeros(ntri,1);

%Loading vertices and normal vectors
%Compute position vectors of triangles with respect to CG
for i=1:ndat
    arg1=i-1; int1=round(arg1/4)+1;
    arg2=i-2; int2=round(arg2/4)+1;
    arg3=i-3; int3=round(arg3/4)+1;
    int4=round(i/4);
    
    if rem(arg1,4)==0
        normal(int1,1)=raw(i,1);
        normal(int1,2)=raw(i,2);
        normal(int1,3)=raw(i,3);
    elseif rem(arg2,4)==0
        vert1(int2,1)=raw(i,1).*L0-Xcg(1);
        vert1(int2,2)=raw(i,2).*L0-Xcg(2);
        vert1(int2,3)=raw(i,3).*L0-Xcg(3);
    elseif rem(arg3,4)==0
        vert2(int3,1)=raw(i,1).*L0-Xcg(1);
        vert2(int3,2)=raw(i,2).*L0-Xcg(2);
        vert2(int3,3)=raw(i,3).*L0-Xcg(3);
    else
        vert3(int4,1)=raw(i,1)*L0-Xcg(1);
        vert3(int4,2)=raw(i,2)*L0-Xcg(2);
        vert3(int4,3)=raw(i,3)*L0-Xcg(3);
    end
end
for i=1:ntri
    A=[vert2(i,1)-vert1(i,1); vert2(i,2)-vert1(i,2); vert2(i,3)-vert1(i,3);];
    B=[vert3(i,1)-vert1(i,1); vert3(i,2)-vert1(i,2); vert3(i,3)-vert1(i,3);];
    dA(i,1)=0.5*norm(cross(A,B));
end
end
