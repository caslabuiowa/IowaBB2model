clear all; close all;
addpath('./surface');
    
%% Set model parameters
load_data;    % importing *.igs surface geometries for hydrostat. computation and kinematic properties

%% Set simulation parameters
% Simulation Time (seconds)
Tfin = 180;
Seastate = 0;        %Sea state value between 0 and 6


%% Run pre-defined maneuver
% Set the variable 'ctrl_mode' as an integer 1-6 
% 1: Horizontal Zigzag
% 2: Self Propulsion with waves;
% 3: Turning circle
% 4: Vertical Zigzag
% 5: 3D Path Following w/ L1 Augmentation
% 6: Custom
ctrl_mode = 1;
ctrl_mode_param; % set mode parameters
