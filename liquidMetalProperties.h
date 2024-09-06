#define EXTERN_C

#ifdef __cplusplus
extern "C" {
#endif

    double GetDensity(double temperature, const char* material);
    double GetSpecificHeat(double temperature, const char* material);
    double GetViscosity(double temperature, const char* material);
    double GetThermalConductivity(double temperature, const char* material);


#ifdef __cplusplus
}
#endif