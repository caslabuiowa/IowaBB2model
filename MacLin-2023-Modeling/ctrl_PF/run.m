clear all; close all;
%addpath('./surface');
%addpath('./BeBOT');
    
%% Set model parameters
load_data;    % importing *.igs surface geometries for hydrostat. computation and kinematic properties
Ts = 0.05; % Step size

d = 50; % Characteristic distance
Ky = 1;  % Path-following gain
Kp = .1; % Trajectory tracking gain

%% Set simulation parameters
% Simulation Time (seconds)
Tf = 500;
Seastate = 0;        %Sea state value between 0 and 6

%% Saved variables table
Desired_Variable = ["Position: x";"Position: y";"Position: z";"Position: phi";"Position: theta";"Position: psi";"Velocity: u";"Velocity: v";"Velocity: w";"Velocity: p";"Velocity: q";"Velocity: r";"Stern plane angle: d1";"Stern plane angle: d2";"Stern plane angle: d3";"Stern plane angle: d4";"Sail plane angle: d5";"Propeller speed: n";"Path position: x";"Path position: y";"Path position: z";"Path velocity: u";"Path velocity: v";"Path velocity: z";"Virtual time: gamma";"Virtual time rate: gamma_dot";"Yaw reference: psi_d";"Depth reference: z_d";"Normalized position error: pos_err";"X position error: x_err";"Y position error: y_err";"Z position error: z_err"];
Data_Title = ["Bx1";"Bx2";"Bx3";"Bx4";"Bx5";"Bx6";"Bv1";"Bv2";"Bv3";"Bv4";"Bv5";"Bv6";"d1";"d2";"d3";"d4";"d5";"n";"pdx";"pdy";"pdz";"pdpx";"pdpy";"pdpz";"gamma";"gamma_dot";"psi_d";"z_d";"pos_err";"x_err";"y_err";"z_err"];
Data_Units = ["m";"m";"m";"rad";"rad";"rad";"m/s";"m/s";"m/s";"rad/s";"rad/s";"rad/s";"deg";"deg";"deg";"deg";"deg";"RPS";"m";"m";"m";"m/s";"m/s";"m/s";"sec";"sec/sec";"rad";"m";"m";"m";"m";"m"];
vars = table(Desired_Variable,Data_Title,Data_Units);

%% Bernstein polynomial generation
%Cpx = flip(xlsread('canyon_gm_scripps.xlsx','A2:A62')); 
%Cpy = flip(xlsread('canyon_gm_scripps.xlsx','B2:B62'));
%Cpz = flip(xlsread('canyon_gm_scripps.xlsx','C2:C62'));
% %Cpx = flip(xlsread('canyon_v2_gm.xlsx','A2:A62')); 
% %Cpy = flip(xlsread('canyon_v2_gm.xlsx','B2:B62'));
% %Cpz = flip(xlsread('canyon_v2_gm.xlsx','C2:C62'));
%Cpx = -Cpx;
%Cpy = -Cpy;

%Cpx = [0; 100;200;300;400;500;600;700;800;900;1000;1100;1200;1300;1400;1500;1600;1700;1800;1900;2000;2100;2200;2300;2400;2500;2600;2700;2800;2900;3000;3100;3200;3300;3400;3500;3600;3700;3800;3900;4000];
%Cpy = [0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0];
%Cpz = [-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15;-15];

%Cpv = -1*[-2*5.14444;-2*5.14444;-5.14444;-5.14444;-5.14444;-5.14444;-5.14444;-2*5.14444;-2*5.14444];

%Cp = [Cpx'; Cpy'; Cpz'];
radius = 400;
numPoints = 100;
theta = linspace(-3/2*pi,2/5*pi,numPoints);
x = radius*cos(theta);
y = radius*sin(theta);
z = -100*(ones(1,numPoints));
Cp = [x;y;z]; % initial heading  is -pi

[~,N] = size(Cp);
N = N-1;
[~,~,Diff] = BeBOT(N,Tf);
Cp_prime = Cp*Diff;

%% Initial conditions
Bx_0 = [-Cp(1,1) -Cp(2,1) Cp(3,1) 0 0 -pi];    %initial displcement
%Bx_0 = [0 0 -15 0 0 0];    %initial displcement
Bv_0 = [-5.14444 0 0 0 0 0];      %initial velocity
Ba_0 = [0 0 0 0 0 0];       %iniial acceleration


%% Maneuver parameters
adap = 1;
v_ref = Bv_0(1);
z_ref = Bx_0(3);
psi_ref = 0;

%% L1 adaptive parameters
L1_adaptive_param;

