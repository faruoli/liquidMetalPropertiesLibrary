#define EXTERN_C

#ifdef __cplusplus
extern "C" {
#endif

    double GetDensity(double temperature, const char* material);
    double GetSpecificHeat(double temperature, const char* material);
    double GetViscosity(double temperature, const char* material);
    double GetKinematicViscosity(double temperature, const char* material);
    double GetSurfaceTension(double temperature, const char* material);
    double GetThermalConductivity(double temperature, const char* material);
    double GetSaturationPressure(double temperature, const char* material);
    double GetMeltingPoint(const char* material);
    double GetBoilingPoint(const char* material);
    double GetThermalExpansion(double temperature, const char* material);

#ifdef __cplusplus
}
#endif
