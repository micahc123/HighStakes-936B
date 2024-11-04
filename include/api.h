// api.h
#ifndef _PROS_API_H_
#define _PROS_API_H_

#ifdef __cplusplus
#include <cerrno>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#else
#include <errno.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#endif

#define PROS_VERSION_MAJOR 3
#define PROS_VERSION_MINOR 8
#define PROS_VERSION_PATCH 3
#define PROS_VERSION_STRING "3.8.3"

#include "pros/adi.h"
#include "pros/colors.h"
#include "pros/distance.h"
#include "pros/error.h"
#include "pros/ext_adi.h"
#include "pros/gps.h"
#include "pros/imu.h"
#include "pros/link.h"
#include "pros/llemu.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/optical.h"
#include "pros/rotation.h"
#include "pros/rtos.h"
#include "pros/screen.h"
#include "pros/vision.h"

#ifdef __cplusplus
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/gps.hpp"
#include "pros/imu.hpp"
#include "pros/link.hpp"
#include "pros/llemu.hpp"
#include "pros/misc.hpp"
#include "pros/motors.hpp"
#include "pros/optical.hpp"
#include "pros/rotation.hpp"
#include "pros/rtos.hpp"
#include "pros/screen.hpp"
#include "pros/vision.hpp"
#endif

#endif  // _PROS_API_H_