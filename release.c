/* Created by Language version: 7.7.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mech_api.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__rel
#define _nrn_initial _nrn_initial__rel
#define nrn_cur _nrn_cur__rel
#define _nrn_current _nrn_current__rel
#define nrn_jacob _nrn_jacob__rel
#define nrn_state _nrn_state__rel
#define _net_receive _net_receive__rel 
#define state state__rel 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define Ves _p[0]
#define Ves_columnindex 0
#define Fmax _p[1]
#define Fmax_columnindex 1
#define b _p[2]
#define b_columnindex 2
#define u _p[3]
#define u_columnindex 3
#define k1 _p[4]
#define k1_columnindex 4
#define k2 _p[5]
#define k2_columnindex 5
#define k3 _p[6]
#define k3_columnindex 6
#define nt _p[7]
#define nt_columnindex 7
#define kh _p[8]
#define kh_columnindex 8
#define depth _p[9]
#define depth_columnindex 9
#define taur _p[10]
#define taur_columnindex 10
#define cainf _p[11]
#define cainf_columnindex 11
#define kt _p[12]
#define kt_columnindex 12
#define kd _p[13]
#define kd_columnindex 13
#define FA _p[14]
#define FA_columnindex 14
#define VA _p[15]
#define VA_columnindex 15
#define T _p[16]
#define T_columnindex 16
#define ica _p[17]
#define ica_columnindex 17
#define drive_channel _p[18]
#define drive_channel_columnindex 18
#define drive_pump _p[19]
#define drive_pump_columnindex 19
#define DFA _p[20]
#define DFA_columnindex 20
#define DVA _p[21]
#define DVA_columnindex 21
#define DT _p[22]
#define DT_columnindex 22
#define cai _p[23]
#define cai_columnindex 23
#define Dcai _p[24]
#define Dcai_columnindex 24
#define v _p[25]
#define v_columnindex 25
#define _g _p[26]
#define _g_columnindex 26
#define _ion_ica	*_ppvar[0]._pval
#define _ion_cai	*_ppvar[1]._pval
#define _style_ca	*((int*)_ppvar[2]._pvoid)
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 /* declaration of user functions */
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_rel", _hoc_setdata,
 0, 0
};
 #define _zbfc _thread[4]._pval[0]
 #define _zkfv _thread[4]._pval[1]
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "Ves_rel", "mM",
 "Fmax_rel", "mM",
 "b_rel", "/mM4-ms",
 "u_rel", "/ms",
 "k1_rel", "/mM-ms",
 "k2_rel", "/ms",
 "k3_rel", "/ms",
 "kh_rel", "/ms",
 "depth_rel", "um",
 "taur_rel", "ms",
 "cainf_rel", "mM",
 "kt_rel", "mM/ms",
 "kd_rel", "mM",
 "FA_rel", "mM",
 "VA_rel", "mM",
 "T_rel", "mM",
 0,0
};
 static double FA0 = 0;
 static double T0 = 0;
 static double VA0 = 0;
 static double cai0 = 0;
 static double delta_t = 1;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(NrnThread*, _Memb_list*, int);
static void nrn_state(NrnThread*, _Memb_list*, int);
 static void nrn_cur(NrnThread*, _Memb_list*, int);
static void  nrn_jacob(NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(NrnThread*, _Memb_list*, int);
static void _ode_matsol(NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[3]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"rel",
 "Ves_rel",
 "Fmax_rel",
 "b_rel",
 "u_rel",
 "k1_rel",
 "k2_rel",
 "k3_rel",
 "nt_rel",
 "kh_rel",
 "depth_rel",
 "taur_rel",
 "cainf_rel",
 "kt_rel",
 "kd_rel",
 0,
 0,
 "FA_rel",
 "VA_rel",
 "T_rel",
 0,
 0};
 static Symbol* _ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 27, _prop);
 	/*initialize range parameters*/
 	Ves = 0.1;
 	Fmax = 0.001;
 	b = 1e+16;
 	u = 0.1;
 	k1 = 1000;
 	k2 = 0.1;
 	k3 = 4;
 	nt = 10000;
 	kh = 10;
 	depth = 0.1;
 	taur = 700;
 	cainf = 1e-08;
 	kt = 1;
 	kd = 0.0005;
 	_prop->param = _p;
 	_prop->param_size = 27;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_ca_sym);
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[1]._pval = &prop_ion->param[1]; /* cai */
 	_ppvar[2]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for ca */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _thread_mem_init(Datum*);
 static void _thread_cleanup(Datum*);
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _release_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("ca", -10000.);
 	_ca_sym = hoc_lookup("ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 6);
  _extcall_thread = (Datum*)ecalloc(5, sizeof(Datum));
  _thread_mem_init(_extcall_thread);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 1, _thread_mem_init);
     _nrn_thread_reg(_mechtype, 0, _thread_cleanup);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 27, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "#ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	nrn_writes_conc(_mechtype, 0);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 rel release.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double FARADAY = 96489;
 /*Top LOCAL _zbfc , _zkfv */
