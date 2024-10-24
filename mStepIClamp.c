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
 
#define nrn_init _nrn_init__mStepIClamp
#define _nrn_initial _nrn_initial__mStepIClamp
#define nrn_cur _nrn_cur__mStepIClamp
#define _nrn_current _nrn_current__mStepIClamp
#define nrn_jacob _nrn_jacob__mStepIClamp
#define nrn_state _nrn_state__mStepIClamp
#define _net_receive _net_receive__mStepIClamp 
 
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
#define del _p[0]
#define del_columnindex 0
#define dur _p[1]
#define dur_columnindex 1
#define ip1 _p[2]
#define ip1_columnindex 2
#define ip2 _p[3]
#define ip2_columnindex 3
#define ip3 _p[4]
#define ip3_columnindex 4
#define ip4 _p[5]
#define ip4_columnindex 5
#define pon1 _p[6]
#define pon1_columnindex 6
#define pon2 _p[7]
#define pon2_columnindex 7
#define pon3 _p[8]
#define pon3_columnindex 8
#define pon4 _p[9]
#define pon4_columnindex 9
#define poff1 _p[10]
#define poff1_columnindex 10
#define poff2 _p[11]
#define poff2_columnindex 11
#define poff3 _p[12]
#define poff3_columnindex 12
#define poff4 _p[13]
#define poff4_columnindex 13
#define i0 _p[14]
#define i0_columnindex 14
#define s _p[15]
#define s_columnindex 15
#define i _p[16]
#define i_columnindex 16
#define v _p[17]
#define v_columnindex 17
#define _g _p[18]
#define _g_columnindex 18
#define _nd_area  *_ppvar[0]._pval
 
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
 static double _hoc_heav(void*);
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

 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(Object* _ho) { void* create_point_process(int, Object*);
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt(void*);
 static double _hoc_loc_pnt(void* _vptr) {double loc_point_process(int, void*);
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(void* _vptr) {double has_loc_point(void*);
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(void* _vptr) {
 double get_loc_point_process(void*); return (get_loc_point_process(_vptr));
}
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 0,0
};
 static Member_func _member_func[] = {
 "loc", _hoc_loc_pnt,
 "has_loc", _hoc_has_loc,
 "get_loc", _hoc_get_loc_pnt,
 "heav", _hoc_heav,
 0, 0
};
#define heav heav_mStepIClamp
 extern double heav( _threadargsprotocomma_ double );
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "del", "ms",
 "dur", "ms",
 "ip1", "nA",
 "ip2", "nA",
 "ip3", "nA",
 "ip4", "nA",
 "pon1", "ms",
 "pon2", "ms",
 "pon3", "ms",
 "pon4", "ms",
 "poff1", "ms",
 "poff2", "ms",
 "poff3", "ms",
 "poff4", "ms",
 "i0", "nA",
 "i", "nA",
 0,0
};
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
 static void _hoc_destroy_pnt(void* _vptr) {
   destroy_point_process(_vptr);
}
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"mStepIClamp",
 "del",
 "dur",
 "ip1",
 "ip2",
 "ip3",
 "ip4",
 "pon1",
 "pon2",
 "pon3",
 "pon4",
 "poff1",
 "poff2",
 "poff3",
 "poff4",
 "i0",
 "s",
 0,
 "i",
 0,
 0,
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 19, _prop);
 	/*initialize range parameters*/
 	del = 0;
 	dur = 1000;
 	ip1 = 0.5;
 	ip2 = -0.3;
 	ip3 = 0.27;
 	ip4 = 0.3;
 	pon1 = 100;
 	pon2 = 300;
 	pon3 = 500;
 	pon4 = 950;
 	poff1 = 130;
 	poff2 = 330;
 	poff3 = 900;
 	poff4 = 980;
 	i0 = 3;
 	s = 2;
  }
 	_prop->param = _p;
 	_prop->param_size = 19;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 2, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _mStepIClamp_reg() {
	int _vectorized = 1;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init,
	 hoc_nrnpointerindex, 1,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 19, 2);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 mStepIClamp mStepIClamp.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 
double heav ( _threadargsprotocomma_ double _lx ) {
   double _lheav;
 if ( _lx < 0.0 ) {
     _lheav = 0.0 ;
     }
   else {
     _lheav = 1.0 ;
     }
   
return _lheav;
 }
 
