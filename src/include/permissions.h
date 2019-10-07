/*
	permissions.h
		Check permissions and make definitions of existing permissions
*/


#pragma once

#ifndef PERMISSIONS_H_
#define PERMISSIONS_H_

#include "export.h"
#include "global.h"

enum class permissionLevel {
	admin, // Same as user, but admin
	user, // Read write
	guest, // Read only permissions, should rarely be used
	NA // Defult value, if this is set find out permission level ourselves
};


#endif
