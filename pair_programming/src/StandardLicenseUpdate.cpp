////////////////////////////////////////////////////////////////////////////////////////////////////
// StandardLicenseUpdate.cpp
// Copyright (c) 2019 Pdfix. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

// system
// other libraries
#include "Pdfix.h"

using namespace PDFixSDK;
namespace StandardLicenseUpdate {
void Run() {
  // initialize Pdfix
  if (!Pdfix_init(Pdfix_MODULE_NAME)) {
    throw std::runtime_error("Pdfix initialization fail");
  }

  Pdfix* pdfix = GetPdfix();
  if (!pdfix) {
    throw std::runtime_error("GetPdfix fail");
  }

  auto authorization = pdfix->GetStandardAuthorization();
  if (!authorization) {
    throw PdfixException();
  }

  if (!authorization->Update(false)) {
    throw PdfixException();
  }

  pdfix->Destroy();
}
}  // namespace StandardLicenseUpdate