static double _hoc_heav(void* _vptr) {
 double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (NrnThread*)((Point_process*)_vptr)->_vnt;
 _r =  heav ( _p, _ppvar, _thread, _nt, *getarg(1) );
 return(_r);
}

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {
  int _i; double _save;{

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
#if EXTRACELLULAR
 _nd = _ml->_nodelist[_iml];
 if (_nd->_extnode) {
    _v = NODEV(_nd) +_nd->_extnode->_v[0];
 }else
#endif
 {
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
 v = _v;
 initmodel(_p, _ppvar, _thread, _nt);
}
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   at_time ( _nt, del ) ;
   at_time ( _nt, del + dur ) ;
   i = i0 + s * ( ( heav ( _threadargscomma_ poff1 - t ) * heav ( _threadargscomma_ t - pon1 ) * ip1 ) + ( heav ( _threadargscomma_ poff2 - t ) * heav ( _threadargscomma_ t - pon2 ) * ip2 - 0.01 ) + ( heav ( _threadargscomma_ poff3 - t ) * heav ( _threadargscomma_ t - pon3 ) * ip3 ) + ( heav ( _threadargscomma_ poff4 - t ) * heav ( _threadargscomma_ t - pon4 ) * ip4 ) ) ;
   }
 _current += i;

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
#if EXTRACELLULAR
 _nd = _ml->_nodelist[_iml];
 if (_nd->_extnode) {
    _v = NODEV(_nd) +_nd->_extnode->_v[0];
 }else
#endif
 {
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
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
 	}
 _g = (_g - _rhs)/.001;
 _g *=  1.e2/(_nd_area);
 _rhs *= 1.e2/(_nd_area);
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) += _rhs;
  }else
#endif
  {
	NODERHS(_nd) += _rhs;
  }
  if (_nt->_nrn_fast_imem) { _nt->_nrn_fast_imem->_nrn_sav_rhs[_ni[_iml]] += _rhs; }
#if EXTRACELLULAR
 if (_nd->_extnode) {
   *_nd->_extnode->_rhs[0] += _rhs;
 }
#endif
 
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
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) -= _g;
  }else
#endif
  {
	NODED(_nd) -= _g;
  }
  if (_nt->_nrn_fast_imem) { _nt->_nrn_fast_imem->_nrn_sav_d[_ni[_iml]] -= _g; }
#if EXTRACELLULAR
 if (_nd->_extnode) {
   *_nd->_extnode->_d[0] += _g;
 }
#endif
 
}
 
}

static void nrn_state(NrnThread* _nt, _Memb_list* _ml, int _type) {

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "mStepIClamp.mod";
static const char* nmodl_file_text = 
  "COMMENT\n"
  "    Point process for generation of multiple step currents at different amplitudes over time.\n"
  "    \n"
  "\n"
  "Take and modified from Kim (2017). Obtained from ModelDB (McDougal et al., 2017; accession  number 235769)\n"
  "\n"
  "- Kim, H. (2017). Muscle length-dependent contribution of motoneuron Cav1.3 channels to force production in model slow motor unit. Journal of Applied Physiology, 123(1). https://doi.org/10.1152/japplphysiol.00491.2016\n"
  "\n"
  "- McDougal, R. A., Morse, T. M., Carnevale, T., Marenco, L., Wang, R., Migliore, M., Miller, P. L., Shepherd, G. M., & Hines, M. L. (2017). Twenty years of ModelDB and beyond: building essential modeling tools for the future of neuroscience. In Journal of Computational Neuroscience (Vol. 42, Issue 1). https://doi.org/10.1007/s10827-016-0623-7\n"
  "ENDCOMMENT\n"
  "\n"
  "    NEURON {\n"
  "        POINT_PROCESS mStepIClamp\n"
  "        RANGE del, dur\n"
  "		RANGE ip1, ip2, ip3, ip4\n"
  "		RANGE pon1, pon2, pon3, pon4\n"
  "		RANGE poff1, poff2, poff3, poff4\n"
  "		RANGE i0, s\n"
  "        ELECTRODE_CURRENT i\n"
  "    }\n"
  "\n"
  "    UNITS {\n"
  "        (nA) = (nanoamp)\n"
  "    }\n"
  "\n"
  "    PARAMETER {\n"
  "        del=0   (ms)\n"
  "        dur=1000   (ms)\n"
  "    		\n"
  "		ip1=0.5 (nA)\n"
  "		ip2=-0.3 (nA)\n"
  "		ip3=0.27 (nA)\n"
  "		ip4=0.3 (nA)\n"
  "\n"
  "		pon1=100 (ms)\n"
  "		pon2=300 (ms)\n"
  "		pon3=500 (ms)\n"
  "		pon4=950 (ms)\n"
  "			\n"
  "		poff1=130 (ms)\n"
  "		poff2=330 (ms)\n"
  "		poff3=900 (ms)\n"
  "		poff4=980 (ms)\n"
  "			\n"
  "			\n"
  "		i0=3 (nA)\n"
  "		s=2			\n"
  "    }\n"
  "\n"
  "    ASSIGNED {\n"
  "        i (nA)\n"
  "    }\n"
  "\n"
  "    BREAKPOINT {\n"
  "        at_time(del)\n"
  "        at_time(del + dur)\n"
  "		\n"
  "		i = i0 + s*((heav(poff1-t)*heav(t-pon1)*ip1) + (heav(poff2-t)*heav(t-pon2)*ip2-0.01) + (heav(poff3-t)*heav(t-pon3)*ip3) + (heav(poff4-t)*heav(t-pon4)*ip4))\n"
  "    }\n"
  "	\n"
  "	FUNCTION heav (x) {\n"
  "		if (x < 0) {heav = 0}\n"
  "		else {heav = 1}\n"
  "	}\n"
  ;
#endif
