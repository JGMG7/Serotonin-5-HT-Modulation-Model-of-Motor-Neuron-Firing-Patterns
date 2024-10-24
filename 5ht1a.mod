TITLE detailed model of GABAB receptors

COMMENT

The models used were obtained and then modified from ModelDB (McDougal et al., 2017; accession number 18198). 

- Destexhe, A., Mainen, Z. F., & Sejnowski, T. J. (1994). Synthesis of models for excitable membranes, synaptic transmission and neuromodulation using a common kinetic formalism. Journal of Computational Neuroscience, 1(3). https://doi.org/10.1007/BF00961734

- Destexhe, A., & Sejnowski, T. J. (1995). G protein activation kinetics and spillover of γ-aminobutyric acid may account for differences between inhibitory responses in the hippocampus and thalamus. Proceedings of the National Academy of Sciences of the United States of America, 92(21). https://doi.org/10.1073/pnas.92.21.9515

- McDougal, R. A., Morse, T. M., Carnevale, T., Marenco, L., Wang, R., Migliore, M., Miller, P. L., Shepherd, G. M., & Hines, M. L. (2017). Twenty years of ModelDB and beyond: building essential modeling tools for the future of neuroscience. In Journal of Computational Neuroscience (Vol. 42, Issue 1). https://doi.org/10.1007/s10827-016-0623-7


	Features:

  	  - peak at 100 ms; time course fit to Tom Otis' PSC
	  - NONLINEAR SUMMATION (psc is much stronger with bursts)
	    due to cooperativity of G-protein binding on K+ channels


	Approximations:

	  - single binding site on receptor	
	  - desensitization of the receptor
	  - model of alpha G-protein activation (direct) of K+ channel
	  - G-protein dynamics is second-order; simplified as follows:
		- saturating receptor
		- Michaelis-Menten of receptor for G-protein production
		- "resting" G-protein is in excess
		- Quasi-stat of intermediate enzymatic forms
	  - binding on K+ channel is fast


	Kinetic Equations:

	  dR/dt = K1 * T * (1-R-D) - K2 * R + d2 * D

	  dD/dt = d1 * R - d2 * D

	  dG/dt = K3 * R - K4 * G

	  R : activated receptor
	  T : transmitter
	  G : activated G-protein
	  K1,K2,K3,K4,d1,d2 = kinetic rate cst

  n activated G-protein bind to a K+ channel:

	n G + C <-> O		(Alpha,Beta)

  If the binding is fast, the fraction of open channels is given by:

	O = G^n / ( G^n + KD )

  where KD = Beta / Alpha is the dissociation constant

ENDCOMMENT



INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}

NEURON {
	POINT_PROCESS HTr1a
	POINTER C
	RANGE R, D, G, g, gmax
	NONSPECIFIC_CURRENT i
	GLOBAL K1, K2, K3, K4, KD, d1, d2, Erev
}
UNITS {
	(nA) = (nanoamp)
	(mV) = (millivolt)
	(umho) = (micromho)
	(mM) = (milli/liter)
}

PARAMETER {

:
:	From simplex fitting to experimental data
:	(Destexhe and Sejnowski, 1995)
:
	K1	= 8004.512 (/ms mM)	: forward binding rate to receptor
	K2	= 124.929 (/ms)		: backward (unbinding) rate of receptor
	K3	= 0.083 (/ms)		: rate of G-protein production
	K4	= 0.0079 (/ms)		: rate of G-protein decay
	d1	= 0.017 (/ms)		: rate of desensitization
	d2	= 0.0053 (/ms)		: rate of re-sensitization
	KD	= 100			: dissociation constant of K+ channel
	n	= 4			: nb of binding sites of G-protein on K+
	Erev	= -95	(mV)		: reversal potential (E_K)
	gmax		(umho)		: maximum conductance
}


ASSIGNED {
	v		(mV)		: postsynaptic voltage
	i 		(nA)		: current = g*(v - Erev)
	g 		(umho)		: conductance
	C		(mM)		: pointer to transmitter concentration
	Gn
}


STATE {
	R				: fraction of activated receptor
	D				: fraction of desensitized receptor
	G				: fraction of activated G-protein
}


INITIAL {
	R = 0
	D = 0
	G = 0
}

BREAKPOINT {
	SOLVE bindkin METHOD cnexp
	Gn = G^n
	g = gmax * Gn / (Gn+KD)
	i = g*(v - Erev)
}


DERIVATIVE bindkin {

	R' = K1 * C * (1-R-D) - K2 * R + d2 * D
	D' = d1 * R - d2 * D
	G' = K3 * R - K4 * G

}


