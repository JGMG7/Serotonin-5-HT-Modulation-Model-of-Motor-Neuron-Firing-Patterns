#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

extern void _5ht1a_reg();
extern void _CaL_reg();
extern void _CaN_reg();
extern void _Ca_conc_reg();
extern void _HH2_reg();
extern void _KCa_reg();
extern void _KDr_reg();
extern void _Naf_reg();
extern void _Nap_reg();
extern void _caL3d_reg();
extern void _mStepIClamp_reg();
extern void _release_reg();

void modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," 5ht1a.mod");
fprintf(stderr," CaL.mod");
fprintf(stderr," CaN.mod");
fprintf(stderr," Ca_conc.mod");
fprintf(stderr," HH2.mod");
fprintf(stderr," KCa.mod");
fprintf(stderr," KDr.mod");
fprintf(stderr," Naf.mod");
fprintf(stderr," Nap.mod");
fprintf(stderr," caL3d.mod");
fprintf(stderr," mStepIClamp.mod");
fprintf(stderr," release.mod");
fprintf(stderr, "\n");
    }
_5ht1a_reg();
_CaL_reg();
_CaN_reg();
_Ca_conc_reg();
_HH2_reg();
_KCa_reg();
_KDr_reg();
_Naf_reg();
_Nap_reg();
_caL3d_reg();
_mStepIClamp_reg();
_release_reg();
}