static int _reset;
static char *modelname = "transmitter release";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 
#define _deriv1_advance _thread[0]._i
#define _dith1 1
#define _recurse _thread[2]._i
#define _newtonspace1 _thread[3]._pvoid
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist2[4];
  static int _slist1[4], _dlist1[4];
 static int state(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {int _reset = 0; {
   _zbfc = b * ( Fmax - FA - VA ) * pow( cai , 4.0 ) ;
   _zkfv = k1 * FA * Ves ;
   DFA = _zbfc - u * FA - _zkfv + k2 * VA ;
   DVA = _zkfv - ( k2 + k3 ) * VA ;
   DT = nt * k3 * VA - kh * T ;
   drive_channel = - ( 10000.0 ) * ica / ( 2.0 * FARADAY * depth ) ;
   if ( drive_channel <= 0. ) {
     drive_channel = 0. ;
     }
   drive_pump = - kt * cai / ( cai + kd ) ;
   Dcai = - _zbfc + 4.0 * u * FA + drive_channel + drive_pump + ( cainf - cai ) / taur ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {
 _zbfc = b * ( Fmax - FA - VA ) * pow( cai , 4.0 ) ;
 _zkfv = k1 * FA * Ves ;
 DFA = DFA  / (1. - dt*( ( - ( u )*( 1.0 ) ) )) ;
 DVA = DVA  / (1. - dt*( ( - ( ( k2 + k3 ) )*( 1.0 ) ) )) ;
 DT = DT  / (1. - dt*( ( - ( kh )*( 1.0 ) ) )) ;
 drive_channel = - ( 10000.0 ) * ica / ( 2.0 * FARADAY * depth ) ;
 if ( drive_channel <= 0. ) {
   drive_channel = 0. ;
   }
 drive_pump = - kt * cai / ( cai + kd ) ;
 Dcai = Dcai  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taur )) ;
  return 0;
}
 /*END CVODE*/
 
static int state (double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {int _reset=0; int error = 0;
 { double* _savstate1 = _thread[_dith1]._pval;
 double* _dlist2 = _thread[_dith1]._pval + 4;
 int _counte = -1;
 if (!_recurse) {
 _recurse = 1;
 {int _id; for(_id=0; _id < 4; _id++) { _savstate1[_id] = _p[_slist1[_id]];}}
 error = nrn_newton_thread(_newtonspace1, 4,_slist2, _p, state, _dlist2, _ppvar, _thread, _nt);
 _recurse = 0; if(error) {abort_run(error);}}
 {
   _zbfc = b * ( Fmax - FA - VA ) * pow( cai , 4.0 ) ;
   _zkfv = k1 * FA * Ves ;
   DFA = _zbfc - u * FA - _zkfv + k2 * VA ;
   DVA = _zkfv - ( k2 + k3 ) * VA ;
   DT = nt * k3 * VA - kh * T ;
   drive_channel = - ( 10000.0 ) * ica / ( 2.0 * FARADAY * depth ) ;
   if ( drive_channel <= 0. ) {
     drive_channel = 0. ;
     }
   drive_pump = - kt * cai / ( cai + kd ) ;
   Dcai = - _zbfc + 4.0 * u * FA + drive_channel + drive_pump + ( cainf - cai ) / taur ;
   {int _id; for(_id=0; _id < 4; _id++) {
if (_deriv1_advance) {
 _dlist2[++_counte] = _p[_dlist1[_id]] - (_p[_slist1[_id]] - _savstate1[_id])/dt;
 }else{
_dlist2[++_counte] = _p[_slist1[_id]] - _savstate1[_id];}}}
 } }
 return _reset;}
 
static int _ode_count(int _type){ return 4;}
 
static void _ode_spec(NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ica = _ion_ica;
  cai = _ion_cai;
  cai = _ion_cai;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  _ion_cai = cai;
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 4; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 	_pv[3] = &(_ion_cai);
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }
 
static void _ode_matsol(NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ica = _ion_ica;
  cai = _ion_cai;
  cai = _ion_cai;
 _ode_matsol_instance1(_threadargs_);
 }}
 
static void _thread_mem_init(Datum* _thread) {
   _thread[_dith1]._pval = (double*)ecalloc(8, sizeof(double));
   _newtonspace1 = nrn_cons_newtonspace(4);
   _thread[4]._pval = (double*)ecalloc(2, sizeof(double));
 }
 
static void _thread_cleanup(Datum* _thread) {
   free((void*)(_thread[_dith1]._pval));
   nrn_destroy_newtonspace(_newtonspace1);
   free((void*)(_thread[4]._pval));
 }
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 1);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {
  int _i; double _save;{
  FA = FA0;
  T = T0;
  VA = VA0;
 {
   FA = 0.0 ;
   VA = 0.0 ;
   T = 0.0 ;
   cai = kd ;
   }
 
}
}

