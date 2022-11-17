clear all; close all;
addpath('./surface');
    
%% Set model parameters
load_data;    % importing *.igs surface geometries for hydrostat. computation and kinematic properties
Ts = 0.05; % Step size

%% Set simulation parameters
% Simulation Time (seconds)
Tf = 5000;
Seastate = 0;        %Sea state value between 0 and 6


%% Initial conditions
Bx_0 = [0 0 -60 0 0 0];    %initial displcement
Bv_0 = [-5.14444 0 0 0 0 0];      %initial velocity
Ba_0 = [0 0 0 0 0 0];       %iniial acceleration


%% Maneuver parameters
adap = 0;
v_ref = Bv_0(1);
z_ref = Bx_0(3);
psi_ref = 0;



