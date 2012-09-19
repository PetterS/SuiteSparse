SuiteSparse
===========
SuiteSparse:  A Suite of Sparse matrix packages at http://www.suitesparse.com

See README.txt

Visual Studio Project Files
---------------------------
This repository adds project files for Visual Studio 2010, making compilation of SuiteSparse for Windows 64-bit easy.

Currently, the project files build the following:

* CHOLMOD
* AMD
* CAMD
* CCOLAMD
* COLAMD

ACML
----
ACML - the AMD Core Math Library - is a very fast BLAS and LAPACK library that works
well on Windows 64-bit. It can be obtained for free. This repository contains the necessary modifications to CHOLMOD for ACML.