static void nrn_init(NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  ica = _ion_ica;
  cai = _ion_cai;
  cai = _ion_cai;
 initmodel(_p, _ppvar, _thread, _nt);
  _ion_cai = cai;
  nrn_wrote_conc(_ca_sym, (&(_ion_cai)) - 1, _style_ca);
}
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt, double _v){double _current=0.;v=_v;{
} return _current;
}

static void nrn_cur(NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 
}
 
}

static void nrn_jacob(NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}
 
}

static void nrn_state(NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
double _dtsav = dt;
if (secondorder) { dt *= 0.5; }
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
  ica = _ion_ica;
  cai = _ion_cai;
  cai = _ion_cai;
 {  _deriv1_advance = 1;
 derivimplicit_thread(4, _slist1, _dlist1, _p, state, _ppvar, _thread, _nt);
_deriv1_advance = 0;
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 4; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 } {
   }
  _ion_cai = cai;
}}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = FA_columnindex;  _dlist1[0] = DFA_columnindex;
 _slist1[1] = VA_columnindex;  _dlist1[1] = DVA_columnindex;
 _slist1[2] = T_columnindex;  _dlist1[2] = DT_columnindex;
 _slist1[3] = cai_columnindex;  _dlist1[3] = Dcai_columnindex;
 _slist2[0] = FA_columnindex;
 _slist2[1] = T_columnindex;
 _slist2[2] = VA_columnindex;
 _slist2[3] = cai_columnindex;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "release.mod";
