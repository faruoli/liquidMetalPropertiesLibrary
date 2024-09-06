# Liquid Metal Properties DLL Library Manual

The Liquid Metal Properties DLL provides a set of functions for calculating the physical properties of various liquid metals based on temperature. 
It computes: 
- Density,
- Viscosity,
- Thermal Conductivity,
- Specific Heat capacity

The available materials are:
- Lead - 'Pb'
- Bismuth - 'Bi'
- LBE - 'LBE'

This library can be integrated into C/C++ programs, as well as MATLAB, for scientific computations and simulations.

Reference: 
"Handbook on Lead-bismuth Eutectic Alloy and Lead Properties, Materials Compatibility, Thermal-hydraulics and Technologies – 2015 Edition"
https://www.oecd-nea.org/jcms/pl_14972/handbook-on-lead-bismuth-eutectic-alloy-and-lead-properties-materials-compatibility-thermal-hydraulics-and-technologies-2015-edition?details=true

## System Requirements (To be checked)
- Windows 10 (64-bit)
- Microsoft Visual Studio 2022 (Community Edition or higher)
- MATLAB R2022a or higher
- C/C++ compiler compatible with the MSVC toolchain


## Installation
1. Download the DLL and header files (`liquidMetalProperties.dll` and `liquidMetalProperties.h`).
2. Copy `liquidMetalProperties.dll` to a directory where your project can reference it, e.g., `C:\path\to\dll`.
3. Ensure that the directory containing the DLL is added to your system's PATH, or place it in the same folder as the executable that uses it.

## Function Reference

### `double GetDensity(double temperature, const char* material)`
Calculates the density of the liquid metal at a given temperature for a specific material.

- **Parameters**:
  - `temperature` (double): The temperature in Kelvin.
  - `material` (const char*): The material name (e.g., "Pb" for lead, "Bi" for bismuth, "LBE" for LBE).
  
- **Returns**:
  - (double): The calculated density in kg/m^3.

### `double GetSpecificHeat(double temperature, const char* material)`
Calculates the specific heat capacity of the liquid metal at a given temperature and for a specific material.

- **Parameters**:
  - `temperature` (double): The temperature in Kelvin.
  - `material` (const char*): The material name (e.g., "Pb" for lead, "Bi" for bismuth, "LBE" for LBE).
  
- **Returns**:
  - (double): The specific heat capacity in J/kg·K.
 
### `double GetViscosity(double temperature, const char* material)`
Calculates the dynamic viscosity of the liquid metal at a given temperature and for a specific material.

- **Parameters**:
  - `temperature` (double): The temperature in Kelvin.
  - `material` (const char*): The material name (e.g., "Pb" for lead, "Bi" for bismuth, "LBE" for LBE).
  
- **Returns**:
  - (double): The specific heat capacity in Pa·s.

### `double GetThermalConductivity(double temperature, const char* material)`
Calculates the thermal conductivity of the liquid metal at a given temperature and for a specific material.

- **Parameters**:
  - `temperature` (double): The temperature in Kelvin.
  - `material` (const char*): The material name (e.g., "Pb" for lead, "Bi" for bismuth, "LBE" for LBE).
  
- **Returns**:
  - (double): The themal conductivity in W/m·K.
 
 ## Example of usage - Matlab
 
% Load the library

loadlibrary('liquidMetalProperties.dll', 'liquidMetalProperties.h');

% Call the functions

temperature = 500;

material = 'Pb';

density = calllib('liquidMetalProperties', 'GetDensity', temperature, material);

specificHeat = calllib('liquidMetalProperties', 'GetSpecificHeat', temperature, material);

disp(['Density: ', num2str(density), ' kg/m^3']);

disp(['Specific Heat: ', num2str(specificHeat), ' J/kg·K']);

% Unload the library

unloadlibrary('liquidMetalProperties');


## Compilation Instructions

To compile the DLL from source, follow these steps:

1. Open the project in Microsoft Visual Studio.
2. Ensure that the correct include paths for external libraries (e.g., MATLAB) are set.
3. Build the project in Release mode for 64-bit architecture.
4. The resulting `liquidMetalProperties.dll` will be located in the `Release` folder.

## Troubleshooting

### Issue: DLL cannot be loaded in MATLAB
- **Solution**: Ensure that the DLL is located in a directory that is on the system PATH or in the current MATLAB working directory. Verify the correct architecture (64-bit) is being used.

### Issue: Incorrect results for specific material
- **Solution**: Double-check that the `material` parameter matches the expected string (e.g., "Pb", "Bi"). The string comparison is case-sensitive.


## Contact Information
For bug reports or additional support, please contact:
- Email: maria.faruoli@vki.ac.be
- GitHub: https://github.com/liquidmetals/issues  ****to fix*****




