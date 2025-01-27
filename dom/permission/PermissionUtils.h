/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef mozilla_dom_PermissionUtils_h_
#define mozilla_dom_PermissionUtils_h_

#include "mozilla/dom/PermissionsBinding.h"
#include "mozilla/dom/PermissionStatusBinding.h"
#include "mozilla/Maybe.h"

namespace mozilla::dom {
class Document;

const nsLiteralCString& PermissionNameToType(PermissionName aName);

/**
 * Returns the permission name given a permission type.
 *
 * Note: the "midi" permission is implemented with two internal permissions
 * ("midi" and "midi-sysex"). For this reason, when we pass "midi-sysex" to
 * this function, it unconditionally returns the "midi" permission name,
 * because that's the only public permission name.
 */
Maybe<PermissionName> TypeToPermissionName(const nsACString& aType);

PermissionState ActionToPermissionState(uint32_t aAction, PermissionName aName,
                                        const Document& aDocument);

}  // namespace mozilla::dom

#endif
