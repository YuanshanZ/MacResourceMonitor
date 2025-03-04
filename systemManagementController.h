//
// Some parts of this c file come from Github repo /osx-cpu-temp and /libsmc and /iStats
// Please refer to their repos for license information
//

#ifndef FINALPROJECT_CPUSTATUS_H
#define FINALPROJECT_CPUSTATUS_H

#include <IOKit/IOKitLib.h>
#include <printf.h>
#include <memory.h>

/**
SMC keys
- T = Temperature (if first char)
- C = CPU
- G = GPU
- P = Proximity
- D = Diode
- H = Heatsink
- B = Battery
*/
#define AMBIENT_AIR_0          "TA0P"
#define AMBIENT_AIR_1          "TA1P"
#define CPU_0_DIODE            "TC0D"
#define CPU_0_HEATSINK         "TC0H"
#define CPU_0_PROXIMITY        "TC0P"
#define BATTERY_0_TEMP         "TB0T"
#define ENCLOSURE_BASE_1       "TB1T"
#define ENCLOSURE_BASE_2       "TB2T"
#define ENCLOSURE_BASE_3       "TB3T"
#define GPU_0_DIODE            "TG0D"
#define GPU_0_HEATSINK         "TG0H"
#define GPU_0_PROXIMITY        "TG0P"
#define HARD_DRIVE_BAY         "TH0P"
#define MEMORY_SLOT_0          "TM0S"
#define MEMORY_SLOTS_PROXIMITY "TM0P"
#define NORTHBRIDGE            "TN0H"
#define NORTHBRIDGE_DIODE      "TN0D"
#define NORTHBRIDGE_PROXIMITY  "TN0P"
#define THUNDERBOLT_0          "TI0P"
#define THUNDERBOLT_1          "TI1P"
#define WIRELESS_MODULE        "TW0P"


/**
SMC keys for fans - 4CC code
- F  = Fan
- Ac = Acutal
- Mn = Min
- Mx = Max
- Sf = Safe
- Tg = Target
Sources: See TMP SMC keys
*/
#define FAN_0            "F0Ac"
#define FAN_0_MIN_RPM    "F0Mn"
#define FAN_0_MAX_RPM    "F0Mx"
#define FAN_0_SAFE_RPM   "F0Sf"
#define FAN_0_TARGET_RPM "F0Tg"
#define NUM_FANS         "FNum"
#define FORCE_BITS       "FS! "

/**
Misc SMC keys - 4 byte multi-character constants
Sources: See TMP SMC keys
*/
#define BATT_PWR "BATP"
#define NUM_KEYS "#KEY"
#define ODD_FULL "MSDI"

#define CURRENT_BATTERY_CAP 1
#define MAX_BATTERY_CAP     2


kern_return_t SMC_open(void);

kern_return_t SMC_close();

double SMC_get_temperature(char *key);

int SMC_get_fan_num();

void SMC_get_fan_speeds(int fanNum, double *speeds);

double SMC_get_fan_speed(char *key);

int SMC_get_current_battery_percent();

int SMC_is_battery_powered();

const char *SMC_get_battery_health();

int SMC_get_time_remaining();

int hasBattery();

int systemSupported();

#endif //FINALPROJECT_CPUSTATUS_H

