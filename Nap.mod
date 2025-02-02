COMMENT
Take from Kim (2017). Obtained from ModelDB (McDougal et al., 2017; accession  number 235769)

- Kim, H. (2017). Muscle length-dependent contribution of motoneuron Cav1.3 channels to force production in model slow motor unit. Journal of Applied Physiology, 123(1). https://doi.org/10.1152/japplphysiol.00491.2016

- McDougal, R. A., Morse, T. M., Carnevale, T., Marenco, L., Wang, R., Migliore, M., Miller, P. L., Shepherd, G. M., & Hines, M. L. (2017). Twenty years of ModelDB and beyond: building essential modeling tools for the future of neuroscience. In Journal of Computational Neuroscience (Vol. 42, Issue 1). https://doi.org/10.1007/s10827-016-0623-7

ENDCOMMENT


TITLE Persistent Sodium Channel

NEURON {
	SUFFIX Nap
	USEION na READ ena WRITE ina
	RANGE gnapbar, ina, g, i
}

UNITS {
	(mA) = (milliamp)
	(mV) = (millivolt)
	(S)  = (siemens)
}

PARAMETER {
	gnapbar	=0.0008 	(mho/cm2) <0,1e9>
}

ASSIGNED {
	v (mV)
	ena (mv)
	ina (mA/cm2)
	i (mA/cm2)
	g (S/cm2)
	minf mtau
}

STATE {
	m
}

BREAKPOINT {
	SOLVE states METHOD cnexp
	g = gnapbar * m * m * m
	i = g * (v - ena)
	ina = i
}

INITIAL { :Assume v has been constant for a long time
	rates(v)
	m = minf
}

DERIVATIVE states { :Computes state variable m and h at present v & t
	rates(v)
	m' = (minf - m)/mtau
}

PROCEDURE rates(v(mV)) {LOCAL a, b
	a = (-0.0353*(v+21.4))/(exp(-(v+21.4)/5)-1)
	b = (0.000883*(v+25.7))/(exp((v+25.7)/5)-1)
	mtau = 1/(a + b)
	minf = a/(a + b)
}
