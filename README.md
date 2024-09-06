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

    
 ## Example of usage - Pyhton

    import ctypes
    from ctypes import c_double, c_char_p
     
    dll  = ctypes.CDLL(r"liquidMetalProperties.dll")
     
    # Define the return types and argument types for the functions in the DLL
    dll.GetDensity.restype = c_double
    dll.GetDensity.argtypes = [c_double]
    dll.GetSpecificHeat.restype = c_double
    dll.GetSpecificHeat.argtypes = [c_double, c_char_p]  # temperature (double) and material (const char*)
    
    # Example usage of the functions
 
    material = b"Pb"  # b"Pb" because ctypes expects a byte string (C-style string)
    # Call GetDensity
    temperature = 1000.0
    density = dll.GetDensity(c_double(temperature),c_char_p(material))
    print(f"Density at {temperature}K: {density} kg/m^3")
    # Call GetSpecificHeat
 
    specific_heat = dll.GetSpecificHeat(c_double(temperature), c_char_p(material))
    print(f"Specific Heat for {material.decode()} at {temperature}K: {specific_heat} J/kg·K")


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
- GitHub: https://github.com/faruoli/liquidMetalPropertiesLibrary/issues




