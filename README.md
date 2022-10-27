[![pre-commit.ci status](https://results.pre-commit.ci/badge/github/theendlessriver13/solpos/master.svg)](https://results.pre-commit.ci/latest/github/theendlessriver13/solpos/master)

# solpos

This library wraps [NREL](https://www.nrel.gov/)'s [SOLPOS 2.0](https://www.nrel.gov/grid/solar-resource/solpos.html) and makes it accessible from python.

The SOLPOS code was vendored from: [NREL/SolarPILOT](https://github.com/NREL/SolarPILOT/tree/21a1466398ec22db24a5a838e5133da58e347b83) which is licensed under a [mixed MIT and GPLv3license](licenses/LICENSE_SolarPILOT).

### References

**SolarPILOT**

Wagner, M.J. (2018). "SolarPILOT Open-Source Software Project: https://github.com/NREL/SolarPILOT/tree/21a1466398ec22db24a5a838e5133da58e347b83." Accessed (27/10/2022). National Renewable Energy Laboratory, Golden, Colorado.

**Astronomical Solar Position**

Michalsky, J. 1988. The Astronomical Almanac's algorithm for approximate solar position (1950-2050). _Solar Energy_ 40 (3), 227-235.

Michalsky, J. 1988. ERRATA: The astronomical almanac's algorithm for approximate solar position (1950-2050). _Solar Energy_ 41 (1), 113.

**Distance from Sun to Earth**

Spencer, J. W. 1971. Fourier series representation of the position of the sun. _Search 2_ (5), 172.
NOTE: This paper gives solar position algorithms as well, but the Michalsky/Almanac algorithm above is more accurate.

**Atmospheric Refraction Correction**

Zimmerman, John C. 1981. _Sun-pointing programs and their accuracy_. SAND81-0761, Experimental Systems Operation Division 4721, Sandia National Laboratories, Albuquerque, NM.

**Shadow Band Correction Factor**

Drummond, A. J. 1956. A contribution to absolute pyrheliometry. _Q. J. R. Meteorol.2 Soc._ 82, 481-493.

**Relative Optical Air Mass**

Kasten, F. and Young, A. 1989. Revised optical air mass tables and approximation formula. _Applied Optics_ 28 (22), 4735-4738.

**Renormalization of KT (“PRIME”)**

Perez, R., P. Ineichen, Seals, R., & Zelenka, A. 1990. Making full use of the clearness index for parameterizing hourly insolation conditions. _Solar Energy_ 45 (2), 111-114.

**Solar Position Relative to Earth**

Iqbal, M. 1983. _An Introduction to Solar Radiation_. Academic Press, NY.
