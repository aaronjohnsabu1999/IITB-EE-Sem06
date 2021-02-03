// ===[ Prof. AMK, EE-Dept., IITB]

// ----[ Scilab-scripts]-----

//------------------------------------------
// P-4: This programme, numerically integrates 
// RLC series circuit, with step-sinusoidal input.
//------------------------------------------ 

// Here following schemes can be tried out: 
// ==> Vary the switching instant, or input supply's phase.
// ==> Vary the values of R, L and C (note choice of h will change).
// ==> Vary the initial conditions on L and C.

//------------------------------------------
// Open this file in Scilab (in Scinotes) and hit F5 btn.
//------------------------------------------
clear;

//   RLC circuit with step-AC (sine)

R = 10;   // in ohm, Note: the resistance.of L is taken into account
C = 10e-6;      // in F
L = 60e-3;      //in H

pi = %pi;	// defines pi

h = 1e-5;       //time-step chosen

Tfinal = 0.1;	// final time of simulation in second

t = 0:h:Tfinal; // generates time array

// sinusoidal supply voltage ...
// Note: one can play with the phase angle of the sinewave,
// in order to change the instant of switching in the RC circuit

Vo = 30*sqrt(2)*sin(2*pi*50*t); // supply voltage is kept zero...
Vc(1) = 0;     //initial value of the voltage across C
IL(1) = 0;

// dynamical equation ...
//--------------------------------------------------------
for k = 1:1:(Tfinal/h)
    Vc(k+1) = Vc(k)+h*(IL(k)/C);
    IL(k+1) = IL(k)+ h*(-IL(k)*(R/L)+(Vo(k)-Vc(k))/L );
end
//--------------------------------------------------------

// note the plot of current is scaled for visualization...

plot(t',50*IL,'b',t',Vo,'r','linewidth',1.5);
xlabel('time (s)');
legend('50 x iL', 'Vin');
title('Response of step-AC (sine) to RLC circuit');
xgrid(1,1.,9);

