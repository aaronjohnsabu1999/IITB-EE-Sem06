// ===[ Prof. AMK, EE-Dept., IITB]
// ----[ Scilab-scripts]-----
//------------------------------------------
// P-3: This programme, numerically integrates 
// RL series circuit, with DC input. 
//------------------------------------------ 

// Here following schemes can be tried out: 
// ==> Vary the switching instant, or input supply's phase.
// ==> Vary the values of R and L (note choice of h will change).
// ==> Vary the initial conditions on L.

//------------------------------------------
// Open this file in Scilab (in Scinotes) and hit F5 btn.
//------------------------------------------
clear;

//  RL circuit with dc step

R = 30;         // in ohm
L = 60e-3;      // in H

pi = %pi;       // defines pi

h = 1e-5;       //time-step chosen

Tfinal = 0.1; 

t = 0:h:Tfinal; // generates time array

// Supply voltage ...

Vo = 9*(ones(length(t),1));

//initial value of the current through L
IL(1) = 0;


// dynamical equation using Forward Euler method
//-------------------------------------------------
for k = 1:1:(Tfinal/h)
    IL(k+1) = IL(k)+ h*(-IL(k)*(R/L)+Vo(k)/L );
end
//-------------------------------------------------



// note the plot of current is scaled for visualization...

plot(t,10*IL','b',t,Vo','r','linewidth',1.5)
xlabel('time (s)');
legend('10 x iL', 'Vin');
title('Response of step-DC to RL circuit');
xgrid(1,1.,9);

