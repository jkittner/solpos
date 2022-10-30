# Welcome to solpos documentation!

This is a thin wrapper around [NREL](https://www.nrel.gov/)'s [SOLPOS 2.0](https://www.nrel.gov/), exposing the `S_solpos` C-function to python as {func}`solpos.solpos`. All possible outputs are calculated, and exposed via the {func}`solpos.SolposResult` NamedTuple-object, so they can be accessed as an attribute.

**NREL's description:**

> NREL's Solar Position and Intensity (SOLPOS 2.0) C function calculates the apparent solar position and intensity (theoretical maximum solar energy) based on date, time, and location on Earth.

- **solpos** on GitHub: [https://github.com/theendlessriver13/solpos](https://github.com/theendlessriver13/solpos)
- NREL's **SOLPOS 2.0**: [https://www.nrel.gov/grid/solar-resource/solpos.html](https://www.nrel.gov/grid/solar-resource/solpos.html)
- NREL's Disclaimer: [https://www.nrel.gov/disclaimer.html](https://www.nrel.gov/disclaimer.html)

## Contents

```{toctree}
---
maxdepth: 2
---

solpos.md
```

## Installation

To install **solpos**, open an interactive shell and run

```console
pip install solpos
```

### Gettings Started

```python
from solpos import solpos

result = solpos(
    year=2022,
    month=10,
    day=27,
    hour=16,
    minute=26,
    second=0,
    timezone=2,
    latitude=51.44579,
    longitude=7.26274,
)
# solar elevation angle refracted
print(result.elevref)
# solar declination
print(result.declin)
# shadow band correction factor
print(result.sbcf)
```

```console
13.568160057067871
-12.900684356689453
1.093388319015503
```

For a detailed description of all (calculated) attributes see: {func}`solpos.SolposResult`.

### Accuracy

The python version wrapping the C-function is tested for accuracy against running the pure C-version and NREL's [SOLPOS online calculator](https://midcdmz.nrel.gov/solpos/solpos.html)

- against the online calculator: {math}`\pm 1 * 10^{-4}`
- against the pure C-Version: {math}`\pm 1 * 10^{-6}`

### License

The project is licesned under the [MIT License](https://github.com/theendlessriver13/solpos/blob/master/LICENSE) and vendors **SOLPOS 2.0** via [SolarPILOT](https://github.com/NREL/SolarPILOT/tree/21a1466398ec22db24a5a838e5133da58e347b83/solpos) which is licensed under a [mixed MIT and GPLv3 license](https://github.com/NREL/SolarPILOT/blob/21a1466398ec22db24a5a838e5133da58e347b83/LICENSE.md) and *[...] allows for-profit and not-for-profit organizations to develop and redistribute software based on SolarPILOT under terms of an MIT license*.

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

## Indices and tables

- {ref}`genindex`
- {ref}`search`
