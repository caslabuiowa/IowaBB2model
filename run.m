clear all; close all;

%% Set model parameters
load_data;    % importing *.igs surface geometries for hydrostat. computation and kinematic properties

%% Set simulation parameters
% Initial Conditions
Bx_0 = [0 0 -100 0 0 0];    %initial displcement
Bv_0 = [-5 0 0 0 0 0];      %initial velocity
Ba_0 = [0 0 0 0 0 0];       %iniial acceleration
% Simulation Time (seconds)
Tfin = 180;
% Sea state
Seastate = 0;        %Sea state value between 0 and 6

%% Run pre-defined maneuver
% Set the variable 'maneuver' as an integer 1-6 
% 1: Horizontal Zigzag
% 2: Self Propulsion with waves;
% 3: Turning circle
% 4: Vertical Zigzag
% 5: 3D Path Following w/ L1 Augmentation
% 6: Custom
maneuver = 1;

