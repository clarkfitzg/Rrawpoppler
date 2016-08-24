#include "ROutputDev.h"


#if 0
SEXP 
ROutputDev::lookupRMethod(const char *name)
{
    SEXP names = GET_NAMES(r_method_funcs);
    int n = Rf_length(r_method_funcs);
    for(int i = 0; i < n; i++) {
        if(strcmp(CHAR(STRING_ELT(names, i)), name) == 0)
            return(VECTOR_ELT(r_method_funcs, i));
    }
    return(R_NilValue);
}


GBool 
ROutputDev::upsideDown()
{
    SEXP fun = lookupRMethod("upsideDown");
    if(fun == R_NilValue) 
        return(1);
    
    SEXP e;
    PROTECT(e = allocVector(LANGSXP, 1));
    SETCAR(e, fun);
    SEXP r_ans = invokeMethod(e);
    UNPROTECT(1);
    return((GBool) LOGICAL(r_ans)[0]);
}
GBool 
ROutputDev::useDrawChar()
{
    SEXP fun = lookupRMethod("useDrawChar");
    if(fun == R_NilValue) 
        return(1);
    
    SEXP e;
    PROTECT(e = allocVector(LANGSXP, 1));
    SETCAR(e, fun);
    SEXP r_ans = invokeMethod(e);
    UNPROTECT(1);
    return((GBool) LOGICAL(r_ans)[0]);
}

GBool 
ROutputDev::interpretType3Chars()
{
    SEXP fun = lookupRMethod("interpretType3Chars");
    if(fun == R_NilValue) 
        return(0); 
    
    SEXP e;
    PROTECT(e = allocVector(LANGSXP, 1));
    SETCAR(e, fun);
    SEXP r_ans = invokeMethod(e);
    UNPROTECT(1);
    return((GBool) LOGICAL(r_ans)[0]);
}



void 
ROutputDev::startPage(int pageNum, GfxState *state, XRef *xref)
{
    SEXP fun = lookupRMethod("startPage");
    if(fun == R_NilValue) 
        return;

    SEXP e, cur;
    PROTECT(e = cur = allocVector(LANGSXP, 4));
    SETCAR(cur, fun); cur = CDR(cur);
    SETCAR(cur, ScalarInteger(pageNum)); cur = CDR(cur);
    SETCAR(cur, createRef(state, "GfxState", NULL)); cur = CDR(cur);
    SETCAR(cur, createRef(xref, "XRef", NULL)); 

    invokeMethod(e);
    UNPROTECT(1);
}

void 
ROutputDev::endPage()
{
    SEXP fun = lookupRMethod("endPage");
    if(fun == R_NilValue) 
        return;

    SEXP e, cur;
    PROTECT(e = cur = allocVector(LANGSXP, 1));
    SETCAR(cur, fun);

    invokeMethod(e);
    UNPROTECT(1);
}


void 
ROutputDev::updateFillColor(GfxState * state)
{
    SEXP fun = lookupRMethod("updateFillColor");
    if(fun == R_NilValue) 
        return;

    SEXP e, cur;
    PROTECT(e = cur = allocVector(LANGSXP, 2));
    SETCAR(cur, fun); cur = CDR(cur);
    SETCAR(cur, createRef(state, "GfxState", NULL)); 

    invokeMethod(e);
    UNPROTECT(1);
}

#endif


#include "Rpoppler.h"
#include "ROutputDev_auto.cpp_code"
