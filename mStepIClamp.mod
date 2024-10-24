COMMENT
    Point process for generation of multiple step currents at different amplitudes over time.
    

Take and modified from Kim (2017). Obtained from ModelDB (McDougal et al., 2017; accession  number 235769)

- Kim, H. (2017). Muscle length-dependent contribution of motoneuron Cav1.3 channels to force production in model slow motor unit. Journal of Applied Physiology, 123(1). https://doi.org/10.1152/japplphysiol.00491.2016

- McDougal, R. A., Morse, T. M., Carnevale, T., Marenco, L., Wang, R., Migliore, M., Miller, P. L., Shepherd, G. M., & Hines, M. L. (2017). Twenty years of ModelDB and beyond: building essential modeling tools for the future of neuroscience. In Journal of Computational Neuroscience (Vol. 42, Issue 1). https://doi.org/10.1007/s10827-016-0623-7
ENDCOMMENT

    NEURON {
        POINT_PROCESS mStepIClamp
        RANGE del, dur
		RANGE ip1, ip2, ip3, ip4
		RANGE pon1, pon2, pon3, pon4
		RANGE poff1, poff2, poff3, poff4
		RANGE i0, s
        ELECTRODE_CURRENT i
    }

    UNITS {
        (nA) = (nanoamp)
    }

    PARAMETER {
        del=0   (ms)
        dur=1000   (ms)
    		
		ip1=0.5 (nA)
		ip2=-0.3 (nA)
		ip3=0.27 (nA)
		ip4=0.3 (nA)

		pon1=100 (ms)
		pon2=300 (ms)
		pon3=500 (ms)
		pon4=950 (ms)
			
		poff1=130 (ms)
		poff2=330 (ms)
		poff3=900 (ms)
		poff4=980 (ms)
			
			
		i0=3 (nA)
		s=2			
    }

    ASSIGNED {
        i (nA)
    }

    BREAKPOINT {
        at_time(del)
        at_time(del + dur)
		
		i = i0 + s*((heav(poff1-t)*heav(t-pon1)*ip1) + (heav(poff2-t)*heav(t-pon2)*ip2-0.01) + (heav(poff3-t)*heav(t-pon3)*ip3) + (heav(poff4-t)*heav(t-pon4)*ip4))
    }
	
	FUNCTION heav (x) {
		if (x < 0) {heav = 0}
		else {heav = 1}
	}