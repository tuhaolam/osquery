/*
 *  Copyright (c) 2014-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

#define WIN32_LEAN_AND_MEAN
#include <Objbase.h>
#include <Windows.h>

#include <osquery/system.h>

namespace osquery {

void Initializer::platformSetup() {
  // Initialize the COM libraries utilized by Windows WMI calls.
  auto ret = ::CoInitializeEx(0, COINIT_MULTITHREADED);
  if (ret != S_OK) {
    ::CoUninitialize();
  }
}

void Initializer::platformTeardown() {
  // Before we shutdown, we must insure to free the COM libs in windows
  ::CoUninitialize();
}

void alarm(int /* noop */) {
  /* This function is a noop. */
}
} // namespace osquery
