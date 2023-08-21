/*
  Based on: https://github.com/wmbusmeters/wmbusmeters/blob/master/src/driver_sharky774.cc
  Copyright (C) 2017-2022 Fredrik Öhrström (gpl-3.0-or-later)
*/

#pragma once

#include "driver.h"

#include <vector>
#include <string>

struct Sharky774: Driver
{
  Sharky774() : Driver(std::string("sharky774")) {};
  virtual esphome::optional<std::map<std::string, double>> get_values(std::vector<unsigned char> &telegram) override {
    std::map<std::string, double> ret_val{};

    add_to_map(ret_val, "total_energy_consumption_kwh", this->get_0C06(telegram));

    if (ret_val.size() > 0) {
      return ret_val;
    }
    else {
      return {};
    }
  };

private:
};