static const char* nmodl_file_text = 
  "TITLE transmitter release\n"
  "\n"
  "COMMENT\n"
  "\n"
  "The models used were obtained and then modified from ModelDB (McDougal et al., 2017; accession number 18198). \n"
  "\n"
  "- Destexhe, A., Mainen, Z. F., & Sejnowski, T. J. (1994). Synthesis of models for excitable membranes, synaptic transmission and neuromodulation using a common kinetic formalism. Journal of Computational Neuroscience, 1(3). https://doi.org/10.1007/BF00961734\n"
  "\n"
  "- Destexhe, A., & Sejnowski, T. J. (1995). G protein activation kinetics and spillover of \n"
  "\n"
  "-aminobutyric acid may account for differences between inhibitory responses in the hippocampus and thalamus. Proceedings of the National Academy of Sciences of the United States of America, 92(21). https://doi.org/10.1073/pnas.92.21.9515\n"
  "\n"
  "- McDougal, R. A., Morse, T. M., Carnevale, T., Marenco, L., Wang, R., Migliore, M., Miller, P. L., Shepherd, G. M., & Hines, M. L. (2017). Twenty years of ModelDB and beyond: building essential modeling tools for the future of neuroscience. In Journal of Computational Neuroscience (Vol. 42, Issue 1). https://doi.org/10.1007/s10827-016-0623-7\n"
  "\n"
  "\n"
  " Simple (minimal?) model of transmitter release\n"
  "\n"
  " - single compartment, need calcium influx and efflux\n"
  "\n"
  " - Ca++ binds to a \"fusion factor\" protein F leading to an activated form FA.\n"
  "   Assuming a cooperativity factor of 4 (see Augustine & charlton, \n"
  "   J Physiol. 381: 619-640, 1986), one obtains:\n"
  "\n"
  "	F + 4 Cai <-> FA	(kb,ku)\n"
  "\n"
  " - FA binds to presynaptic vesicles and activates them according to:\n"
  "\n"
  "	FA + V <-> VA		(k1,k2)\n"
  "\n"
  "   VA represents the \"activated vesicle\" which is able to bind to the\n"
  "   membrane and release transmitter.  Presynaptic vesicles (V) are \n"
  "   considered in excess.\n"
  "\n"
  " - VA releases nt transmitter molecules in the synaptic cleft\n"
  "\n"
  "	VA  ->  nt T		(k3)\n"
  "\n"
  "   This reaction is the slowest and a constant number of transmitter per \n"
  "   vesicule is considered (nt).  \n"
  "\n"
  " - Finally, T is hydrolyzed according to a first-order reaction\n"
  "\n"
  "	T  ->  ...		(kh)\n"
  "\n"
  "\n"
  "-----------------------------------------------------------------------------\n"
  "ENDCOMMENT\n"
  "\n"
  "\n"
  "INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX rel\n"
  "	USEION ca READ ica, cai WRITE cai\n"
  "	RANGE T,FA,CA,Fmax,Ves,b,u,k1,k2,k3,nt,kh\n"
  ": from cad :\n"
  "	RANGE depth,kt,kd,cainf,taur\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(mA) = (milliamp)\n"
  "	(mV) = (millivolt)\n"
  "	(mM) = (milli/liter)\n"
  ": from cad:\n"
  "	(molar) = (1/liter)			: moles do not appear in units\n"
  ":	(mM)	= (millimolar)\n"
  "	(um)	= (micron)\n"
  ":	(mA)	= (milliamp)\n"
  "	(msM)	= (ms mM)\n"
  "\n"
  "}\n"
  ": from cad:\n"
  "\n"
  "CONSTANT {\n"
  "	FARADAY = 96489		(coul)		: moles do not appear in units\n"
  ":	FARADAY = 96.489	(k-coul)	: moles do not appear in units\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "\n"
  "	Ves = 0.1 	(mM)		: conc of vesicles\n"
  "	Fmax = 0.001	(mM)		: conc of fusion factor F\n"
  "	b = 1e16 	(/mM4-ms)	: ca binding to F\n"
  "	u = 0.1  	(/ms)		: ca unbinding \n"
  "	k1 = 1000   	(/mM-ms)	: F binding to vesicle\n"
  "	k2 = 0.1	(/ms)		: F unbinding to vesicle\n"
  "	k3 = 4   	(/ms)		: exocytosis of T\n"
  "	nt = 10000			: nb of molec of T per vesicle\n"
  "	kh = 10  	(/ms)		: cst for hydolysis of T\n"
  ": from cad:\n"
  "	depth	= .1	(um)		: depth of shell\n"
  "	taur	= 700	(ms)		: rate of calcium removal\n"
  "	cainf	= 1e-8	(mM)\n"
  "	kt	= 1	(mM/ms)		: estimated from k3=.5, tot=.001\n"
  "	kd	= 5e-4	(mM)		: estimated from k2=250, k1=5e5\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	ica		(mA/cm2)\n"
  "	drive_channel	(mM/ms)\n"
  "	drive_pump	(mM/ms)\n"
  "}\n"
  "\n"
  "STATE {\n"
  "	FA	(mM)\n"
  "	VA	(mM)\n"
  "	T	(mM)\n"
  "	cai	(mM) \n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "	FA = 0\n"
  "	VA = 0\n"
  "	T = 0\n"
  ":	cai = 1e-8\n"
  "	cai = kd\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE state METHOD derivimplicit\n"
  "}\n"
  "\n"
  "LOCAL bfc , kfv\n"
  "\n"
  "DERIVATIVE state {\n"
  "\n"
  "	bfc = b * (Fmax-FA-VA) * cai^4\n"
  "	kfv = k1 * FA * Ves\n"
  ":	this is the old equation incorporated into the below:\n"
  ":	cai'	= - bfc + 4 * u * FA \n"
  "	FA'	= bfc - u * FA - kfv + k2 * VA\n"
  "	VA'	= kfv - (k2+k3) * VA\n"
  "	T'	= nt * k3 * VA - kh * T\n"
  ": from cad:\n"
  "\n"
  "	drive_channel =  - (10000) * ica / (2 * FARADAY * depth)\n"
  "\n"
  "	if (drive_channel <= 0.) { drive_channel = 0. }	: cannot pump inward\n"
  "\n"
  ":	drive_pump = -tot * k3 * cai / (cai + ((k2+k3)/k1) )	: quasistat\n"
  "	drive_pump = -kt * cai / (cai + kd )		: Michaelis-Menten\n"
  "\n"
  ":	this is the eq for cai prime from cad incorporated into below:\n"
  ":	cai' = drive_channel + drive_pump + (cainf-cai)/taur\n"
  "	cai'= -bfc+4*u*FA + drive_channel + drive_pump + (cainf-cai)/taur\n"
  "\n"
  "}	\n"
  ;
#endif
