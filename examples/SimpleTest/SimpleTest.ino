#include <Arduino.h>
#include <SoftwareWire.h>
#include <h1_SW35xx.h>
#include "SoftwareWireWrapper.h"


using namespace h1_SW35xx;

// Create a SoftwareWire instance (choose your SDA and SCL pins)
SoftwareWire softWire(2, 3);
// Wrap the SoftwareWire instance
SoftwareWireWrapper softWrapper(softWire);
// Instantiate the SW35xx device with the wrapper
SW35xx device(softWrapper);

const char *fastChargeType2String(SW35xx::fastChargeType_t fastChargeType) {
  switch (fastChargeType) {
  case SW35xx::NOT_FAST_CHARGE:
    return "Not fast charge";
    break;
  case SW35xx::QC2:
    return "QC2.0";
    break;
  case SW35xx::QC3:
    return "QC3.0";
    break;
  case SW35xx::FCP:
    return "FCP";
    break;
  case SW35xx::SCP:
    return "SCP";
    break;
  case SW35xx::PD_FIX:
    return "PD Fix";
    break;
  case SW35xx::PD_PPS:
    return "PD PPS";
    break;
  case SW35xx::MTKPE1:
    return "MTK PE1.1";
    break;
  case SW35xx::MTKPE2:
    return "MTK PE2.0";
    break;
  case SW35xx::LVDC:
    return "LVDC";
    break;
  case SW35xx::SFCP:
    return "SFCP";
    break;
  case SW35xx::AFC:
    return "AFC";
    break;
  default:
    return "unknown";
    break;
  }
}

void setup() {
  Serial.begin(115200);
  softWrapper.begin(); // Initialize the SoftwareWire bus
  device.begin();
  Serial.println("SW35xx device initialized using SoftwareWire.");
}

void loop() {
  device.readStatus();
  Serial.print("Input Voltage: ");
  Serial.print(device.vin_mV);
  Serial.println(" mV");
  // … print other values as needed
  delay(2000);
}