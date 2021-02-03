//===[ Prof. AMK, EE-Dept., IITB]

// ----[ Scilab-scripts]-----
//------------------------------------------
// This programme, numerically integrates 
// RL series circuit, with step-sinusoidal input. 
//------------------------------------------ 

// Here following schemes can be tried out: 
// ==> Vary the switching instant, or input supply's phase.
// ==> Vary the values of R and L (note choice of h will change).
// ==> Vary the initial conditions on L.

//------------------------------------------
// Open this file in Scilab (in Scinotes) and hit F5 btn.
//------------------------------------------
clear;

//  RL circuit with step-AC (sine)

R = 0.15;    // in ohm
L = 60e-3;

pi = %pi;	// defines pi

h = 1e-5;   //time-step chosen

Tfinal = 0.4;

t = 0:h:Tfinal; // generates time array

// sinusoidal supply voltage ...
Vo = 10*sin(2*pi*50*t);
psio=10/2/pi/50;



//initial value of the current through L
psi(1) = 0;


// dynamical equation using Forward Euler method
//-------------------------------------------------
for k = 1:1:(Tfinal/h)
    psi(k+1) = psi(k)- h*psi(k)/L*(1+1*exp(2*abs(psi(k))/psio)/2)*(R)+h*Vo(k) ;
end
//-------------------------------------------------

IL =psi/L.*(1+1*exp(2*abs(psi)/psio)/2);

figure(1)
plot(t',psi*2*pi*50,'b',t,Vo,'r','linewidth',1.5)
xlabel('time (s)');
legend('w*psi', 'Vin');
title('Response of step-AC (sine) to RL circuit');
xgrid(1,1.,9);

//abort
// note the plot of current is scaled for visualization...

figure(2)
plot(t',10*IL,'b',t,Vo,'r','linewidth',1.5)
xlabel('time (s)');
legend('10 x iL', 'Vin');
title('Response of step-AC (sine) to RL circuit');
xgrid(1,1.,9);
