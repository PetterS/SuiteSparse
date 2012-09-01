#ifndef CHOLMOD_BLAS_ACML_H
#define CHOLMOD_BLAS_ACML_H

#include <acml.h>
#include <stdlib.h>

#define CHOLMOD_ARCHITECTURE "Microsoft Windows"
#define BLAS_NO_UNDERSCORE
#define BLAS_INT int

#define CHECK_BLAS_INT (sizeof (BLAS_INT) < sizeof (Int))
#define EQ(K,k) (((BLAS_INT) K) == ((Int) k))

#define MKCOMPLEX(ptr) (doublecomplex*)(ptr)

//#define DEBUGBLAS(function) printf("Executing %s...\n", #function); fflush(stdout);
#define DEBUGBLAS(function) // no-op

#define BLAS_dgemv(trans,m,n,alpha,A,lda,X,incx,beta,Y,incy) \
	DEBUGBLAS(dgemv) \
	dgemv(trans[0], m, n, alpha[0], A, lda, X, incx, beta[0], Y, incy)

#define BLAS_zgemv(trans,m,n,alpha,A,lda,X,incx,beta,Y,incy) \
	DEBUGBLAS(zgemv) \
	zgemv(trans[0], m, n, MKCOMPLEX(alpha), MKCOMPLEX(A), lda, MKCOMPLEX(X), incx, MKCOMPLEX(beta), MKCOMPLEX(Y), incy) 

#define BLAS_dtrsv(uplo,trans,diag,n,A,lda,X,incx) \
	DEBUGBLAS(dtrsv) \
	dtrsv(uplo[0], trans[0], diag[0], n, A, lda, X, incx)

#define BLAS_ztrsv(uplo,trans,diag,n,A,lda,X,incx) \
	DEBUGBLAS(ztrsv) \
	ztrsv(uplo[0], trans[0], diag[0], n, MKCOMPLEX(A), lda, MKCOMPLEX(X), incx)

#define BLAS_dtrsm(side,uplo,transa,diag,m,n,alpha,A,lda,B,ldb) \
	DEBUGBLAS(dtrsm) \
	dtrsm(side[0], uplo[0], transa[0], diag[0], m, n, alpha[0], A, lda, B, ldb)

#define BLAS_ztrsm(side,uplo,transa,diag,m,n,alpha,A,lda,B,ldb) \
	DEBUGBLAS(ztrsm) \
	ztrsm(side[0], uplo[0], transa[0], diag[0], m, n, MKCOMPLEX(alpha), MKCOMPLEX(A), lda, MKCOMPLEX(B), ldb)

#define BLAS_dgemm(transa,transb,m,n,k,alpha,A,lda,B,ldb,beta,C,ldc) \
	DEBUGBLAS(dgemm) \
	dgemm(transa[0], transb[0], m, n, k, alpha[0], A, lda, B, ldb, beta[0], C, ldc)

#define BLAS_zgemm(transa,transb,m,n,k,alpha,A,lda,B,ldb,beta,C,ldc) \
	DEBUGBLAS(zgemm) \
	zgemm(transa[0], transb[0], m, n, k, MKCOMPLEX(alpha), MKCOMPLEX(A), lda, MKCOMPLEX(B), ldb, MKCOMPLEX(beta), MKCOMPLEX(C), ldc)

#define BLAS_dsyrk(uplo,trans,n,k,alpha,A,lda,beta,C,ldc) \
	DEBUGBLAS(dsyrk) \
	dsyrk(uplo[0], trans[0], n, k, alpha[0], A, lda, beta[0], C, ldc)

#define BLAS_zherk(uplo,trans,n,k,alpha,A,lda,beta,C,ldc) \
	DEBUGBLAS(zhgerk) \
	zherk(uplo[0], trans[0], n, k, alpha[0], A, lda, beta[0], C, ldc)

#define LAPACK_dpotrf(uplo,n,A,lda,info) \
	DEBUGBLAS(dpotrf) \
	dpotrf(uplo[0], n, A, lda, &info)

#define LAPACK_zpotrf(uplo,n,A,lda,info) \
	DEBUGBLAS(zpotrf) \
	zpotrf(uplo[0], n, MKCOMPLEX(A), lda, &info)

/* ========================================================================== */

void BLAS_DSCAL (BLAS_INT *n, double *alpha, double *Y, BLAS_INT *incy) ;

#define BLAS_dscal(n,alpha,Y,incy) \
	DEBUGBLAS(dscal) \
	dscal(n, alpha[0], Y, incy)

#define BLAS_zscal(n,alpha,Y,incy) \
	DEBUGBLAS(zscal) \
	zscal(n, MKCOMPLEX(alpha), MKCOMPLEX(Y), incy)

#define BLAS_dger(m,n,alpha,X,incx,Y,incy,A,lda) \
	DEBUGBLAS(dger) \
	dger(m, n, alpha[0], X, incx, Y, incy, A, lda)

#define BLAS_zgeru(m,n,alpha,X,incx,Y,incy,A,lda) \
	DEBUGBLAS(zgeru) \
	zger(m, n, alpha[0], MKCOMPLEX(X), incx, MKCOMPLEX(Y), incy, MKCOMPLEX(A), lda)

#endif