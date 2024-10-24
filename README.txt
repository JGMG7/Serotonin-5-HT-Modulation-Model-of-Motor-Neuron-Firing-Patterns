Serotonin (5-HT) Modulation Model of Motor Neuron Firing Patterns


This package is running with the NEURON simulation program version 8.2 available on internet at:
 https://www.neuron.yale.edu/neuron/ 

The package contains mechanisms (.mod files) and programs (.hoc files) needed
to simulate excitatory and inhibitory events corresponding to:

Computational model of a motoneuron incorporating the 5-HT1a serotonin receptor
and a presynaptic neuron that releases serotonin (5-HT) upon stimulation. The model aims to elucidate
the role of serotonin in motor function and its impact on motoneuron excitability.
 


  PROGRAMS
  ========

motor_unit.hoc : which in turn contains the following programs: 

	v_e_moto6_export.hoc    :  Anatomical data corresponding to a cat motoneuron (i.e., v_e_moto6), which is available in the public database (www.neuromorph.org)

	add_hil_is.hoc          :  Geometry and connection of axonal hillock and initial segment

	mem_mechanism_pass.hoc  :   Passive properties of the motoneuron model

	mem_mechanism_acti.hoc  :  Active properties of the motoneuron model

	neuro_transmitter.hoc   :  Detailed kinetic synapse mechanism

	fixnseg.hoc             :  func lambda_f() { local i, x1, x2, d1, d2, lam
        			           if (n3d() < 2) {
                			           return 1e5*sqrt(diam/(4*PI*$1*Ra*cm))

	
	add_pics_istim.hoc      :  Localization of intracellular stimulation at the soma and Ca-PIC channels over dendrites at the similar distance from the soma

		CaL_PICs.hoc    :  Localization of synaptic inputs and Ca-PIC channels over dendrites at the similar distance from the soma



  MECHANISMS
  ==========

5ht1a.mod       : 5-HT1a receptor

Ca_conc.mod     : Calcium concentration

CaL.mod         : L-type Calcium channel

caL3d.mod       : high-threshold calcium current in the presynaptic terminal

CaN.mod         : N-type Calcium channel

HH2.mod         : Hippocampal HH channels

KCa.mod         : Ca activated potassium channel

KDr.mod         : Delayed rectifier potassium channel

mStepIClamp.mod : Point process for generation of multiple step currents at different amplitudes over time

Naf.mod         : Fast Sodium Channel

Nap.mod         : Persistent Sodium Channel

release.mod     : kinetic model for the release of transmitter



  HOW TO RUN
  ==========

To compile the demo, NEURON and INTERVIEWS must be installed and working on
the machine you are using.  Just type "nrnivmodl" to compile the mechanisms
given in the mod files.

Then, execute the motor_unit.hoc program:


Once the menu and graphics interface has appeared, click on "File"
and click on "load session" and select "5HT1a.ses". Finally click on 
"Init & Run" in "RunControl"



  MODIFICATIONS
  ==========

"""""5-HT1a  receptors density:"""""

To modify density this receptor in initial segment, change in the "insert postsynaptic mechanisms" sections of "neurotransmitter.hoc" program.

objectvar c[500]             <---- change to desired quantity


for i = 0, 499 {             <---- desired quantity - 1
    c[i] = new HTr1a()                        // create synapse
    is c[i].loc(0.5 + 0.001 * (i + 1))  // assign postsynaptic compartment
    setpointer c[i].C, PRE.T_rel(0.5)        // assign presynaptic compartment



for i = 0, 499 {             <---- desired quantity - 1

   c[i].gmax = 0.0001  //    (umho)   maximum conductance



"""""5-HT concentration:"""""

To modify 5-HT concentration release, change in the "insert presynaptic mechanisms" sections of "neurotransmitter.hoc" program.


nt_rel  = 10000 // 1000 // 100 // 10 // number of transmitter molecule per vesicle        <---- change to desired quantity 10000 = 10 mM; 1000 = 1 mM; 100 = 0.1 mM; 10 = 0.01 mM


For more information about how to get NEURON and how to install it, please
refer to the following sites:
  https://www.neuron.yale.edu/neuron/ 